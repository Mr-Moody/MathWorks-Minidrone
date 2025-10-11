image = imread("path3.png");

BW = rgb2gray(image);

B = edge(BW, "canny");

hold off
figure(1)
imshow(BW)

figure(2)
imshow(B)


% for i = 1:n
%     boundary = B{i};
%     plot(boundary(:,2),120-boundary(:,1));
%     hold on
% end
% axis equal
% xlim([1 160])
% ylim([1 120])
% hold off

% p = polyfit(B(:,2),B(:,1), 1);
% t = linspace(1,160);
% y = polyval(p,t);
% 
% hold on
% plot(t,y);

[H,T,R] = hough(BW, "RhoResolution",0.5,"Theta",-90:0.5:89);
% a = imadjust(rescale(H));
% imshow(a, "XData", T, "YData", R, "InitialMagnification", "fit");

% Find peaks in the Hough transform
P = houghpeaks(H, 10, 'Threshold', 0.3 * max(H(:)));

% Extract lines
lines = houghlines(BW, T, R, P, 'FillGap', 5, 'MinLength', 20);

figure(3);
imshow(BW);
hold on;

for k = 1:length(lines)
    xy = [lines(k).point1; lines(k).point2];
    plot(xy(:,1), xy(:,2), 'LineWidth', 2, 'Color', 'green');
end


intersections = [];

for i = 1:length(lines)
    for j = i+1:length(lines)
        % Get line endpoints
        p1 = lines(i).point1;
        p2 = lines(i).point2;
        p3 = lines(j).point1;
        p4 = lines(j).point2;
        
        % Compute intersection
        [xi, yi] = polyxpoly([p1(1) p2(1)], [p1(2) p2(2)], ...
                             [p3(1) p4(1)], [p3(2) p4(2)]);
        if ~isempty(xi)
            intersections = [intersections; [xi yi]];
        end
    end
end

plot(intersections(:,1), intersections(:,2), 'ro', 'MarkerSize', 8, 'LineWidth', 2);

vx = 0;
vy = 1;

% Example current position of the drone (center of image or known coordinate)
x0 = size(BW,2)/2;
y0 = size(BW,1)/2;

% Compute distances from current position to all intersections
distances = sqrt((intersections(:,1) - x0).^2 + (intersections(:,2) - y0).^2);

% Find intersections within some radius (e.g., 30 pixels)
radius = 30;
nearbyPoints = intersections(distances < radius, :);
nearbyDistances = distances(distances < radius);

% Normalize heading vector
v = [vx vy] / norm([vx vy]);

% Compute unit vectors from current position to each candidate point
vectors = nearbyPoints - [x0 y0];
vectors = vectors ./ vecnorm(vectors, 2, 2);

% Compute cosine similarity between heading and candidate directions
alignment = vectors * v';

% Pick the point that is most aligned (max cosine) and reasonably far
[~, bestIdx] = max(alignment + 50 * (1 - nearbyDistances / max(nearbyDistances)));
bestPoint = nearbyPoints(bestIdx, :);



% Get all line endpoints
for k = 1:length(lines)
    p1 = lines(k).point1;
    p2 = lines(k).point2;
    
    % Compute perpendicular projection of bestPoint onto line segment
    proj = p1 + dot(bestPoint - p1, p2 - p1) / dot(p2 - p1, p2 - p1) * (p2 - p1);
    
    % Check if projection is within segment bounds
    if all(proj >= min([p1; p2])) && all(proj <= max([p1; p2]))
        % Store the projected point
        projPoints(k,:) = proj;
    else
        projPoints(k,:) = [NaN NaN];
    end
end

% Pick the valid projected point closest to bestPoint
validProj = projPoints(~isnan(projPoints(:,1)), :);
[~, minIdx] = min(vecnorm(validProj - bestPoint, 2, 2));
finalTarget = validProj(minIdx, :);

hold on
plot(finalTarget(1), finalTarget(2), 'bx', 'MarkerSize', 12, 'LineWidth', 2);
hold off



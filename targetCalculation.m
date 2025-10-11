image = imread("path2.png");
path = rgb2gray(image);

vx = 0;
vy = 1;

scale = 1/100; %pixel to realworld x,y scale

% Hough transform and find peaks
[H,T,R] = hough(path, "RhoResolution",0.5,"Theta",-90:0.5:89);
P = houghpeaks(H, 10, 'Threshold', 0.3 * max(H(:)));

% extract lines
lines = houghlines(path, T, R, P, 'FillGap', 5, 'MinLength', 20);

n = length(lines);

MAX_INTERSECTIONS = 200;                     % choose safe upper bound
intersections = zeros(MAX_INTERSECTIONS,2);  % fixed size
count = 0;

for i = 1:n
    for j = i+1:n
        % line start and end points
        p1 = lines(i).point1;
        p2 = lines(i).point2;
        p3 = lines(j).point1;
        p4 = lines(j).point2;
        
        % find intersections between lines
        %[xi, yi] = polyxpoly([p1(1) p2(1)], [p1(2) p2(2)], [p3(1) p4(1)], [p3(2) p4(2)]);
        %polyxpoly not supported for code generation

        [xi, yi, isIntersecting] = segmentIntersection(p1, p2, p3, p4);

        if isIntersecting
            count = count + 1;
            if count <= MAX_INTERSECTIONS
                intersections(count,:) = [xi yi];
            end
        end

    end
end

if count == 0
    dx = single(0);
    dy = single(0);
    return
end
intersections = intersections(1:count,:);

%plot(intersections(:,1), intersections(:,2), 'ro', 'MarkerSize', 8, 'LineWidth', 2);


% current position of drone in the camera is the middle
x0 = size(path,2)/2;
y0 = size(path,1)/2;

% find distances to intersections
distances = sqrt((intersections(:,1) - x0).^2 + (intersections(:,2) - y0).^2);

% find line intersections within a radius of drone
radius = 1000;
nearby_points = intersections(distances < radius, :);
nearby_distances = distances(distances < radius);

if isempty(nearby_points)
    dx = single(vx * scale);
    dy = single(vy * scale);
    return
end

% normalise vectors
v = [vx vy] / norm([vx vy]);

vectors = nearby_points - [x0 y0];
vectors = vectors ./ vecnorm(vectors, 2, 2);

% dot product cosine alignment
alignment = vectors * v';

% target point most aligned with some distance
[~, idx] = max(alignment + 0.1 * (1 - nearby_distances / max(nearby_distances)));
best_point = nearby_points(idx, :);

projected_points = zeros(n,2);

for k = 1:n
    p1 = lines(k).point1;
    p2 = lines(k).point2;
    
    % perpendicular projection of point onto line
    projected = p1 + dot(best_point - p1, p2 - p1) / dot(p2 - p1, p2 - p1) * (p2 - p1);
    
    % make sure within bounds
    if all(projected >= min([p1; p2])) && all(projected <= max([p1; p2]))
        projected_points(k,:) = projected;
    else
        projected_points(k,:) = [NaN NaN];
    end
end

% select only the valid points
valid = projected_points(~isnan(projected_points(:,1)), :);

[~, minIdx] = min(vecnorm(valid - best_point, 2, 2));
target = valid(minIdx, :);

dxpixels = target(1) - x0;
dypixels = target(2) - y0;

dxdouble = dxpixels * scale;
dydouble = dypixels * scale;

%update velocity vector
v = [dxdouble dydouble];
v = v / norm(v);

vx = v(1);
vy = v(2);

dx = single(dxdouble);
dy = single(dydouble);

figure(1);
imshow(image);
hold on

plot(target(1), target(2), "x");
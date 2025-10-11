function [forward, right] = fcn(path)
    % [n,m] = size(path);
    % 
    % persistent weighting;
    % if isempty(weighting)
    %     temp = zeros(n, m/2);
    % 
    %     for i=1:n
    %         for j=1:m/2
    %             temp(i,j) = sqrt(i^2+j^2);
    %         end
    %     end
    % 
    %     temp = temp / 200;
    % 
    %     temp = rot90(temp, 2);
    % 
    %     weighting = [flip(temp,2) temp];
    % 
    %     weighting = weighting .^ 1.25;
    % 
    %     % weighting = sqrt(weighting);
    % 
    % end
    % 
    % weighted_path = weighting .* double(path);
    % 
    % Q1 = path(1:n/2, m/2:m);
    % Q2 = path(n/2+1:n, m/2+1:m);
    % Q3 = path(n/2+1:n, 1:m/2);
    % Q4 = path(1:n/2, 1:m/2);
    % 
    % Q1avg = mean(Q1, "all");
    % Q2avg = mean(Q2, "all");
    % Q3avg = mean(Q3, "all");
    % Q4avg = mean(Q4, "all");
    % 
    % front = mean(weighted_path(1:n/2,1:m), "all");
    % back = mean(weighted_path(n/2+1:n, 1:m), "all");
    % 
    % forward = -single(front - back);
    % right = single(Q1avg + Q2avg - Q3avg - Q4avg);
    % 
    % total = single(Q1avg + Q2avg + Q3avg + Q4avg);
    % 
    % disp(mean(weighted_path(:,n)));

    %B = bwboundaries(path);

    % if mean(weighted_path(:,n)) > 0.02
    %     right = right + 0.5;
    % end
    % if mean(weighted_path(:,1)) > 0.02
    %     right = right - 0.5;
    % end

    %movement offset
    d = 0.1;

    B = edge(path, "canny");

    p = polyfit(B(:,2),120-B(:,1), 1);

    % If near to vertical line for straight ahead
    if p(1) > 1e3 || p(1) < - 1e3
        right = single(0);
        forward = single(d);
        return
    end
    
    theta = atan2(p(1),1);
    right = single(d*cos(theta));
    forward = single(d*sin(theta));

    % midx = 80;
    % midy = polyval(p, midx);

end
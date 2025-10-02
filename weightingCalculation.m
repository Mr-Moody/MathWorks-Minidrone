n = 120;
m = 160;

weighting = zeros(n, m/2);

    for i=1:n
        for j=1:m
            weighting(i,j) = sqrt(i^2+j^2);
        end
    end

    weighting = weighting / 200;

    weighting = rot90(weighting, 2);

    % weighting = cat(1,weighting,flip(weighting,2));

    weighting = [weighting flip(weighting,2)];

  

    display(weighting)
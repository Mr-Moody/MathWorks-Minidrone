n = 120;
m = 160;

temp = zeros(n, m/2);

for i=1:n
    for j=1:m/2
        temp(i,j) = sqrt(i^2+j^2);
    end
end

temp = temp / 200;

temp = rot90(temp, 2);

% weighting = [temp flip(temp,2)];
weighting = [flip(temp,2) temp];

weighting = weighting .^ 3;

heatmap(weighting);
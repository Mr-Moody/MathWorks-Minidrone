%% Variables
n = 120;
m = 160;

%% Weighting 1

temp = zeros(n, m/2);

for i=1:n
    for j=1:m/2
        temp(i,j) = sqrt(i^2+j^2);
    end
end

temp = temp / 200;

temp = rot90(temp, 2);

weighting = [temp flip(temp,2)];

weighting = weighting .^ 0.7;

weighting(:,1:3) = weighting(:,1:3) * 5;
weighting(:,m-2:m) = weighting(:,m-2:m) * 5;

heatmap(weighting);

%% Weighting 2

temp = zeros(n, m/2);

for i=1:n
    for j=1:m/2
        temp(i,j) = j;
    end
end

temp = temp / 200;

temp = rot90(temp, 2);

weighting = [temp flip(temp,2)];

weighting(:,1:3) = 10;
weighting(:,m-2:m) = 10;

heatmap(weighting);
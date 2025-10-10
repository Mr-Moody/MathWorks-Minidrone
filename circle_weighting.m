% radial weighting matrix;
clear; clc;

n = 120;
m = 160;
quadrant = [zeros(n/2,m/2)];
count_i = 0;
count_j = 0;

for i = 1:n/2
    for j = 1:m/2
        quadrant(i,j) = sqrt(i^2 + j^2);
        % count_j = count_j + 1;
    end
    % count_i = count_i + 1;
end 

quadrant = quadrant/100;
matrix = [quadrant flip(quadrant,2);
          flip(quadrant,1) rot90(quadrant,2)];

inverted_matrix = [rot90(quadrant,2) flip(quadrant,1);
    flip(quadrant,2) quadrant];

heatmap(inverted_matrix)


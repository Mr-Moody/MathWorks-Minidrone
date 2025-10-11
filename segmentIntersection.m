function [xi, yi, isIntersecting] = segmentIntersection(p1, p2, p3, p4)
%#codegen
    isIntersecting = false;
    xi = NaN;
    yi = NaN;

    % line 1: a1*x + b1*y = c1
    a1 = p2(2) - p1(2);
    b1 = p1(1) - p2(1);
    c1 = a1 * p1(1) + b1 * p1(2);

    % line 2: a2*x + b2*y = c2
    a2 = p4(2) - p3(2);
    b2 = p3(1) - p4(1);
    c2 = a2 * p3(1) + b2 * p3(2);

    determinant = a1 * b2 - a2 * b1;

    if abs(determinant) < 1e-10
        % parallel lines, no intersection
        return;
    end

    % find intersection
    xi = (b2 * c1 - b1 * c2) / determinant;
    yi = (a1 * c2 - a2 * c1) / determinant;

    % bounding box
    if xi >= min(p1(1), p2(1)) && xi <= max(p1(1), p2(1)) && ...
       yi >= min(p1(2), p2(2)) && yi <= max(p1(2), p2(2)) && ...
       xi >= min(p3(1), p4(1)) && xi <= max(p3(1), p4(1)) && ...
       yi >= min(p3(2), p4(2)) && yi <= max(p3(2), p4(2))
        isIntersecting = true;
    end
end

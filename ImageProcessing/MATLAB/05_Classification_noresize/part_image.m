function [new_cell] = part_image(mat_src)
    height = size(mat_src, 1);
    width  = size(mat_src, 2);

    nParts = 9;     % Total number of blocks = nParts * nParts

    offset_x = width / nParts;
    offset_y = height / nParts;

    x1 = 0;
    y1 = 0;

    for p = 1:nParts
        for q = 1:nParts
            new_cell{p, q} = imcrop(mat_src, [x1, y1, offset_x, offset_y]);

            x1 = x1 + offset_x;
        end
        x1 = 0;
        y1 = y1 + offset_y;
    end
end

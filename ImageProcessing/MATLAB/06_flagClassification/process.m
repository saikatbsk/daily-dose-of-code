dim = size(img);
Rows = dim(1);
Cols = dim(2);

partitions = 8;

for indx1 = 1:Rows
    for indx2 = 1:Cols
        t1 = 0;
        t2 = 1/partitions;
        for indx3 = 1:partitions
            if(img(indx1, indx2) > t1 && img(indx1, indx2) <= t2)
                img(indx1, indx2) = min(t1, t2);
            end
            t1 = t2;
            t2 = t2 + (1 / partitions);
        end
    end
end
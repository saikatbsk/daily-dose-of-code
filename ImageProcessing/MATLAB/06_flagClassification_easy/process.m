dim = size(img);
rows = dim(1);
cols = dim(2);

partitions = 8;

for p = 1:rows
    for q = 1:cols
        t1 = 0;
        t2 = 1/partitions;
        for r = 1:partitions
            if(img(p, q) > t1 && img(p, q) <= t2)
                img(p, q) = min(t1, t2);
            end
            t1 = t2;
            t2 = t2 + (1 / partitions);
        end
    end
end
clear; clc;

% Load images
imL = imread('im0.png');
imR = imread('im1.png');

% Composite image for 3D viewing
% imComp = cat(3, imL(:, :, 1), imR(:, :, 2:3));
% figure(1);
% imshow(imComp); title('Composite Image for 3D viewing');

% Compute disparity map using block matching and sub-pixel estimation
fprintf('Performing basic block matching...\n'); %fflush(stdout);

% Timer
tic();

% Create gray image
grayL = mean(imL, 3);
grayR = mean(imR, 3);

% DBasicSubpixel will hold the result of the block matching
DBasicSubpixel = zeros(size(grayL), 'single');

% Disparity range
disparityRange = 50;

% Size of blocks for block matching
halfBlockSize = 7;
blockSize = 2 * halfBlockSize + 1;

% Image dimensions
[imHeight, imWidth] = size(grayL);

for m = 1:imHeight
    % min/max row bounds for the template and blocks
    minr = max(1, m - halfBlockSize);
    maxr = min(imHeight, m + halfBlockSize);

    for n = 1:imWidth
        minc = max(1, n - halfBlockSize);
        maxc = min(imWidth, n + halfBlockSize);

        % mind = max(-disparityRange, 1 - minc);
        mind = 0;
        maxd = min(disparityRange, imWidth - maxc);

        template = grayR(minr:maxr, minc:maxc);
        numBlocks = maxd - mind + 1;
        blockDiffs = zeros(numBlocks, 1);

        for i = mind : maxd
            block = grayL(minr:maxr, (minc + i):(maxc + i));
            blockIndex = i - mind + 1;
            blockDiffs(blockIndex, 1) = sum(sum(abs(template - block)));
        end

        [temp, sortedIndeces] = sort(blockDiffs);
        bestMatchIndex = sortedIndeces(1, 1);
        d = bestMatchIndex + mind - 1;

        if ((bestMatchIndex == 1) || (bestMatchIndex == numBlocks))
            % Skip sub-pixel estimation and store initial disparity value
            DBasicSubpixel(m, n) = d;
        else
            % SAD values at the closest matching block (C2) and it's immidiate
            % neighbors (C1 and C3)
            C1 = blockDiffs(bestMatchIndex - 1);
            C2 = blockDiffs(bestMatchIndex);
            C3 = blockDiffs(bestMatchIndex + 1);

            % Adjust disparity
            DBasicSubpixel(m, n) = d - (0.5 * (C3 - C1) / (C1 - (2 * C2) + C3));
        end
    end

    if (mod(m, 10) == 0)
        fprintf('Image row %d / %d (%.0f%%)\n', m, imHeight, (m / imHeight) * 100); %fflush(stdout);
    end
end

elapsed = toc();
fprintf('Time taken %.2f min.\n', elapsed / 60.0); %fflush(stdout);

fprintf('Displaying disparity map...\n'); %fflush(stdout);

figure(1)
subplot(1, 2, 1); imshow(imL);
subplot(1, 2, 2); imshow(imR);

figure(2); clf;
imshow(DBasicSubpixel, []);
axis image;
colormap('jet');
colorbar;
title(strcat('Basic block matching, Sub-px acc., Search right, Block size = ', num2str(blockSize)));

% save 'variables.mat';

%% ========================================================================
%% Combine SURF with spatial features.
%%
%% Parameters:
%%      pts             - SURF features.
%%      img             - Actual image in consideration.
%%
%% Returns:
%%      comb_features   - Combined features.
%% ========================================================================

function comb_features = addSpatialFeatures2x2(pts, img)
    comb_features = [];

    for i = 1:size([pts.descriptor], 2)
        spat_features = [];

        if [pts(i).x] >= size(img, 2)/2
            spat_features = [2];
        else
            spat_features = [1];
        end

        if [pts(i).y] >= size(img, 1)/2
            spat_features = [spat_features; 2];
        else
            spat_features = [spat_features; 1];
        end

        comb_features = [comb_features, [pts(i).descriptor; spat_features]];
    end
end

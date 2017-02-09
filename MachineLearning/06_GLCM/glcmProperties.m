function properties = glcmProperties(I, offsets)
    glcm  = graycomatrix(I, 'Offset', offsets);
    stats = graycoprops(glcm);

    properties = [stats.Contrast stats.Correlation stats.Energy stats.Homogeneity];
end

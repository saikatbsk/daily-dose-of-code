%% Read Leeds Butterfly Dataset (v1.0) - (segmentations)

function segmentations = readImageSet(rootpath)
    c001 = dir(fullfile('leedsbutterfly', 'segmentations', '001_*.png'));
    c002 = dir(fullfile('leedsbutterfly', 'segmentations', '002_*.png'));
    c003 = dir(fullfile('leedsbutterfly', 'segmentations', '003_*.png'));
    c004 = dir(fullfile('leedsbutterfly', 'segmentations', '004_*.png'));
    c005 = dir(fullfile('leedsbutterfly', 'segmentations', '005_*.png'));
    c006 = dir(fullfile('leedsbutterfly', 'segmentations', '006_*.png'));
    c007 = dir(fullfile('leedsbutterfly', 'segmentations', '007_*.png'));
    c008 = dir(fullfile('leedsbutterfly', 'segmentations', '008_*.png'));
    c009 = dir(fullfile('leedsbutterfly', 'segmentations', '009_*.png'));
    c010 = dir(fullfile('leedsbutterfly', 'segmentations', '010_*.png'));

    segmentations = { c001 c002 c003 c004 c005 c006 c007 c008 c009 c010 };
end

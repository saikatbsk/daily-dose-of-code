%% Read Leeds Butterfly Dataset (v1.0)

function imagesets = readImageSet(rootpath)
    c001 = dir(fullfile('leedsbutterfly', 'images', '001_*.jpg'));
    c002 = dir(fullfile('leedsbutterfly', 'images', '002_*.jpg'));
    c003 = dir(fullfile('leedsbutterfly', 'images', '003_*.jpg'));
    c004 = dir(fullfile('leedsbutterfly', 'images', '004_*.jpg'));
    c005 = dir(fullfile('leedsbutterfly', 'images', '005_*.jpg'));
    c006 = dir(fullfile('leedsbutterfly', 'images', '006_*.jpg'));
    c007 = dir(fullfile('leedsbutterfly', 'images', '007_*.jpg'));
    c008 = dir(fullfile('leedsbutterfly', 'images', '008_*.jpg'));
    c009 = dir(fullfile('leedsbutterfly', 'images', '009_*.jpg'));
    c010 = dir(fullfile('leedsbutterfly', 'images', '010_*.jpg'));

    imagesets = { c001 c002 c003 c004 c005 c006 c007 c008 c009 c010 };
end

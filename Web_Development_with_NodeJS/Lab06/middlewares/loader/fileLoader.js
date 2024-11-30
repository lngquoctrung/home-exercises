const fs = require('fs');
const path = require('path');

const icons = {
    '': 'fa-folder',
    '.txt': 'fa-file-alt',
    '.jpg': 'fa-file-image',
    '.png': 'fa-file-image',
    '.pdf': 'fa-file-pdf',
    '.doc': 'fa-file-word',
    '.docx': 'fa-file-word',
    '.xls': 'fa-file-excel',
    '.xlsx': 'fa-file-excel',
    '.zip': 'fa-file-archive',
    '.rar': 'fa-file-archive',
    '.mp3': 'fa-file-audio',
    '.mp4': 'fa-file-video',
    '.avi': 'fa-file-video',
    '.mkv': 'fa-file-video',
    '.flv': 'fa-file-video',
    '.mov': 'fa-file-video',
    '.wmv': 'fa-file-video',
    '.mpg': 'fa-file-video',
    '.mpeg': 'fa-file-video',
    '.m4v': 'fa-file-video',
    '.avi': 'fa-file-video',
    '.flv': 'fa-file-video',
    '.mov': 'fa-file-video',
    '.wmv': 'fa-file-video',
    '.mpg': 'fa-file-video',
    '.mpeg': 'fa-file-video',
    '.m4v': 'fa-file-video',
    '.avi': 'fa-file-video',
    '.flv': 'fa-file-video',
    '.mov': 'fa-file-video',
    '.wmv': 'fa-file-video',
    '.mpg': 'fa-file-video',
    '.mpeg': 'fa-file-video',
}

const fileTypes = {
    '': 'Folder',
    '.txt': 'Text',
    '.jpg': 'Image',
    '.png': 'Image',
    '.pdf': 'PDF',
    '.doc': 'Word',
    '.docx': 'Word',
    '.xls': 'Excel',
    '.xlsx': 'Excel',
    '.zip': 'Archive',
    '.rar': 'Archive',
    '.mp3': 'Audio',
    '.mp4': 'Video',
    '.avi': 'Video',
    '.mkv': 'Video',
    '.flv': 'Video',
    '.mov': 'Video',
    '.wmv': 'Video',
    '.mpg': 'Video',
    '.mpeg': 'Video',
    '.m4v': 'Video',
    '.avi': 'Video',
    '.flv': 'Video',
    '.mov': 'Video',
    '.wmv': 'Video',
    '.mpg': 'Video',
    '.mpeg': 'Video',
    '.m4v': 'Video',
    '.avi': 'Video',
    '.flv': 'Video',
    '.mov': 'Video',
    '.wmv': 'Video',
    '.mpg': 'Video',
    '.mpeg': 'Video',
    '.m4v': 'Video',
    '.avi': 'Video',
    '.flv': 'Video',
    '.mov': 'Video',
    '.wmv': 'Video',
    '.mpg': 'Video',
    '.mpeg': 'Video',
    '.m4v': 'Video',
}

function formatFileSize(bytes){
    if (bytes === 0) return '0 Bytes';

    const sizes = ['Bytes', 'KB', 'MB', 'GB', 'TB'];
    // 1024 là cơ số chuyển đổi (1KB = 1024 Bytes)
    const i = Math.floor(Math.log(bytes) / Math.log(1024));
    
    // Làm tròn đến 2 chữ số thập phân
    const size = (bytes / Math.pow(1024, i)).toFixed(2);
    
    return `${size} ${sizes[i]}`;
}

module.exports = async (req, res, next) => {
    const rootUserDir = `${process.env.ROOT_DIR}/${req.session.name}`;
    try{
        // Check the folder exists or not
        try{
            await fs.promises.access(rootUserDir);
        }
        catch(error){
            // Create the folder
            await fs.promises.mkdir(rootUserDir, {recursive: true});
        }

        // Read all files in the folder
        const files = await fs.promises.readdir(rootUserDir);

        // Get detail information about each files and folders
        const fileDetails = await Promise.all(files.map(async (file) => {
            const filePath = path.join(rootUserDir, file);
            const stats = await fs.promises.stat(filePath);
            return {
                name: file,
                path: filePath,
                extension: path.extname(file),
                isDirectory: stats.isDirectory(),
                icon: icons[path.extname(file)] || 'fa-file',
                type: fileTypes[path.extname(file)] || 'File',
                size: stats.isDirectory() ? '-': formatFileSize(stats.size),   
                lastModified: stats.mtime.toISOString().split('T')[0]
            };
        }));
        req.files = fileDetails;
        next();
    }
    catch(error){
        console.log(error);
    }
}
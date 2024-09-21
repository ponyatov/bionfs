#include "bionfs.hpp"

int fuse_fs_getattr(const char *path, struct stat *st) {  //
    return -ENOSYS;
}

int readdir(const char *, void *, fuse_fill_dir_t, off_t,
            struct fuse_file_info *) {  //
    return -ENOSYS;
}

// int fuse_fs_getattr() { return -ENOSYS; }
// ... but
// int fuse_fs_open() { return 0; }
// int fuse_fs_release() { return 0; }
// int fuse_fs_opendir() { return 0; }
// int fuse_fs_releasedir() { return 0; }
// int fuse_fs_statfs() { return 0; }

struct fuse_operations operations = {
    .getattr = fuse_fs_getattr,
    .readdir = readdir  //
};

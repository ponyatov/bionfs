#ifndef __unix__
#error Linux-only code
#endif

#include "bionfs.hpp"

struct STATE {
    size_t count = 0;
} state;

#define PD ((STATE *)fuse_get_context()->private_data)

void *fuse_fs_init(struct fuse_conn_info *conn) {  //
    PD->count = 0;
    uid_t uid = fuse_get_context()->uid;
    fprintf(stderr, "\nuid:%i count:%i\n\n", uid, PD->count);

    return conn;
}

int fuse_fs_getattr(const char *path, struct stat *st) {  //
    uid_t uid = fuse_get_context()->uid;

    fprintf(stderr, "\nuid:%i count:%i\n\n", uid,PD->count++);
    return -ENOSYS;
}

int fuse_fs_readdir(const char *, void *, fuse_fill_dir_t, off_t,
                    struct fuse_file_info *) {  //
    fprintf(stderr, "\ncount: %i\n\n", PD->count++);
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
    .readdir = fuse_fs_readdir,  //
    // .init = fuse_fs_init,        //
};

int main(int argc, char *argv[]) {
    arg(0, argv[0]);
    for (int i = 1; i < argc; i++) {  //
        arg(i, argv[i]);
    }
    assert(argc >= 2);
    fprintf(stderr, "\npath: %s\n\n", realpath(argv[argc - 1], NULL));

    return fuse_main(argc, argv, &operations, &state);
}

void arg(int argc, char argv[]) {  //
    fprintf(stderr, "argv[%i] = <%s>\n", argc, argv);
}

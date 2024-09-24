#ifndef __unix__
#error Linux-only code
#endif

#include "bionfs.hpp"

fuse_state _state = {.mountpath = nullptr, .count = 0};

void *fuse_fs_init(struct fuse_conn_info *conn) {  //
    uid_t uid = fuse_get_context()->uid;
    fprintf(stderr, "\nuid:%i count:%i\n\n", uid, state->count);

    return conn;
}

int fuse_fs_getattr(const char *path, struct stat *st) {  //
    uid_t uid = fuse_get_context()->uid;

    fprintf(stderr, "\nuid:%i count:%i\n\n", uid, state->count++);
    return -ENOSYS;
}

int fuse_fs_readdir(const char *, void *, fuse_fill_dir_t, off_t,
                    struct fuse_file_info *) {  //
    fprintf(stderr, "\ncount: %i\n\n", state->count++);
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
    assert(argc >= 3);
    fprintf(stderr, "\n");
    assert(_state.imagepath = realpath(argv[argc - 2], NULL));
    fprintf(stderr, "image: %s\n", _state.imagepath);
    assert(_state.mountpath = realpath(argv[argc - 1], NULL));
    fprintf(stderr, "mount: %s\n", _state.mountpath);
    fprintf(stderr, "\n");

    return fuse_main(argc, argv, &operations, &_state);
}

void arg(int argc, char argv[]) {  //
    fprintf(stderr, "argv[%i] = <%s>\n", argc, argv);
}

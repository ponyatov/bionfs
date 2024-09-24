#ifndef __unix__
#error Linux-only code
#endif

#include "bionfs.hpp"

// fuse_state _state = {.mountpath = nullptr, .count = 0};

// void *fuse_fs_init(struct fuse_conn_info *conn) {  //
//     uid_t uid = fuse_get_context()->uid;
//     fprintf(stderr, "\nuid:%i count:%i\n\n", uid, state->count);

//     return conn;
// }

// int fuse_fs_getattr(const char *path, struct stat *st) {  //
//     uid_t uid = fuse_get_context()->uid;

//     fprintf(stderr, "\nuid:%i count:%i\n\n", uid, state->count++);
//     return -ENOSYS;
// }

// int fuse_fs_readdir(const char *, void *, fuse_fill_dir_t, off_t,
//                     struct fuse_file_info *) {  //
//     fprintf(stderr, "\ncount: %i\n\n", state->count++);
//     return -ENOSYS;
// }

// int fuse_fs_getattr() { return -ENOSYS; }
// ... but
// int fuse_fs_open() { return 0; }
// int fuse_fs_release() { return 0; }
// int fuse_fs_opendir() { return 0; }
// int fuse_fs_releasedir() { return 0; }
// int fuse_fs_statfs() { return 0; }

// struct fuse_operations operations = {
//     .getattr = fuse_fs_getattr,
//     .readdir = fuse_fs_readdir,  //
//     // .init = fuse_fs_init,        //
// };

// struct bion_config config = {0};
// const char *device = nullptr;

// const char help_text[] =
//     "usage: %s [options] device mountpoint\n"
//     "\n";

// static struct fuse_opt bion_fuse_opts[] = {
//     FUSE_OPT_KEY("-V", KEY_VERSION), FUSE_OPT_KEY("--version", KEY_VERSION),
//     FUSE_OPT_KEY("-h", KEY_HELP), FUSE_OPT_KEY("--help", KEY_HELP),
//     FUSE_OPT_END};

// int bion_fuse_opt_proc(void *data, const char *arg, int key,
//                        struct fuse_args *args) {
//     switch (key) {
//         case FUSE_OPT_KEY_NONOPT:
//             fprintf(stderr, "arg:%s\n", arg);
//             exit(1);
//         case KEY_HELP:
//             fprintf(stderr, help_text, args->argv[0]);
//             fuse_opt_add_arg(args, "-ho");
//             fuse_main(args->argc, args->argv, &operations, NULL);
//             exit(1);
//         default:
//             return 1;
//     }
// }

int main(int argc, char *argv[]) {
    arg(0, argv[0]);
    for (int i = 1; i < argc; i++) {  //
        arg(i, argv[i]);
    }

    // assert(argc >= 3);
    // fprintf(stderr, "\n");
    // assert(_state.imagepath = realpath(argv[argc - 2], NULL));
    // fprintf(stderr, "image: %s\n", _state.imagepath);
    // assert(_state.mountpath = realpath(argv[argc - 1], NULL));
    // fprintf(stderr, "mount: %s\n", _state.mountpath);
    // fprintf(stderr, "\n");

    // struct fuse_args args = FUSE_ARGS_INIT(argc, argv);
    // fuse_opt_parse(&args, &config, bion_fuse_opts, bion_fuse_opt_proc);
    // assert(device);

    return (new BION(argv,argv))->run();
    // return fuse_main(argc, argv, &operations, &_state);
}

void arg(int argc, char argv[]) {  //
    fprintf(stderr, "argv[%i] = <%s>\n", argc, argv);
}

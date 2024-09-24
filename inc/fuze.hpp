/// @file
/// @brief C++ wrapper for `libfuse`

#pragma once

#ifndef FUSE_USE_VERSION
#define FUSE_USE_VERSION 26
#endif

#include <fuse.h>

/// @defgroup fuze fuze
/// @brief C++ wrapper for `libfuse`
/// @{

/// @brief https://libfuse.github.io/doxygen/index.html
/// - `high-level` synchronous API
/// - `low-level` asynchronous API
namespace fuze {

template <class T>
class FUSE {
   public:
    /// @name no copy
    FUSE(const FUSE &) = delete;
    FUSE &operator=(const FUSE &) = delete;
    FUSE &operator=(FUSE &&) = delete;

    ~FUSE() = default;
};

/// @brief `fuse_operations`<br>
/// https://libfuse.github.io/doxygen/structfuse__operations.html
namespace operations {  //

extern "C" enum fuse_readdir_flags { FUSE_READDIR_PLUS = (1 << 0) };

typedef int (*getattr)(const char *, struct stat *, struct fuse_file_info *fi);
typedef int (*readlink)(const char *, char *, size_t);
typedef int (*mknod)(const char *, mode_t, dev_t);
typedef int (*mkdir)(const char *, mode_t);
typedef int (*unlink)(const char *);
typedef int (*rmdir)(const char *);
typedef int (*symlink)(const char *, const char *);
typedef int (*rename)(const char *, const char *, unsigned int flags);
typedef int (*link)(const char *, const char *);
typedef int (*chmod)(const char *, mode_t, struct fuse_file_info *fi);
typedef int (*chown)(const char *, uid_t, gid_t, struct fuse_file_info *fi);
typedef int (*truncate)(const char *, off_t, struct fuse_file_info *fi);
typedef int (*open)(const char *, struct fuse_file_info *fi);
typedef int (*read)(const char *, char *, size_t, off_t,
                    struct fuse_file_info *fi);
typedef int (*write)(const char *, const char *, size_t, off_t,
                     struct fuse_file_info *fi);
typedef int (*statfs)(const char *, struct statvfs *);
typedef int (*flush)(const char *, struct fuse_file_info *fi);
typedef int (*release)(const char *, struct fuse_file_info *fi);
typedef int (*fsync)(const char *, int, struct fuse_file_info *fi);
typedef int (*setxattr)(const char *, const char *, const char *, size_t, int);
typedef int (*getxattr)(const char *, const char *, char *, size_t);
typedef int (*listxattr)(const char *, char *, size_t);
typedef int (*removexattr)(const char *, const char *);
typedef int (*opendir)(const char *, struct fuse_file_info *fi);
typedef int (*readdir)(const char *, void *, fuse_fill_dir_t, off_t,
                       struct fuse_file_info *, enum fuse_readdir_flags);
typedef int (*releasedir)(const char *, struct fuse_file_info *fi);
typedef int (*fsyncdir)(const char *, int, struct fuse_file_info *fi);

typedef void *(*init)(struct fuse_conn_info *conn, struct fuse_config *cfg);

typedef void (*destroy)(void *private_data);

typedef int (*access)(const char *, int);

;
typedef int (*create)(const char *, mode_t, struct fuse_file_info *fi);
typedef int (*lock)(const char *, struct fuse_file_info *, int cmd,
                    struct flock *);
typedef int (*utimens)(const char *, const struct timespec tv[2],
                       struct fuse_file_info *fi);
typedef int (*bmap)(const char *, size_t blocksize, uint64_t *idx);
typedef int (*ioctl)(const char *, unsigned int cmd, void *arg,
                     struct fuse_file_info *, unsigned int flags, void *data);
typedef int (*poll)(const char *, struct fuse_file_info *,
                    struct fuse_pollhandle *ph, unsigned *reventsp);
typedef int (*write_buf)(const char *, struct fuse_bufvec *buf, off_t off,
                         struct fuse_file_info *fi);
typedef int (*read_buf)(const char *, struct fuse_bufvec **bufp, size_t size,
                        off_t off, struct fuse_file_info *fi);
typedef int (*flock)(const char *, struct fuse_file_info *, int op);
typedef int (*fallocate)(const char *, int, off_t, off_t,
                         struct fuse_file_info *fi);
typedef ssize_t (*copy_file_range)(const char *path_in,
                                   struct fuse_file_info *fi_in,
                                   off_t offset_in, const char *path_out,
                                   struct fuse_file_info *fi_out,
                                   off_t offset_out, size_t size, int flags);
typedef off_t (*lseek)(const char *, off_t off, int whence,
                       struct fuse_file_info *fi);

};  // namespace operations

};  // namespace fuze

/// @}

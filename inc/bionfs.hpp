#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/// @defgroup main main
/// @{

/// @brief program entry point
/// @param argc number of command line arguments
/// @param argv command line arguments
/// @return 0
extern int main(int argc, char *argv[]);

/// @brief print single command line argument
/// @param argc index
/// @param argv value
extern void arg(int argc, char argv[]);

/// @}

/// @defgroup fuse fuse
/// @brief `libfuse`
///
/// ## libfuse tutorial
/// - https://www.cs.nmsu.edu/~pfeiffer/fuse-tutorial/html/index.html
/// -
/// https://maastaar.net/fuse/linux/filesystem/c/2016/05/21/writing-a-simple-filesystem-using-fuse/
///
/// ## wear leveling references
///
/// - https://github.com/littlefs-project/littlefs-fuse
///
/// @{

#ifndef FUSE_USE_VERSION
#define FUSE_USE_VERSION 26
#endif

#include "fuze.hpp"
#include <sys/errno.h>

class BION : public fuze::FUSE<BION> {  //
};

// /// @brief global state
// struct fuse_state {
//     char *imagepath;  ///< absolute path for flash image
//     char *mountpath;  ///< absolute mount point path
//     size_t count;     ///< operations count
// };
// extern fuse_state _state;
// #define state ((fuse_state *)(fuse_get_context()->private_data))

// #include <unistd.h>
// #include <sys/types.h>
// #include <time.h>
// #include <string.h>

// struct bion_config {
//     void *context;
// };

// /// @brief command line options
// enum lfs_fuse_keys {
//     KEY_VERSION,
//     KEY_HELP,
// };

// extern const char *device;      ///< device / image file
// extern const char help_text[];  ///< short help text

/// @}

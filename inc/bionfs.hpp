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

/// @defgroup fuse FUSE
/// @brief @ref fuse.h
///
/// ## tutorial
/// - https://www.cs.nmsu.edu/~pfeiffer/fuse-tutorial/
///
/// ## libfuse
/// - @ref fuse_main (argc, argv, fuse_operations *op, user_data=NULL)
///
/// @{

#define FUSE_USE_VERSION 30
#include <fuse.h>
#include <sys/errno.h>

/// @brief global state
struct fuse_state {
    char *imagepath;  ///< absolute path for flash image
    char *mountpath;  ///< absolute mount point path
    size_t count;     ///< operations count
};
extern fuse_state _state;
#define state ((fuse_state *)(fuse_get_context()->private_data))

// #include <unistd.h>
// #include <sys/types.h>
// #include <time.h>
// #include <string.h>

/// @}

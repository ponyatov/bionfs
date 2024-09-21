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
/// @ref fuse_main
/// @{

#define FUSE_USE_VERSION 30
#include <fuse.h>
#include <sys/errno.h>
// #include <unistd.h>
// #include <sys/types.h>
// #include <time.h>
// #include <string.h>

/// @}

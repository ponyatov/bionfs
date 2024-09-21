#ifndef __unix__
#error Linux-only code
#endif

#include "bionfs.hpp"

int main(int argc, char *argv[]) {
    arg(0, argv[0]);
    for (int i = 1; i < argc; i++) {  //
        arg(i, argv[i]);
    }
    return fuse_main(argc, argv, &operations, NULL);
}

void arg(int argc, char argv[]) {  //
    fprintf(stderr, "argv[%i] = <%s>\n", argc, argv);
}

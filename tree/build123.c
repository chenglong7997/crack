#include <stdio.h>
#include <stdlib.h>
#include "build.h"

int main()
{
//    node_t* root = build123();
    node_t* root = build_n_tree(13);
    print_tree(root);
}

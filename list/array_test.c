#include <stdio.h>
#include <stdlib.h>
#include "build.h"

int main()
{
    node_t* head = build_n_list(10);
    print_list(head);
}

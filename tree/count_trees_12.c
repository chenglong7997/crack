/*
 *suppose you are building an N node bst with the values 1....n, how many
 *structurally different bst are there that store those values?
 * */

#include <stdio.h>
#include <stdlib.h>

void count_trees_test();
int count_trees(int num_keys);

int main()
{
    count_trees_test();
}

void count_trees_test()
{
    printf("1 keys have %d trees\n", count_trees(1));
    printf("2 keys have %d trees\n", count_trees(2));
    printf("3 keys have %d trees\n", count_trees(3));
    printf("4 keys have %d trees\n", count_trees(4));
}

int count_trees(int num_keys)
{
    if (num_keys <= 1)
        return 1;
    int sum = 0;
    for (int i = 0; i < num_keys; i++)
    {
        int left = count_trees(num_keys - i - 1);
	int right = count_trees(i);
	sum += left * right;
    }
    return sum;
}



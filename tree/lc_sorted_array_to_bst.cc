#include <iostream>
#include <vector>
#include "build.h"
#include "bfs.cc"
using namespace std;


node_t* sorted_array_to_bst(vector<int> &num)
{
    if (num.size() == 0) return NULL;

    int mid = num.size() / 2;
    node_t* root = new_node(num[mid]);

    vector<int> num1(num.begin(), num.begin() + mid);
    vector<int> num2(num.begin() + mid + 1, num.end());
    node_t* left = sorted_array_to_bst(num1);
    node_t* right = sorted_array_to_bst(num2);

    root->left = left;
    root->right = right;

    return root;
}

void test()
{
    int a[] = {1, 3, 4, 6, 7, 10, 33};
    vector<int> num(a, a + 7);
    node_t *root = sorted_array_to_bst(num);

    bfs(root);
}

int main()
{
    test();
}

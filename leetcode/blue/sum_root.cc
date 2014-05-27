#include <iostream>
#include "bfs.cc"
using namespace std;


int helper(node_t* root, int sum)
{
    if (root == NULL) return 0;

    sum = sum * 10 + root->data;

    if (!root->left && !root->right) return sum;

    return helper(root->left, sum) + helper(root->right, sum);
}

int sum_numbers(node_t* root)
{
    return helper(root, 0);
}

void test()
{
    node_t* root = build_n_tree(5, 0);
    bfs(root);
    cout<<sum_numbers(root)<<endl;
}

int main()
{
    test();
}

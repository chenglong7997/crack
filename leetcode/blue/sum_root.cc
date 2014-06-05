/*Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.
 *
 * An example is the root-to-leaf path 1->2->3 which represents the number 123.
 *
 * Find the total sum of all root-to-leaf numbers.
 *
 * For example,
 *
 *         1
 *        / \
 *       2   3
 *          The root-to-leaf path 1->2 represents the number 12.
 *          The root-to-leaf path 1->3 represents the number 13.
 *
 *          Return the sum = 12 + 13 = 25.
 *
 * */

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

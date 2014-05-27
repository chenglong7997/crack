#include <iostream>

const int MAX=256;

int map_index[MAX];
void map2_index(int inorder[], int n)
{
    for (int i = 0; i < n; i++)
    {
        assert(0 <= inorder[i] && inorder[i] <= MAX - 1);
	map_index[inorder[i]] = i;
    }
}

node_t* build_in_pre(int in[], int pre[], int n, int offset)
{
    assert(n >= 0);
    if (n == 0) return NULL;
    int rootval = pre[0];
    int i = map_index[rootval] - offset;
    node_t* root = new_node(rootval);
    //without current root
    root->left = build_in_pre(in, pre + 1, i, offset);
    root->right = build_in_pre(in + i + 1, pre + i + 1, n - i - 1, offset + i + 1);
    
    //construct from in and post order
    root->left = build_in_post(in, post, i, offset);
    root->right = build_in_post(in + i + 1, post + i, n - i - 1, offset + i + 1);
    return root;
}

int main()
{

}

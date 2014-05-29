/*
 *generate all the bsts
 *
 * */

#include <iostream>
#include <vector>

using namespace std;

vecto<node_t*>* generate(int start, int end)
{
    vector<node_t*> subtree = new vector<node_t*>();

    for (int i = start; i <= end; i++)
    {
        vector<node_t*> *leftsub = generate(start, i - 1);
	vector<node_t*> *rightsub = generate(i + 1, end);
	// leftsub has 2 nodes, rightsub has 3 nodes. then the total tree
	// equals all the leftsubs * rightsubs
        for (int j = 0; j < leftsub.size(); j++)
	{
	    for (int k = 0; k < rightsub.size(); j++)
	    {
	        node_t* root = new_node(i);
		root->left = (*leftsub)[j];
		root->right = (*rightsub)[k];
		subtree->push_back(root);
	    }
	}
    }
    return subtree;
}

vector<node_t*> generate_trees(int n)
{
    vector<node_t*> ret;
    if (n == 0)
    {
        ret.push_back(NULL);
	return ret;
    }
    return *generate(1, n);
}


int main()
{

}

#include <iostream>
#include <stack>



void print_zigzag(node_t* root)
{
    if (root == NULL) return;

    stack<node_t*> current_level, next_level;
    int left_to_right = 1;
    current_level.push(root);

    while(!current_level.empty())
    {
        node_t* cur = current_level.top();
	current_level.pop();
	if (cur)
	{
	    cout<<cur->data<<" ";
	    if (left_to_right)
	    {
	        next_level.push(cur->left);
		next_level.push(cur->right);
	    } else {
	        next_level.push(cur->right);
		next_level.push(cur->left);
	    }

	    if (current_level.empty())
	    {
	        cout<<endl;
		left_to_right = !left_to_right;
		swap(current_level, next_level);
	    }
	}
    }
}

int main()
{

}

#define null nullptr
#include <iostream>
using namespace std;
template <class t> 
class bst {
private: 
	struct node
	{
		t data;
		node*left;
		node*right;	node (t v) {
		data = v;
		left = null;
		right  = null;
	}
	};
	node*root= null;
	void Add (t v, node*root)
	{
	if (v >= root->data) 
	{
		if (root->right == null) root-> right = new node(v);
		else Add(v, root->right); 

	} else {
		if (root->left == null) root -> left = new node(v);
		else Add (v, root->left);
	}

	}
	node* getmaxer(node*root)
	{
		if (root->right == null) return root;
		else return getmaxer(root->right);	
	}
	node* getmin(node*root)
	{
		if (root->left == null) return root;
		else return getmin(root->left);	
	}
	node*searcher(t v, node*root)
	{
		if (root==null) return 0; 
		if (v > root -> data) return searcher (v, root->right); 
		else if (v < root -> data) return searcher(v,root->left);  
		else return root;
	}
	void searcherr(t v, node*&root, node *&par = null)
	{
		if(root==null) return;
		if (v > root -> data)
		{
			par = root;
			root = root->right;
			searcherr (v, root, par); 
		}
			else if (v < root -> data) 
			{
				par = root;
			root = root->left;
				searcherr(v,root, par);  
			}
			else return;
	}
	node* mdelte(node*root, t v)
	{
		if (root == null) return null;
		if (v<root->data) root-> left = mdelte(root->left, v);
		else if (v>root->data) root-> right = mdelte(root->right, v);
		else {
			if (root->left == null) {
				node*temp = root->right;
				delete root; 
				return temp;
			}
		else	if (root->right == null) {
				node*temp = root->left;
				delete root; 
				return temp;
			} else {
				t m = getmaxer(root->left)->data;
				root->data = m;
				root->left = mdelte(root->left, m);
			}
		}
		return root;
	}
	
	
public: 
	void add(t value)
	{
		if(root==null)
			{
				root = new node(value);
			}
		else {
			Add(value, root);
		}
	}
	t max()
	{
		if (root == null) return -1;
		return getmaxer(root)->data;
		 
	}
	t min()
	{
		if (root == null) return -1;
		return getmin(root)->data;
	}
	int search(t v)
	{
		if (searcher(v, root)) return 1; 
		return 0;
	}
	void deleter(t v)
	{
		mdelte(root , v);
	}
};
int main()
{
	bst <int> lol;
	lol.add(5);
	lol.add(9);
	lol.add(1);
	lol.add(100);
	cout << endl;
	cout << lol.min();
	lol.deleter(1);
	cout << endl;
	cout << lol.min();
}


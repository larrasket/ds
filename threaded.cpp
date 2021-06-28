#include <iostream>
#include <cstdlib>
#include <climits> 
using namespace std;
struct node
{
	node*left;
	node *right;
	int data;
	bool right_theard;
	bool left_theard;

};
class tbst {
private: 
	node*root; 	
public: 
	tbst(){
								      /* Constructor to create  */
		root = new node; 				      /* dummy node. 		*/
		root -> left = root;
	       	root -> right =  root;
		root->left_theard=true;
		root -> data = INT_MAX; 			     
	}
	void insert(int value) {
		node*check_key = root;
		while(1) {
			if (check_key->data < value) {
				if(check_key->right_theard) break;    /* Trying to find the best */
				check_key = check_key-> right;	      /* place to insert the new */
			}					      /* node, like a regular	 */
			else if (check_key->data > value) {           /* binary tree, but as you */
				if(check_key->left_theard) break;     /* can notice, I check for */  
				check_key = check_key -> left;	      /* free node place with    */
								      /* its threaded rather	 */
								      /* nullptr 		 */
			} else return;				      /* invaild input to inser  */
		}
		node* new_node = new node;
		new_node->data = value;
		new_node->right_theard = true;
		new_node->left_theard = true;
		if (check_key->data < value) {			      /* insertion in the right. */
			new_node->right = check_key->right; 
			new_node->left = check_key; 
			check_key->right = new_node;
			check_key->right_theard = false;
		}
		else  { 					      /* insertion in the left.  */
			new_node->right = check_key; 
			new_node->left = check_key->left; 
			check_key->left = new_node;
			check_key->left_theard = false;
		}
			
	}
	node* leftmost(node*root)                                     /* function to get the     */
								      /* leftmost node, you can  */
								      /* also include this in    */
	{							      /* next function without   */
	while(!root->left_theard) root = root->left;                  /* recursion, if you don't */
	return root; 						      /* want to use any stack,  */
	} 							      /* but I prefer to   	 */
	void inorder(){						      /* implement it like this  */
		node *it = leftmost(root);
		while(1)
		{
		cout << it->data;				      /* print it! we are in the */
		if ( it->right_theard)				      /* leftmose, then go to    */
		it = it->right; 				      /* right_theard which will */
		 else it = leftmost(it->right);			      /* be its root, then go    */
		if (it ==root) break; 				      /* right to get the right  */
		}						      /* node. If we rached the  */	
	}							      /* root again, then we're  */
								      /* done. 			 */
};

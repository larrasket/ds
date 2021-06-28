#include "include.h"
#include <cmath>
#include <memory>
#include <numeric>
/* I skipped the first 4 chapters exercises. */
/* 5 (Binary Tree) Exercises. 
 * 
 * 5.1 
 *  Section 5.1.1 claims that a full binary tree
 *  has the highest number of leaf nodes among all
 *  trees with n internal nodes. Prove that this is true 
 *  
 *  A binary tree is full if each node is either a leaf 
 *  or possesses exactly two child nodes, so if we have 
 *  a full binary tree that has a total of N nodes, the
 *  total number of leaves must be equal to (N + 1)/2.
 *  Otherwise, if the tree is not full, a lot of its 
 *  nodes can have the minimum number of leaves.
 * ---
 * 5.2
 *  Define the degree of a node as the number of its
 *  non-empty children. Prove by induction that the
 *  number of degree 2 nodes in any binary tree is
 *  one less than the number of leaves.
 *
 *  As the degree of a node is the number edges in 
 *  its endpoints, which lead to its child, we can
 *  define the degree of node as the number of its child. 
 *  
 *  Let a binary tree be within this base case which in it has only
 *  one leaf:
 *   N
 *   |
 *  (L)
 *  The number of 2 degree nodes is 0, what is exactly less than
 *  number of leafs by one, let's add another leaf: 
 *     N
 *    / \
 *   L   L
 *   Thus the number of leafs has been increased by one, therefore
 *   the number of 2 degree nodes must be L (total leafs) - 1 = 1. 
 * --- 
 * 5.3
 *  Prove by induction that if tree T is a full binary tree with n
 *  internal nodes, I is T’s internal path length, and E is T’s
 *  external path length, then E = I + 2n for n ≥ 0.
 *  
 *  Let a tree's E = 0, I =0, hence E = I + 2 = 0 is true, now
 *  let's consider the following tree: 
 *  	N 
 *    /   \
 *   T1    T2
 *
 *  Let T1 Have l internal nodes and T2 have r internal nodes, and
 *  let Il, Ir is l's I, r's I respectively. Then E1 = Il + 2l and
 *  Er = Ir + 2r. As n = l + r + 1 (total nodes), then 2l + 2r + 2
 *  = n. 
 * ---
 * 5.4
 *  Explain why function preorder2 from Section 5.2 makes half as
 *  many recursive calls as function preorder. 
 *   
 *   Consider that preorder calls both of left/right node, even the
 *   leaf is NULL meanwhile preorder2 calls itself if and only if
 *   the node that it is being called with have a child, so in the
 *   case of preorder, it calls nodes + its leafs, in the other
 *   hands, preorder2 calls only nodes. (notice that the number of
 *   nodes in a binary tree = number of leafs + 1). 
 * ---
 * 5.5 
 *  (a) Modify the preorder traversal of Section 5.2 to perform an
 *  in_order traversal of a binary tree. */
    void in_order(struct node* root)
    {
	if (root == NULL) return;
	in_order (root->left);
	visit(root);
	in_order (root->right);
    }
/*
 *  (b) Modify the preorder traversal of Section 5.2 to preform a
 *  post_order traversal of a binary tree */
    void post_order(struct node* root)
    {
	if (root == NULL) return;
	post_order (root->left);
	post_order (root->right);
	visit(root);
    }
 /*
  * ---
  * 5.6
  *  Write a recursive function named search that takes as input 
  *  the pointer to the root of a binary tree (not a BST!) and a
  *  value K, and returns true if value K appears in the tree and
  *  false otherwise.
  */
     bool search(struct node * root ,int val)
	{
	if (root == NULL) return 0;
	if (root -> data == val) return true;
	search (root ->left , val);
	search (root ->right , val);
	}
/*
 * 5.7
 *  Write an algorithm that takes as input the pointer to the root
 *  of a binary tree and prints the node values of the tree in level
 *  order. Level order first prints the root, then all nodes of level
 *  1, then all nodes of level 2, and so on. Hint: Preorder traversals
 *  make use of a stack through recursive calls. Consider making use of
 *  another data structure to help implement the levelorder traversal
 */  
	void levelOrder(struct node *root)
    {
    if (root == NULL) return;
    std::queue<node *> q;
    node *curr;
    q.push(root);
    q.push(NULL);
    while (q.size() > 1)
    {
        curr = q.front();
        q.pop();
        if (curr == NULL)
        {
           q.push(NULL);
        }
          
        else {
            if(curr->left)
            q.push(curr->left);
            if(curr->right)
            q.push(curr->right);
	    visit(curr);
        }
      }
      }
/*
 * 5.8
 *  Write a recursive function that returns the height of a binary tree.
 */
    int height(struct node*root){
   	if (root == NULL) return 0;
	return 1 + std::max( height (root->left) , height (root -> right) );	
    }
/*
 * 5.9
 *   Write a recursive function that returns a count of the number of 
 *   leaf nodes in a binary tree.
 */
    int leafs(struct node*root)
	{
	if (root == NULL) return 0;
	if (root->left == NULL  && root -> right == NULL) return 1;
	return leafs (root -> right) + leafs (root->left);
	}
/*
 * 5.10
 *  Assume that a given binary tree stores integer vales in its nodes.	
 *  Write a recursive function that sums the values of all nodes in
 *  the tree. 
 */
   int sums (struct node*root)
	{
		if (root == NULL) return 0;
		return root -> data + sums (root->left) + sums (root->right);
	}
/*
 * 5.11
 * Assume that a given binary tree stores integer values in its nodes.
 * Write a recursive function that traverses a binary tree, and prints
 * the value of every node who’s grandparent has a value that is a
 * multiple of five. 
 */
int isfivemulti(struct node* root, int l)
{
	if (root == NULL) return 0;
	if (l == 3 )
	{	visit(root);
	}
	isfivemulti(root->left, l+1);
	isfivemulti(root->right, l+1);


}
void printit(struct node* root)
{
	if (root == NULL) return;
	if(root->data % 5 == 0)
	isfivemulti(root, 1);
	printit(root->left);
	printit(root->right);
}	
/*
 * 5.12
 * Write a recursive function that traverses a binary tree, and prints
 * the value of every node which has at least four great-grandchilren
 */

int isfive(struct node* root, int l)
{
	if (root == NULL) return 0;
	if (l == 4 )
	{	return true;	
	}
	isfive(root->left, l+1);
	isfive(root->right, l+1);


}
void printfive(struct node* root)
{
	if (root == NULL) return;
	if(isfive(root, 1)) visit(root);
	printfive(root->left);
	printfive(root->right);
}	
/*
 * 5.13 
 *  Compute the overhead fraction for each of the following full
 *  binary tree implementations. 
 *
 *  (a) All nodes store data, two child pointers, and a parent
 *  pointer. The data field requires four bytes and each pointer
 *  requires four bytes.
 *
 *  (n-1)(16)+(12) - ((n+1)/2 ) * 8.
 *
 *  (b) All nodes store data and two child pointers. The data field
 *  requires sixteen bytes and each pointer requires four bytes.
 *
 *  n(8 + 16) - ((n+1)/2) * 8
 *
 *  (d) Only leaf nodes store data; internal nodes store two child
 *  pointers. The data field requires eight bytes and each pointer
 *  requires four bytes
 *
 *  ((n+1)/2) * 8 +  (n - ((n+1)/2)) * 8 
 * ---
 * 5.14
 *  Why is the BST Property defined so that nodes with values equal to
 *  the value of the root appear only in the right subtree, rather
 *  than allow equal-valued nodes to appear in either subtree?
 *  
 *  Because if the BST defined to put the left child as bigger or
 *  equal to OR smaller or equal to, it would take extra time to
 *  search for the duplicated nodes rather than if it have not been
 *  put in only one side.
 * ---
 * 5.15
 *  (a) Show the BST that results from inserting the values 15, 20, 25,
 *  18, 16, 5, and 7 (in that order). 
 *  
 *  				15
 *	                      /     \
 *	                     5       20
 *	                      \     /   \
 *	                       7  18     25
 *	                         /       
 *	                       16
 * 
 *  (b) Show the enumerations for the tree of (a) that result from
 *  doing a preorder traversal, an inorder traversal, and a postorder
 *  traversal. 
 *
 *  pre-order: 15 5 20 18 16 25
 *  in-order:  5 7 15 16 18 20 25 
 *  post-order: 7 5 16 18 25 20 15
 * ---
 * 5.16
 *  Draw the BST that results from adding the value 5 to the BST shown
 *  in Figure 5.13(a). 
 *
 *                           37
 *                          /   \
 *                        24     42
 *                       /  \   /  \
 *                      7   32 40   42
 *                     /              \
 *                    2                120 
 *                     \
 *                      5
 *
 * ---
 * 5.17
 *  Draw the BST that results from deleting the value 7 from the BST
 *  of Figure 5.13(b).
 *  
 *                          120
 *                         /
 *                       42	
 *                      /   \
 *                    7      42
 *                   / \    
 *                  2   32 
 *                      / \ 
 *                    24   37 
 *                           \
 *                           40
 * ---
 * 5.18
 *  Write a function that prints out the node values for a BST in
 *  sorted order from highest to lowest. 
 */ 
    void sortedprint(struct node* root) 
    { if (root == NULL) return;
      sortedprint (root->right);
      visit(root);
      sortedprint (root->left);
    }	
/*
 * 5.19
 *  Write a recursive function named smallcount that, given the
 *  pointer to the root of a BST and a key K, returns the number of
 *  nodes having key values less than or equal to K. Function
 *  smallcount should visit as few nodes in the BST as possible. 		
 */
    int smallcount(struct node* root, int key)
    {
    if (root == NULL ) return 0;
    if (key < root->data) smallcount(root ->left, key);
    else return 1 + smallcount (root -> right, key) + smallcount (root->left,key);
    
    }
		
/*
 * 5.20
 *  Write a recursive function named printRange that, given the pointer
 *  to the root of a BST, a low key value, and a high key value, prints
 *  in sorted order all records whose key values fall between the two
 *  given keys.
 */
   void printRange(struct node* root, int leftkey, int rightkey)
       {
	if (root == NULL) return;
	if (root->data < rightkey) printRange(root->right, leftkey, rightkey);
	if (root->data > leftkey) printRange (root -> left , leftkey, rightkey);
	if (root->data > leftkey && root ->data < rightkey) visit (root); 
       }
/*
 * 5.21
 *  Write a recursive function named checkBST that, given the pointer
 *  to the root of a binary tree, will return true if the tree is a
 *  BST, and false if it is not. 
 */
    int checkBST(struct node* root)
	  {
		  if (root==NULL) return 1;
		  if (root->left != NULL && root->left->data > root->data)
    		  return 0;
		  if (root->right != NULL && root->right->data < root->data)
    		  return 0;
		  if (!checkBST(root->left) || !checkBST(root->right))
      		  return 0;
		  return 1;
	  }
/*
 * 5.22
 *  Describe a simple modification to the BST that will allow it to
 *  easily support finding the Kth smallest value in Θ(log n) average
 *  case time.
 *
 *  Like 5.18, we can just modify 5.18's function to traversal nodes
 *  from smallest to the highest, and use a count variable as a flag
 *  when the count flag equal to k, return node data. 
 * ---
 * 5.23
 * What are the minimum and maximum numbers of elements in a heap of
 * height h?
 *
 *  At least 2^h, and at most 2^(h + 1)-1. 
 * ---
 * 5.24
 *  Where in a max-heap might the smallest element reside?
 *
 *  As in the max-heap the biggest value is the root, the smallest
 *  value should be the leaf nodes,
 * ---
 * 5.25
 *  Show the max-heap that results from running buildHeap on the
 *  following values stored in an array: 10 5 12 3 2 1 8 7 9 4.
 *
 *  12 9 10 7 4 1 8 5 3 2
 * ---
 * 5.26
 *  (a) Show the heap that results from deleting the maximum value from
 *  the max-heap of figure 2.20b. 
 *
 *  6 4 1 2 3 5
 *
 *  (b) Show the heap that results from deleting the element with
 *  value 5 from the max-heap of Figure 5.20b.
 *
 *  7 4 6 1 2 3
 * ---
 * 5.27
 *  Revise the heap definition of Figure 5.19 to implement a min-heap.
 *  The member function removemax should be replaced by a new function
 *  called removemin. 
 *  
 *  NOTE: I can't find the function removemax, however, I've two
 *  methods in my mind to implement removemin, the first you can
 *  traversal the whole array recursively to reach the heep, when   
 *  reach it, check each value until you find the minimum value,
 *  delete it and reheapify the array. The seconed, and I think it's
 *  better, is to search first for the min element in the array and
 *  detect its position, then just delete it and heapify the array.
 * ---
 * 5.28
 *  |------------+---+---+---+---+----+----+----+----+----+----+----+----|
 *  | Letter     | A | B | C | D | E  | F  | G  | H  | I  | J  | K  | L  |
 *  |------------+---+---+---+---+----+----+----+----+----+----+----+----|
 *  | Frequancey | 2 | 3 | 5 | 7 | 11 | 13 | 17 | 19 | 23 | 31 | 37 | 41 |
 *  |------------+---+---+---+---+----+----+----+----+----+----+----+----|
 *  Weighted path length would bd about 3.2.
 * ---
 * 5.29 
 *  What will the Huffman coding tree look like for a set of sixteen
 *  characters all with equal weight? What is the average code length
 *  for a letter in this case? How does this differ from the smallest
 *  possible fixed length code for sixteen characters?
 *  TODO. 
 * ---
 * 5.30
 *  A set of characters with varying weights is assigned Huffman codes.
 *  If one of the characters is assigned code 001, then.
 *  (a) Describe all codes that cannot have been assigned.
 *  (b) Describe all codes that must have been assigned.
 * TODO. 
 * ---
 * 5.31
 *  Assume that a sample alphabet has the following weights:
 *   |------------+---+---+----+----+----+----+----+----|
 *   | Letter     | Q | Z | F  | M  | T  | S  | O  | E  |
 *   | Frequancey | 2 | 3 | 10 | 10 | 10 | 15 | 20 | 30 |
 *   |------------+---+---+----+----+----+----+----+----|
 * TODO
 * 5.32
 *  You must keep track of some data. Your options are:
 *  (1) A linked-list maintained in sorted order.
 *  (2) A linked-list of unsorted records.
 *  (3) A binary search tree.
 *  (4) An array-based list maintained in sorted order.
 *  (5) An array-based list of unsorted records.
 *  For each of the following scenarios, which of these choices,
 *  what would be the best? explain your answer.
 *  
 *   (a) The records are guaranteed to arrive already sorted from
 *   lowest to high- est (i.e., whenever a record is inserted, its key
 *   value will always be greater than that of the last record inserted).
 *   A total of 1000 inserts will be interspersed with 1000 search. 
 *   
 *   An array-based list of unsorted records.
 *   Explanation: As the data well be inserted sorted, so there is no
 *   need to resort it again, also there is no need to build a dynamic
 *   data structure as the number of data is constant (1000).
 *
 *   (b) The records arrive with values having a uniform random
 *   distribution (so the BST is likely to be well balanced).
 *   1,000,000 insertions are performed, followed by 10 search.
 *
 *   An array-based list of unsorted records.
 *   Explanation: Since the number of insertion operation is much bigger
 *   than the number of search operations, the priority will to be pay 
 *   attention to the complexity of insertion than search. 
 *
 *   (c) The records arrive with values having a uniform random
 *   distribution (so the BST is likely to be well balanced). 1000
 *   insertions are interspersed with 1000 searches. 
 *
 *   A binary search tree. 
 *   Explanation: As the number of insertions is equal to the
 *   number of searches, BTS will be very suitable for this situation
 *   with average insertions complexity considered by O(log n) and search
 *   complexity considered with O(log n). 
 *
 *   (d) The records arrive with values having a uniform random
 *   distribution (so the BST is likely to be well balanced). 1000
 *   insertions are performed, followed by 1,000,000 searches. 
 *   
 *   An array-based list maintained in sorted order.
 *   Explanation: Insertion complexity'd be about O(n), but the
 *   attention is paid to the search complexity which'd be O(1) since
 *   it is sorted array. 
  */


/*			 5.9 (Binary Tree) Projects                      */ 
 /*
  * 5.1
  *  Re-implement the composite design for the binary tree node class
  *  of Fig- ure 5.11 using a flyweight in place of NULL pointers to
  *  empty node 
  *  TODO
  * ---
  * 5.2
  *  One way to deal with the “problem” of NULL pointers in binary
  *  trees is to use that space for some other purpose. One example is
  *  the threaded binary tree. Extending the node implementation of
  *  Figure 5.7, the threaded binary tree stores with each node two
  *  additional bit fields that indicate if the child pointers lc and
  *  rc are regular pointers to child nodes or threads. If lc is not a
  *  pointer to a non-empty child (i.e., if it would be NULL in a
  *  regular binary tree), then it instead stores a pointer to the
  *  inorder predecessor of that node. The inorder predecessor is the
  *  node that would be printed immediately before the current node in
  *  an inorder traversal. If rc is not a pointer to a child, then it
  *  instead stores a pointer to the node’s inorder successor. The
  *  inorder successor is the node that would be printed immediately
  *  after the current node in an inorder traversal. The main
  *  advantage of threaded binary trees is that operations such as
  *  inorder traversal can be implemented without using recursion or a
  *  stack 
  *  */
  struct dnode
  {
  	dnode*left;
  	dnode *right;
  	int data;
  	bool right_theard;
  	bool left_theard;
  
  };
  class tbst {
  private: 
  	dnode*droot; 	
  public: 
  	tbst(){
  								      /* Constructor to create  */
  		droot = new dnode; 				      /* dummy node. 		*/
  		droot -> left = droot;
  	       	droot -> right =  droot;
  		droot->left_theard=true;
  		droot -> data = INT_MAX; 			     
  	}
  	void insert(int value) {
  		dnode*check_key = droot;
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
  		dnode* new_node = new dnode;
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
  	dnode* leftmost(dnode*droot)                                     /* function to get the     */
  								      /* leftmost node, you can  */
  								      /* also include this in    */
  	{							      /* next function without   */
  	while(!droot->left_theard) droot = droot->left;                  /* recursion, if you don't */
  	return droot; 						      /* want to use any stack,  */
  	} 							      /* but I prefer to   	 */
  	void inorder(){						      /* implement it like this  */
  		dnode *it = leftmost(droot);
  		while(1)
  		{
		std::cout << it->data;				      /* print it! we are in the */
  		if ( it->right_theard)				      /* leftmose, then go to    */
  		it = it->right; 				      /* right_theard which will */
  		 else it = leftmost(it->right);			      /* be its root, then go    */
  		if (it ==droot) break; 				      /* right to get the right  */
  		}						      /* node. If we rached the  */	
  	}							      /* root again, then we're  */
  								      /* done. 			 */
  };
     /*
  * ---
  * 5.2
  *  Implement a city database using a BST to store the database
  *  records. Each database record contains the name of the city (a
  *  string of arbitrary length) and the coordinates of the city
  *  expressed as integer x- and y-coordinates. The BST should be
  *  organized by city name. Your database should allow records to be
  *  inserted, deleted by name or coordinate, and searched by name or
  *  coordinate. Another operation that should be supported is to
  *  print all records within a given distance of a specified point.
  *  Collect running-time statistics for each operation. Which
  *  operations can be implemented reason- ably efficiently (i.e., in
  *  Θ(log n) time in the average case) using a BST? Can the database
  *  system be made more efficient by using one or more additional
  *  BSTs to organize the records by location?
  *  */
class db {
private: 
	struct node
	{
	node*left;
	node *right;
	int x,y;
	string name;	
	node(int i, int j, string s)
	{
		x = i;
		y = j;
		name = s;
		left = null;
		right = null;

	}
	};
	node*root;
	void inserthelp(int x, int y,string name, node*root) {

		int check = root->name.compare(name);	
		if (check>0) 
		{
			if (root->left == null) root->left = new node(x,y,name);
			else inserthelp(x,y,name,root->left);
		} else 
		{
			if (root->right ==null) root->right = new node (x,y , name); 
			else inserthelp(x,y,name,root->right);	
		}
		
		
		
	}
	void printh(node*root) {
	if (root==null) return;
	cout << "\tCity name: " << root-> name << "\n\tcoordinates: " << root->x << ", " << root-> y << "\n";
	printh(root->right);
	printh(root->left);
	}
	bool searchh (string name, node*root){
	if(root==null) return 0;
	int check = root->name.compare(name);	
	if (check>0) 
	{
	return	searchh(name,root->left);

	} else if (check < 0) 
	{

	return	searchh(name,root->right);
	} else return 1;
	
	}
	void searchh(int x, int y, node*root,int &c) {
	if (root==null) return;
	if (root->x == x && root->y == y)
	{
		c=1;
		return;
	}
	 searchh(x,y,root->left,c);
	searchh(x,y,root->right,c);
	}
	void printer(int x, int y, int d , node*root){
		if (root==null) return;
		if (  ( root->x <= x + d  && root->x >= x-d )  && ( root->y <= y + d  && root->y >= y-d )      ) {
	cout << "\tCity name: " << root-> name << "\n\tcoordinates: " << root->x << ", " << root-> y << "\n";
		} printer (x,y,d,root->left);
		  printer (x,y,d,root->right);
	}

public: 
	db() {
	 root = null;

	}
	void insert (int x, int y, string name){
		if (root==null) root = new node(x,y,name);
		else inserthelp(x,y,name,root);
	}
	void print() {
	printh(root);
	}
	bool search(string k) {
	return searchh(k, root);
	}
	bool search(int x, int y) {
		int c=0;
		searchh(x,y,root,c);
		return c;
	}
	void print_d (int x, int y, int d){
	
		printer(x,y,d,root);
	}
};

  /*
  *  Yes, it can be implemented more efficient if we used another BST
  *  to handle the coordinates only and organize it by numbers, so
  *  whenever we need to look for a coordinate we don't have to
  *  travers the whole tree but would be in average time complexty 
  *  about O(log n), like any regular BST. Instead of passing the same
  *  values twice, it should handle the data within its pointers.
  * ---
  * 5.4
  *  Create a binary tree ADT that includes generic traversal methods
  *  that take a visitor, as described in Section 5.2. Write functions
  *  count and BSTcheck of Section 5.2 as visitors to be used with the
  *  generic traversal method.
  *  TODO.
  * 5.5
  *  Implement a priority queue class based on the max-heap class 
  *  implementation of Figure 5.19. The following methods should be 
  *  supported for manip- ulating the priority queue: 
  *     void enqueue(int ObjectID, int priority);
  *     int dequeue();
  *     void changeweight(int ObjectID, int newPriority);
  *  Method enqueue inserts a new object into the priority queue
  *  with ID num- ber ObjectID and priority priority. Method dequeue
  *  removes the object with highest priority from the priority queue and
  *  returns its object ID.  Method changeweight changes the priority of the
  *  object with ID number ObjectID to be newPriority. The type for E
  *  should be a class that stores the object ID and the priority for that
  *  object. You will need a mech- anism for finding the position of the
  *  desired object within the heap. Use an array, storing the object with
  *  ObjectID i in position i. (Be sure in your testing to keep the ObjectIDs
  *  within the array bounds.) You must also modify the heap implementation
  *  to store the object’s position in the auxil- iary array so that
  *  updates to objects in the heap can be updated as well in the array.    
  */
template<class t> 
class pq
  {
  	struct h {
  		t data;
  		t priority;
  	};
  	h *harr; 
  	int capacity;
  	int heap_size;
  	      
  public:
  void swap(h &x, h &y) {
  	t tmp1 = x.data, tmp2 = x.priority;
  	x.data = y.data; x.priority =y.priority;
  	y.data = tmp1; y.priority = tmp2;
  
  }
  pq(int cap)
  {
  	heap_size = 0;
  	capacity = cap;
  	harr = new h[cap];
  }
    	int parent(int i) { return (i-1)/2; }
    	int left(int i) { return (2*i + 1); }
    	int right(int i) { return (2*i + 2); }
    	int getMin() { return harr[0].data; };
  void MaxHeapify(int i)
    {
    	int l = left(i);
    	int r = right(i);
    	int smallest = i;
    	if (l < heap_size && harr[l].priority > harr[i].priority)
    		smallest = l;
    	if (r < heap_size && harr[r].priority > harr[smallest].priority)
    		smallest = r;
    	if (smallest != i)
      	{
      		swap(harr[i], harr[smallest]);
      		MaxHeapify(smallest);
    	}
    }
    void enqueue(t k, t p)
    {
    	if (heap_size == capacity)
    	{
    		return;
    	}
    
    	heap_size++;
    	int i = heap_size - 1;
    	harr[i].data = k;
    	harr[i].priority = p;
    	while (i != 0 && harr[parent(i)].priority < harr[i].priority)
    	{
    	swap(harr[i], harr[parent(i)]);
    	i = parent(i);
    	}
    }
    void changeweight(int i, int new_val)
    {
    	harr[i].data = new_val;
    	while (i != 0 && harr[parent(i)].priority > harr[i].priority)
    	{
    	swap(harr[i], harr[parent(i)]);
    	i = parent(i);
    	}
    }
  
    int extractMin()
    {
    	if (heap_size <= 0)
    		return INT_MAX;
    	if (heap_size == 1)
    	{
    		heap_size--;
    		return harr[0].data;
    	}
    
    	// Store the minimum value, and remove it from heap
    	int root = harr[0].data;
    	harr[0] = harr[heap_size-1];
    	heap_size--;
    	MaxHeapify(0);
    
    	return root;
    }
    
    void dequeue()
    {
    	changeweight(0, INT_MIN);
    	extractMin();
    } 
    t front () {
  	  return harr[0].data;
    }
    t back () {
  	  return harr[heap_size-1].data;
    }
    
  };
/*int main() {
  	pq <int>l(4) ;
  	l.enqueue(3,5);
  	l.enqueue(2,9);
  	l.enqueue(1,2);
  	cout << l.front();
}*/

/*
 * 5.6
 *  The Huffman coding tree function buildHuff of Figure 5.29
 *  manipulates a sorted list. This could result in a Θ(n2 )
 *  algorithm, because placing an inter- mediate Huffman tree on the
 *  list could take Θ(n) time. Revise this algorithm to use a priority
 *  queue based on a min-heap instead of a list.
 *
 * 5.7 
 * ---
 *  Complete the implementation of the Huffman coding tree, building
 *  on the code presented in Section 5.6. Include a function to
 *  compute and store in a table the codes for each letter, and
 *  functions to encode and decode messages. This project can be
 *  further extended to support file compression. To do so requires
 *  adding two steps: (1) Read through the input file to generate
 *  actual frequencies for all letters in the file; and (2) store a
 *  representation for the Huffman tree at the beginning of the
 *  encoded output file to be used by the decoding function. If you
 *  have trouble with devising such a representation, see Section 5.7. 
 *  
 *  BIG TODO
 *
 *
 */



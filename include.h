#define INF (10e9)
#define null nullptr
#include <iostream> 
#include <cmath>
#include <climits>
#include <numeric>
#include <array>
#include <map>
#include <queue>
#include <set>
#include <vector>
#include <stack>
#include <deque>
#include <algorithm>
#include <string>
#include <unordered_set>
#include <unordered_map>
#define begend(v)				((v).begin()), ((v).end())
using namespace std;
#define sz(v)				((int)((v).size()))
struct node {
   int data;
   struct node *left;
   struct node *right;
};
struct node *createNode(int val) {
   struct node *temp = (struct node *)malloc(sizeof(struct node));
   temp->data = val;
   temp->left = temp->right = NULL;
   return temp;
}
struct node* insertNode(struct node* node, int val) {
   if (node == NULL) return createNode(val);
   if (val < node->data)
   node->left = insertNode(node->left, val);
   else if (val > node->data)
   node->right = insertNode(node->right, val);
   return node;
}
void visit(struct node* root)
{
	std::cout << root->data;
}
void visit2(struct node* root)
{
	if (root->data % 5 ==0 )
	std::cout << root->data;
}



/*
▄▀█ █░█ ▀█▀ █░█ █▀█ █▀█ ░░▄▀ █▀ ▄▀█ █░░ █▀▀ █░█ █▀▄▀█ █░█ █░█ ▄▀█ █▀▄▀█ █▀▀ █▀▄
█▀█ █▄█ ░█░ █▀█ █▄█ █▀▄ ▄▀░░ ▄█ █▀█ █▄▄ ██▄ █▀█ █░▀░█ █▄█ █▀█ █▀█ █░▀░█ ██▄ █▄▀
*/

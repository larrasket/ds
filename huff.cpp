#include "priority_queue.h"
#include <iostream>
#include <memory>
#include <unordered_map>
class huffman {
private: 
	struct node
	{
		node*left;
		node*right;
		int value;
		node(int v) {
		value =v;
		left = null;
		right =null;	
/*		return node;*/
		}
	};
	bool isleaf(node*n) { return (n->left == null && n ->right == null);  }
	void print(node*root,string x) {
		if (root==null) return;
		cout << root->value << endl;
		print(root->left, x+"0");
		print(root->right, x+"1");
	}

public: 
	huffman(unordered_map<int ,char>x) {
		pq<node*, int>heap(x.size());
		for (auto &k :  x) {
			heap.enqueue(new node(k.first), k.second);
		}
/*		int ii1=heap.size();
  		for (int i = 0; i < ii1; ++i) {
  			cout << heap.back()->value << endl;;
  			heap.rdequeue();
		}*/
		node*top,*left,*right;
		node*ttop;
	while(heap.size()>1) {
/*		left = new node(heap.dequeue());
  		right = new node(heap.dequeue());
  		top = new node (left -> value + right-> value );
  		top -> left = left;
  		top -> right = right;
		heap.enqueue(top, top->value);*/
/*		left = new node(0);*/
		left = heap.dequeue();
		right = heap.dequeue();
		cout << "LEFT IS " << left->value << endl;
		cout << "RIGHT IS " << right->value << endl;
		top = new node (right->value + left->value);
		top->left = left;
		top->right = right;
		cout << "TOP IS " << top->value << endl;
		heap.enqueue(top, top->value);
	}
	cout << "?";
	} 
};

int main() {
   unordered_map<int,char>h;	
   h[5 ]='a';
   h[9 ]='b'; 
   h[12]='c'; 
   h[13]='d'; 
   h[16]='e'; 
   h[45]='f'; 
   huffman x(h);

/*	pq <int,int>l(6) ;
  	l.enqueue(6,45);
  	l.enqueue(4,13);
  	l.enqueue(1,5);
  	l.enqueue(2,9);
  	l.enqueue(3,12);
  	l.enqueue(5,16);
  	cout << l.back() << endl;;
  	l.dequeue();
  	cout << l.back() << endl;;
  	l.dequeue();
  	l.enqueue(7,14);
  	cout << l.back() << endl;;
  	l.dequeue();
  	cout << l.back() << endl;;
  	l.dequeue();
	cout << l.back() << endl;;*/
  
}

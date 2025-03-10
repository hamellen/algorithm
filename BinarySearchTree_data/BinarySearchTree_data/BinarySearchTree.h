#pragma once

struct Node {

	Node* _parent = nullptr;
	Node* _left = nullptr;
	Node* _right = nullptr;
	int data;
};


class BinarySearchTree
{
public:

	Node* root = nullptr;
public:



	
	void pre_order(Node* node);
	void in_order(Node* node);
	void post_order(Node* node);
	void insert(int key);
	void Delete(int key);
	void Delete(Node* node);
	void Replace(Node* u, Node* v);
	Node* get_root();

	Node* Search(Node* node, int key);//���
	Node* Search2(Node* node, int key);//while

	Node* Min(Node* _node);
	Node* Max(Node* _node);
	Node* Next(Node* _node);
};


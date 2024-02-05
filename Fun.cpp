#include <iostream>
using namespace std;
class node_for_extends {
public:
	struct node {
		string data;
		int val = 0;
		node* left = nullptr;
		node* right = nullptr;
		node* next = nullptr;
		node* pre = nullptr;
	};
};
class stack_aslinked_list : public node_for_extends {
public:
	node* top;
	stack_aslinked_list() {
		top = NULL;
	}
	void push(string val) {
		node* nd = new node();
		nd->data = val;
		nd->next = top;
		top = nd;
	}
	int push_int(int val) {
		node* nd = new node();
		nd->data = val;
		nd->next = top;
		top = nd;
		return  val;
	}
	void pop() {
		node* ndfd = new node();
		if (top == NULL)
			cout << "stack is underflow.";
		else {
			cout << "poped element is:" << top->data << endl;
			ndfd = top;
			top = top->next;
			delete ndfd;
		}
	}
	void dis() {
		node* nd = new node;
		nd = top;
		while (nd != NULL) {
			cout << nd->data << endl;
			nd = nd->next;
		}
	}
};
class array_asqueue {
public:
	int queue[20] = { 0 }, front, rear;
	array_asqueue() {
		front = rear = -1;
	}
	void inq(int val) {
		
			if (front == -1)
				front = rear = 0;
			queue[rear] = val;
			rear++;
		
	}
	void dis() {
		for (int i = 0; i < 20; i++)
		{
			cout << queue[i] << endl;
		}
	}
};
class tree : public node_for_extends {
public:
	node* curr = new node();
	tree() {
		curr = NULL;
	}
	void tree1(int val) {
		int v;
		node* temp = new node();
		temp->val = val;

		if (curr == NULL) {
			curr = new node();
			curr->val = temp->val;
			curr->left = NULL;
			curr->right = NULL;
		}
		else {
			v = addnode(curr, temp);
			if (v == 1)
				cout << "to left";
			else if (v == 2)
				cout << "to right";
			else if (v == 3)
				cout << "same";
		}
	}
	int addnode(node* fcurr, node* fnew) {
		if (fcurr->val == fnew->val)
		{
			return 3;
		}
		else {
			if (fcurr->val > fnew->val)
			{
				if (fcurr->left != NULL)
					addnode(fcurr->left, fnew);
				else {
					fcurr->left = fnew;
					(fcurr->left)->left = NULL;
					(fcurr->right)->right = NULL;
					return 1;

				}
			}
			else {
				if (fcurr->right != NULL)
					addnode(fcurr->right, fnew);
				else {
					fcurr->right = fnew;
					(fcurr->right)->left = NULL;
					(fcurr->right)->right = NULL;
					return 2;
				}
			}
		}
	}
	int postorder(node* fprcurr) {
		if (fprcurr == NULL)
			return 0;
		else {

			if (fprcurr->left != NULL)
				postorder(fprcurr->left);
			if (fprcurr->right != NULL)
				postorder(fprcurr->right);
			cout << fprcurr->val << "  \n";
		}
	}
};

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
class The_System {
public:
	stack_aslinked_list stack1;
	The_System() {
		cout << "=================================WELLCOME TO THE SCHOOL SYSTEM!======================================\n\n";
		cout << "\t\t\tTo enter a new student to the system, Please! enter->[1]\n";
		cout << "\t\t\tTo show where is your exam!,          Please! enter->[2]\n";
		cout << "\t\t\tTo show outstanding student,          Please! enter->[3]\n";
		cout << "\t\t\tTo exit,                              Please! enter->[4]\n";

	}
	void Name() {
		cout << "Please! enter the student's name\n";
		string name;
		cin >> name;
		stack1.push(name);
	}
	void Age() {
		cout << "Please! enter the student's age\n";
		string age;
		cin >> age;
		stack1.push(age);
	}
	void Gander() {
		cout << "Please! enter the student's Gander\n";
		string gander;
		cin >> gander;
		stack1.push(gander);
	}
	int set_id() {
		cout << "Please! enter the student's id from 1->20\n";
		int id;
		cin >> id;
		return id;
		stack1.push_int(id);
	}
	void exams() {
		cout << "Enter The ID\n";
		int id;
		cin >> id;
			array_asqueue queue1;
		for (int j = 0; j <= 20; j++)
		{
			queue1.inq(j);
		}

		for (int i = 0; i <= 20; i++) {
			if (id == queue1.queue[i]) {
				if (id == 1 || id < 1 * 7)
					cout << "    " << " in 1st examinations committee \n";
				else if (id == 1 * 7 || id < 2 * 7)
					cout << "    " << " in 2nd examinations committee \n";
				else if (id == 2 * 7 || id < 3 * 7)
					cout << "    " << " in 3rd examinations committee \n";
				else
					cout << "      " << "Wrong ID";
			}
				
		}
	}
	void Outstanding_Students() {
		tree tree1;
		int val3, val2, val1;
		cout << "Enter the 3st heighst student.\n";
		cin >> val1;
		tree1.tree1(val1);
		cout << "Enter the 2st heighst student.\n";
		cin >> val2;
		tree1.tree1(val2);
		cout << "Enter the 1st heighst student.\n";
		cin >> val3;
		tree1.tree1(val3);
		cout << "The ranking the students:\n";
		tree1.postorder(tree1.curr);
	}
};
int main()
{

	
	do
	{
		The_System s;
		char ch;
		cin >> ch;
		if (ch == '1') {
			s.Name();
			s.Age();
			s.Gander();
			s.set_id();
			cout << "Your information have been registred in the school system\n";
		}
		else if (ch == '2')
			s.exams();
		else if (ch == '3')
			s.Outstanding_Students();
		else if (ch == '4')
			break;
		

	} while (true);
}

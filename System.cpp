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

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

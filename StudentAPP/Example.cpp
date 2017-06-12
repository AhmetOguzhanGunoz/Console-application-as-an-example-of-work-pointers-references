#include <iostream>
#include <string>

using namespace std;

const int STUDENTLEVEL = 3; //0:University , 1:Master, 2:Doctorate

class Student
{
	static int id[STUDENTLEVEL];
	int studentid;
	char *name;
	int level;

public:
	Student(char* _name, int _level = 0);
	~Student()
	{
		cout << "Student destructor" << endl;
		delete[] name;
	}
	virtual void display() const;
};

int Student::id[] = { 0,0,0 };

Student::Student(char* _name, int _level)
{
	cout << "Student constructor" << endl;
	if (_level <0 || _level>2)
	{
		cout << "Object cannot be initialized. Student level is undetermined" << endl;
		this->~Student();
		return;
	}

	level = _level;
	studentid = ++id[level];
	name = new char[strlen(_name) + 1];
	strcpy(name, _name);

}

void Student::display() const
{
	cout << "Student Display" << endl;
	cout << "Student ID: " << studentid << endl;
	cout << "Name: " << name << endl;
	cout << "Level: ";

	switch (level)
	{
	case 0: cout << "University " << endl; break;
	case 1: cout << "Master " << endl; break;
	case 2: cout << "Doctorate " << endl; break;
	}

}

class Assistant :public Student
{
	double salary;

public:
	Assistant(char* _name, int _level, double _salary) :Student(_name, _level)
	{
		cout << "Assistant Constructor" << endl;
		salary = _salary;
	}

	void dislay() const
	{
		Student::display();
		cout << "Salary: " << salary << endl;
	}
};

int main()
{
	Student *s1;
	Student *s2;
	Student *s3;

	Assistant a1("John Brown", 1, 3000);
	Assistant a2("Sam Smith", 1, 5000);
	Student st1("Pam Allen");

	s1 = &a1;
	s2 = &a2;
	s3 = &st1;

	s1->display();
	s2->display();
	s3->display();

	s1->~Student();
	s2->~Student();
	s3->~Student();
	
	system("pause");
	return 0;
}

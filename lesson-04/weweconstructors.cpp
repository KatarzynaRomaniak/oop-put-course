
#include <iostream>

using namespace std;

class Employee {
public:
	Employee(int);
	Employee(string);
private:
	string name;
	int id;
};

Employee::Employee(int n){
id = n;
cout << id;
}

Employee::Employee(string name) {
this->name = name;
cout << name;
}


int main()
{
	Employee person1("Wlodzimierz\n");
	Employee person2("Jesse\n");
	Employee person3(3269);
}


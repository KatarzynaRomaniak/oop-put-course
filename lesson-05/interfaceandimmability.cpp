
#include <iostream>
using namespace std;

class Shape {
public:
	virtual void WhichShape() = 0;
};

class Square:public Shape {
	string shape = "square";

public:
	virtual void WhichShape(){
		cout << "The shape is " <<shape<< endl;
	}
};


int main()
{
    Square k;
	k.WhichShape();
}



#include <iostream>
#include <vector>

using namespace std;

class Insect {
public:
	string name;

	Insect(string name){ this->name = name; }
};

class Flower {
private:
	string species;
	string color;
	vector<Insect> insects;
public:
	void Infestation(Insect i) {
		insects.push_back(i);
	}
	void PrintInfestation() {
		for (auto i : insects) {
			cout << i.name << endl;
		}
	}
};

int main()
{
	Insect i("LeptontarsaDecemlineata");
	Flower f;
	f.Infestation(i);
	f.PrintInfestation();
}

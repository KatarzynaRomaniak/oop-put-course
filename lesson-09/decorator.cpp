#include <iostream>
#include <vector>
#include <algorithm>



class IntegerSequence {
public:
	virtual std::vector<int>
		Numbers() const = 0;
};



class VectorSequence:
public IntegerSequence 
{
private:
	std::vector<int> sequence;

public:
	VectorSequence(std::vector<int> sq) : sequence(sq) {}

	std::vector<int> Numbers() const override 
	{
		return sequence;
	}
};




class SortedSequence: 
public IntegerSequence {
private:
	IntegerSequence* sequence;

public:
	SortedSequence(IntegerSequence* sq) : sequence(sq) {}

	std::vector<int> Numbers() const override 
	{
		std::vector<int> numbers = sequence->Numbers();
		std::sort( numbers.begin(), numbers.end() );
		
		return numbers;
	}
};





class PositiveSequence:
public IntegerSequence 
{
private:
	IntegerSequence* sequence;

public:
	PositiveSequence(IntegerSequence* sq) : sequence(sq) {}

	std::vector<int> Numbers() const override {
		std::vector<int> numbers = sequence->Numbers();
		numbers.erase(
			std::remove_if( numbers.begin(), numbers.end(), [](int num) { return num < 0; }),
			numbers.end()
		);
		return numbers;
	}
};




class EvenSequence:
public IntegerSequence 
{
private:
	IntegerSequence* sequence;

public:
	EvenSequence(IntegerSequence* sq) : sequence(sq) {}

	std::vector<int> Numbers() const override {
		std::vector<int> numbers = sequence->Numbers();
		numbers.erase
		(
			std::remove_if(numbers.begin(), numbers.end(), [](int num) { return num % 2 != 0; }),
			numbers.end()
		);
		
		return numbers;
	}
};




int main() {
	std::vector<int> originalSequence = { 1, -18, 56, 0, 8, 1, -1, 2, 12, -4, 2137, 11, -154};

	IntegerSequence* sequence = new SortedSequence
	(
		new EvenSequence
		(
			new PositiveSequence
			(
				new VectorSequence(originalSequence)
			)
		)
	);

	std::vector<int> pdNumbers = sequence->Numbers();

	std::cout << "New sequence: ";

	for (int num : pdNumbers) 
	{
		std::cout << num << "  ";
	}

	return 0;
}

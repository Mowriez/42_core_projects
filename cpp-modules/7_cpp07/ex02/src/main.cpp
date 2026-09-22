#include <iostream>
#include <Array.hpp>
#include <stdlib.h>

#define MAX_VAL 30

class Dog {
private:
		float	_amountOfEyes;
	public:
		Dog() {
			std::srand(std::clock());
			_amountOfEyes = static_cast<float>(std::rand()) / static_cast<float>(std::clock()) / 1200;
		}
		float	getEyeNumber() {
			return _amountOfEyes;
		};
};

int main(int, char**)
{
	std::cout << std::endl;
	srand(time(NULL)); //bad random number generator
	int* numbersList= new int[MAX_VAL];
	std::cout << "---General template class handling---" << std::endl;
	std::cout << "        <<<Basic types>>>" << std::endl;
	std::cout << "Constructor with int type" << std::endl;
	Array<int>			IntArray(MAX_VAL);
	std::cout << std::endl;
	std::cout << "Constructor with string type" << std::endl;
	Array<std::string>	StringArray(4);
	std::cout << std::endl;

	std::cout << "Fill the array in IntArray with random values" << std::endl;
	for (int i = 0; i < MAX_VAL; i++) {
		const int value = rand();
		IntArray[i] = value;
		numbersList[i] = value;
	}
	std::cout << "check if they are accessible and of the right type" << std::endl;
	for (int i = 0; i < MAX_VAL; i++) {
		std::cout << "Array[" << i << "]: " << IntArray[i] << std::endl;
		if (numbersList[i] != IntArray[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			return 1;
		}
	}
	std::cout << "Check access outside of valid range" << std::endl;
	try
	{
		std::cout << "Negative num: ";
		IntArray[-2] = 0;
	}
	catch(const std::exception& e) {
		std::cerr << "Error: " << e.what() << '\n';
	}
	try
	{
		std::cout << "Bigger than array size: ";
		IntArray[MAX_VAL + 1] = 0;
	}
	catch(std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}
	std::cout << "<<<Check writing access>>>" << std::endl;
	for (int i = 0; i < MAX_VAL; i++)
	{
		numbersList[i] = rand();
	}
	delete [] numbersList;
	std::cout << std::endl;
	std::cout << "        <<<Check the copy constructor/assignment overload>>>"
			  << std::endl;
	{
		Array<int> tmp;
		tmp = IntArray;
		Array<int> test(tmp);
	}
	std::cout << std::endl;
	std::cout << "        <<<Check for deep copy >>>" << std::endl;
	{
		Array<int>* tmp = new Array<int>(1);
		(*tmp)[0] = 5;
		Array<int> test(*tmp);
		delete tmp;
		std::cout << "test[0]: " << test[0] << std::endl;
	}
	std::cout << std::endl;

	std::cout << "     <<<Complex type (class Dog)>>>" << std::endl;
	Array<Dog>			Kennel(5);
	for (unsigned int i = 0; i < 5; i++) {
		std::cout << "Dog #" << i << " has " << Kennel[i].getEyeNumber() << " eyes!"
				<< std::endl;
 	}
	return 0;
}

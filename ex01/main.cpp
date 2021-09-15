#include "span.hpp"
#include <vector>

int main(void)
{
	Span array(10000);
	try
	{
		std::cout << "-----------Try empty array-----------" << std::endl;
		array.shortestSpan();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << "----------Try with one elem------------" << std::endl;
		array.addNumber(5);
		array.longestSpan();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << "----------Add 5000 elems------------" << std::endl;
		array.addNumber(3);
		array.addNumber(17);
		array.addNumber(9);
		array.addNumber(11);
		std::cout << "Size of my array: " << array.getSize() << std::endl;
		std::cout << "Shortest span: " << array.shortestSpan() << std::endl;
		std::cout << "Longest span: " << array.longestSpan() << std::endl;
		std::vector<int> array2;
		for (int i = 0; i < 5000; i++)
		{
			array2.push_back((i + 5) / 3);
		}
		array.addNumber(array2.begin(), array2.end());
		std::cout << "Check after addin vector" << std::endl;
		std::cout << "Size of my array: " << array.getSize() << std::endl;
		std::cout << "Shortest span: " << array.shortestSpan() << std::endl;
		std::cout << "Longest span: " << array.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << "---------Try to add 5000 elems-------------" << std::endl;
		std::vector<int> array2;
		for (int i = 0; i < 5000; i++)
		{
			array2.push_back((i + 5) / 3);
		}
		array.addNumber(array2.begin(), array2.end());
		std::cout << "Check after addin vector" << std::endl;
		std::cout << "Size of my array: " << array.getSize() << std::endl;
		std::cout << "Shortest span: " << array.shortestSpan() << std::endl;
		std::cout << "Longest span: " << array.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}
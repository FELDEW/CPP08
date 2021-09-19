#include "easyfind.hpp"
#include <vector>
#include <set>



int main(void)
{
	{
		std::cout << "Vector: " << std::endl;
		std::vector<int> array;
		array.push_back(10);
		array.push_back(8);
		array.push_back(7);
		array.push_back(6);
		array.push_back(4);
		array.push_back(2);
		array.push_back(1);
		int to_find;
		for (int i = 0; i < 4; i++)
		{
			to_find = i * 3;
			try
			{
				std::cout << "Search: " << to_find << '\n';
				easyfind(array, to_find);
				std::cout << "Sucsess!" << '\n' << "-----------------" << '\n';
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << '\n';
				std::cout << "Failure!" << '\n' << "-----------------" << '\n';
			}
		}
		std::cout << "set: " << std::endl;
		std::set<int> array2;
		array2.insert(10);
		array2.insert(8);
		array2.insert(8);
		array2.insert(7);
		array2.insert(6);
		array2.insert(4);
		array2.insert(2);
		array2.insert(1);
		int to_find2;
		std::cout << array2.size() << std:: endl;
		for (int i = 0; i < 4; i++)
		{
			to_find2 = i * 2;
			try
			{
				std::cout << "Search: " << to_find2 << '\n';
				easyfind(array2, to_find2);
				std::cout << "Sucsess!" << '\n' << "-----------------" << '\n';
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << '\n';
				std::cout << "Failure!" << '\n' << "-----------------" << '\n';
			}
		}
	}
	return (0);
}
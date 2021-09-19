#include "mutantstack.hpp"
#include <vector>


class Awesome 
{
	public:
		Awesome ():_n(0) {}
		Awesome(int n): _n(n) {}
		Awesome(Awesome const &rhs): _n(rhs._n) {}
		bool operator==(Awesome const & rhs) const { return (this->_n == rhs._n); }
		bool operator!=(Awesome const & rhs) const { return (this->_n != rhs._n); }
		bool operator>(Awesome const & rhs) const { return (this->_n > rhs._n); }
		bool operator<(Awesome const & rhs) const { return (this->_n < rhs._n); }
		bool operator>=(Awesome const & rhs) const { return (this->_n >= rhs._n); }
		bool operator<=(Awesome const & rhs) const { return (this->_n <= rhs._n); }
		Awesome &operator=(Awesome const & rhs) { this->_n = rhs._n; return (*this); }
		int getN() const { return (this->_n);}
	private:
		int _n;
};

std::ostream& operator<<(std::ostream &out, const Awesome& origin)
{
	out << origin.getN();
	return (out);
}


int main()
{
	std::cout << "------Int--------" << std::endl;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "Size of stack: " << mstack.size() << std::endl;
	mstack.push(3);
	std::cout << "Top: " << mstack.top() << std::endl;
	mstack.push(5);
	mstack.push(737);
	std::cout << "Top: " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "Top: " << mstack.top() << std::endl;
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << " | ";
		++it;
	}
	std::cout << std::endl;
	std::cout << "------Const int--------" << std::endl;
	const MutantStack<int> s(mstack);
	MutantStack<int>::const_iterator its = s.begin();
	MutantStack<int>::const_iterator itse = s.end();
	while (its != itse)
	{
		std::cout << *its << " | ";
		++its;
	}
	std::cout << std::endl;
	std::cout << "---------------------------" << std::endl;
	std::cout << "------Awesome class--------" << std::endl;
	std::cout << "---------------------------" << std::endl;
	MutantStack<Awesome> mstack1;
	std::cout << "Add: " << 2 << std::endl;
	mstack1.push(Awesome(2));
	std::cout << "Add: " << 4 << std::endl;
	mstack1.push(Awesome(4));
	std::cout << "Top: " << mstack1.top() << std::endl;
	std::cout << "Size of stack: " << mstack1.size() << std::endl;
	std::cout << "Delete top element" << std::endl;
	mstack1.pop();
	std::cout << "Size of stack: " << mstack1.size() << std::endl;
	std::cout << "Top: " << mstack1.top() << std::endl;
	std::cout << "Add: " << 20 << std::endl;
	mstack1.push(Awesome(20));
	std::cout << "Add: " << 0 << std::endl;
	mstack1.push(Awesome());
	std::cout << "Top: " << mstack1.top() << std::endl;
	std::cout << "Delete top element" << std::endl;
	mstack1.pop();
	std::cout << "Top: " << mstack1.top() << std::endl;
	MutantStack<Awesome>::iterator itawe = mstack1.begin();
	MutantStack<Awesome>::iterator iteawe = mstack1.end();
	++itawe;
	--itawe;
	while (itawe != iteawe)
	{
		std::cout << *itawe << " | ";
		++itawe;
	}
	std::cout << std::endl;
	std::cout << "------Const awesome--------" << std::endl;
	const MutantStack<Awesome> s1(mstack1);
	MutantStack<Awesome>::const_iterator itsawe = s1.begin();
	MutantStack<Awesome>::const_iterator itseawe = s1.end();
	while (itsawe != itseawe)
	{
		std::cout << *itsawe << " | ";
		++itsawe;
	}
	std::cout << std::endl;
	return (0);
}
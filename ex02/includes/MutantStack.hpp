#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

# define BRIGHT_RED "\033[1;31m"
# define BRIGHT_BLUE "\033[1;34m"
# define ORANGE "\033[38;5;208m"
# define BRIGHT_GREEN "\033[1;32m"
# define RESET "\033[0m"
# define LINE 30

#include <iostream>
// #include <deque>
#include <stack>
#include <map>

template<typename T>
class MutantStack: public std::stack<T>
{
	public:
		MutantStack(void): std::stack<T>()
		{
			std::cout << BRIGHT_GREEN "MutantStack: constructor called\n" RESET;
		}
		MutantStack(const MutantStack<T> &other): std::stack<T>(other)
		{
			(void)other;
			std::cout << BRIGHT_GREEN "MutantStack: copy constructor called\n" RESET;
		}
		MutantStack<T>	&operator=(const MutantStack<T> &other)
		{
			std::cout << BRIGHT_GREEN "MutantStack: assignment operator\n" RESET;
			if (this != &other)
				std::stack<T>::operator=(other);
			return (*this);
		}
		~MutantStack(void)
		{
			std::cout << BRIGHT_RED "MutantStack: destructor called\n" RESET;
		}

		//Iterator setup
		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator	begin(void)
		{
			return (this->c.begin());
		}
		iterator	end(void)
		{
			return (this->c.end());
		}
};

template<typename T>
std::ostream	&operator<<(std::ostream &out, const MutantStack<T> &other)
{
	(void)other;
	out << "MutantStack";
	return (out);
}

#endif
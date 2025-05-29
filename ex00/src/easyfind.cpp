#include "easyfind.hpp"

easyfind::easyfind()
{
	std::cout << BRIGHT_GREEN "easyfind: constructor called\n" RESET;
}
easyfind::easyfind(const easyfind &other)
{
	std::cout << BRIGHT_GREEN "easyfind: copy constructor called\n" RESET;
	*this = other;
}
easyfind&	easyfind::operator=(const easyfind &other)
{
	std::cout << BRIGHT_GREEN "easyfind: assignment operator\n" RESET;
	if (this != &other)
		/*	copy	*/
	return (*this);
}
easyfind::~easyfind()
{
	std::cout << BRIGHT_RED "easyfind: destructor called\n" RESET;
}

std::ostream	&operator<<(std::ostream &out, const easyfind &other)
{
	(void)other;
	out << "temp";
	return (out);
}

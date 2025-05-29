#include "Span.hpp"

Span::Span(void): n(1)
{
	this->storage.resize(this->n);
	std::cout << BRIGHT_GREEN "Span: default constructor called\n" RESET;
}
Span::Span(const unsigned int &n): n(n)
{
	this->storage.resize(this->n);
	std::cout << BRIGHT_GREEN "Span: constructor called\n" RESET;
}
Span::Span(const Span &other)
{
	std::cout << BRIGHT_GREEN "Span: copy constructor called\n" RESET;
	*this = other;
}
Span&	Span::operator=(const Span &other)
{
	std::cout << BRIGHT_GREEN "Span: assignment operator\n" RESET;
	if (this != &other)
	{
		this->n = other.size();
		this->storage.resize(n);
		for (unsigned int i = 0; i < n; i++)
			storage[i] = other.getStorage()[i];
	}
	return (*this);
}
Span::~Span(void)
{
	std::cout << BRIGHT_RED "Span: destructor called\n" RESET;
}

std::ostream	&operator<<(std::ostream &out, const Span &other)
{
	(void)other;
	out << "(Span) size: " << other.size() << "; Storage[0]: " << other.getStorage()[0];
	return (out);
}

unsigned int			Span::size(void) const
{
	return (n);
}
const std::vector<int>&	Span::getStorage(void) const
{
	return(storage);
}

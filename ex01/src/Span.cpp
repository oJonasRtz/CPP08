#include "Span.hpp"

static void	timeToThrow(const std::string &message)
{
	throw (std::runtime_error(BRIGHT_RED + message + RESET));
}

Span::Span(void): n(1)
{
	numInStorage = 0;
	std::cout << BRIGHT_GREEN "Span: default constructor called\n" RESET;
}
Span::Span(const unsigned int &n): n(n)
{
	numInStorage = 0;
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
		this->storage = other.getStorage();
		this->numInStorage = other.getNumsStorage();
	}
	return (*this);
}

Span&	Span::operator=(const int &n)
{
	this->addNumber(n);
	return (*this);
}
Span::~Span(void)
{
	std::cout << BRIGHT_RED "Span: destructor called\n" RESET;
}

std::ostream	&operator<<(std::ostream &out, const Span &other)
{
	(void)other;
	out << "(Span) size: " << other.size() <<
		"; Stored numbers: " << other.getNumsStorage();
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
int						Span::getNumsStorage(void) const
{
	return (numInStorage);
}

void	Span::addNumber(const int &value)
{
	if (numInStorage == n)
		timeToThrow("Span: cannot add number - storage is full.");
	storage.push_back(value);
	numInStorage++;
}
int		Span::shortestSpan(void) const
{
	if (numInStorage == 0 || numInStorage == 1)
		timeToThrow("Span: cannot search - storage has no data enough");

	int	s = storage[0];
	for (unsigned int i = 1; i < n; i++)
		if (storage[i] < s)
			s = storage[i];
	
	return (s);
}
int		Span::longestSpan(void) const
{
	if (numInStorage == 0 || numInStorage == 1)
		timeToThrow("Span: cannot search - storage has no data enough");

	int	s = storage[0];
	for (unsigned int i = 1; i < n; i++)
		if (storage[i] < s)
			s = storage[i];
	return (s);
}

void					Span::showContent(void) const
{
	if (numInStorage == 0)
	{
		std::cout << "Span: no values to show\n";
		return;
	}
	
	for (unsigned int i = 0; i < n; i++)
		std::cout << "Span[" << i << "]: " ORANGE << storage[i] << RESET << std::endl;
}
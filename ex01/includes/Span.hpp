#ifndef SPAN_HPP
#define SPAN_HPP

# define BRIGHT_RED "\033[1;31m"
# define BRIGHT_BLUE "\033[1;34m"
# define ORANGE "\033[38;5;208m"
# define BRIGHT_GREEN "\033[1;32m"
# define RESET "\033[0m"
# define LINE 40

#include <iostream>
#include <vector>
#include <map>

class Span
{
	private:
		unsigned int		n;
		std::vector<int>	storage;	
	public:
		Span(void);
		Span(const unsigned int &n);
		Span(const Span &other);
		Span	&operator=(const Span &other);
		~Span(void);

		//	Methods
		void	addNumber(const int &value);
		int		shortestSpan(void) const;
		int		longestSpan(void) const;

		//	Getters
		unsigned int			size(void) const;
		const std::vector<int>	&getStorage(void) const;
};

std::ostream	&operator<<(std::ostream &out, const Span &other);


template <typename T>
static void	canonical(const T &original)
{
	std::cout << ORANGE << std::string(LINE, '-') << "\n" << "\tCanonical Ortodox tests\n" << std::string(LINE, '-') << RESET << std::endl;
	std::cout << "\tConstructors\n" << std::string(LINE, '-') << std::endl;
	T	a;
	T	b = T(10);

	std::cout << "\n\tOperator <<\n" << std::string(LINE, '-') << std::endl;
	std::cout << original << "\n" << a << "\n" << b << "\n";

	std::cout << "\n\tAssignment test =\n" << std::string(LINE, '-') << std::endl;
	a = b;
	std::cout << a << "\n" << b << "\n";

	std::cout << "\n\tCopy constructors test =\n" << std::string(LINE, '-') << std::endl;
	T	*c = new T(b);
	std::cout << b << "\n" << *c << std::endl;
	delete c;

	std::cout << "\n\tDestructors\n" << std::string(LINE, '-') << std::endl;
}

#endif
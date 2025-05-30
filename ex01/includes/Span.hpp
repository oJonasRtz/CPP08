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
#include <algorithm>
#include <iterator>
#include <map>

class Span
{
	private:
		unsigned int		n;
		unsigned int		numInStorage;
		std::vector<int>	storage;
	
		void				timeToThrow(const std::string &message) const;
	public:
		Span(void);
		Span(const unsigned int &n);
		Span(const Span &other);
		Span	&operator=(const Span &other);
		Span	&operator=(const int &n);
		~Span(void);

		//	Methods
		void				addNumber(const int &value);
		unsigned int		shortestSpan(void) const;
		unsigned int		longestSpan(void) const;
		template<typename T>
		void				addRange(T start, T end)
		{
			unsigned int	range = std::distance(start, end);

			if (range > n - numInStorage)
				timeToThrow("Span: cannot add range - not enough space.");
			
			storage.insert(storage.end(), start, end);
			numInStorage += range;
		}

		//	Getters
		unsigned int			size(void) const;
		const std::vector<int>	&getStorage(void) const;
		int						getNumsStorage(void) const;
		void					showContent(void) const;
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
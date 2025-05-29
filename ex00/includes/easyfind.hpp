#ifndef EASYFIND_HPP
#define EASYFIND_HPP

# define BRIGHT_RED "\033[1;31m"
# define BRIGHT_BLUE "\033[1;34m"
# define ORANGE "\033[38;5;208m"
# define BRIGHT_GREEN "\033[1;32m"
# define RESET "\033[0m"

#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <map>

template<typename T>
void	easyfind(const T &src, const int &n)
{
	typename	T::const_iterator	i = std::find(src.begin(), src.end(), n);

	std::cout << *i << std::endl;	
}

template<typename T>
void	initConteiner(T &src, int a, int b, int c)
{
	src.push_back(a);
	src.push_back(b);
	src.push_back(c);
}

#endif
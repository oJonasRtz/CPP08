#ifndef EASYFIND_HPP
#define EASYFIND_HPP

# define BRIGHT_RED "\033[1;31m"
# define BRIGHT_BLUE "\033[1;34m"
# define ORANGE "\033[38;5;208m"
# define BRIGHT_GREEN "\033[1;32m"
# define RESET "\033[0m"
# define LINES 70

#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <map>

template<typename T>
typename T::value_type	easyfind(const T &src, int n)
{
	typename	T::const_iterator	i;
	
	i = std::find(src.begin(), src.end(), n);
	if (i == src.end())
		throw (std::runtime_error(BRIGHT_RED "easyfind: Couldn't find the value." RESET));
	return (*i);
}

template<typename T>
void	initConteiner(T &src, int a, int b, int c)
{
	src.push_back(a);
	src.push_back(b);
	src.push_back(c);
}

template<typename T>
void	test(const std::string &name, const T &conteiner, const int &n)
{
	std::cout << ORANGE << name << RESET " is looking for:\t\t" ORANGE << n << RESET << std::endl;
	std::cout << ORANGE << name << RESET " found:\t\t\t" ORANGE << easyfind(conteiner, n) << RESET << std::endl;
}

#endif
#include "easyfind.hpp"

int	main(void)
{
	std::vector<int>				v;
	std::list<int>					l;

	initConteiner(v, 1, 2, 3);
	initConteiner(l, 12, 1, 2);

	easyfind(v, 3);
	easyfind(l, 12);

	return (0);
}


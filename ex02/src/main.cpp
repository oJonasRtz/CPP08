#include "MutantStack.hpp"

static void	drawTitle(const std::string &title, bool orange)
{
	if (orange)
		std::cout << ORANGE << std::string(LINE, '=') << "\n\t" << title << "\n" << std::string(LINE, '=') << RESET << std::endl;
	else
		std::cout << std::string(LINE, '=') << "\n\t" << title << "\n" << std::string(LINE, '=') << std::endl;
}

static void	iteratorTest(void)
{
	drawTitle("Iterator", 1);
	MutantStack<int>	a;

	a.push(10);
	a.push(156);
	a.push(42);

	for (MutantStack<int>::iterator i = a.begin(); i != a.end(); i++)\
		std::cout << "a: " ORANGE << *i << RESET << std::endl;
	drawTitle("Destructor", 0);
}

static void	subjectTest(void)
{
	drawTitle("Subject test", 1);

	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << "top: " ORANGE << mstack.top() << RESET << std::endl;
	mstack.pop();
	std::cout << "size: " ORANGE << mstack.size() << RESET << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);

	drawTitle("Destructors", 0);
}

static int	doAgainDoRight(void)
{
	std::cout << BRIGHT_RED "How to use: ./mutant <test number>\n" RESET;
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (doAgainDoRight());

	std::map<std::string, void(*)(void)>	map;
	map["1"] = &iteratorTest;
	map["2"] = &subjectTest;

	if (map.find(argv[1]) == map.end())
		return (doAgainDoRight());

	drawTitle("MutantStack", 1);
	map[argv[1]]();

	return (0);
}


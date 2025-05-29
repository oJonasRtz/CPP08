#include "Span.hpp"

static void	drawTitle(const std::string &title, bool orange)
{
	if (orange)
		std::cout << ORANGE << std::string(LINE, '=') << "\n\t\t" << title << "\n" << std::string(LINE, '=') << RESET << std::endl;
	else
		std::cout << std::string(LINE, '=') << "\n\t" << title << "\n" << std::string(LINE, '=') << std::endl;
}

static void	canonicalTest(void)
{
	Span	a;

	canonical(a);
}

static int	howToUse(void)
{
	std::cout << BRIGHT_RED "./span <test number>\n" RESET;
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (howToUse());

	//Setup
	std::map<std::string, void(*)(void)>	map;
	map["1"] = &canonicalTest;

	//	Input check
	std::map<std::string, void (*)(void)>::iterator	temp = map.find(argv[1]);
	if (temp == map.end())
		return (howToUse());
	
	//	Execute test
	drawTitle("Span", 1);
	temp->second();
	return (0);
}

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

static void	shortLongTest(void)
{
	Span	a(10);

	try{

		/*
			* These are error-handling tests *
		*/
		// std::cout << "Largest: " << a.longestSpan() << std::endl;
		std::cout << "Shortest: " << a.shortestSpan() << std::endl;
	}catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

static void	addTests(void)
{
	drawTitle("AddNumber()", 1);
	Span	a(10);

	drawTitle("Before", 0);
	std::cout << "a: " ORANGE << a << RESET << std::endl;
	a.showContent();
	try{
		a.addNumber(15);
		a.addNumber(4);
		a.addNumber(27);
		a.addNumber(95);
		a.addNumber(15);
		a = 5;
		a = 45;
		a = 87;
		a = 42;
		a = 0;

		/*
			Error-handling test
				* This should trigger an exception
					trying to add an eleventh member in Span(10);
		*/
		a.addNumber(1);
	}catch (const std::exception &e){
		std::cerr << e.what() << std::endl;
	}
	drawTitle("After", 0);
	std::cout << "a: " ORANGE << a << RESET << std::endl;
	a.showContent();

	//	Copy test
	drawTitle("Copy test", 0);
	Span	b = a;
	std::cout << "b: " << ORANGE << b << RESET << std::endl;
	b.showContent();
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (howToUse());

	//Setup
	std::map<std::string, void(*)(void)>	map;
	map["1"] = &canonicalTest;
	map["3"] = &shortLongTest;
	map["2"] = &addTests;

	//	Input check
	if (map.find(argv[1]) == map.end())
		return (howToUse());
	
	//	Execute test
	drawTitle("Span", 1);
	map[argv[1]]();

	return (0);
}

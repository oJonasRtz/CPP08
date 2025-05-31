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

static std::vector<int>	getVector(const unsigned int &n)
{
	std::vector<int>	v;

	for (unsigned int i = 0; i < n; i++)
		v.push_back(rand() / 10000);
	
	return (v);
}

static int	howToUse(void)
{
	std::cout << BRIGHT_RED "./span <test number>\n" RESET;
	return (0);
}

// static void	fillSpan(Span &s, const unsigned int &n)
// {
// 	for (unsigned int i = 0; i < n; i++)
// 		s = i;
// }

static void	shortLongTest(void)
{
	drawTitle("shortest(); longest()", 1);
	std::vector<int>	v = getVector(10);

	try{
		drawTitle("Test 1", 0);
		Span	a(10);
		a.addRange(v.begin(), v.end());
		// fillSpan(a, 10);
		std::cout << "a: " ORANGE << a << RESET << std::endl;
		a.showContent();

		std::cout << "Shortest span: " ORANGE << a.shortestSpan() << RESET << std::endl;
		std::cout << "Longest span: " ORANGE << a.longestSpan() << RESET << std::endl;
	
		drawTitle("Test 2", 0);
		Span	b(5);
		b.addNumber(15);
		b.addNumber(4);
		b.addNumber(27);
		b.addNumber(95);
		b.addNumber(15);
		
		// fillSpan(b, 5);
		std::cout << "b: " ORANGE << b << RESET << std::endl;
		b.showContent();

		std::cout << "Shortest span: " ORANGE << b.shortestSpan() << RESET << std::endl;
		std::cout << "Longest span: " ORANGE << b.longestSpan() << RESET << std::endl;

		drawTitle("Destructors", 0);
	}catch(const std::exception &e){
		std::cerr << e.what() << std::endl;
	}

	/*
		Error-handling test
	*/
	try
	{
		drawTitle("Test 3 <shortest>", 0);
		Span	c;
		std::cout << "c: " ORANGE << c << RESET << std::endl;
		c.showContent();

		c.shortestSpan();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		drawTitle("Test 3 <longest>", 0);
		Span	c;
		std::cout << "c: " ORANGE << c << RESET << std::endl;
		c.showContent();

		c.longestSpan();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		drawTitle("Test 4 <shortest>", 0);
		Span	c;
		c = 42;
		std::cout << "c: " ORANGE << c << RESET << std::endl;
		c.showContent();

		c.shortestSpan();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		drawTitle("Test 4 <longest>", 0);
		Span	c;
		c = 42;
		std::cout << "c: " ORANGE << c << RESET << std::endl;
		c.showContent();

		c.longestSpan();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

static void	addTests(void)
{
	std::vector<int>	v = getVector(5);
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
		a = 15;
		a.addRange(v.begin(), v.end());
		// fillSpan(a, 5);

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

	drawTitle("Destructors", 0);
}

static void	subjectTest(void)
{
	drawTitle("Subject test", 1);

	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}

static void	rangeTest(void)
{
	drawTitle("addRange()", 1);

	//Setup
	std::vector<int>	v = getVector(10);
	
	Span	a(10);
	drawTitle("Before", 0);
	std::cout << "a: " ORANGE << a << RESET << std::endl;
	a.showContent();

	try
	{
		a.addRange(v.begin(), v.end());
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}


	drawTitle("After", 0);
	std::cout << "a: " ORANGE << a << RESET << std::endl;
	a.showContent();

	drawTitle("Destructor", 0);
}

static void	tenThousandMiles(void)
{
	drawTitle("10k numbers", 1);

	std::vector<int>	v = getVector(10000);
	Span				a(10000);

	drawTitle("Inicial stats", 0);
	std::cout << "a: " ORANGE << a << RESET << std::endl;
	a.showContent();

	try
	{
		a.addRange(v.begin(), v.end());
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	drawTitle("Final stats", 0);
	std::cout << "a: " ORANGE << a << RESET << std::endl;
	a.showContent();

	drawTitle("Destructors", 0);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (howToUse());

	srand(time(NULL));

	//Setup
	std::map<std::string, void(*)(void)>	map;
	map["1"] = &canonicalTest;
	map["3"] = &shortLongTest;
	map["2"] = &addTests;
	map["4"] = &subjectTest;
	map["5"] = &rangeTest;
	map["6"] = &tenThousandMiles;

	//	Input check
	if (map.find(argv[1]) == map.end())
		return (howToUse());
	
	//	Execute test
	drawTitle("Span", 1);
	map[argv[1]]();

	return (0);
}

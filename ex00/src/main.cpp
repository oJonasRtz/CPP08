#include "easyfind.hpp"

int	main(void)
{
	//	Title
	std::cout << BRIGHT_GREEN <<
			std::string(LINES, '=') <<
			"\n\t\t\t\tEasyfind\n" <<
			std::string(LINES, '=') <<
			RESET << std::endl;
	
	//	Setup for tests
	std::vector<int>	v;
	std::list<int>		l;
	initConteiner(v, 1, 2, 3);
	initConteiner(l, 12, 1, 2);


	// std::list<std::string> s;
	// s.push_back("hello");
	// s.push_back("world");
	// test("String", s, "world");

	//	Print values
	std::cout << BRIGHT_BLUE << std::string(LINES, '=') << RESET << std::endl;
	std::cout << "\t\t\t\tSetup\n";
	std::cout << BRIGHT_BLUE << std::string(LINES, '=') << RESET << std::endl;
	drawConteiner("Vector", v);
	std::cout << std::string(LINES, '=') << std::endl;
	drawConteiner("List", l);
	std::cout << std::string(LINES, '=') << std::endl;

	//	Tests
	std::cout << BRIGHT_BLUE << std::string(LINES, '=') << RESET << std::endl;
	std::cout << "\t\t\t\tTests\n";
	std::cout << BRIGHT_BLUE << std::string(LINES, '=') << RESET << std::endl;
	try
	{
		test("Vector", v, 2);
		test("List", l, 12);
		std::cout << std::string(LINES, '=') << std::endl;
		
		test("List2", l, 1);
		test("Vector2", v, 3);
		std::cout << std::string(LINES, '=') << std::endl;
		
		test("Error", l, 42);
	}catch (const std::exception &e){
		std::cerr << e.what() << std::endl;
		std::cout << std::string(LINES, '=') << std::endl;
	}

	return (0);
}

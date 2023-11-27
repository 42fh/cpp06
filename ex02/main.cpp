#include <iostream>
#include "Base.hpp"
#include "A.hpp"
// #include "B.hpp"
// #include "C.hpp"
#include "Foo.hpp"

int main()
{
	std::srand(std::time(NULL));

	std::cout << "====== identify* test ======" << std::endl;
	for (int i = 0; i < 10; i++)
	{
		Base* p = generate();
		identify(p);
		delete p;
	}	


	std::cout << "====== identify& test ======" << std::endl;
	for (int i = 0; i < 10; i++)
	{
		Base* p = generate();
		identify(*p);
		delete p;
	}	

	return 0;
}

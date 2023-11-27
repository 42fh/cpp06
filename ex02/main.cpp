#include <iostream>
#include "Base.hpp"
#include "A.hpp"
// #include "B.hpp"
// #include "C.hpp"
#include "Foo.hpp"

int main()
{
	std::srand(std::time(NULL));

	for (int i = 0; i < 10; i++)
	{
		Base* p = generate();
		identify(p);
		delete p;
	}	
	return 0;
}

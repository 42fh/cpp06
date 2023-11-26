#include <iostream>
#include "Serializer.hpp"

int main()
{
	Data d1("nope");
	Data d2("fish");

	Data *p;
	p = &d1;
	std::cout << p->getStr() << std::endl;

	// serialize into in and deserialize into ptr
	uintptr_t n = Serializer::serialize(&d2);
	p = Serializer::deserialize(n);
	
	// check that p points to d1 now
	std::cout << p->getStr() << std::endl;
	return 0;
}

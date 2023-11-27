#include "Foo.hpp"

Base* generate(void)
{
	
	int i = std::rand() % 3;
	if (i == 0)
	{
		A* a = new A();
		return (a);
	}
	else if (i == 1)
	{
		Base* b = new B();
		return (b);
	}
	else 
	{
		Base* c = new C();
		return (c);
	}
}

void identify(Base* p)
{
	A* a;
	B* b;
	C* c;
	a = dynamic_cast<A*>(p);
	b = dynamic_cast<B*>(p);
	c = dynamic_cast<C*>(p);
	if (a != NULL){std::cout << "Type A detected" << std::endl; return;}
	if (b != NULL){std::cout << "Type B detected" << std::endl; return;}
	if (c != NULL){std::cout << "Type C detected" << std::endl; return;}
}
// void identify(Base& p){(void) p;}
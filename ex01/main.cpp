#include "Serializer.hpp"

int main()
{
	Serializer::serialize((Data*)1);
	Serializer::deserialize((uintptr_t) 1);	
	return 0;
}

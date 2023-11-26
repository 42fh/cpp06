#include "Serializer.hpp"

Serializer::Serializer()
{
}

Serializer::~Serializer()
{
}

uintptr_t Serializer::serialize(Data* ptr)
{
	(void) ptr;
	return (uintptr_t)1;
}
Data* Serializer::deserialize(uintptr_t raw)
{
	(void) raw;
	return (Data*)1;
}

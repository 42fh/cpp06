#pragma once

#include <stdint.h>
#include "Data.hpp"

class Serializer
{
public:
	Serializer();
	Serializer(Serializer&);
	Serializer& operator=(Serializer&);
	virtual ~Serializer() = 0;

	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);
};


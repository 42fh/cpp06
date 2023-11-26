#include <stdint.h>
#include "Data.hpp"

class Serializer
{
public:
	Serializer();
	~Serializer();

	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);
};


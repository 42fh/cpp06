#include "Data.hpp"

Data::Data(): str("DefaultString"){}
Data::Data(std::string s): str(s){}
Data::Data(Data& r): str(r.str){}
Data::~Data(){}
Data& Data::operator=(Data& rhs){this->str = rhs.str; return *this;}
std::string Data::getStr(){return str;}
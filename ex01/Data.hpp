#include <string>

class Data
{
private:
	std::string str;
public:
	Data();
	Data(Data&);
	Data(std::string str);
	~Data();
	Data& operator=(Data&);
	std::string getStr();
};

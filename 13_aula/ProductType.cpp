#include <string>

class ProductType {
private:
	std::string _name;
public:
	ProductType(std::string name) : _name(name) {}
	std::string getName() { return _name; }
	void setName(std::string name) { _name = name; }
};

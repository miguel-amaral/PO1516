#include <string>

class PaymentMethod {
private:
	std::string _name;
public:
	PaymentMethod(std::string name) : _name(name) {}
	std::string getName() { return _name; }
	void setName(std::string name) { _name = name; }
};

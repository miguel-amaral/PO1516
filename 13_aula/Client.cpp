#include <time.h>
#include <string>
#include "Purchase.cpp"

class Client {
private:
	std::string name;
	int contact;
	time_t birthday;
	time_t first_buy;
    std::list< std::shared_ptr<Purchase> > _purchases;
public:

};

#include <forward_list>
#include <list>
#include <ctime>
#include <string>
#include "Purchase.cpp"

class Client {
private:
	std::string _name;
	long int _contact;
	std::time_t _birthday;
	std::time_t _firstBuy;
  std::list< std::shared_ptr<Purchase> > _purchases;
	int _points;
	float _discount = 0;
public:
	Client(std::time_t birthday, long int contact, std::string name) :
	 					_birthday(birthday), _contact(contact), _name(name){
		_points = 0;
	}
	void addPurchase(std::shared_ptr<Purchase> p){
		_purchases.push_back(std::move(p));
		_points += p->getValue();
		if(_firstBuy){
			_firstBuy = p->getDate();
		}
	}
	void setDiscount(double discount){
		_discount = discount;
	}

	int getPoints(){return points;}


};

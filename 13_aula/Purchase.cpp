#include <forward_list>
#include <ctime>
#include "ProductType.cpp"
#include "PaymentMethod.cpp"

class Purchase {
private:
	std::time_t _date;
	int _value =0;
	std::shared_ptr<PaymentMethod> _paymentMethod;
	std::shared_ptr<ProductType> _prodType;
public:
	Purchase(std::time_t date, std::string payment, int value,
		std::string prodType ) : _date(date), _value(value){
			 		_paymentMethod = std::make_shared<PaymentMethod>(prodType);
			 		_prodType = std::make_shared<ProductType>(prodType);
	}
	int getValue(){
		return _value;
	}
	std::time_t getDate(){
		return _date;
	}
	void applyDiscount(float discount){
		_value = _value * (1-discount);
	}

};

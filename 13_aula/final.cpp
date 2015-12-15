/* ------------------- */
/*   Aluno    78865    */
/*   Miguel   Amaral   */
/* Quarta Feira 15h30  */
/* ------------------- */


/* ------------------- */
/*  PaymentMethod.cpp  */
/* ------------------- */
#include <string>

class PaymentMethod {
private:
	std::string _name;
public:
	PaymentMethod(std::string name) : _name(name) {}
	std::string getName() { return _name; }
	void setName(std::string name) { _name = name; }
};

/* ------------------- */
/*    ProductType.cpp  */
/* ------------------- */
#include <string>

class ProductType {
private:
	std::string _name;
public:
	ProductType(std::string name) : _name(name) {}
	std::string getName() { return _name; }
	void setName(std::string name) { _name = name; }
};

/* ------------------- */
/*    Purchase.cpp     */
/* ------------------- */
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

/* ------------------- */
/*      Filter.hpp     */
/* ------------------- */
class Filter {
public:
    virtual std::list< std::shared_ptr<Client>>
                  getFilteredList(Store *store) =0;
};

/* ------------------- */
/*      Filter.cpp     */
/* ------------------- */
#include <forward_list>
#include <list>
//#include "Client.cpp"

class XPurchases : public Filter {
private:
  int _purchaseNumber;
public:
  XPurchases(int purchaseNumber){
    _purchaseNumber = purchaseNumber;
  }


  std::list< std::shared_ptr<Client>> getFilteredList(Store *store){

    std::cout << "A filtrar PURCHASES " << std::endl;
    std::list< std::shared_ptr<Client>> returnList;
    for (int i = 0; i < store->getSize(); i++) {
        std::shared_ptr<Client> c = store->getClient(i);
        if(c->getPurchaseListSize() >= _purchaseNumber)
          returnList.push_back(std::move(c));
    }
    return returnList;
  }

};

class XPoints : public Filter {
private:
  int _pointsMin;
public:
  XPoints(int pointsMin){
    _pointsMin = pointsMin;
  }


  std::list< std::shared_ptr<Client>> getFilteredList(Store *store){
    std::cout << "A filtrar POINTS " << std::endl;
    std::list< std::shared_ptr<Client>> returnList;
    for (int i = 0; i < store->getSize(); i++) {
        std::shared_ptr<Client> c = store->getClient(i);
        if(c->getPoints() >= _pointsMin)
          returnList.push_back(std::move(c));
    }
    return returnList;
  }

};

/* ------------------- */
/*     Client.cpp      */
/* ------------------- */
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
		_points = _points + p->getValue();
		if(_firstBuy){
			_firstBuy = p->getDate();
		}
		_purchases.push_back(std::move(p));
	}

	void setDiscount(double discount){
		_discount = discount;
	}

	int getPurchaseListSize(){
		return _purchases.size();
	}

	int getPoints(){return _points;}
	void setPoints(int points){ _points = points;}

	std::string getName(){return _name;}


};

/* ------------------- */
/*      Store.cpp      */
/* ------------------- */
#include <string>
#include "Client.cpp"
#include "Filter.hpp"

class Store {
private:
	std::string _name;
	std::list< std::shared_ptr<Client> > _clients;
public:
	Store(std::string name) : _name(name){}
	void addClient(std::shared_ptr<Client> c){
		_clients.push_back(std::move(c));
	}

	std::list< std::shared_ptr<Client> > getList(std::shared_ptr<Filter> filter){
		return filter->getFilteredList(this);
	}

	std::shared_ptr<Client> getClient(int index) {
		std::list<std::shared_ptr<Client>>::iterator i = _clients.begin();
		std::advance(i, index);
		return *i;
}

int getSize() {
		return _clients.size();
}
};

/* ------------------- */
/*       App.cpp       */
/* ------------------- */
#include <forward_list>
#include <iostream>

class Store;

#include "Store.cpp"
#include "Filter.cpp"

int main(){
  std::shared_ptr<Store> store = std::make_shared<Store>("loja de ferragens");
  time_t currTime;
  time_t tenYears;
  time(&currTime);
  tenYears = currTime - (10*365*24*60*60);


  std::shared_ptr<Client> c1=std::make_shared<Client>(currTime,1111111,"Joao");
  std::shared_ptr<Client> c2=std::make_shared<Client>(tenYears,9999999,"Jota");
  store->addClient(c1);
  store->addClient(c2);

  std::shared_ptr<Purchase> p1 =
                      std::make_shared<Purchase>(currTime, "cash", 30, "milk");
  std::shared_ptr<Purchase> p2 =
                      std::make_shared<Purchase>(currTime, "cash", 30, "eggs");
  std::shared_ptr<Purchase> p3 =
                      std::make_shared<Purchase>(currTime, "cash", 30, "milk");
  std::shared_ptr<Purchase> p4 =
            std::make_shared<Purchase>(currTime, "credit_card", 1000, "laptop");


  c1->addPurchase(p1);
  c1->addPurchase(p2);
  c1->addPurchase(p3);

  c2->addPurchase(p4);


  std::shared_ptr<Filter> f2 = std::make_shared<XPurchases>(2);
  std::list< std::shared_ptr<Client> > listaCompras2 = store->getList(f2);

  std::list<std::shared_ptr<Client>>::iterator i;
  for (i = listaCompras2.begin(); i != listaCompras2.end(); ++i) {
      std::shared_ptr<Client> cliente = *i;
      std::cout << cliente->getName() << std::endl;

  }

  std::shared_ptr<Filter> f3 = std::make_shared<XPoints>(100);
  std::list< std::shared_ptr<Client> > listaPontos400 = store->getList(f3);
  for (i = listaPontos400.begin(); i != listaPontos400.end(); ++i) {
      std::shared_ptr<Client> cliente = *i;
      cliente->setDiscount(0.50);
      std::cout << cliente->getName() << std::endl;
  }
  return 0;
}

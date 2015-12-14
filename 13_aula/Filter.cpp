#include <forward_list>
//#include "Client.cpp"


class Filter {
public:
    virtual std::list< std::shared_ptr<Client>>
                  getFilteredList(std::list< std::shared_ptr<Client> > list) =0;
};


class XPurchases : public Filter {
private:
  int _purchaseNumber;
public:
  XPurchases(int purchaseNumber){
    _purchaseNumber = purchaseNumber;
  }


  std::list< std::shared_ptr<Client>>
                getFilteredList(std::list< std::shared_ptr<Client> > list){


  }

}

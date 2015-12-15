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

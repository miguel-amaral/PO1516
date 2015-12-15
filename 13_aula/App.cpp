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
  std::shared_ptr<Client> c2=std::make_shared<Client>(tenYears,9999999,"Jota ");
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

  std::shared_ptr<Filter> f3 = std::make_shared<XPoints>(400);
  std::list< std::shared_ptr<Client> > listaPontos50 = store->getList(f3);
  for (i = listaPontos50.begin(); i != listaPontos50.end(); ++i) {
      std::shared_ptr<Client> cliente = *i;
      cliente->setDiscount(0.50);
      std::cout << cliente->getName() << std::endl;
  }
  return 0;
}

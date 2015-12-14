#include <forward_list>
#include <iostream>


#include "Store.cpp"
#include "XYearsCommitment.cpp"
#include "XPurchases.cpp"

int main(){
  std::shared_ptr<Store> store = std::make_shared<Store>("loja de ferragens");
  time_t currTime;
  time_t tenYearsAgo;
  time(&currTime);
  tenYearsAgo = currTime - (10*365*24*60*60);


  std::shared_ptr<Client> c1 = std::make_shared<Client>(currTime,1111111,"Joao");
  std::shared_ptr<Client> c2 = std::make_shared<Client>(tenYearsAgo,9999999,"Miguel");
  store->addClient(c1);
  store->addClient(c2);

  std::shared_ptr<Filter> f2 = std::make_shared<XPurchases>(2);
  std::shared_ptr<Filter> f3 = std::make_shared<XPoints>(50);

  std::cout << currTime << std::endl;
  std::cout << tenYearsAgo << std::endl;

  return 0;
}

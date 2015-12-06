#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <sstream>
#include <forward_list>
#include <list>
class Person;
class Company;
class Region;

class  FlexyIRS {
public:
    virtual double visitPerson(Person *p)=0;

    virtual double visitCompany(Company *c)=0;

    virtual double visitRegion(Region *r) =0;
};


class  Taxpayer {

public:
    virtual double accept(FlexyIRS *irs) =0;
};

class Person : public Taxpayer {
public:
    double accept(FlexyIRS *irs) {
        return irs->visitPerson(this);
    }
};

class Company : public Taxpayer {
private:
    std::list< std::shared_ptr<Person> > _employees;
public:

    double accept(FlexyIRS *irs) {
        return irs->visitCompany(this);
    }

    // Os seguintes métodos são apenas para testar, não é necessário
    // implementar!
    void addPerson(std::shared_ptr<Person> p) {
      _employees.push_back(std::move(p));
    }

    std::shared_ptr<Person> getPerson(int index) {
        std::list<std::shared_ptr<Person>>::iterator i = _employees.begin();
        std::advance(i, index);
        return *i;
    }

    int getSize() {
        return _employees.size();
    }
};
class Region : public Taxpayer {
private:
    std::list< std::shared_ptr<Company> > _companies;
public:
    double accept(FlexyIRS *irs) {
        return irs->visitRegion(this);
    }

    // Os seguintes métodos são apenas para testar, não é necessário
    // implementar!

    void addCompany(std::shared_ptr<Company> c) {
      _companies.push_back(std::move(c));
    }

    std::shared_ptr<Company> getCompany(int index) {
        std::list<std::shared_ptr<Company>>::iterator i = _companies.begin();
        std::advance(i, index);
        return *i;
    }

    int getSize() {
        return _companies.size();
    }
};
class FastTrack : public FlexyIRS {
public:
    double visitPerson(Person *p) {
        return 1;
    }

    double visitCompany(Company *c) {
        double tax = 0;

        for (int i = 0; i < c->getSize(); i++) {
            std::shared_ptr<Person> p = c->getPerson(i);
            tax += p->accept(this);
        }

        if (c->getSize() < 4)
            tax *= 0.6;

        return tax;
    }

    double visitRegion(Region * r) {
        double tax = 0;
        bool hasDiscount = false;

        for (int i = 0; i < r->getSize(); i++) {
            std::shared_ptr<Company> c = r->getCompany(i);
            tax += c->accept(this);
            if (c->getSize() < 10)
                hasDiscount = true;
        }

        if (hasDiscount)
            tax *= 0.8;

        return tax;
    }
};


int main(){
  std::shared_ptr<Company> c1 = std::make_shared<Company>();
  std::shared_ptr<Company> c2 = std::make_shared<Company>();
  std::shared_ptr<Company> c3 = std::make_shared<Company>();
  std::shared_ptr<Region>  r1 = std::make_shared<Region>();
  std::shared_ptr<Region>  r2 = std::make_shared<Region>();
  std::shared_ptr<Region>  r3 = std::make_shared<Region>();
  FlexyIRS *irs = new FastTrack();

  for (int i = 0; i < 20; i++)
      c1->addPerson(std::make_shared<Person>());


  for (int i = 0; i < 3; i++)
      c2->addPerson(std::make_shared<Person>());


  for (int i = 0; i < 8; i++)
      c3->addPerson(std::make_shared<Person>());

  r1->addCompany(c1);
  r2->addCompany(c2);
  r3->addCompany(c1);
  r3->addCompany(c3);

  // Tem uma empresa com 20 empregados, logo não tem descontos,
  // e paga 20.
  std::cout  << "A região r1 irá pagar " <<  r1->accept(irs)<< "\n";

  // Tem uma empresa com 3 empregados, logo tem desconto de 20%
  // para além do desconto de 40% da empresa, por isso deve pagar
  // 3*0.6*0.8 = 1.44
  std::cout  << "A região r2 irá pagar " <<  r2->accept(irs)<< "\n";

  // Tem uma empresa com 20 empregados e outra com 8, logo irá ter
  // apenas o desconto de 20%, pagando 28*0.8 = 22.4
  std::cout  << "A região r3 irá pagar " <<  r3->accept(irs) << "\n";

  delete(irs);

  return 0;

}

Miguel Amaral 78865 
Quarta Feira 15h30

class  FlexyIRS {
public:
    virtual double visitPerson (Person  *p)=0;
    virtual double visitCompany(Company *c)=0;
    virtual double visitRegion (Region  *r)=0;
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
};
class Region : public Taxpayer {
private:
    std::list< std::shared_ptr<Company> > _companies;
public:
    double accept(FlexyIRS *irs) {
        return irs->visitRegion(this);
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

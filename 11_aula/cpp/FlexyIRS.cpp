class abstract FlexyIRS {
public:
    virtual double visitPerson(Person p)=0;

    virtual double visitCompany(Company c)=0;

    virtual double visitRegion(Region r) =0;
};

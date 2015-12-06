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

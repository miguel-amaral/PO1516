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

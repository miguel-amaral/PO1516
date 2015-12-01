class Region : public Taxpayer {
private:
    std::list< std::shared_ptr<Company> > _companies;
    double accept(FlexyIRS irs) {
        return irs.visitRegion(this);
    }

    // Os seguintes métodos são apenas para testar, não é necessário
    // implementar!

public:
    void addCompany(std::shared_ptr<Company> c) {
      _companies.push_back(std::move(c));
    }

    /*FIXME*/
    std::shared_ptr<Company> getCompany(int index) {
        return _companies.get(index);
    }

    int getSize() {
        return _companies.size();
    }
}

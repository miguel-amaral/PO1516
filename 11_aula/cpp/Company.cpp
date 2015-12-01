class Company : public Taxpayer {
private:
    std::list< std::shared_ptr<Person> > _employees;
public:
    private ArrayList<Person> _employees = new ArrayList<>();

    double accept(FlexyIRS irs) {
        return irs.visitCompany(this);
    }

    // Os seguintes métodos são apenas para testar, não é necessário
    // implementar!
/*
    public void addPerson(Person p) {
        _employees.add(p);
    }

    public Person getPerson(int index) {
        return _employees.get(index);
    }

    public int getSize() {
        return _employees.size();
    }*/
}

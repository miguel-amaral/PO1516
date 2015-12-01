class Person : public Taxpayer {
public:
    double accept(FlexyIRS irs) {
        return irs.visitPerson(this);
    }
}

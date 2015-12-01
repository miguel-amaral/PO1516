class FastTrack : public FlexyIRS {
public:
    double visitPerson(std::shared_ptr<Person> p) {
        return 1;
    }

    double visitCompany(std::shared_ptr<Company> c) {
        double tax = 0;

        for (int i = 0; i < c->getSize(); i++) {
            std::shared_ptr<Person> = c.getPerson(i);
            tax += p->accept(this);
        }

        if (c->getSize() < 4)
            tax *= 0.6;

        return tax;
    }

    double visitRegion(std::shared_ptr<Region> r) {
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
}

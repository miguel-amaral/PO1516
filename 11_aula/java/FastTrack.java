public class FastTrack implements FlexyIRS {

    public double visitPerson(Person p) {
        return 1;
    }

    public double visitCompany(Company c) {
        double tax = 0;

        for (int i = 0; i < c.getSize(); i++) {
            Person p = c.getPerson(i);
            tax += p.accept(this);
        }

        if (c.getSize() < 4)
            tax *= 0.6;

        return tax;
    }

    public double visitRegion(Region r) {
        double tax = 0;
        boolean hasDiscount = false;

        for (int i = 0; i < r.getSize(); i++) {
            Company c = r.getCompany(i);
            tax += c.accept(this);
            if (c.getSize() < 10)
                hasDiscount = true;
        }

        if (hasDiscount)
            tax *= 0.8;

        return tax;
    }
}
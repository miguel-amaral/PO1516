import java.util.ArrayList;

public class Region extends Taxpayer {

    private ArrayList<Company> _companies = new ArrayList<>();

    public double accept(FlexyIRS irs) {
        return irs.visitRegion(this);
    }

    // Os seguintes métodos são apenas para testar, não é necessário
    // implementar!

    public void addCompany(Company c) {
        _companies.add(c);
    }

    public Company getCompany(int index) {
        return _companies.get(index);
    }

    public int getSize() {
        return _companies.size();
    }
}
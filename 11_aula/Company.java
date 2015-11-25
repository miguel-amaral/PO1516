import java.util.ArrayList;

public class Company extends Taxpayer {
    
    private ArrayList<Person> _employees = new ArrayList<>();

    public double accept(FlexyIRS irs) {
        return irs.visitCompany(this);
    }

    // Os seguintes métodos são apenas para testar, não é necessário
    // implementar!

    public void addPerson(Person p) {
        _employees.add(p);
    }

    public Person getPerson(int index) {
        return _employees.get(index);
    }

    public int getSize() {
        return _employees.size();
    }
}
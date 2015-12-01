public class Person extends Taxpayer {
    
    public double accept(FlexyIRS irs) {
        return irs.visitPerson(this);
    }
}
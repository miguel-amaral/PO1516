public class App {
    public static void main(String[] args) {
        Company  c   = new Company();
        Company  c2  = new Company();
        Company  c3  = new Company();
        Region   r   = new Region();
        Region   r2  = new Region();
        Region   r3  = new Region();
        FlexyIRS irs = new FastTrack();

        for (int i = 0; i < 20; i++)
            c.addPerson(new Person());


        for (int i = 0; i < 3; i++)
            c2.addPerson(new Person());


        for (int i = 0; i < 8; i++)
            c3.addPerson(new Person());

        r.addCompany(c);
        r2.addCompany(c2);
        r3.addCompany(c);
        r3.addCompany(c3);

        // Tem uma empresa com 20 empregados, logo não tem descontos,
        // e paga 20.
        System.out.printf("A região r irá pagar %f.%n", r.accept(irs));

        // Tem uma empresa com 3 empregados, logo tem desconto de 20%
        // para além do desconto de 40% da empresa, por isso deve pagar
        // 3*0.6*0.8 = 1.44
        System.out.printf("A região r2 irá pagar %f.%n", r2.accept(irs));

        // Tem uma empresa com 20 empregados e outra com 8, logo irá ter
        // apenas o desconto de 20%, pagando 28*0.8 = 22.4
        System.out.printf("A região r3 irá pagar %f.%n", r3.accept(irs));
    }
}
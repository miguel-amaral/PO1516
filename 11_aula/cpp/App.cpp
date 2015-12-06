        std::shared_ptr<Company> c1 = std::make_shared<Company>();
        std::shared_ptr<Company> c2 = std::make_shared<Company>();
        std::shared_ptr<Company> c3 = std::make_shared<Company>();
        std::shared_ptr<Region>  r1 = std::make_shared<Region>();
        std::shared_ptr<Region>  r1 = std::make_shared<Region>();
        std::shared_ptr<Region>  r2 = std::make_shared<Region>();
        std::shared_ptr<Region>  r3 = std::make_shared<Region>();
        FlexyIRS *irs = new FastTrack();

        for (int i = 0; i < 20; i++)
            c1->addPerson(std::make_shared<Person>());


        for (int i = 0; i < 3; i++)
            c2->addPerson(std::make_shared<Person>());


        for (int i = 0; i < 8; i++)
            c3->addPerson(std::make_shared<Person>());

        r1->addCompany(c1);
        r2->addCompany(c2);
        r3->addCompany(c1);
        r3->addCompany(c3);

        // Tem uma empresa com 20 empregados, logo não tem descontos,
        // e paga 20.
        std::cout  << "A região r1 irá pagar " <<  r1->accept(irs)<< "\n";

        // Tem uma empresa com 3 empregados, logo tem desconto de 20%
        // para além do desconto de 40% da empresa, por isso deve pagar
        // 3*0.6*0.8 = 1.44
        std::cout  << "A região r2 irá pagar " <<  r2->accept(irs)<< "\n";

        // Tem uma empresa com 20 empregados e outra com 8, logo irá ter
        // apenas o desconto de 20%, pagando 28*0.8 = 22.4
        std::cout  << "A região r3 irá pagar " <<  r3->accept(irs) << "\n";
    }
}

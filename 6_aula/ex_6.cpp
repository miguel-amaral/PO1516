/* Miguel Antão Pereira Amaral 78865 */
/* Aula Quarta feira 15h 30 */

#include <iostream>
#include <forward_list>
#include <list>

class Helped{
public:
  virtual int totalHelp() =0;
  virtual void receiveHelp(int amount) =0;
};

class Beneficiaries : public Helped{};

class Single : public Beneficiaries {
private:
  int _amount;
public:
  Single(): _amount(0) {}
  ~Single(){
    std::cout << "\e[31mDeleting Single\e[0m\n";
  }
  int totalHelp() {
    std::cout << "\e[34mSingle: totalHelp " << _amount << "\e[0m\n";
    return _amount;
  }

  void receiveHelp(int amount) {
    _amount += amount;
  }
};

class Collective : public Beneficiaries {
private:
  std::list< std::shared_ptr<Single> > _mylist;
public:
  ~Collective() {
    std::cout << "\e[31mDeleting Collective\e[0m\n";
  }
  int totalHelp() {
    std::cout << "\e[32mCollective: totalHelp \e[0m\n" ;
    int total = 0;
    for (std::shared_ptr<Single> x: _mylist){
      total += x->totalHelp();
    }
    return total;
  }

  void receiveHelp(int money) {
    int individualHelp = 0;
    if (!_mylist.empty()){
      individualHelp = money / _mylist.size();
      for (std::shared_ptr<Single> x: _mylist){
        x->receiveHelp(individualHelp);
      }
    }
  }
  void addSingle(std::shared_ptr<Single> s){
    _mylist.push_front(std::move(s));
  }
};

class Region : public Helped {
private:
    std::list< std::shared_ptr<Beneficiaries> > _mylist;
public:
    ~Region() {
      std::cout << "\e[31mDeleting Region\e[0m\n";
    }
    int totalHelp() {
      std::cout << "\e[33mRegion: totalHelp : \e[0m" << std::endl;
      int total = 0;
      for (std::shared_ptr<Beneficiaries> x: _mylist){
        total += x->totalHelp();
      }
      return total;
    }

    void receiveHelp(int money){
      int individualHelp = 0;
      if (!_mylist.empty()){
        individualHelp = money / _mylist.size();
        for (std::shared_ptr<Beneficiaries> x: _mylist){
          x->receiveHelp(individualHelp);
        }
      }
    }

    void addCollective(std::shared_ptr<Collective> c){
      _mylist.push_front(std::move(c));
    }
    void addSingle(std::shared_ptr<Single> s){
      _mylist.push_front(std::move(s));
    }


};



int main(){

    std::shared_ptr<Single> s1 = std::make_shared<Single>();
    std::shared_ptr<Single> s2 = std::make_shared<Single>();
    std::shared_ptr<Single> s3 = std::make_shared<Single>();
    std::shared_ptr<Single> s4 = std::make_shared<Single>();
    std::shared_ptr<Single> s5 = std::make_shared<Single>();
    std::shared_ptr<Single> s6 = std::make_shared<Single>();
    std::shared_ptr<Collective> c1 = std::make_shared<Collective>();
    std::shared_ptr<Region> r1 = std::make_shared<Region>();
    s1->receiveHelp(1);
    s2->receiveHelp(1);
    s3->receiveHelp(1);
    s4->receiveHelp(1);
    s5->receiveHelp(1);
    s6->receiveHelp(1);

    std::cout <<"S1 totalHelp: " << s1->totalHelp() << "\n";

    r1->addCollective(c1);
    r1->addSingle(s1);
    r1->addSingle(s2);
    r1->addSingle(s3);
    std::cout << "R1 totalHelp " <<r1->totalHelp() << "\n";
    s1->receiveHelp(100000);
    std::cout << "R1 totalHelp " <<r1->totalHelp() << "\n";

    c1->addSingle(s5);
    c1->addSingle(s6);
    c1->addSingle(s4);

    r1->receiveHelp(400);
    r1->receiveHelp(900);
    c1->receiveHelp(500);
    std::cout << "C1 totalHelp " <<c1->totalHelp() << "\n";
    std::cout << "R1 totalHelp " << r1->totalHelp() << "\n";
}

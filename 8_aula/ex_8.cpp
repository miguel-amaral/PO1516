/* Miguel Antão Pereira Amaral 78865 */
/* Aula Quarta feira 15h 30          */
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <sstream>
#include <forward_list>
class Cat {
private:
  int _age = 0;
  std::string _name = "anonimo";
public:
  Cat(): _age(0),_name("anonimo"){}
  Cat(int age, std::string name) : _age(age), _name(name){;}
  std::string getName(){ return _name;}
  void setName(std::string name){  _name = name;}
  int getAge(){ return _age;}
  void setAge(int age){ _age = age;}
  friend std::ostream &operator<<(std::ostream &os, Cat &cat) {
    os << "(Cat) ";
    os << "name: " << cat.getName();
    os << " age: " << cat.getAge();
    return os;
  }
  friend std::istream &operator>>(std::istream &is, Cat &cat) {
    std::string garbage;
    std::string name;
    int age;
    is >> garbage;
    is >> garbage;
    is >> name;
    is >> garbage >> age;
    cat.setName(name);
    cat.setAge(age);
    return is;
  }
};

int main(){

  /* Create Cats */
  std::shared_ptr<Cat> c1 = std::make_shared<Cat>();
  std::shared_ptr<Cat> c2 = std::make_shared<Cat>(24,"Tareco");
  std::shared_ptr<Cat> c3 = std::make_shared<Cat>(6,"Pantufa");
  std::cout << *c1 << std::endl;
  std::cout << *c2 << std::endl;
  std::cout << *c3 << std::endl;

  /* Put Cats in stream */
  std::stringstream stream1;
  stream1 << *c2;
  stream1 << *c3;

  /* Create 2 new clean cats*/
  std::shared_ptr<Cat> c4 = std::make_shared<Cat>();
  std::shared_ptr<Cat> c5 = std::make_shared<Cat>();
  
  /*REcover cats from the stream*/
  stream1 >> *c4;
  stream1 >> *c5;

  /* Print the cats again */
  std::cout << "Recovered Cats" << std::endl;
  std::cout << *c4 << std::endl;
  std::cout << *c5 << std::endl;
  return 0;
}

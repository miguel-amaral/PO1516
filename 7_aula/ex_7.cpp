/* Miguel Antão Pereira Amaral 78865 */
/* Aula Quarta feira 15h 30 */
#include <iostream>
#include <map>
#include <utility>
#include <forward_list>
#include <list>

class CellAlreadyExists{};
class NoSuchCell{};


class Cell {
private:
  std::pair <int,int> _coords;
public:
  Cell(int x, int y){
    _coords = std::make_pair (x,y);
  }

  int getCoordinateX(){
    return _coords.first;
  }
  int getCoordinateY(){
    return _coords.second;
  }

  std::pair <int,int> getCoords(){
    return _coords;
  }

  virtual int getValue() =0;
  //virtual getElement() =0;
  friend bool operator<( Cell& l,  Cell& r) {
       return l.getValue() < r.getValue();
   }
  friend bool operator>( Cell& l,  Cell& r) {
       return r < l;
   }
  virtual void print(std::ostream& where)  =0 ;
  friend std::ostream &operator<<(std::ostream &os, Cell   &cell) {
    cell.print(os);
    return os;
  }
  //redefinir operator <<
};
class IntCell : public Cell {
private:
  int _element=0;
public:
  IntCell(int x, int y, int value): Cell(x,y){
    _element = value;
  }
  void setValue(int newValue){
    _element = newValue;
  }
  int getValue(){
    return _element;
  }
  int getElement(){
    return _element;
  }
  void print(std::ostream& os) {
    os << _element;
  }
};
class StringCell : public Cell {
private:
  std::string _element="";
public:
  StringCell(int x, int y, std::string string): Cell(x,y){
    _element = string;
  }
  /*
  void setValue(int newValue){
    _element = newValue;
  }*/
  int getValue(){
    return 0;
  }
  std::string getElement(){
    return _element;
  }
  void print(std::ostream& os) {
    os << _element;
  }
};
class RefCell : public Cell {
private:
  std::shared_ptr<Cell> _element;
public:
  RefCell(int my_x, int my_y, std::shared_ptr<Cell> cell): Cell(my_x,my_y){
    _element = cell;
  }
  int getValue(){
    return _element->getValue();
  }
  void print(std::ostream& os) {
    os << "REF TO --> [x: " << getCoordinateX() << " | y: " ;
    os << getCoordinateY() << "]: ";
    os << *_element;
  }
};
class FormulaCell : public Cell {
private:
  std::list< std::shared_ptr<Cell> > _mylist;

public:

  FormulaCell(int my_x, int my_y, std::list< std::shared_ptr<Cell> > lista)\
                                                              : Cell(my_x,my_y){
    _mylist = lista;
    //_element = cell;
  }
  int getValue(){
    int soma =0;
    for (std::shared_ptr<Cell> x: _mylist){
      soma += x->getValue();
    }
    return soma;
  }
  void print(std::ostream& os) {
    os << "Formula ( ";
    int i=0;
    for (std::shared_ptr<Cell> x: _mylist){
      os << "arg nr:" << i << " " << *x << " | ";
      i++;
    }
    os << ") ";
  }
};


class CalcSheet {
private:
  std::map<std::pair<int ,int>, std::shared_ptr<Cell> > _myMap;
public:

  std::shared_ptr<Cell> getCell(std::pair <int,int> pair){
    std::map<std::pair <int,int>, std::shared_ptr<Cell> >::iterator it;
    it = _myMap.find(pair);
    if (it == _myMap.end())
      std::cout << "\e[31m[ERROR] \e[0mCell not found" << std::endl;
    return it->second;
  }

  void addCell(std::shared_ptr<Cell> cell){
    std::pair<int,int> coords = cell->getCoords();
    std::pair<std::map<std::pair <int,int>, std::shared_ptr<Cell> >   \
                                                            ::iterator,bool> it;
    std::pair<std::pair <int,int>, std::shared_ptr<Cell> > toInsert = \
                                                   std::make_pair (coords,cell);

    it = _myMap.insert (toInsert);
    if (it.second==false) {
      std::cout << "\e[31m[ERROR] \e[0mAs coordenas [x=" << coords.first
      << " | y=" << coords.second <<"] ja estao em uso" << std::endl;
    }
  }
  friend std::ostream &operator<<(std::ostream &os, CalcSheet &folha) {
    os << "\e[33m[INFO]\e[0m printing CalcSheet" << std::endl;
    for (auto& elem : folha._myMap){
      std::shared_ptr<Cell> c1 = elem.second;

      os << "[x: " << c1->getCoordinateX() << " ";
      os << "| y: " << c1->getCoordinateY() << "]: ";
      os <<*c1 << std::endl;
    }
    os << "\e[33m[INFO]\e[0m --end" << std::endl;
    return os;
  }

};

int main(){
    std::list< std::shared_ptr<Cell> > lista;
    std::list< std::shared_ptr<Cell> > lista2;
    std::shared_ptr<CalcSheet> folha = std::make_shared<CalcSheet>();
    std::shared_ptr<IntCell> c1 = std::make_shared<IntCell>(0,0,5);
    std::shared_ptr<StringCell> c2 = std::make_shared<StringCell>(0,1,"string");
    std::shared_ptr<RefCell> c3 = std::make_shared<RefCell>(0,2,c1);
    std::shared_ptr<RefCell> c4 = std::make_shared<RefCell>(0,3,c2);
    std::shared_ptr<IntCell> c5 = std::make_shared<IntCell>(0,4,5);
    std::shared_ptr<StringCell> c6 = std::make_shared<StringCell>(0,5,"Tareco");

    lista.push_front(c3);
    lista.push_front(c4);
    lista.push_front(c5);
    std::shared_ptr<FormulaCell> c7 = \
                std::make_shared<FormulaCell>(2,2,lista);
    lista2.push_front(c1);
    lista2.push_front(c7);
    lista2.push_front(c2);
    lista2.push_front(c3);
    std::shared_ptr<FormulaCell> c8 = \
                std::make_shared<FormulaCell>(1,1,lista2);


    std::cout << "c7 value: " << c7->getValue() << std::endl;
    std::cout << "c8 value: " << c8->getValue() << std::endl;

    std::cout << "c1: " << *c1 << std::endl;
    std::cout << "c2: " << *c2 << std::endl;
    std::cout << "c3: " << *c3 << std::endl;
    std::cout << "c4: " << *c4 << std::endl;
    c1->setValue(11);
    folha->addCell(c1);
    folha->addCell(c2);
    folha->addCell(c1);
    folha->addCell(c3);
    folha->addCell(c4);
    folha->addCell(c5);
    folha->addCell(c6);
    folha->addCell(c7);
    folha->addCell(c8);
    std::cout << *folha;
    c1->setValue(22);
    std::cout << *folha;

    bool comparacao = *c1 < *c2;
    std::cout << "c1: " << *c1 << " < c2: " << *c2
      << " ? answer: " << comparacao << std::endl;

    comparacao = *c2 < *c1;
    std::cout << "c2: " << *c2 << " < c1: " << *c1
      << " ? answer: " << comparacao << std::endl;

    comparacao = *c5 < *c1;
    std::cout << "c5: " << *c5 << " < c1: " << *c1
      << " ? answer: " << comparacao << std::endl;
}

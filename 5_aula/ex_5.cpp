/* Miguel Antão Pereira Amaral 78865 * 4ªa Feira 14h30 */
/* Exercicio 5 C++ */
/* Tables and its Printers */

#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>

class Printer{
public:
  virtual void format(int i) =0;
};

class BracketsPrinter : public Printer {
public:
    void format(int i){
      std::cout << "[ " << i << " ]" << std::endl;
    }
};

class DuplicatePrinter : public Printer {
public:
    void format(int i){
      std::cout << i << i << std::endl;
  }
};

class Table{
  private:
    std::vector<int> _vector;
  public:
    Table(int size) : _vector(size,0) {
      /*zero is the default value*/
    }

    int getValue(int position){
      return _vector[position];
    }

    void setValue(int position, int value){
      _vector[position] = value;
    }

    void setAll(int default_value) {
      unsigned i;
      int size = _vector.size();
      for ( i=0 ; i < size ; i++)
        _vector[i]=default_value;
    }
    void print(Printer &p){
      for (int elem : _vector)
        p.format(elem);
    }
};

#include <random>
int main(){
  int t_size = 7;
  Table t(t_size);
  int i = 0;
  for (i = 0 ; i < t_size ; i++)
    t.setValue(i , rand() % 100);

  DuplicatePrinter d;
  BracketsPrinter b;
  t.print(d);
  printf("\n" );
  t.print(b);
  return 0;
}

#include <iostream>
#include <forward_list>

class crap{
public:
  int _oh1;
  int _oh2;
  crap(int _1, int _2): _oh1(_1),_oh2(_2){}
  friend std::ostream &operator<<(std::ostream &os, const crap &batata) {
      os << "(" << batata._oh1 << ","<< batata._oh2 << ")";
      return os;
    }

};


int main(){
  crap c1(1,1);
  crap c2(2,2);
  crap c3(3,3);
  crap c4(4,4);
  crap c5(5,5);
  crap c6(2,2);


  std::forward_list<crap> mylist;
  for (crap& x: mylist) std::cout << x << '\n';
  mylist.push_front (c1);
  mylist.push_front (c2);
  mylist.push_front (c3);
  mylist.push_front (c4);
  mylist.push_front (c5);
//  mylist.remove(c6);
//
}

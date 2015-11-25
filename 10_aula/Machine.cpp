#include <string>
#include <forward_list>
#include <iostream>


class Machine {
private:
  std::shared_ptr<MachineState> _state = std::make_shared<OpenOffState>( std::make_shared<Machine>());
public:
  void setState(std::shared_ptr<MachineState> state) { _state = state; }

  void power()  { _state->power();}
  void open()   { _state->open(); }
  void tick()   { _state->tick(); }
  void status() { std::cout << _state->status(); }
};

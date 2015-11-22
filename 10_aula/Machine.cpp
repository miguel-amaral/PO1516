
#pragma once
#include <string>
#include "MachineState.cpp"
#include <forward_list>

class Machine {
private:
  std::shared_ptr<MachineState> _state = std::make_shared<MachineState>();
public:
  void setState(std::shared_ptr<MachineState> state) { _state = state; }

  void power() { _state->power();}
  void open()  { _state->open(); }
  void tick()  { _state->tick(); }

  std::string status() { return _state->status(); }
};

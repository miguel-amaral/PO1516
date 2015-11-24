#pragma once
#include "Machine.cpp"

class MachineState{
protected:
  std::shared_ptr<Machine> _machine;
public:
  MachineState(std::shared_ptr<Machine> machine): _machine(machine){}
  virtual std::string status() =0;
  void tick() { /*FIXME*/ }
  void power(){ /*FIXME*/ }
  void open() { /*FIXME*/ }
  void close(){ /*FIXME*/ }
};

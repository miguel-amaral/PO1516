#pragma once
/*#ifndef MACHINE_STATE_H
#define MACHINE_STATE_H*/

/*
#include "Machine.cpp"
#include <forward_list>
class MachineState{
protected:
  std::shared_ptr<Machine> _machine;
public:
MachineState(std::shared_ptr<Machine> machine);
  virtual virtual std::string status() =0;
  virtual void tick();
  virtual void power();
  virtual void open();
  virtual void close();
};
*/

class Machine;
class MachineState;
class OpenOffState;
class CoolingState;
class WashingState;
class ClosedOffState;

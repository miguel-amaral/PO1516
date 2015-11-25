class CoolingState : public MachineState{
private:
  int _tick = 0;
public:
  CoolingState(std::shared_ptr<Machine> machine): MachineState(machine){}
  std::string status() {
    return "(Cooling)\n\tdoor:closed;\n\tmachine:on;\n\t" + " tick value: " +
                                                   std::to_string(_tick); + "\n"
  }
  void tick() {
    if( ++_tick == 120 )
      _machine.setState(std::make_shared<ClosedOffState>(_machine));
  }
};

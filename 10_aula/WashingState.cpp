class WashingState : public MachineState{
private:
  int _tick = 0;
public:
  WashingState(std::shared_ptr<Machine> machine): MachineState(machine){}
  std::string status() {
    return "(Washing)\n\tdoor:closed;\n\tmachine:on;\n\t" + "tick value: " +
                                                   std::to_string(_tick) + "\n";
  }
  void tick() {
    if( ++_tick == 5400 )
      _machine.setState(std::make_shared<Cooling>(_machine));
  }
  void power(){
    _machine.setState(std::make_shared<Cooling>(_machine));
  }
};

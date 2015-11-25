class ClosedOffState : public MachineState{
public:
  ClosedOffState(std::shared_ptr<Machine> machine): MachineState(machine){}
  std::string status() {
    return "(ClosedOff)\n\tdoor:closed;\n\tmachine:off;\n";
  }
  void open() {
    _machine.setState(std::make_shared<OpenOffState>(_machine));
  }
  void power() {
    _machine.setState(std::make_shared<Washing>(_machine));
  }
};

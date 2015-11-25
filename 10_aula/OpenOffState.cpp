class OpenOffState : public MachineState{
public:
  OpenOffState(std::shared_ptr<Machine> machine): MachineState(machine){}
  std::string status() {
    return "(OpenOff)\n\tdoor:open;\n\tmachine:off;\n";
  }
  void close() {
    _machine.setState(std::make_shared<ClosedOffState>(_machine));
  }
};

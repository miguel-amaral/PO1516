class Washing{
protected:
  std::shared_ptr<Machine> _machine;
  int _tick = 0
public:
  MachineState(std::shared_ptr<Machine> machine): _machine(machine){}
  std::string status() { return "Washing: tick value: " + std::toString(_tick);}
  void tick() {
    if( ++_tick == 5400 )
      _machine.setState(std::make_shared<Cooling>(_machine));
  }
  void power(){ /*FIXME*/ }
  void open() { /*FIXME*/ }
  void close(){ /*FIXME*/ }
};

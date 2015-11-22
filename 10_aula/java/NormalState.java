public class NormalState extends MachineState {

    public NormalState(Machine machine) {
        super(machine);
    }

    public void on() {
        _machine.setState(new TestState(_machine));
    }

    public void off() {
        _machine.setState(new WaitState(_machine));
    }

    public void sound() {
        _machine.setState(new AlarmState(_machine));        
    }
}
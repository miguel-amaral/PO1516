public class WaitState extends MachineState {

    public WaitState(Machine machine) {
        super(machine);
    }

    public void on() {
        _machine.setState(new TestState(_machine));
    }

    public void off() {
        _machine.setState(new NormalState(_machine));
    }

    public void sound() {
        
    }
}
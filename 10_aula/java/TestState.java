public class TestState extends MachineState {

    public TestState(Machine machine) {
        super(machine);
    }

    public void on() {
        _machine.setState(new NormalState(_machine));
    }

    public void off() {
        _machine.setState(new WaitState(_machine));
    }

    public void sound() {
        
    }
}
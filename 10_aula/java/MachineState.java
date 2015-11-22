public abstract class MachineState {

    protected Machine _machine;

    public MachineState(Machine machine) {
        _machine = machine;
    }

    public abstract void on();
    public abstract void off();
    public abstract void sound();

    @Override
    public String toString() {
        return getClass().getName();
    }
}
public class Machine {

    private MachineState _state = new NormalState(this);

    public void setState(MachineState state) {
        _state = state;
    }

    public void on() {
        System.out.print(_state + " --(on)-> ");
        _state.on();
        System.out.println(_state);
    }

    public void off() {
        System.out.print(_state + " --(off)-> ");
        _state.off();
        System.out.println(_state);
    }

    public void sound() {
        System.out.print(_state + " --(sound)-> ");
        _state.sound();
        System.out.println(_state);
    }
}
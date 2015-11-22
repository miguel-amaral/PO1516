public class App {
    public static void main(String[] args) {
        Machine m = new Machine();
        m.on();
        m.off();        
        m.off();
        m.sound();
        m.off();
        m.on();
        m.sound();
        m.on();
    }
}
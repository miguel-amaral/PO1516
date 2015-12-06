import java.io.*;

public class App {
    public static void main(String[] args) throws IOException {
        CatOutputChannel channel = new CatOutputChannel(
                                   new DataOutputStream(
                                   new BufferedOutputStream(
                                   new FileOutputStream("cute_cats.dat"))));

        channel.put(new Cat(2, 3.14f, "Tareco"));
        channel.put(new Cat(4, 4.5f, "Pantufa"));

        channel.close();
    }
}
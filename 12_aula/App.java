import java.io.*;

public class App {
    public static void main(String[] args) {
        try {
            CatInputChannel channel  =  new CatInputChannel(  
                                        new DataInputStream(
                                        new BufferedInputStream(
                                        new FileInputStream("cute_cats.dat"))));

            Cat cat1 = channel.get();
            Cat cat2 = channel.get();

            System.out.println(cat1);
            System.out.println(cat2);

            channel.close();
        }
        catch (IOException e) {
            e.printStackTrace();
        }
    }
}
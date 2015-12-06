import java.io.DataInputStream;
import java.io.IOException;

public class CatInputChannel {

    private DataInputStream _stream;

    public CatInputChannel(DataInputStream stream) {
        _stream = stream;
    }

    public Cat get() throws IOException {
        int age = _stream.readInt();
        float weight = _stream.readFloat();
        String name = _stream.readUTF();

        return new Cat(age, weight, name);
    }

    public void close() throws IOException {
        _stream.close();
    }
}
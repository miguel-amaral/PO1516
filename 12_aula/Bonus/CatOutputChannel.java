import java.io.DataOutputStream;
import java.io.IOException;

public class CatOutputChannel {

    DataOutputStream _stream;

    public CatOutputChannel(DataOutputStream stream) {
        _stream = stream;
    }

    public void put(Cat cat) throws IOException {
        int    age    = cat.getAge();
        float  weight = cat.getWeight();
        String name   = cat.getName();

        _stream.writeInt(age);
        _stream.writeFloat(weight);
        _stream.writeUTF(name);
    }

    public void close() throws IOException {
        _stream.close();
    }
}
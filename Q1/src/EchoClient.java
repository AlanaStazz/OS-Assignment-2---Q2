import java.io.BufferedInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.net.Socket;

public class EchoClient {
    public static void main(String args[]){
        try{
            /* Make connection to server */
            Socket sock = new Socket("127.0.0.1", 666);

            InputStream in = sock.getInputStream();
            BufferedInputStream bin = new BufferedInputStream(in);

            /* Read line from the socket */
            String rec;


        } catch(IOException e){
            System.err.println(e);
        }
    }
}

import java.io.IOException;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;

public class EchoServer {
    public static void main(String args[]){
            try {
                ServerSocket sock = new ServerSocket(666);

                /* Listen for connections */
                while (true) {
                    Socket client = sock.accept();

                    PrintWriter out = new PrintWriter(client.getOutputStream(), true);

                    /* Write data to the socket */
                    out.println("TEST");

                    /*Close the socket and start listening again*/
                    client.close();

                }
            } catch(IOException e){
                System.err.println(e);
            }
    }
}

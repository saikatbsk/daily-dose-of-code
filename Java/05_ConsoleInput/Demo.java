/*
 * Inputting password via Console
 */
import java.io.Console;
import java.util.Arrays;

class Demo {
    static String user;
    static char [] password;

    public static void main(String[] args) {
        Console con = System.console();
        if(con == null) {
            System.err.println("Console Object is not available!");
            System.exit(1);
        }

        user = con.readLine("Username: ");
        password = con.readPassword("Password: ");

        if(checkPassword(user, password)) {
            Arrays.fill(password, ' ');  //-- Remove password from memory
            System.out.println("Login Successful");
        }
    }

    static boolean checkPassword(String user, char [] password) {
        return true;
    }
}

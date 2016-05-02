import java.util.Scanner;               //-- Needed to use the Scanner
import java.io.File;                    //-- Needed for file operation
import java.io.FileNotFoundException;   //-- Needed for file operation

/* Another way to handle the FileNotFoundException is by using "try-catch". */
class Demo2 {
    public static void main(String [] args) {
        String line;

        try {
            Scanner in = new Scanner(new File("Sample.txt"));
            // Scanner in = new Scanner(new File("sample.txt")); // Exception

            line = in.nextLine();

            System.out.println(line);
        }
        catch(FileNotFoundException ex) {
            ex.printStackTrace();
        }
    }
}

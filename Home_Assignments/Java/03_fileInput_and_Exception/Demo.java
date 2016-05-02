import java.util.Scanner;               //-- Needed to use the Scanner
import java.io.File;                    //-- Needed for file operation
import java.io.FileNotFoundException;   //-- Needed for file operation

/* One way to handle the FileNotFoundException is by using "throws". */
class Demo {
    public static void main(String [] args)
    throws FileNotFoundException {      //-- Declare "throws" here.
        String line;

        Scanner in = new Scanner(new File("Sample.txt"));
        // Scanner in = new Scanner(new File("sample.txt")); // Exception

        line = in.nextLine();

        System.out.println(line);
    }
}

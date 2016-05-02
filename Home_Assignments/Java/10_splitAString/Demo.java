import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;

public class Demo {
    public static void main(String []args) throws FileNotFoundException {
        String Name[] = new String[100];
        int Age[]     = new int[100];
        double Wage[] = new double[100];

        Scanner in = new Scanner(new File("file.txt"));

        int i = 0;

        while(in.hasNextLine()) {
            String line = in.nextLine();
            String tokens[] = line.split("#");

            Name[i] = tokens[0];
            Age[i]  = Integer.parseInt(tokens[1]);
            Wage[i] = Double.parseDouble(tokens[2]);

            i = i + 1;
        }

        for(int j = 0 ; j < i ; j++) {
            System.out.println(Name[j] + " " + Age[j] + " " + Wage[j]);
        }
     }
}

/* Java supports 3 standard input/output streams:
 *      1. System.in (standard input device)
 *      2. System.out (standard output device)
 *      3. System.err (standard error device)
 *
 * System.in is defaulted to the keyboard, while System.out and System.err is
 * defaulted to the console. They can be redirected to other devices.
 */

import java.util.Scanner;       //-- Needed to use the Scanner

class Demo {
    public static void main(String [] args) {
        int num1;
        double num2;
        String str1;
        String str2;

        Scanner in = new Scanner(System.in);
        Scanner in_ = new Scanner(System.in);

        System.out.println("Enter an integer");
        num1 = in.nextInt();        //-- Read an int
        System.out.println(num1);

        System.out.println("Enter a double");
        num2 = in.nextDouble();     //-- Read a double
        System.out.println(num2);

        /* Use next() to read a String token, up to white space */
        System.out.println("Enter a string");
        str1 = in.next();
        System.out.println(str1);

        /*
         * Use nextLine() to read entire line including white spaces,
         * but excluding the terminating newline.
         */
        System.out.println("Enter another string");
        str2 = in_.nextLine();
        System.out.println(str2);

        in.close();
        in_.close();
    }
}

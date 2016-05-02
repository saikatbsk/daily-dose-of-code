/*
 * The Java Swing API provides a way to implement GUI applications using Java
 * in a platform independent way.
 *
 * This example demonstrates the use of JOptionPane to create a dialog box.
 */

import javax.swing.JOptionPane;

class Demo {
    public static void main(String [] args) {
        final double PI = 3.14159265359;
        String radStr;
        double rad, area;

        /* Read an input string from dialog box */
        radStr = JOptionPane.showInputDialog("Enter the radius:");

        rad = Double.parseDouble(radStr);
        area = rad * rad * PI;

        System.out.println("Area of the circle is " + area);
    }
}

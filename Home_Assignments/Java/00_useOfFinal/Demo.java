/*
 * A variable declared with the final keyword is a constant or a non-modifiable
 * variable.
 * --- Their values cannot be changed during program execution.
 * --- Also constants must be initialized during declaration.
 *
 * The final keyword can be used in following contexts:
 *      1. a variable
 *      2. a method
 *      3. a class
 *
 * --- A final method cannot be overridden.
 * --- A final class cannot be extended.
 */

final class Demo {
    // final double PI;     //-- WRONG! We must initialize.
    final double PI = 3.14159265359;

    /* The following method is final. It cannot be overridden. */
    final double getPI() {
        return PI;
    }

    /* --- The following results in compilation error. Because we cannot assign
           a new value to a final variable.

    void setPI(double val) {
        PI = val;
    }

    --- */

    public static void main(String [] args) {
        Demo obj = new Demo();
        // obj.setPI(3.142);    //-- Cannot do this.

        System.out.println("PI = " + obj.getPI());
    }
}

/* --- The following lines of code results in compilation error. Because the
       final method getPI() cannot be overridden.

class Demo1 extends Demo {
    double getPI() {}
}

--- */

/* --- The following lines of also code results in compilation error. Because
       final class Demo cannot be extended.

class Demo1 extends Demo {}

--- */

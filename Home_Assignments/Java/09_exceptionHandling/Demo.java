import java.lang.ArithmeticException;

public class Demo {
    int numToDivide;
    int numToDivideBy;

    Demo() {}

    Demo(int numToDivide, int numToDivideBy) {
        this.numToDivide = numToDivide;
        this.numToDivideBy = numToDivideBy;
    }

    public double divide() throws ArithmeticException {
        if(numToDivideBy == 0)
            throw new ArithmeticException("Cannot divide by zero!");

        return numToDivide / numToDivideBy;
    }

    public static void main(String [] args) {
        Demo obj = null;

        try {
            obj = new Demo(8, 0);
            System.out.println(obj.divide());
        }
        catch (ArithmeticException ex) {
            System.out.println("Arithmetic exception caught! cannot divide by 0.");
            ex.printStackTrace();
        }
        finally {
            //-- Rest of the code
        }
    }
}

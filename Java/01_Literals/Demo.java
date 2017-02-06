/* Literals are specific constant values, such as 123, -49, 'a', "hello world".
 * --- Literals are constant values that can be directly assigned to variables,
 * --- or can be used as part of an expression.
 */

class Demo {
    public static void main(String [] args) {
        String name = "Basak";          //-- String is double-quoted
        char gender = 'm';              //-- char is single-quoted
        boolean isMarried = false;      //-- true or false
        byte numChildren = 0;           //-- Range of byte is [-127, 128]
        short yearOfBirth = 1990;       //-- Range of short is [-32767, 32768]. Beyond byte
        int salary = 88700;             //-- Beyond the ranges of byte and short
        long netAsset = 8234567890L;    //-- Need suffix 'L' for long. Beyond int
        double weight = 59;             //-- With fractional part
        float gpa = 7.0f;               //-- Need suffix 'f' for float

        /* println() can be used to print value of any type */
        System.out.println("Name is " + name);
        System.out.println("Gender is " + gender);
        System.out.println("Is married is " + isMarried);
        System.out.println("Number of children is " + numChildren);
        System.out.println("Year of birth is " + yearOfBirth);
        System.out.println("Salary is " + salary);
        System.out.println("Net Asset is " + netAsset);
        System.out.println("Weight is " + weight);
        System.out.println("GPA is " + gpa);
    }
}

import java.io.*;

public class StudentTest {
    public static void main(String [] args) {
      Student stu1 = new Student("Avishikta Lodh");
      Student stu2 = new Student("Upasana Maity");

      stu1.Dept("IT");
      stu1.Year(1);
      stu1.Roll(13);
      stu1.Marks(78, 87);
      stu1.Display();

      stu2.Dept("MMD");
      stu2.Year(1);
      stu2.Roll(5);
      stu2.Marks(87, 78);
      stu2.Display();
    }
}

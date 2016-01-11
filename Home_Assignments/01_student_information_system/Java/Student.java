import java.io.*;

public class Student {
    String name;
    String dept;
    int year;
    int roll;
    int sub1, sub2;

    public Student(String stuName){
        this.name = stuName;
    }

    public void Dept(String stuDept){
        dept =  stuDept;
    }

    public void Year(int stuYear){
        year = stuYear;
    }

    public void Roll(int stuRoll){
        roll = stuRoll;
    }

    public void Marks(int stuSub1, int stuSub2) {
        sub1 = stuSub1;
        sub2 = stuSub2;
    }

    public void Display(){
        System.out.println("Name: " + name);
        System.out.println("Dept: " + dept);
        System.out.println("Year: " + year);
        System.out.println("Roll: " + roll);
        System.out.println("Marks in Sub1: " + sub1);
        System.out.println("Marks in Sub2: " + sub2);
    }
}

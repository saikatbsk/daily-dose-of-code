class Test {
    public static void main(String [] args) {
        Point pt1 = new Point(3, 2);
        Point pt2 = new Point(9, 7);

        double d = pt1.getDistanceFrom(pt2);
        System.out.println("Distance from pt1 to pt2 is = " + d);
    }
}

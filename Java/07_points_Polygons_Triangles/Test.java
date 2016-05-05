class Test {
    public static void main(String [] args) {
        Point pt1 = new Point(3, 2);
        Point pt2 = new Point(9, 7);

        double d = pt1.getDistanceFrom(pt2);
        System.out.println("Distance from pt1 to pt2 is = " + d);

        Point pts[] = new Point[4];
        pts[0] = new Point(5, 1);
        pts[1] = new Point(5, 5);
        pts[2] = new Point(1, 4);
        pts[3] = new Point(2, 1);

        SimplePolygon poly = new SimplePolygon(pts);
        System.out.println("Peremeter of the Polygon = " + poly.getPerimeter());

        Point pts2[] = new Point[3];
        pts2[0] = new Point(5, 1);
        pts2[1] = new Point(5, 5);
        pts2[2] = new Point(1, 4);

        Triangle triangle = new Triangle(pts2, false);
        System.out.println("Peremeter of the Triangle = " + triangle.getPerimeter());

        Point pts3[] = new Point[3];
        pts3[0] = new Point(0, 0);
        pts3[1] = new Point(6, 0);
        pts3[2] = new Point(3, 5.196);

        Triangle triangle_eq = new Triangle(pts3, true);
        System.out.println("Peremeter of the Triangle = " + triangle_eq.getPerimeter());
    }
}

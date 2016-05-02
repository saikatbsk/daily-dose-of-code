class SimplePolygon {
    Point points[]= new Point[100];
    int numOfPoints;
    double perimeter;

    SimplePolygon() {}

    SimplePolygon(Point pts[]) {
        numOfPoints = pts.length;
        for(int i = 0 ; i < numOfPoints ; i++) {
            points[i] = pts[i];
        }
    }

    double getPerimeter() {
        int i, j;
        double d;

        for(i = 0 ; i < numOfPoints ; i++) {
            if(i == numOfPoints - 1)
                j = 0;
            else
                j = i + 1;

            d = points[i].getDistanceFrom(points[j]);
            perimeter = perimeter + d;
        }

        return perimeter;
    }
}

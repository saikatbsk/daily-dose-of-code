class Triangle extends SimplePolygon {
    boolean isEquilateral;

    Triangle(Point pts[], boolean isEquilateralTriangle) {
        isEquilateral = isEquilateralTriangle;
        numOfPoints = 3;

        for(int i = 0 ; i < numOfPoints ; i++) {
            points[i] = pts[i];
        }
    }

    double getPerimeter() {
        if(isEquilateral == true) {
            perimeter = points[0].getDistanceFrom(points[1]) * 3;
        }
        else
            super.getPerimeter();

        return perimeter;
    }
}

class DemoExtended extends Demo {
    int c;

    DemoExtended(int a, int b, int c) {
        super(a, b);
        this.c = c;
    }

    @Override
    void display() {
        System.out.println(a + " " + b + " " + c);
    }

    public static void main(String [] args) {
        DemoExtended obj = new DemoExtended(2, 3, 4);
        obj.display();
    }
}

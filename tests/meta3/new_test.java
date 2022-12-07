class AA {
    public static void main() {
        b = true;
        a = 1;
        f();
        f(1);
        fa(1,2);
        AA();
    }   

    public static boolean b;
    public static int a;

    public static void AA() {
        // declaration
    }

    public static void f() {
        // declaration
    }
    public static int f(int c) {
        // declaration
        c = 4;
        return c;
    }

    public static double f(int t, int d) {
        // declaration
    }

    public static boolean fa(int t, int d) {
        // declaration
    }
}
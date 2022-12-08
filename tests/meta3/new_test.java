class AA {
    public static int main() {
        b = true;
        a = 1;
        a = 1+3;
        f();
        f(1);
        fa(1,2);
        AA();
        f(1,2,3);
    }   

    public static boolean b;
    public static int a;
    public static int f;

    public static int AA() {
        // declaration
    }

    public static boolean f(int c) {
        // declaration
        c = 4;
        return c;
    }
    public static void f() {
        // declaration
    }

    public static double f(int t, int d) {
        // declaration
    }

    public static boolean fa(int t, int d) {
        // declaration;
    }

  
    public static boolean f(int t, int d,double k) {
        // declaration
    }
    public static void f(int t, double d,double k) {
        // declaration
    }
}
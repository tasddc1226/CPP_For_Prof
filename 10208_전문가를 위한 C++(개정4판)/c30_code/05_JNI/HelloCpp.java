public class HelloCpp {

    static {
        System.loadLibrary("hellocpp");
    }

    // �� �޼���� C++�� �����Ѵ�.
    public static native void callCpp();

    public static void main(String[] args)
    {
        System.out.println("Hello from Java!");
        callCpp();
    }
}

public class HelloCpp {

    static {
        System.loadLibrary("hellocpp");
    }

    // 이 메서드는 C++로 구현한다.
    public static native void callCpp();

    public static void main(String[] args)
    {
        System.out.println("Hello from Java!");
        callCpp();
    }
}

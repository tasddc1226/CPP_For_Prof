class X {};
class Y {};

int main()
{
	X x;
	Y y;

	X* xp = &x;
	Y* yp = &y;

	// 관련 없는 클래스의 포인터를 변환할 때는 reinterpret_cast()를 사용해야 한다.
	// static_cast로는 할 수 없다.
	xp = reinterpret_cast<X*>(yp);

    // 포인터를 void*로 변환할 때는 캐스팅할 필요 없다.
    void* p = xp;
    // void*를 포인터로 변환할 때는 reinterpret_cast()를 사용해야 한다.
    xp = reinterpret_cast<X*>(p);

	// 관련 없는 클래스의 레퍼런스를 변환할 때는 reinterpret_cast()를 사용해야 한다.
	// static_cast로는 할 수 없다.
	X& xr = x;
	Y& yr = reinterpret_cast<Y&>(x);

	return 0;
}

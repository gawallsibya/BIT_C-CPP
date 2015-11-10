#include <iostream>
using namespace std;

class Rect
{
	int left, top, right, bottom;

public:
	Rect() {}
	Rect(int a, int b, int c, int d) : left(a), top(b), right(c), bottom(d)
	{
	}

	int GetArea()
	{
		return (right - left) * (bottom - top);
	}

	bool PtInRect(int x, int y)
	{
		if ( left < x && right > x && top  < y && bottom > y )
			 return true;
		return false;
	}

	void print()
	{
		cout << left << ", " << top << " ~ " << right << ", " << bottom << endl;
	}

	void InflateRect(int dx, int dy)
	{
		right  += dx;
		bottom += dy;
	}
};

void main()
{
	Rect r (10,10,20,20);

	r.InflateRect(10, 10);
	r.print();

	int s = r.GetArea();

	if ( r.PtInRect(15, 15))
		cout << "(15,15) is In r" << endl;
}
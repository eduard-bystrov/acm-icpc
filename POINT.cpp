struct Point
{
	typedef long double longd;
	typedef longd vartype;
	const longd EPS = 1e-9;
	/*
	vartype D  = (v1*v1)*(v2*v2) - (v1*v2)*(v2*v1);
	vartype k1 = (-(v2*v2)*(v1*p)+(v2*v1)*(v2*p)) / D;
	vartype k2 = ( (v1*v1)*(v2*p)-(v1*v2)*(v1*p)) / D;
	*/
	vartype x, y;
	Point() {}
	Point(vartype x, vartype y) : x(x), y(y) {}
	longd len() const
	{
		return sqrt(x*x + y*y);
	}
	vartype len2() const
	{
		return x*x + y*y;
	}
	longd aatan2() const
	{
		return atan2(y, x);
	}
	longd getAngle(const Point& v2) const
	{
		return (*(this)*v2) / (len()*v2.len());
	}
	vartype vp(const Point& v2) const
	{
		return x*v2.y - y*v2.x;
	}
	int turn(const Point& v2) const
	{
		vartype res = vp(v2);
		if (abs(res) <= EPS) return 0;
		if (res > 0) return 1;
		if (res < 0) return -1;
		return 0;
	}
	vartype getKFract(const Point& v2) const
	{
		return (*(this)*v2);
	}
	longd getK(const Point& v2) const
	{
		return getKFract(v2) / (longd)len2();
	}
	Point projection(const Point& v2) const
	{
		return *(this)*getK(v2);
	}
	Point rotate(const longd q) const
	{
		Point t(x, y);
		int f = (q >= 0 ? 1 : -1);
		t.x = x*cos(q) + y*sin(q)*f;
		t.y = -sin(q)*x*f + y*cos(q);
		return t;
	}
	Point rotateInt(const int q) const
	{
		Point t(x, y);
		if (q == 0) return t;
		if (q == 90) { swap(t.x, t.y); t.x = -t.x; }
		else if (q == -90) { swap(t.x, t.y); t.y = -t.y; }
		else if (q == 180) { t.x = -t.x; t.y = -t.y; }
		return t;
	}

	Point operator = (const Point v2)
	{
		this->x = v2.x;
		this->y = v2.y;
		return *this;
	}
	friend Point operator * (const Point& v1, const vartype num)
	{
		return Point(v1.x*num, v1.y*num);
	}
	friend Point operator / (const Point& v1, const vartype num)
	{
		return Point(v1.x / (longd)num, v1.y / (longd)num);
	}
	friend vartype operator * (const Point& v1, const Point& v2)
	{
		return v1.x*v2.x + v1.y*v2.y;
	}
	friend Point operator + (const Point& v1, const Point& v2)
	{
		return Point(v1.x + v2.x, v1.y + v2.y);
	}
	friend Point operator - (const Point& v1, const Point& v2)
	{
		return Point(v1.x - v2.x, v1.y - v2.y);
	}
	friend Point operator - (const Point& v1)
	{
		return Point(-v1.x, -v1.y);
	}
	friend bool operator == (const Point& v1, const Point& v2)
	{
		return v1.x == v2.x&&v1.y == v2.y;
	}
	friend bool operator != (const Point& v1, const Point& v2)
	{
		return !(v1 == v2);
	}
	friend istream& operator >> (istream& in, Point& ptr)
	{
		return in >> ptr.x >> ptr.y;
	}
};
typedef Point Vector;

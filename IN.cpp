struct IN
{
	template<typename T>
	friend IN& operator >> (IN& in, T& a)
	{
		if (typeid(a) == typeid(char))
		{
			scanf("%c", &a);
		}
		else if (typeid(a) == typeid(short int))
		{
			scanf("%hi", &a);
		}
		else if (typeid(a) == typeid(unsigned short int))
		{
			scanf("%hu", &a);
		}
		else if (typeid(a) == typeid(int))
		{
			scanf("%d", &a);
		}
		else if (typeid(a) == typeid(unsigned int))
		{
			scanf("%u", &a);
		}
		else if (typeid(a) == typeid(long int))
		{
			scanf("%li", &a);
		}
		else if (typeid(a) == typeid(long long int))
		{
			scanf("%I64", &a);
		}
		else if (typeid(a) == typeid(unsigned long long int))
		{
			scanf("%llu", &a);
		}
		else if (typeid(a) == typeid(float))
		{
			scanf("%f", &a);
		}
		else if (typeid(a) == typeid(double))
		{
			scanf("%lf", &a);
		}
		else if (typeid(a) == typeid(long double))
		{
			scanf("%Lf", &a);
		}
		else cin >> a;
		return in;
	}
} In;
#define cin In

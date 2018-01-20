int SS = 1e7;
vector<bool> isprime(SS + 1, true);
vector<int> prime;

void INIT()
{
	isprime[0] = isprime[1] = false;
	for (int i = 2; i <= SS; ++i)
		if (isprime[i])
		{
			prime.push_back(i);
			if (i * 1ll * i <= SS)
				for (int j = i*i; j <= SS; j += i)
					isprime[j] = false;
		}
			
}
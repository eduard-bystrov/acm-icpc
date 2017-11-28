struct Vertex
{
	Vertex() : vec(N, -1) {};

	bool firstPlay = false;
	bool secondPlay = false;
	bool leaf = false;
	
	vector<int> vec;
};

vector<Vertex> bor;

void AddString(const string& str)
{
	int v = 0;

	for (const char& ch : str)
	{
		int c = ch - 'a';

		if (bor[v].vec[c] == -1)
		{
			bor[v].vec[c] = bor.size();
			bor.push_back(Vertex());
		}

		v = bor[v].vec[c];
	}

	bor[v].leaf = true;
}

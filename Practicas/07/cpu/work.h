const int N = 3<<4;

int v1[N][N*N], v2[N*N][N*N], v3[N][N*N];

void work(int begin, int end)
{
	for (int i = begin; i < end; ++i)
		for (int k = 0; k < N * N; ++k)
			for (int j = 0; j < N * N; ++j)
				v3[i][j] += v1[i][k] * v2[k][j];
}


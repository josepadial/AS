// optimal number of threads

#include <future>
#include "work.h"

int main()
{
	const int T = std::thread::hardware_concurrency();
	
	std::future<void> f[T]; // to avoid ~future calling wait()
	
	for (int i = 0; i < T; ++i)
		f[i] = std::async(work, i * (N / T), (i + 1) * (N / T));
}

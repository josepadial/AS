#include <fstream>
#include <string>

const int N = 1<<9;

void work(int begin, int end)
{
	for (int i = begin; i < end; ++i)
	{
		std::fstream file("/tmp/" + std::to_string(i) + ".txt");
		file << "cognito, ergo sum!" << std::endl;
	}
}


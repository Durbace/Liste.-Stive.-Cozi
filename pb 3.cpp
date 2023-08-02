#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <cmath>
#include <fstream>
void BucketSort(std::vector<float>& v)
{
	int n = v.size();
	std::vector<std::list<float>> buckets(n);
	for (int i = 0; i < n; i++)
	{
		int bucket_idx = floor(v[i] * n);
		buckets[bucket_idx].push_back(v[i]);
	}
	for (int i = 0; i < n; i++)
		buckets[i].sort();
	int index = 0;
	for (int i = 0; i < n; i++)
		for (float elem : buckets[i])
			v[index++] = elem;
}
int main()
{
	std::vector<float> v;
	float nr;
	std::ifstream f("input.txt");
	while (f >> nr)
		v.push_back(nr);
	f.close();
	BucketSort(v);
	for (float elem : v)
	{
		std::cout << elem << " ";
	}
	std::cout << std::endl;
	return 0;
}

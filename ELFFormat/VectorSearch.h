#include <cstdint>
#include <vector>
#include <algorithm>

template <typename T, class L>
T* findInVector(const std::vector<T>& elements, L lambda)
{
	auto indexFound = std::find_if(elements.begin(), elements.end(), lambda);

	if (indexFound != elements.end())
	{
		const uint32_t index = indexFound - elements.begin();
		return (T*)&elements[index];
	}

	return NULL;
}
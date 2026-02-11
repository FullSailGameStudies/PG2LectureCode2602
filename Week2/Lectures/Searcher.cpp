#include "Searcher.h"

//
// Part B-1
//

int Searcher::LinearSearch(const std::vector<Light>& lights, int greenToFind) const
{
	int index = NOT_FOUND;
	for (int i = 0; i < lights.size(); i++)
	{
		if (lights[i].green == greenToFind)
		{
			index = i;
			break;
		}
	}
	return index;
}

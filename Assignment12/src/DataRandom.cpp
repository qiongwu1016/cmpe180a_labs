#include <stdlib.h>
#include <time.h>
#include "DataRandom.h"
#include "Element.h"

void DataRandom::generate_data(vector<Element>& data, int size)
{
    data.clear();

    // Reuse previously generated random data.
    if (random_data.size() == size)
    {
        data = random_data;
    }

    // Generate new random data.
    else
    {
        random_data.clear();
        srand(time(NULL));  // seed the random number generator

        for (int i = 0; i < size; i++)
        {
            long r = rand()%size;
            Element elmt(r);
            random_data.push_back(elmt);
            data.push_back(elmt);
        }
    }
}

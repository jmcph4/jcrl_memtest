#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "constants.h"
#include "macros.h"
#include "multiset.h"

int main(int argc, char** argv)
{
    if(argc != 2)
    {
        fprintf(stderr, "Usage: %s n\n", argv[0]);
        return EXIT_FAILURE;
    }

    unsigned int n = atoi(argv[1]);

    unsigned int res = 0;

    Multiset multiset;
    
    res = multiset_init(&multiset);

    if(res != JCRL_ERR_OK)
    {
        fprintf(stderr, "[ERROR] Failed to initialise multiset. JCRL returned:"
                "%d\n", res);
        return EXIT_FAILURE;
    }

    for(unsigned int i=0;i<n;i++)
    {
        res = multiset_add(G_INT(i), &multiset);

        if(res != JCRL_ERR_OK)
        {
            fprintf(stderr, "[ERROR] Failed to append item %d to multiset. JCRL"
                    "returned: %d\n", i, res);
            return EXIT_FAILURE;
        }
    }

    res = multiset_free(NULL, &multiset);

    if(res != JCRL_ERR_OK)
    {
        fprintf(stderr, "[ERROR] Failed to free multiset. JCRL returned %d\n",
                res);
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}


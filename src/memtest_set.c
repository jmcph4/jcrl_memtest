#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "constants.h"
#include "macros.h"
#include "set.h"

int main(int argc, char** argv)
{
    if(argc != 2)
    {
        fprintf(stderr, "Usage: %s n\n", argv[0]);
        return EXIT_FAILURE;
    }

    unsigned int n = atoi(argv[1]);

    unsigned int res = 0;

    Set set;
    
    res = set_init(&set);

    if(res != JCRL_ERR_OK)
    {
        fprintf(stderr, "[ERROR] Failed to initialise set. JCRL returned:"
                "%d\n", res);
        return EXIT_FAILURE;
    }

    for(unsigned int i=0;i<n;i++)
    {
        res = set_add(G_INT(i), &set);

        if(res != JCRL_ERR_OK)
        {
            fprintf(stderr, "[ERROR] Failed to append item %d to set. JCRL"
                    "returned: %d\n", i, res);
            return EXIT_FAILURE;
        }
    }

    res = set_free(NULL, &set);

    if(res != JCRL_ERR_OK)
    {
        fprintf(stderr, "[ERROR] Failed to free set. JCRL returned %d\n",
                res);
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}


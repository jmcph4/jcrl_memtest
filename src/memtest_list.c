#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "constants.h"
#include "macros.h"
#include "list.h"

int main(int argc, char** argv)
{
    if(argc != 2)
    {
        fprintf(stderr, "Usage: %s n\n", argv[0]);
        return EXIT_FAILURE;
    }

    unsigned int n = atoi(argv[1]);

    unsigned int res = 0;

    List list;
    
    res = list_init(&list);

    if(res != JCRL_ERR_OK)
    {
        fprintf(stderr, "[ERROR] Failed to initialise list. JCRL returned: %d\n", res);
        return EXIT_FAILURE;
    }

    for(unsigned int i=0;i<n;i++)
    {
        res = list_append(G_INT(i), &list);

        if(res != JCRL_ERR_OK)
        {
            fprintf(stderr, "[ERROR] Failed to append item %d to list. JCRL returned: %d\n", i, res);
            return EXIT_FAILURE;
        }
    }

    res = list_free(NULL, &list);

    if(res != JCRL_ERR_OK)
    {
        fprintf(stderr, "[ERROR] Failed to free list. JCRL returned %d\n", res);
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}


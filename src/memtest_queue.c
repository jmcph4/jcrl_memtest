#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "constants.h"
#include "macros.h"
#include "queue.h"

int main(int argc, char** argv)
{
    if(argc != 2)
    {
        fprintf(stderr, "Usage: %s n\n", argv[0]);
        return EXIT_FAILURE;
    }

    unsigned int n = atoi(argv[1]);

    unsigned int res = 0;

    Queue queue;
    
    res = queue_init(&queue);

    if(res != JCRL_ERR_OK)
    {
        fprintf(stderr, "[ERROR] Failed to initialise queue. JCRL returned: %d\n", res);
        return EXIT_FAILURE;
    }

    for(unsigned int i=0;i<n;i++)
    {
        res = queue_push(G_INT(i), &queue);

        if(res != JCRL_ERR_OK)
        {
            fprintf(stderr, "[ERROR] Failed to append item %d to queue. JCRL returned: %d\n", i, res);
            return EXIT_FAILURE;
        }
    }

    res = queue_free(NULL, &queue);

    if(res != JCRL_ERR_OK)
    {
        fprintf(stderr, "[ERROR] Failed to free queue. JCRL returned %d\n", res);
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}


#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "constants.h"
#include "macros.h"
#include "stack.h"

int main(int argc, char** argv)
{
    if(argc != 2)
    {
        fprintf(stderr, "Usage: %s n\n", argv[0]);
        return EXIT_FAILURE;
    }

    unsigned int n = atoi(argv[1]);

    unsigned int res = 0;

    Stack stack;
    
    res = stack_init(&stack);

    if(res != JCRL_ERR_OK)
    {
        fprintf(stderr, "[ERROR] Failed to initialise stack. JCRL returned: %d\n", res);
        return EXIT_FAILURE;
    }

    for(unsigned int i=0;i<n;i++)
    {
        res = stack_push(G_INT(i), &stack);

        if(res != JCRL_ERR_OK)
        {
            fprintf(stderr, "[ERROR] Failed to push item %d onto stack. JCRL returned: %d\n", i, res);
            return EXIT_FAILURE;
        }
    }

    res = stack_free(NULL, &stack);

    if(res != JCRL_ERR_OK)
    {
        fprintf(stderr, "[ERROR] Failed to free stack. JCRL returned %d\n", res);
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}


#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "constants.h"
#include "macros.h"
#include "digraph.h"

int main(int argc, char** argv)
{
    if(argc != 3)
    {
        fprintf(stderr, "Usage: %s v e\n", argv[0]);
        return EXIT_FAILURE;
    }

    unsigned int v = atoi(argv[1]);
    unsigned int e = atoi(argv[2]);

    unsigned int res = 0;

    Digraph digraph;
    
    res = digraph_init(&digraph);

    if(res != JCRL_ERR_OK)
    {
        fprintf(stderr, "[ERROR] Failed to initialise directed graph. "
                "JCRL returned: %d\n", res);
        return EXIT_FAILURE;
    }

    unsigned int v_num = 0;
    unsigned int e_num = 0;

    for(unsigned int i=0;i<v;i++)
    {
        res = digraph_vertex_insert(G_INT(i), &v_num, &digraph);

        if(res != JCRL_ERR_OK)
        {
            fprintf(stderr, "[ERROR] Failed to insert vertex %d into directed"
                    " graph JCRL returned: %d\n", i, res);
            return EXIT_FAILURE;
        }
    }
    
    for(unsigned int i=0;i<e;i++)
    {
        res = digraph_connect(G_INT(i), i % v, (i + 1) % v, &e_num, &digraph);

        if(res != JCRL_ERR_OK)
        {
            fprintf(stderr, "[ERROR] Failed to insert edge %d into directed"
                    " graph JCRL returned: %d\n", i, res);
            return EXIT_FAILURE;
        }
    }

    res = digraph_free(NULL, &digraph);

    if(res != JCRL_ERR_OK)
    {
        fprintf(stderr, "[ERROR] Failed to free directed graph. "
                "JCRL returned %d\n", res);
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}


#include "monty.h"

void pint_error(unsigned int line)
{
        char *postfix = ": can't pint, stack empty";

        write(2, "L", 1);
        write(2, &line, 5);
        write(2, postfix, strlen(postfix));
}

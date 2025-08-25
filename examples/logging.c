#include <stdio.h>
#include "../logging.h"

int main()
{
    LOG("This is a log message");
    ERROR("This is an error message");
    WARN("This is a warning message");
    INFO("This is an info message");
    DEBUG("This is a debug message");
    TODO("This is a todo message");

    int x = 5;
    ASSERT(x == 5, "x should be 5");
    ASSERT(x != 5, "x should not be 5"); // This will trigger the assertion

    return 0;
}

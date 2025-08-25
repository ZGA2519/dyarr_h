// filepath: /Users/organ/Desktop/Code/utillib/examples/struct_array.c
#include "../dyarr.h"
#include <stdio.h>

/*
    This program demonstrates the usage of dynamic arrays with structs in C.
    It defines a `Person` struct, creates a dynamic array of `Person` structs,
    adds some entries, prints them, removes one entry, and prints the array again.
*/

typedef struct {
    int id;
    char name[32];
} Person;

int main() {
    Person *people = NULL;

    // Add some people
    arrpush(people, ((Person){1, "Alice"}));
    arrpush(people, ((Person){2, "Bob"}));
    arrpush(people, ((Person){3, "Charlie"}));

    // Print all people
    for (size_t i = 0; i < arrlen(people); i++) {
        printf("Person %zu: id=%d, name=%s\n", i, people[i].id, people[i].name);
    }

    // Remove the second person (Bob)
    arrdel(people, 1);

    printf("\nAfter deletion:\n");
    for (size_t i = 0; i < arrlen(people); i++) {
        printf("Person %zu: id=%d, name=%s\n", i, people[i].id, people[i].name);
    }

    arrfree(people);
    return 0;
}
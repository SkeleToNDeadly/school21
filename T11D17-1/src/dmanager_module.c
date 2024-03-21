#include <stdio.h>
#include <stdlib.h>

#include "door_struct.h"

#define DOORS_COUNT 15
#define MAX_ID_SEED 10000

void initialize_doors(struct door* doors);

int main() {
    struct door doors[DOORS_COUNT];

    initialize_doors(doors);

    // Sort doors by ID
    sort_doors(doors, DOORS_COUNT);

    for (int i = 0; i < DOORS_COUNT; i++) {
        printf("%d, %d\n", doors[i].id, doors[i].status);
    }

    return 0;
}

// Doors initialization function
// ATTENTION!!!
// DO NOT CHANGE!
void initialize_doors(struct door* doors) {
    for (int i = 0; i < DOORS_COUNT; i++) {
        doors[i].id = (i) % DOORS_COUNT;
        doors[i].status = 0;
    }
}

void sort_doors(struct door* doors, int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (doors[j].id > doors[j + 1].id) {
                struct door temp = doors[j];
                doors[j] = doors[j + 1];
                doors[j + 1] = temp;
            }
        }
    }
}

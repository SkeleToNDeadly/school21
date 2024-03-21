#ifndef DOOR_STRUCT_H
#define DOOR_STRUCT_H

struct door {
    int id;
    int status; // 0 - закрыто, 1 - открыто
};

void sort_doors(struct door* doors, int count);

#endif

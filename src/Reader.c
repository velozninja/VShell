#include  <stdio.h>
#include  "MemoryRam.h"
#include  <string.h>
#include "CPU.h"
#include  "DISK.h"


int reader(int argc, char *argv[]) {
    if (argc < 3) {
        return 1;
    }
    char *category = argv[1];
    char *command = argv[2];

    if (strcmp(category, "system") == 0) {
        if (strcmp(command, "ram") == 0) {
            memory();
        }
        else if (strcmp(command, "cpu") == 0) {
            cpu();

        }
        else if (strcmp(command, "disk") == 0) {
            disk();
            
        }
    }

}
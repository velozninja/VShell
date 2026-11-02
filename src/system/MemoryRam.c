

#include <windows.h>
#include "MemoryRam.h"
#include <stdio.h>
int memory(void) {
    MEMORYSTATUSEX mem = {0};
    mem.dwLength = sizeof(mem);
    if (!GlobalMemoryStatusEx(&mem)) {
        return 1;
    }
    double total = mem.ullTotalPhys / 1073741824.0;
    double avaliable = mem.ullAvailPhys / 1073741824.0;
    double used =  total - avaliable;

    printf("Ram Total: %.2f GB\n", total);
    printf("Ram usada: %.2f GB\n", used);
    printf("Ram disponivel: %.2f GB\n", avaliable);
    printf("Uso: %lu%%\n", mem.dwMemoryLoad);
    return 0;
}
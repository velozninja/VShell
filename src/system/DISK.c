#include <stdio.h>
#include <windows.h>
#include "DISK.h"

void disk(void) {
    ULARGE_INTEGER available;
    ULARGE_INTEGER total;
    ULARGE_INTEGER free;

    if (!GetDiskFreeSpaceExA(
        "C:\\",
        &available,
        &total,
        &free
    )) {
        printf("Erro ao consultar disco.\n");
        return;
    }

    double totalGB = total.QuadPart / 1073741824.0;
    double usedGB = (total.QuadPart - free.QuadPart) / 1073741824.0;
    double availableGB = available.QuadPart / 1073741824.0;

    printf("Disco C:\\\n");
    printf("Total: %.2f GB\n", totalGB);
    printf("Usado: %.2f GB\n", usedGB);
    printf("Disponivel: %.2f GB\n", availableGB);
}
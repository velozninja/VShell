#include <stdio.h>
#include <windows.h>
#include "CPU.h"

void cpu(void) {
    FILETIME idle1, kernel1, user1;
    FILETIME idle2, kernel2, user2;

    // Primeira leitura
    if (!GetSystemTimes(&idle1, &kernel1, &user1)) {
        printf("Erro ao consultar CPU.\n");
        return;
    }

    // Espera 1 segundo
    Sleep(1000);

    // Segunda leitura
    if (!GetSystemTimes(&idle2, &kernel2, &user2)) {
        printf("Erro ao consultar CPU.\n");
        return;
    }

    ULARGE_INTEGER i1, k1, u1;
    ULARGE_INTEGER i2, k2, u2;

    i1.LowPart = idle1.dwLowDateTime;
    i1.HighPart = idle1.dwHighDateTime;

    k1.LowPart = kernel1.dwLowDateTime;
    k1.HighPart = kernel1.dwHighDateTime;

    u1.LowPart = user1.dwLowDateTime;
    u1.HighPart = user1.dwHighDateTime;

    i2.LowPart = idle2.dwLowDateTime;
    i2.HighPart = idle2.dwHighDateTime;

    k2.LowPart = kernel2.dwLowDateTime;
    k2.HighPart = kernel2.dwHighDateTime;

    u2.LowPart = user2.dwLowDateTime;
    u2.HighPart = user2.dwHighDateTime;

    ULONGLONG idle = i2.QuadPart - i1.QuadPart;

    ULONGLONG total =
        (k2.QuadPart + u2.QuadPart) -
        (k1.QuadPart + u1.QuadPart);

    if (total == 0) {
        printf("Não foi possível calcular o uso.\n");
        return;
    }

    double usage = 100.0 * (total - idle) / total;

    printf("CPU Usage: %.2f%%\n", usage);
}
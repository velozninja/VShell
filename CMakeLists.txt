cmake_minimum_required(VERSION 4.3)
project(VShell C)

set(CMAKE_C_STANDARD 11)

add_executable(VShell src/main.c
        src/Reader.c
        includes/Reader.h
        includes/MemoryRam.h
        src/system/MemoryRAm.c
        includes/MemoryRam.h
        includes/CPU.h
        src/system/CPU.c
        includes/DISK.h
        src/system/DISK.c)
target_include_directories(VShell PRIVATE includes)
set_target_properties(VShell PROPERTIES RUNTIME_OUTPUT_DIRECTORY "C:\\Tools\\VShell")
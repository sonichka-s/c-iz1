#pragma once
#include "stdio.h"

typedef struct {
    char* author;
    char* singer;
    char* name;
    char* duration;
} Song;

Song* song_constructor(char* author, char* singer, char* name, char* length);


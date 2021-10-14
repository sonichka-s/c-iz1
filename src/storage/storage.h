#pragma once
#include "stdlib.h"
#include "song_data.h"

typedef struct {
    size_t length;
    size_t capacity;
    Song* song;
} Storage;

Storage* storage_constructor(size_t length, size_t capacity);
int add_song(Storage* storage, char* author, char* singer, char* name, char* duration);
int print_author_eq_singer(Storage* storage);
int free_storage(Storage** storage);



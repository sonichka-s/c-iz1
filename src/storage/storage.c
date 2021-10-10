#include "storage.h"
#include "stdlib.h"
#include "stdio.h"

Storage* storage_constructor(size_t length, size_t capacity){
    Storage* buf = (Storage*) malloc(sizeof(Storage));

    if (buf == NULL){
        return NULL;
    }
    buf->length = length;
    buf->capacity = capacity;
}

int add_song(Storage* storage, char* author, char* singer, char* name, char* duration) {
    Song* temp;

    temp->author = author;
    temp->singer = singer;
    temp->name = name;
    temp->duration = duration;

    if(storage == NULL || temp == NULL){
        return NULL;
    }

    if (storage->length + 1 > storage->capacity){
        storage->capacity *= 2;
        storage->song = (Song *) realloc(storage->song,sizeof(Song) * storage->capacity);

        if (storage->song == NULL) {
            return NULL;
        }
    }
    size_t index = storage->length - 1;

    storage->song[index] = *temp;
    storage->length += 1;

    return 1;
}

int print_author_eq_singer(Storage* storage){
    for (size_t i = 0; i < storage->length; ++i) {
        if (storage->song[i].author == storage->song[i].singer){
            printf("%s","author: ");
            puts(storage->song[i].author);
            printf("%s","singer: ");
            puts(storage->song[i].singer);
            printf("%s","name: ");
            puts(storage->song[i].name);
            printf("%s","duration: ");
            puts(storage->song[i].duration);
        }
    }
}

int free_storage(Storage** storage){
    if (*storage == NULL){
        return 1;
    }
    if ((*storage)->song == NULL){
        free(*storage);
        *storage = NULL;
    }
    free((*storage)->song);
    free(*storage);
    *storage = NULL;
}

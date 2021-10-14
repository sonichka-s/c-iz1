#include "song_data.h"
#include "storage.h"
#include "stdio.h"

int main() {
    Storage* storage;
    storage = storage_constructor(0, 1);

    add_song(storage, "ab", "ab", "name1", "3:15");
    add_song(storage, "ab", "ac", "name1", "3:15");
    add_song(storage, "lb", "lb", "name2", "3:15");

    print_author_eq_singer(storage);

    free_storage(&storage);

    return 0;
}


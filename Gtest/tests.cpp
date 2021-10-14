#include "gtest/gtest.h"

extern "C"
{
#include "song_data.h"
#include "storage.h"
}

int free_storage_for_tests(Storage** storage){
    if (*storage == NULL){
        return 1;
    }

    if ((*storage)->song == NULL){
        free(*storage);
        *storage = NULL;
        return 1;
    }

    free((*storage)->song);
    free(*storage);
    *storage = NULL;
    return 1;
}

const char author[] = "a1";
const char singer[] = "a2";
const char name[] = "a3";
const char duration[] = "4:53";

TEST(STORAGE_CONSTRUCTOR, TEST_STORAGE_CONSTRUCTOR){
    Storage* test_storage = reinterpret_cast<Storage *>(malloc(sizeof(Storage)));

    size_t expect_length = 0;
    size_t expect_capacity = 1;
    Song* expected_song = NULL;

    test_storage = storage_constructor(expect_length, expect_capacity);

    EXPECT_EQ(test_storage->length, expect_length);
    EXPECT_EQ(test_storage->capacity, expect_capacity);
    EXPECT_EQ(test_storage->song, expected_song);

    free_storage_for_tests(&test_storage);
    EXPECT_EQ(test_storage, nullptr);
}

TEST(ADD_SONG, TEST_ADD_SONG){
    Storage* test_storage = storage_constructor(0, 1);

    add_song(test_storage, (char *)author, (char *)singer, (char *)name, (char *)duration);

    EXPECT_EQ(test_storage->song[0].author, (char *)author);
    EXPECT_EQ(test_storage->song[0].singer, (char *)singer);
    EXPECT_EQ(test_storage->song[0].name, (char *)name);
    EXPECT_EQ(test_storage->song[0].duration, (char *)duration);

    free_storage_for_tests(&test_storage);
    EXPECT_EQ(test_storage, nullptr);
}

TEST(FREE_STORAGE, TEST_FREE_STORAGE){
    Storage *test_storage = reinterpret_cast<Storage *>(malloc(sizeof(Storage)));

    test_storage = storage_constructor(0, 1);

    free_storage(&test_storage);
    EXPECT_EQ(test_storage, nullptr);
}
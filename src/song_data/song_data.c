#include "stdlib.h"
#include "song_data.h"

Song* song_constructor(char* author, char* singer, char* name, char* duration){
    Song* buf = (Song *)malloc(sizeof(Song));

    if (buf == NULL){
        return NULL;
    }
    buf->author = author;
    buf->singer = singer;
    buf->name = name;
    buf->duration = duration;

    return buf;
}
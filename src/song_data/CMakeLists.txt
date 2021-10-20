add_library(song song_data.h song_data.c)
target_include_directories(song PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

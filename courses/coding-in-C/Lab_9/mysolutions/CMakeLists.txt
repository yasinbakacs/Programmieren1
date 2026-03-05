cmake_minimum_required(VERSION 3.10)

project(Playlist C)

set(CMAKE_C_STANDARD 11)

include_directories(include)

add_executable(playlist
    main.c
    src/playlist.c
)
#include <stdio.h>

#include "include/playlist.h"

void main(){
    Playlist myPlaylist;

    init_playlist(&myPlaylist);

    add_song(&myPlaylist, "Crawling", "Linkin Park");
    add_song(&myPlaylist, "Layla", "Eric Clapton");
    add_song(&myPlaylist, "Esperanto", "Max Herre");
    
    print_List(&myPlaylist);

    delete_firstSong(&myPlaylist);

    printf("\n\n");
    print_List(&myPlaylist);

    delete_Playlist(&myPlaylist);
}
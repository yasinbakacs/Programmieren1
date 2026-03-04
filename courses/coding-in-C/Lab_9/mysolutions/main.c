#include <stdio.h>

#include "include/playlist.h"

int main(void){
    Playlist myPlaylist;

    init_playlist(&myPlaylist);

    add_song(&myPlaylist, "Crawling", "Linkin Park");
    add_song(&myPlaylist, "Layla", "Eric Clapton");
    add_song(&myPlaylist, "Esperanto", "Max Herre");
    
    print_List(&myPlaylist);

    delete_firstSong(&myPlaylist);

    printf("\n\n");
    print_List(&myPlaylist);

    Song *found = find_song_by_title(&myPlaylist, "Esperanto");

    if (found != NULL){
    printf("Gefunden: %s von %s\n", found->title, found->artist);
    }else printf("Song nicht gefunden.\n");

    delete_Playlist(&myPlaylist);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Song{
    char *title;
    char *artist;
    struct Song *next;
} Song;


typedef struct Playlist{
    Song *head;
} Playlist;


//@brief Initializes the playlist by setting head to NULL.
//
//@param [in] Playlist *playlist: A pointer to the playlist that needs to be initialized.

void init_playlist(Playlist *playlist){
    playlist->head = NULL;
}

//@brief Adds a new Song to end of Playlist. Memory is allocated dynamically.


Song *add_song(Playlist *playlist, const char *title, const char *artist){
    Song *newSong = malloc(sizeof(Song));
    if (newSong == NULL){
        printf("Fehler bei Datenspeicher Zuweisung\n");
        return NULL;
    }
    
    newSong->artist = strdup(artist);
    if (newSong->artist[49] == NULL){
        printf("Fehler bei Datenspeicher Zuweisung\n");
        free(newSong);
        return NULL;
    }
    
    newSong->title = strdup(title);
    if (newSong->title[49] == NULL){
        printf("Fehler bei Datenspeicher Zuweisung\n");
        free(newSong->artist[49]);
        free(newSong);
        return NULL;
    }
    newSong->title[49] = &title;
    newSong->next = NULL;
    Song *current = playlist->head;
    while (current != NULL && current->next != NULL) {
        current = current->next;
    }
    if (current == NULL) {
        playlist->head = newSong;
    } else {
        current->next = newSong;
    }
    return newSong;

    free(newSong);
}



void main(){
    Playlist myPlaylist;
    init_playlist(&myPlaylist);
    add_song(&myPlaylist, "Bohemian Rhapsody", "Queen");
    add_song(&myPlaylist, "Stairway to Heaven", "Led Zeppelin");
}
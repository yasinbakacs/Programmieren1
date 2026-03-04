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
    if (newSong->artist == NULL){
        printf("Fehler bei Datenspeicher Zuweisung\n");
        free(newSong);
        return NULL;
    }
    
    newSong->title = strdup(title);
    if (newSong->title == NULL){
        printf("Fehler bei Datenspeicher Zuweisung\n");
        free(newSong->artist);
        free(newSong);
        return NULL;
    }
    
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

//@brief Prints out the Playlist with Song title and artist
//
//@param [in] Playlist *playlist a pointer to the playlist that needs printing.

void print_List(const Playlist *playlist){
    Song *temp = playlist->head;
    while (temp != 0){
        printf("Artist: %s\n", temp->artist);
        printf("Title: %s\n", temp->title);
        temp = temp->next;
    }
}


//@brief Deletes the first song of the playlist.
//
//@param [in] Playlist *playlist a pointer to the playlist where the first song is to be deleted.

void delete_firstSong(Playlist *playlist){
    Song *temp = playlist->head;

    playlist->head = temp->next;

    free(temp->artist);
    free(temp->title);
    free(temp);
}


void main(){
    Playlist myPlaylist;
    init_playlist(&myPlaylist);
    add_song(&myPlaylist, "Crawling", "Linkin Park");
    add_song(&myPlaylist, "Layla", "Eric Claptonn");
    add_song(&myPlaylist, "Esperanto", "Max Herre");
    print_List(&myPlaylist);
    delet_firstSong(&myPlaylist);
    print_List(&myPlaylist);
    delete_Playlist(&myPlaylist);
}
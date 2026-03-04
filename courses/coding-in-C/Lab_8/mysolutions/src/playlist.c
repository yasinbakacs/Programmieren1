#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/playlist.h"




//@brief Initializes the playlist by setting head to NULL.
//
//@param [in] Playlist *playlist: A pointer to the playlist that needs to be initialized.

void init_playlist(Playlist *playlist){
    playlist->head = NULL;
}

//@brief Adds a new Song to end of Playlist. Memory is allocated dynamically.

Song *add_song(Playlist *playlist, const char *title, const char *artist){

    if (playlist->count >= MAX_SONGS){
        printf("Maximale Playlistlaenge erreicht.");
        return NULL;
    }

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
    
    playlist->count++;

    return newSong;
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
    playlist->count--;
}


//@brief Deletes the whole playlist and frees the memory.
//
//@param [in] Playlist *playlist a pointer to the playlist that is to be deletet.

void delete_Playlist(Playlist *playlist){
    Song *temp = playlist->head;

    while(temp != NULL){
        Song *current = temp;
        temp = temp->next;

        free(current->artist);
        free(current->title);
        free(current);
    }
    playlist->head = NULL;
    playlist->count = 0;
}


#ifndef PLAYLIST_H
#define PLAYLIST_H

#define MAX_SONGS 5

typedef struct Song{
    char *title;
    char *artist;
    struct Song *next;
} Song;

typedef struct Playlist{
    Song *head;
    int count;
} Playlist;

void init_playlist(Playlist *playlist);

Song *add_song(Playlist *playlist, const char *title, const char *artist);

void print_List(const Playlist *playlist);

void delete_firstSong(Playlist *playlist);

void delete_Playlist(Playlist *playlist);

#endif


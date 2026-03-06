#include <assert.h>
#include <string.h>
#include <stdio.h>
#include "../include/playlist.h"

/* === Unit-tests === */

// example unit test
void test_init_playlist(void)
{
    Playlist p;
    init_playlist(&p);

    assert(p.head == NULL);
    assert(p.count == 0);
}

void test_add_song(void){
    Playlist p;
    init_playlist(&p);

    add_song(&p, "Song1", "Artist1");
    assert(p.count == 1);
    assert(p.head != 0);
    assert(strcmp(p.head->title, "Song1") == 0);
    assert(strcmp(p.head->artist, "Artist1") == 0);

    delete_Playlist(&p);
}


void test_delete_firstSong(void){
    Playlist p;
    init_playlist(&p);

    add_song(&p, "Test", "tst");
    add_song(&p, "Test1", "tst1");
    add_song(&p, "Test2", "tst2");
    delete_firstSong(&p);
    assert(p.count == 2);
    assert(p.head != NULL);
    assert(strcmp(p.head->title, "Test1") == 0);
    assert(strcmp(p.head->artist, "tst1") == 0);




}
/* === Test-Runner === */

int main(void)
{
    test_init_playlist();
    test_add_song();
    test_delete_firstSong();
    //test_delete_firstSong_empty(); // what happens if we delete first song from empty playlist
    //test_delete_playlist();
    //test_max_songs_limit(); // verify if the limit will be not be surpassed

    printf("Alle Playlist-Tests erfolgreich bestanden.\n");
    return 0;
}
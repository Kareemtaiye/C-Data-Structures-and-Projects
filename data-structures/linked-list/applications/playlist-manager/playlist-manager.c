#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// DCM: Not checking for malloc errors
typedef struct Node {
    char *title;
    char *artist;
    int duration;  // mins
    struct Node *next;
    struct Node *prev;
} Node;  // Song is circular.

typedef struct Playlist {
    char *name;
    Node *songs;
    struct Playlist *next;
    struct Playlist *prev;
} Playlist;  // playlist is circular.

typedef struct App {
    char *name;
    Playlist *playlists;
} App;  // The Music app.

App *app;

/* Defined helper functions */
// compare songs titles.
int compare(char *s1, char *s2) {
    for (;
         (unsigned char)*s1 == (unsigned char)*s2 && (unsigned char)*s1 != '\0';
         s1++, s2++);
    return (unsigned char)*s1 - (unsigned char)*s2;
}

int isAppEmpty() { return app == NULL || app->playlists == NULL; }

int isPlaylistEmpty(Playlist *playlist) {
    return playlist == NULL || playlist->songs == NULL;
}

Playlist *createPlaylist() {
    int x;
    printf("Number of playlist to create(max is 5): ");
    scanf("%d", &x);
    while (getchar() != '\n');  // flushes the new line

    if (x > 5) {
        printf("Cannot create more than 5 playlist at a time\n");
        return NULL;
    }

    int i;
    char name[100];
    Playlist *head = NULL;
    Playlist *new_playlist;

    for (i = 1; i <= x; i++) {
        printf("Enter the name for playlist %d: ", i);
        fgets(name, sizeof(name), stdin);
        name[strcspn(name, "\n")] = '\0';

        new_playlist = malloc(sizeof(Playlist));
        new_playlist->name = strdup(name);

        // Creating the first playlist.
        if (head == NULL) {
            new_playlist->next = new_playlist;
            new_playlist->prev = new_playlist;
            head = new_playlist;  // Head playist(Playlist)

        }  // simply appends to become the last playlist
        else {
            new_playlist->next = head;
            new_playlist->prev = head->prev;
            head->prev->next = new_playlist;
            head->prev = new_playlist;
        }

        // printf("\nPlaylist: (%s) created\n ", name);
    }

    // first playlist on the app.
    if (isAppEmpty()) {
        app->playlists = head;
    } else {
        head->next = app->playlists;
        head->prev = app->playlists->prev;
        app->playlists->prev->next = head;
        app->playlists->prev = head;
    }

    printf("Playlist(s) creation completed");

    return head;
}

Playlist *getFirstPl() {
    if (isAppEmpty()) {
        printf("App is empty");
        return NULL;
    }

    return app->playlists;
}

Playlist *getLastPlaylist() {
    if (isAppEmpty()) {
        printf("App is empty");
        return NULL;
    }

    return app->playlists->prev;
}

Playlist *searchPlaylist(char *name) {
    if (isAppEmpty()) {
        printf("App is empty");
        return NULL;
    }

    // Fist playlist
    Playlist *first_pl = getFirstPl();
    if (compare(first_pl->name, name) == 0) {
        return first_pl;
    }

    // Last playlist
    Playlist *last_pl = getLastPlaylist();
    if (compare(last_pl->name, name) == 0) {
        return last_pl;
    }

    Playlist *ptr = first_pl->next;
    int res;
    while (ptr != first_pl && (res = compare(ptr->name, name)) != 0) {
        ptr = ptr->next;
    }

    // if a result is found
    if (res == 0) {
        return ptr;  // return the found playlist.
    }

    return NULL;  // no result is found
}

Node *getFirstSong(Playlist *playlist) {
    if (isPlaylistEmpty(playlist)) {
        printf("Playlist is empty");
        return NULL;
    }

    return playlist->songs;
}

Node *getLastSong(Playlist *playlist) {
    if (isPlaylistEmpty(playlist)) {
        printf("Playlist is empty");
        return NULL;
    }

    return playlist->songs->prev;
}

Node *searchSong(Playlist *playlist, char *title) {
    if (isPlaylistEmpty(playlist)) {
        printf("Playlist is empty ");
        return NULL;
    }

    Node *first_song = getFirstSong(playlist);
    if (compare(first_song->title, title) == 0) {
        return first_song;
    }

    Node *last_song = getLastSong(playlist);
    if (compare(last_song->title, title) == 0) {
        return last_song;
    }

    Node *ptr = first_song->next;
    int res;
    while (ptr != first_song && (res = compare(ptr->title, title)) != 0) {
        ptr = ptr->next;
    }

    if (res == 0) {
        return ptr;  // return the found result if result is found
    }

    // no result is found
    return NULL;
}

// Adds song at the end of the playlist. O(1).
Node *add(Playlist *playlist, char *title, char *artist, int dur) {
    Node *new_song = malloc(sizeof(Node));
    new_song->artist = artist;
    new_song->title = title;
    new_song->duration = dur;

    if (isPlaylistEmpty(playlist)) {
        new_song->next = new_song;
        new_song->prev = new_song;
        playlist->songs = new_song;
    } else {
        Node *head = getFirstSong(playlist);

        new_song->next = head;
        new_song->prev = head->prev;
        head->prev->next = new_song;
        head->prev = new_song;
    }

    return new_song;
}

// Delete a sing by titile.
char *deleteSong(Playlist *playlist, char *title) {
    if (isPlaylistEmpty(playlist)) {
        printf("Playlist is empty");
        return NULL;
    }

    // if song is the first.
    Node *head = getFirstSong(playlist);
    if (compare(head->title, title) == 0) {
        playlist->songs = head->next;
        playlist->songs->prev = head->prev;
        head->prev->next = playlist->songs;
        free(head);
        head = NULL;

        return title;
    }

    // if song is the last.
    Node *tail = getLastSong(playlist);
    if (compare(tail->title, title) == 0) {
        tail->prev->next = head;
        head->prev = tail->prev;
        free(tail);
        tail = NULL;

        return title;
    }

    Node *temp = playlist->songs;
    int res;
    while (temp != tail && (res = compare(temp->title, title)) != 0) {
        temp = temp->next;
    }

    // if song is found.
    if (res == 0) {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        free(temp);
        temp = NULL;
        return title;
    }

    // No song with title found after traversal.
    return NULL;
}

Node *nextSong(Playlist *playlist) {
    if (isPlaylistEmpty(playlist)) {
        printf("Playlist is empty");
        return NULL;
    };

    playlist->songs = playlist->songs->next;
    return playlist->songs;
}

Node *prevSong(Playlist *playlist) {
    if (isPlaylistEmpty(playlist)) {
        printf("Playlist is empty");
        return NULL;
    };

    playlist->songs = playlist->songs->prev;
    return playlist->songs;
}

void freePlaylistMem(Playlist *playlist) {
    if (isPlaylistEmpty(playlist)) {
        return;
    }

    Node *current = playlist->songs->next;
    Node *next;

    while (current != playlist->songs) {
        next = current->next;
        free(current);
        current = next;
    }

    free(current);
    current = next = NULL;
}

void displayPlaylists() {
    if (isAppEmpty()) {
        printf("App is empty");
        return;
    }

    Playlist *current = app->playlists;
    int x = 1;
    do {
        printf("%d %s ", x++, current->name);
        current = current->next;
    } while (current != app->playlists);
}

void displaySongs(Playlist *pl) {
    Node *current = pl->songs;

    do {
        printf("%s ", current->title);
    } while (current != pl->songs);

    printf("\n");
}

int main() {
    app = malloc(sizeof(App));
    app->name = strdup("Music App");
    app->playlists = NULL;

    Playlist *first_playlist = createPlaylist();
    // Playlist *new_playlist = createPlaylist();

    printf("Enter your option\n");
    int x;
    while (1) {
        printf(
            "1. Create Playlist(s)\n"
            "2. Add song to playlist\n"
            "3. Search for a song in a playlist\n"
            "4. Search for a playlist\n"
            "5. Show all playlists\n"
            "6. Show all songs in a playlist\n"
            "7. Delete song from a playlist\n"
            "8. Play next song\n"
            "9. Play previous song\n"
            "10. Exit\n");
    }
    scanf("%d", &x);
    switch (x) {
        case 1:
            createPlaylist();
            break;
        case 2:
            char pl_name[100];
            printf("Enter the name of the playlist: ");
            fgets(pl_name, sizeof(pl_name), stdin);
            pl_name[strspn(pl_name, "\n")] = '\0';

            Playlist *pl_search_res = searchPlaylist(pl_name);

            // Playlist not found
            if (pl_search_res == NULL) {
                printf("Playlist not found");
                break;
            }

            char line[300], title[100], artist[100];
            int dur;
            printf(
                "Enter the song's title, artist, and duration in the format (t "
                "n d)\n");

            fgets(line, sizeof(line), stdin);
            line[strspn(line, "\n")] = '\0';

            sscanf(line, "\"%99[^\"]\" \"%99[^\"]\" %d", title, artist, &dur);

            Node *added_song = add(pl_search_res, title, artist, dur);
            printf("Song: %s added to playlist: %s\n", added_song->title,
                   pl_name);

            break;
        case 3:
            printf(
                "Enter the playlist name and song title in the format: (song, "
                "pl) in quotes.\n");
            // Node *res = searchSong()
            break;
        case 5:
            printf("\nApp playlists \n");
            displayPlaylists();
            break;
        case 10:
            printf("Exiting...\n");

            return;
            break;
        default:
            break;
    }

    return 0;
}
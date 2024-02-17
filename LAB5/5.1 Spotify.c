//66070503416 Thapana Liamthongkaow
//Lab 5.1 Spotify
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SONGS 100
#define MAX_NAME_LENGTH 50

// Structure to represent a song in the queue
typedef struct Song {
    char name[MAX_NAME_LENGTH];
    char artist[MAX_NAME_LENGTH];
    int duration;
    struct Song* next;
} Song;

// Create a global head for the queue
Song* head = NULL;
int total_duration = 0;

// Function prototypes
void add_song(char name[], char artist[], int duration);
void play_song();
void show_playlist();
Song* create_song_node(char name[], char artist[], int duration);
void free_playlist();

int main() {
    char command[10];
    char name[MAX_NAME_LENGTH], artist[MAX_NAME_LENGTH];
    int duration;

    while (1) {
        printf("> ");
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            scanf(" %[^\n]s", name);  // Read entire line for song name
            scanf(" %[^\n]s", artist); // Read entire line for artist
            scanf("%d", &duration);
            add_song(name, artist, duration);
        } else if (strcmp(command, "play") == 0) {
            play_song();
        } else if (strcmp(command, "sum") == 0) {
            show_playlist();
        } else if (command[0] == '\n') {
            break;
        } else {
            printf("Invalid command.\n");
        }
    }

    free_playlist();
    return 0;
}

void add_song(char name[], char artist[], int duration) {
    Song* new_song = create_song_node(name, artist, duration);

    if (!head) {
        head = new_song;
    } else {
        Song* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = new_song;
    }

    total_duration += duration;
}

void play_song() {
    if (!head) {
        printf("No songs in the playlist.\n");
        return;
    }

    printf("Now playing: %s by %s\n", head->name, head->artist);
    head = head->next;
}

void show_playlist() {
    if (!head) {
        printf("No songs in the playlist.\n");
        return;
    }

    printf("Songs in the playlist:\n");
    Song* temp = head;
    while (temp) {
        printf("%s by %s %dsec\n", temp->name, temp->artist, temp->duration);
        temp = temp->next;
    }

    printf("Remaining Time: %dsec\n", total_duration);
}

Song* create_song_node(char name[], char artist[], int duration) {
    Song* new_song = (Song*)malloc(sizeof(Song));
    strcpy(new_song->name, name);
    strcpy(new_song->artist, artist);
    new_song->duration = duration;
    new_song->next = NULL;
    return new_song;
}

void free_playlist() {
    Song* temp = head;
    while (temp) {
        Song* next = temp->next;
        free(temp);
        temp = next;
    }
}
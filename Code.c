//music player in c
#include <stdio.h>
#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")

char songlist[4][50] = {
    "Birds of a feather",
    "Piano",
    "About You",
    "Upbeat"
};

char songpaths[5][100] = {
    "C:\\Users\\Mahinoor\\Downloads\\Birds of a feather.wav",
    "C:\\Users\\Mahinoor\\Downloads\\Piano Music.wav",
    "C:\\Users\\Mahinoor\\Downloads\\About You.wav",
    "C:\\Users\\Mahinoor\\Downloads\\instrumental.mp3",
    "C:\\Users\\Mahinoor\\Downloads\\trap wsve.mp3"
};

char playPauseChoice[10];

void displaysonglist() {
    printf("Available songs:\n");
    printf("a) Birds of a feather\n");
    printf("b) Piano \n");
    printf("c) About You\n");
    printf("d) Instrumental\n");
    printf("e) Trap Wave\n");
}

void guide() {
    printf("'Stop' to stop the song\n");
    printf("'next' to skip to the next song\n");
    printf("'previous' to skip to the previous song\n");
}



void skipprevious(int songnum);
void skipnext(int songnum);

void songplay(char playpause[10], int songnum){
    if(strcmp(playpause, "Stop") == 0){
        PlaySound(NULL, 0, 0);
    }
    else if(strcmp(playpause, "next") == 0){
        skipnext(songnum + 1);
    }
    else if(strcmp(playpause, "previous") == 0){
        skipprevious(songnum - 1);
    }
    else {
        printf("Invalid command. Please enter 'Stop', 'next', 'previous', or 'pause'.\n");
    }
}

void skipnext(int songnum){ 
    PlaySound(NULL, 0, 0);
    Sleep(1000); 
    if(songnum >= 0 && songnum < 5) {
        printf("Skipping to next song...\n");
        printf("Playing: %s\n", songlist[songnum]);
        PlaySound(songpaths[songnum], NULL, SND_FILENAME | SND_ASYNC);
        //Sleep(1000); // Simulate a delay for the next song to play
        scanf(" %s", playPauseChoice);
        songplay(playPauseChoice, songnum);
    } else {
        printf("No next song available.\n");
        songplay(playPauseChoice, songnum);
    }
}



void skipprevious(int songnum){
    if(songnum > 0 && songnum < 5) {
        PlaySound(NULL, 0, 0);
        Sleep(1000);
        printf("Skipping to previous song...\n");
        printf("Playing: %s\n", songlist[songnum]);
        PlaySound(songpaths[songnum], NULL, SND_FILENAME | SND_ASYNC);
        Sleep(1000); 
        scanf(" %s", playPauseChoice);
        songplay(playPauseChoice, songnum);
    } else {
        printf("No previous song available.\n");
        songplay(playPauseChoice, songnum);
    }
}



int main() {
    //display song list
    displaysonglist();
    char choice;
    printf("Choose a song to play: ");
    scanf(" %c", &choice);
    guide();
    char playPauseChoice[10];
    int songnum;

    switch (choice) {
        case 'a':
            songnum = 0;
            printf("Playing 'Birds of a feather'...\n");
            PlaySound(songpaths[songnum], NULL, SND_FILENAME | SND_ASYNC);
            scanf(" %s", playPauseChoice);
            songplay(playPauseChoice, songnum);
            break;
        case 'b':
            songnum = 1;
            printf("Playing 'Piano'...\n");
            PlaySound(songpaths[songnum], NULL, SND_FILENAME | SND_ASYNC);
            scanf(" %s", playPauseChoice);
            songplay(playPauseChoice, songnum);
 
            break;
        case 'c':
            songnum = 2;
            printf("Playing 'About You'...\n");
            PlaySound(songpaths[songnum], NULL, SND_FILENAME | SND_ASYNC);
            scanf(" %s", playPauseChoice);
            songplay(playPauseChoice, songnum);
            break;
        case 'd':
            songnum = 3;
            printf("Playing 'Instrumental'...\n");
            PlaySound(songpaths[songnum], NULL, SND_FILENAME | SND_ASYNC);
            scanf(" %s", playPauseChoice);
            songplay(playPauseChoice, songnum);
            break;
        case 'e':
            songnum = 4;
            printf("Playing 'Trap Wave'...\n");
            PlaySound(songpaths[songnum], NULL, SND_FILENAME | SND_ASYNC);
            scanf(" %s", playPauseChoice);
            songplay(playPauseChoice, songnum);
            break;
        default:
            printf("Invalid choice. Please select a valid song option \n");
    }

    return 0;

}


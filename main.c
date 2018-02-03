#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define STR_SIZE 160
#include "sortAndShuffle.h"

#define MAX_ARTISTS 4
#define MAX_SONGS 3

void removeNewline(char a[][STR_SIZE], int i);
void createPlaylist(char playlist[][STR_SIZE], char artists[][STR_SIZE], char songsArtist1[][STR_SIZE], char songsArtist2[][STR_SIZE], char songsArtist3[][STR_SIZE], char songsArtist4[][STR_SIZE], int *artistSongNum);

int main(void)
{
	/*
	// the array containing artists names.
	char artists[MAX_ARTISTS][STR_SIZE] = {0};
	// songs for Artist 1.
	char songsArtist1[MAX_SONGS][STR_SIZE] = {0};
	// songs for Artist 2.
	char songsArtist2[MAX_SONGS][STR_SIZE] = {0};
	// songs for Artist 3.
	char songsArtist3[MAX_SONGS][STR_SIZE] = {0};
	// songs for Artist 4.
	char songsArtist4[MAX_SONGS][STR_SIZE] = {0};
	// the total number of artists (Note it can be less than 4).
	int numOfArtists = 0;
	// the total number of songs for each artist (Note that less than 3 songs can be provided for each artist).
	int numSongsPerArtist[MAX_ARTISTS] = {0};
	// the total number of songs.
	int totalSongs = 0;*/
	
	char artists[MAX_ARTISTS][STR_SIZE] = {"b\n", "c\n", "d\n", "a\n"};
	char songsArtist1[MAX_SONGS][STR_SIZE] = {"a3\n", "a1\n", "a2\n"};
	char songsArtist2[MAX_SONGS][STR_SIZE] = {"b3\n", "b1\n", "b2\n"};
	char songsArtist3[MAX_SONGS][STR_SIZE] = {"c3\n", "c1\n", "c2\n"};
	char songsArtist4[MAX_SONGS][STR_SIZE] = {"d3\n", "d1\n", "d2\n"};
	int numOfArtists = 4;
	int numSongsPerArtist[MAX_ARTISTS] = {3, 3, 3, 3};
	int totalSongs = 3 * 4;
	
	
	/*
	* Use here functions that you should implement to insert artists and songs from the standard input.
	* Note that you also need to track the number of artists and the number of songs for each artist.
	*/
	int artNum, songNum;
	/*
	for (artNum = 0; artNum < MAX_ARTISTS; artNum++)
	{
		// takes in the artist names from user.
		printf("Insert an artist/group name:\n");
		fgets(artists[artNum], STR_SIZE, stdin);
		removeNewline(artists, artNum);	// removes newline in artists.
		puts("");
		
		// takes in the artist songs from user and removes newline in songs.
		for (songNum = 0; songNum < MAX_SONGS; songNum++)
		{
			printf("Insert song %d for %s\n", songNum+1, artists[artNum]);
			if (artNum == 0)
			{
				fgets(songsArtist1[songNum], STR_SIZE, stdin);
				removeNewline(songsArtist1, songNum);
			}
			else if (artNum == 1)
			{
				fgets(songsArtist2[songNum], STR_SIZE, stdin);
				removeNewline(songsArtist2, songNum);
			}
			else if (artNum == 2)
			{
				fgets(songsArtist3[songNum], STR_SIZE, stdin);
				removeNewline(songsArtist3, songNum);
			}
			else if (artNum == 3)
			{
				fgets(songsArtist4[songNum], STR_SIZE, stdin);
				removeNewline(songsArtist4, songNum);
			}
			// keeps track number of songs per artist and total number of songs.
			numSongsPerArtist[artNum] += 1;
			totalSongs += 1;
		}
		// keeps track the number of artists.
		numOfArtists += 1;
		puts("");
	}*/
	
	// for removing newline.
	for (artNum = 0; artNum < MAX_ARTISTS; artNum++)
	{
		removeNewline(artists, artNum);	// removes newline in artists.
		for (songNum = 0; songNum < MAX_SONGS; songNum++)
			if (artNum == 0)
				removeNewline(songsArtist1, songNum);
			else if (artNum == 1)
				removeNewline(songsArtist2, songNum);
			else if (artNum == 2)
				removeNewline(songsArtist3, songNum);
			else if (artNum == 3)
				removeNewline(songsArtist4, songNum);
	}
	
	
	/*
	* Use here the function sortArtists to sort the array of the artists and sortSongs to sort the songs of each artist
	* Print each artist (alphabetically) and for each of them print the list of songs sorted alphabetically
	*/
	// sorts the artist.
	mergeSort(artists, 0, numOfArtists-1);
	// sorts the song names by lexicographic ordering in ascending order.
	for (artNum = 0; artNum < numOfArtists; artNum++)
		if (artNum == 0)
			mergeSort(songsArtist1, 0, numSongsPerArtist[artNum]-1);
		else if (artNum == 1)
			mergeSort(songsArtist2, 0, numSongsPerArtist[artNum]-1);
		else if (artNum == 2)
			mergeSort(songsArtist3, 0, numSongsPerArtist[artNum]-1);
		else if (artNum == 3)
			mergeSort(songsArtist4, 0, numSongsPerArtist[artNum]-1);
	
	printf("Sorted list of songs:\n");
	for (artNum = 0; artNum < MAX_ARTISTS; artNum++)
	{
		// prints the artist name.
		printf("%s\n", artists[artNum]);
		
		// prints the songs of the artist.
		for (songNum = 0; songNum < MAX_SONGS; songNum++)
		{
			if (artNum == 0)
				printf("    -  %s\n", songsArtist1[songNum]);
			else if (artNum == 1)
				printf("    -  %s\n", songsArtist2[songNum]);
			else if (artNum == 2)
				printf("    -  %s\n", songsArtist3[songNum]);
			else if (artNum == 3)
				printf("    -  %s\n", songsArtist4[songNum]);
		}
	}
	
	
	/*
	* Use here the function shuffleSongs to shuffle all the songs
	* Print the list of shuffled songs
	*/
	int artistSongNum = 0;
	char playlist[MAX_ARTISTS*MAX_SONGS*2][STR_SIZE] = {0}; // holds the artist + song that is added to the playlist.
	
	// creates a playlist by adding all the songs with their artist together.
	createPlaylist(playlist, artists, songsArtist1, songsArtist2, songsArtist3, songsArtist4, &artistSongNum);
	createPlaylist(playlist, artists, songsArtist1, songsArtist2, songsArtist3, songsArtist4, &artistSongNum);
	
	// shuffle playlist via knuth fisher-yates's algorithm.
	printf("\n\nShuffled Playlist:\n");
	shuffleArrayOfStrings(playlist, totalSongs * 2);
	
	// prints the shuffled playlist.
	for (artistSongNum = 0; artistSongNum < totalSongs * 2; artistSongNum++)
		printf("%d: %s\n", artistSongNum, playlist[artistSongNum]);
	
	return 0;
}

void createPlaylist(char playlist[][STR_SIZE], char artists[][STR_SIZE], char songsArtist1[][STR_SIZE], char songsArtist2[][STR_SIZE], char songsArtist3[][STR_SIZE], char songsArtist4[][STR_SIZE], int *i)
{
	int artistSongNum = *i;	// stores the artistSongNum.
	int artNum, songNum;
	for (artNum = 0; artNum < MAX_ARTISTS; artNum++)
		for (songNum = 0; songNum < MAX_SONGS; songNum++, artistSongNum++)
		{
			strcat(playlist[artistSongNum], artists[artNum]);
			strcat(playlist[artistSongNum], " - ");
			if (artNum == 0)
				strcat(playlist[artistSongNum], songsArtist1[songNum]);
			else if (artNum == 1)
				strcat(playlist[artistSongNum], songsArtist2[songNum]);
			else if (artNum == 2)
				strcat(playlist[artistSongNum], songsArtist3[songNum]);
			else if (artNum == 3)
				strcat(playlist[artistSongNum], songsArtist4[songNum]);
		}
	*i = artistSongNum;	// returns the artistSongNum back into main.
}
	
void removeNewline(char a[][STR_SIZE], int i)
{
	int len = strlen(a[i])-1;
	if (a[i][len] == '\n')
		a[i][len] = '\0';
}

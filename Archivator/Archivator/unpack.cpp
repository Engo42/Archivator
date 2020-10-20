#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

void unpack(char* filename) {
	FILE* filein = fopen(filename, "rb");

	int namesize;
	fread(&namesize, 4, 1, filein);

	char* newfilename = (char*)malloc(namesize + 1);
	newfilename[namesize] = '\0';
	fread(newfilename, 1, namesize, filein);

	int filesize;
	fread(&filesize, 4, 1, filein);

	char* mem = new char[filesize];
	for (int i = 0; i < filesize; i++) {
		fread(&mem[i], 1, 1, filein);
	}

	FILE* fileout = fopen(newfilename, "wb");
	for (int i = filesize - 1; i >= 0; i--) {
		fwrite(&mem[i], 1, 1, fileout);
	}
}
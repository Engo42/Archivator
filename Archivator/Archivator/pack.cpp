#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <filesystem>

void pack(char* filename) {
	FILE* filein = fopen(filename, "rb");

	fseek(filein, 0L, SEEK_END);
	int filesize = ftell(filein);
	fseek(filein, 0L, SEEK_SET);

	char* mem = new char[filesize];
	for (int i = 0; i < filesize; i++) {
		fread(&mem[i], 1, 1, filein);
	}

	FILE* fileout = fopen("out.packed", "wb");

	int namesize = strlen(filename);
	fwrite(&namesize, 4, 1, fileout);
	fwrite(filename, namesize, 1, fileout);

	fwrite(&filesize, 4, 1, fileout);
	for (int i = namesize - 1; i >= 0; i--) {
		fwrite(&mem[i], 1, 1, fileout);
	}
}
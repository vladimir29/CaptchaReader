#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "bmp_header.h"
#include<math.h>

/*Subprogramul cifra compara un tablou de 5x5 dintr-o matrice primita ca paramatru, si in cazul in care
corespunde cu tabloul constant al ulei cifre (dintre cele 10 declarate la inceput), returneaza cifra respectiva*/

int cifra(int matrice[100][100], int lin, int col)
{
	const int zero[5][5] = { {1, 1, 1, 1, 1}, {1, 0, 0, 0, 1}, {1, 0, 0, 0, 1}, {1, 0, 0, 0, 1}, {1, 1, 1, 1, 1} };
	const int unu[5][5] = { {0, 0, 0, 0, 1}, {0, 0, 0, 0, 1}, {0, 0, 0, 0, 1}, {0, 0, 0, 0, 1}, {0, 0, 0, 0, 1} };
	const int doi[5][5] = { {1, 1, 1, 1, 1}, {0, 0, 0, 0, 1}, {1, 1, 1, 1, 1}, {1, 0, 0 ,0, 0}, {1, 1, 1, 1, 1} };
	const int trei[5][5] = { {1, 1, 1, 1, 1}, {0, 0, 0, 0, 1}, {1, 1, 1, 1, 1}, {0, 0, 0, 0, 1}, {1, 1, 1, 1, 1} };
	const int patru[5][5] = { {1, 0, 0, 0, 1}, {1, 0, 0, 0, 1}, {1, 1, 1, 1, 1}, {0, 0, 0, 0, 1}, {0, 0, 0, 0, 1} };
	const int cinci[5][5] = { {1, 1, 1, 1, 1}, {1, 0, 0, 0, 0}, {1, 1, 1, 1, 1}, {0, 0, 0, 0, 1}, {1, 1, 1, 1, 1} };
	const int sase[5][5] = { {1, 1, 1, 1, 1}, {1, 0, 0, 0, 0}, {1, 1, 1, 1, 1}, {1, 0, 0, 0, 1}, {1, 1, 1, 1, 1} };
	const int sapte[5][5] = { {1, 1, 1, 1, 1}, {0, 0, 0, 0, 1}, {0, 0, 0, 0, 1}, {0, 0, 0, 0, 1}, {0, 0, 0, 0, 1} };
	const int opt[5][5] = { {1, 1, 1, 1, 1}, {1, 0, 0, 0, 1}, {1, 1, 1, 1, 1}, {1, 0, 0, 0, 1}, {1, 1, 1, 1, 1} };
	const int noua[5][5] = { {1, 1, 1, 1, 1}, {1, 0, 0, 0, 1}, {1, 1, 1, 1, 1}, {0, 0, 0, 0, 1}, {1, 1, 1, 1, 1} };
	
	int i, j, ok;

	ok = 1;
	for(i = 0; i < 5; i++)
	for(j = 0; j < 5; j++)
	if(matrice[i+lin][j+col] != zero[i][j])
	ok = 0;
	if(ok) return 0;

	ok = 1;
	for(i = 0; i < 5; i++)
	for(j = 0; j < 5; j++)
	if(matrice[i+lin][j+col] != unu[i][j])
	ok = 0;
	if(matrice[lin][col+5]==1) ok=0;
	if(ok) return 1;

	ok = 1;
	for(i = 0; i < 5; i++)
	for(j = 0; j < 5; j++)
	if(matrice[i+lin][j+col] != doi[i][j])
	ok = 0;
	if(ok) return 2;

	ok = 1;
	for(i = 0; i < 5; i++)
	for(j = 0; j < 5; j++)
	if(matrice[i+lin][j+col] != trei[i][j])
	ok = 0;
	if(ok) return 3;

	ok = 1;
	for(i = 0; i < 5; i++)
	for(j = 0; j < 5; j++)
	if(matrice[i+lin][j+col] != patru[i][j])
	ok = 0;
	if(ok) return 4;

	ok = 1;
	for(i = 0; i < 5; i++)
	for(j = 0; j < 5; j++)
	if(matrice[i+lin][j+col] != cinci[i][j])
	ok = 0;
	if(ok) return 5;

	ok = 1;
	for(i = 0; i < 5; i++)
	for(j = 0; j < 5; j++)
	if(matrice[i+lin][j+col] != sase[i][j])
	ok = 0;
	if(ok) return 6;

	ok = 1;
	for(i = 0; i < 5; i++)
	for(j = 0; j < 5; j++)
	if(matrice[i+lin][j+col] != sapte[i][j])
	ok = 0;
	if(ok) return 7;

	ok = 1;
	for(i = 0; i < 5; i++)
	for(j = 0; j < 5; j++)
	if(matrice[i+lin][j+col] != opt[i][j])
	ok = 0;
	if(ok) return 8;

	ok = 1;
	for(i = 0; i < 5; i++)
	for(j = 0; j < 5; j++)
	if(matrice[i+lin][j+col] != noua[i][j])
	ok = 0;
	if(ok) return 9;

	return -1;
}
	
int main()
{
	struct bmp_fileheader *info;
	struct bmp_infoheader *info2;
	int i, j, width, height, m1, m2, m3, matrice_img[100][100], matrice_img1[100][100], widths;
	char nume_img[100], sfr[100], fis2[100];

	FILE* inp = fopen("input.txt", "rt"); //deschid fisierul din care vor fi extrase informatiile

	//in continuare se extrag informatiile necesare pentru taskurile 1 si 2
	fgets(nume_img, 100, inp);
	nume_img[strlen(nume_img)-1]='\0';
	fscanf(inp, "%d", &m1);
	fscanf(inp, "%d", &m2);
	fscanf(inp, "%d", &m3);

	FILE* f = fopen(nume_img, "rb");//deschid fisierul binar din care voi citi
	nume_img[strlen(nume_img)-4]='\0';
	strcpy(sfr, nume_img);
	strcat(sfr, "_task1.bmp");
	strcpy(fis2, nume_img);
	strcat(fis2, "_task2.txt");
	FILE* g = fopen(sfr, "wb");//deschid fisierul binar in care voi scrie rezultatul pentru task 1
	FILE* h = fopen(fis2, "wt");//deschid fisierul text in care voi scrie rezultatul pentru task 2

	info = calloc(14, sizeof(char));
	info2 = calloc(40, sizeof(char));
    
	fread(info, sizeof(char), 14, f); 
	fread(info2, sizeof(char), 40, f);

	//copiez dimensiunile imaginii in doua variabile mai usor de folosit
	width = (*info2).width;
	height = (*info2).height;

	fwrite(info, sizeof(char), 14, g);
	fwrite(info2, sizeof(char), 40, g);

	int *blu, *grn, *red;

	for(i = 0; i < height; i++)
	{
		for(j = 0; j < width; j++)
		{
			blu = calloc(1, sizeof(unsigned char));
			grn = calloc(1, sizeof(unsigned char));
			red = calloc(1, sizeof(unsigned char));
			fread(blu, sizeof(unsigned char), 1, f);
			fread(grn, sizeof(unsigned char), 1, f);
			fread(red, sizeof(unsigned char), 1, f);
			//am citit pixelii imaginii unul cate unul si am creat o matrice corespunzatoare imaginii
			if( blu[0]==255 && grn[0]==255 && red[0]==255 )
			matrice_img[i][j]=0;//pe locurile pixelilor albi am pus valoarea "0"
			else 
			{
				matrice_img[i][j]=1;//pe locurile pixelilor colorati am pus valoarea "1"
				//in continuare, am modificat culorile pixelilor colorati asa cum se cere la task 1
				blu[0] = m1;
				grn[0] = m2;
				red[0] = m3;
			}
			fwrite(blu, sizeof(unsigned char), 1, g);
			fwrite(grn, sizeof(unsigned char), 1, g);
			fwrite(red, sizeof(unsigned char), 1, g);
			//am scris pixelii unul cate unul intr-un alt fisier binar
			free(blu);
			free(grn);
			free(red);
		}

		//in cazul in care e nevoie, scriu paddingul in fisierul binar de output
		widths = width;
		while(widths%4)
		{
			fseek(f, 1, SEEK_CUR);
			putc('\0', g);
			widths--;
		}		
	}
	
	fclose(f);
	fclose(g);

	for(i = height-1; i >= 0; i--)
	{
		for(j = 0; j < width; j++)
		{
			matrice_img1[abs(i-height+1)][j] = matrice_img[i][j];
		}
	} 

	for(j = 0; j < width; j++)
	for(i = 0; i < height; i++)
	if(cifra(matrice_img1, i, j) >= 0) 
	{
		fprintf(h, "%d", cifra(matrice_img1, i, j));
	}

	return 0;
}

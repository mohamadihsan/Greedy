#include <stdio.h>
#include <conio.h>
#include <conio2.h>

#define max_node 	50
#define max1 		150
#define infinity 	5000

int matriks[max_node][max_node], i, j, jarak[max_node], kunjungan[max_node];
int mendahului[max_node], final=0;
int jalan[max1];
int jarak_kecil, jarak_baru, k, s, d, alur, n, alur_jalan;

void hasil_tampilan() {
	i = d;
	jalan[final] = d;
	final++;
 
	while(mendahului[i] != s) {
  		j = mendahului[i];
  		i = j;
  		jalan[final] = i;
  		final++;
	}

	jalan[final] = s;
	printf("\nJalur terpendek yang diikuti :\n\n");

	for(i = final; i > 0; i--)
 		printf("\t\t(%d -> %d) dengan harga/jarak =  %d\n\n", jalan[i], jalan[i-1], matriks[jalan[i]][jalan[i-1]]);

	printf("\nTotal harga/jarak = %d", jarak[d]);
}

main() {
	do
	{
		system("cls");
		printf("\n=============== ALGORTIMA DIJKSTRA ===============\n\n");
		printf("\nMasukkan jumlah node dalam matriks [1..50] :  ");
		scanf("%d", &n);
		if(n>50)
		{
			textcolor(LIGHTRED);printf("\nJumlah node hanya sampai 50\n");
			textcolor(WHITE);getch();
		}
	}while(n>50);
	printf("\nMasukkan harga/jarak matrix :\n\n");

	for(i = 0; i < n; i++) {
	  		for(j = 0; j < n; j++) {
	  			printf("Matrix Element [%d,%d]: ", i+1, j+1);
	    		scanf("%d",&matriks[i][j]);
	  		}
	}

	printf("\nMasukkan node sumber (0 ke %d) : ", n-1);
	scanf("%d", &s);
	do
	{
		printf("\nMasukkan node tujuan (0 ke %d) : ", n-1);
		scanf("%d", &d); 
		if(d>n-1)
		{
			textcolor(LIGHTRED);printf("Node tidak ada, Silahkan ULANGI");
			textcolor(WHITE);getch();
		}
		if(d==s)
		{
			textcolor(LIGHTRED);printf("\nNode berada di tempat yang tetap\n");
			textcolor(WHITE);printf("Jarak = 0");
			getch();exit(0);
		}
	}while(d>n-1);
	for(i = 0; i < n; i++) {
  		jarak[i] = infinity;
  		mendahului[i]  = infinity;
	}

	jarak[s]    = 0;
	alur        = s;
	kunjungan[alur] = 1;
	while(alur != d) {
  		alur_jalan  = jarak[alur];
  		jarak_kecil = infinity;
  
  		for(i = 0; i < n; i++) {
    		if(kunjungan[i] == 0) {
      			jarak_baru = alur_jalan + matriks[alur][i];
      			if(jarak_baru < jarak[i]) {
    				jarak[i] = jarak_baru;
    				mendahului[i]  = alur;
      			}
      			if(jarak[i]<jarak_kecil) {
    				jarak_kecil = jarak[i];
    				k = i;
      			}
    		}
    	}

  		alur = k;
  		kunjungan[alur] = 1;
	}

	hasil_tampilan();
	getch();
}


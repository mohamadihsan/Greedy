#include <stdio.h>
#include <conio.h>

#define MAXNODES 	50
#define MAX1 		150
#define INFINITY 	5000

int weight[MAXNODES][MAXNODES], i, j, jarak[MAXNODES], visit[MAXNODES];
int precede[MAXNODES], final=0;
int jalan[MAX1];
int smalldist, newdist, k, s, d, current, n, distcurr;

void Display_Result() {
	i = d;
	jalan[final] = d;
	final++;
 
	while(precede[i] != s) {
  		j = precede[i];
  		i = j;
  		jalan[final] = i;
  		final++;
	}

	jalan[final] = s;
	printf("\nJalur terpendek yang diikuti :\n\n");

	for(i = final; i > 0; i--)
 		printf("\t\t(%d -> %d) dengan harga/jarak =  %d\n\n", jalan[i], jalan[i-1], weight[jalan[i]][jalan[i-1]]);

	printf("\nTotal harga/jarak = %d", jarak[d]);
}

main() {
	printf("\nMasukkan jumlah node dalam matriks [1..50] :  ");
	scanf("%d", &n);
	printf("\nMasukkan harga/jarak matrix :\n\n");

	for(i = 0; i < n; i++) {
	  		for(j = 0; j < n; j++) {
	  			printf("Matrix Element [%d,%d]: ", i+1, j+1);
	    		scanf("%d",&weight[i][j]);
	  		}
	}

	printf("\nMasukkan node sumber (0 ke %d) : ", n-1);
	scanf("%d", &s);
	printf("\nMasukkan node tujuan (0 ke %d) : ", n-1);
	scanf("%d", &d); 
	for(i = 0; i < n; i++) {
  		jarak[i] = INFINITY;
  		precede[i]  = INFINITY;
	}

	jarak[s]    = 0;
	current        = s;
	visit[current] = 1;
	while(current != d) {
  		distcurr  = jarak[current];
  		smalldist = INFINITY;
  
  		for(i = 0; i < n; i++) {
    		if(visit[i] == 0) {
      			newdist = distcurr + weight[current][i];
      			if(newdist < jarak[i]) {
    				jarak[i] = newdist;
    				precede[i]  = current;
      			}
      			if(jarak[i]<smalldist) {
    				smalldist = jarak[i];
    				k = i;
      			}
    		}
    	}

  		current = k;
  		visit[current] = 1;
	}

	Display_Result();
	getch();
}
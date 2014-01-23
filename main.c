#include <stdio.h>
#include <conio.h>

#define MAXNODES 50
#define MAX1 150
#define INFINITY 5000

int weight[MAXNODES][MAXNODES], i, j, distance[MAXNODES], visit[MAXNODES];
int precede[MAXNODES], final=0;
int path[MAX1];
int smalldist, newdist, k, s, d, current, n, distcurr;

void Display_Result() {
	i = d;
	path[final] = d;
	final++;
 
	while(precede[i] != s) {
  		j = precede[i];
  		i = j;
  		path[final] = i;
  		final++;
	}

	path[final] = s;
	printf("\nThe shortest path followed is :\n\n");

	for(i = final; i > 0; i--)
 		printf("\t\t(%d -> %d) with cost = %d\n\n", path[i], path[i-1], weight[path[i]][path[i-1]]);

	printf("\nFor total cost = %d", distance[d]);
}

main() {
	printf("\nEnter the number of nodes(Less than 50)in the matrix : ");
	scanf("%d", &n);
	printf("\nEnter the cost matrix :\n\n");

	for(i = 0; i < n; i++)
  		for(j = 0; j < n; j++)
    		scanf("%d",&weight[i][j]);

	printf("\nEnter the source node (0 to %d) : ", n-1);
	scanf("%d", &s);
	printf("\nEnter the destination node (0 to %d) : ", n-1);
	scanf("%d", &d); 
	for(i = 0; i < n; i++) {
  		distance[i] = INFINITY;
  		precede[i]  = INFINITY;
	}

	distance[s]    = 0;
	current        = s;
	visit[current] = 1;
	while(current != d) {
  		distcurr  = distance[current];
  		smalldist = INFINITY;
  
  		for(i = 0; i < n; i++) {
    		if(visit[i] == 0) {
      			newdist = distcurr + weight[current][i];
      			if(newdist < distance[i]) {
    				distance[i] = newdist;
    				precede[i]  = current;
      			}
      			if(distance[i]<smalldist) {
    				smalldist = distance[i];
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
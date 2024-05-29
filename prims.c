// Prim's Algorithm in C

#include<stdio.h>
#include<stdbool.h> 

#define INF 9999999

#define v 5

int G[v][v] = {
  {0, 9, 75, 0, 0},
  {9, 0, 95, 19, 42},
  {75, 95, 0, 51, 66},
  {0, 19, 51, 0, 31},
  {0, 42, 66, 31, 0}};

int main() {
 int visited[v];
 
for(int x=0; x<v; x++){
    visited[x]=0;
}
 visited[0]=1;
 int no_edges=0, i=0,j=0,x,y;
 
 while(no_edges< v-1){
         int min=INF;

 for (i=0; i < v; i++){
     if (visited[i]==1){
         for (j=0; j< v;j++){
             if(visited[j]!=1 && G[i][j]!=0){
                 if(G[i][j]<min){
                     min=G[i][j];
                     x=i;
                     y=j;
                 }
             }
         }
     }
 }
 printf("%d - %d: %d\n",x,y,G[x][y]);
 visited[y]=1;
 no_edges++;
}
}

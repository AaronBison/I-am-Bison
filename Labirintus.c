#include "Labirintus.h"
#include <stdio.h>
#include <stdlib.h>

LAB *Create(const char *allomany)
{
    LAB *labi = (LAB *)calloc(1, sizeof(LAB));
    int n,m,i,j,ex,ey,sx,sy;
    FILE*f=fopen(allomany,"r");
    fscanf(f,"%d%d",&n,&m);

    labi->n=n;
    labi->m=m;

    labi->labirint = (int **)calloc(n+2, sizeof(int*));
    for(i=0; i<n+2; i++)
        labi->labirint[i] = (int *)calloc(m+2, sizeof(int));

    for(i=1;i<n+1;i++)
        for(j=1;j<m+1;j++)
            fscanf(f,"%d",&labi->labirint[i][j]);

    fscanf(f,"%d%d",&ex,&ey);
    labi->ex=ex+1;
    labi->ey=ey+1;

    fscanf(f,"%d%d",&sx,&sy);
    labi->sx=sx+1;
    labi->sy=sy+1;

    labi->labirint[ex+1][ey+1]=2;
    labi->labirint[sx+1][sy+1]=3;


    return labi;
}

void print(LAB *a)
{
    int i,j;
    for(i=1;i<a->n+1;i++){
        for(j=1;j<a->m+1;j++)
            printf("%d ",a->labirint[i][j]);
    printf("\n");
    }
}

void printcsel(LAB *a)
{
    int i,j;
    for(i=0;i<a->n+2;i++){
        for(j=0;j<a->m+2;j++)
            switch( a->labirint[i][j] )
            {
            case 0:
                printf("+ ");
                break;
            case 1:
                printf(". ");
                break;
            case 2:
                printf("e ");
                break;
            case 3:
                printf("s ");
                break;
            }
    printf("\n");
    }
}

void destroy(LAB *a)
{
    int i;
    for(i=0;i<a->n;i++)
        free(a->labirint[i]);
    free(a->labirint);
}

int Solved(LAB *a)
{
    if(a->ex==a->sx && a->ey==a->sy)
        return 1;
    return 0;
}

void Move(LAB *a,char step)
{
    int ex,ey;

    ex=a->ex;
    ey=a->ey;

    switch ( step ){
        case 'A':
            if(a->labirint[ex][ey-1]!=0){
                    a->labirint[ex][ey-1]=2;
                    a->labirint[ex][ey]=1;
                    ey=ey-1;
            }
            break;

        case 'S':
            if(a->labirint[ex+1][ey]!=0){
                    a->labirint[ex+1][ey]=2;
                    a->labirint[ex][ey]=1;
                    ex=ex+1;
            }
            break;

        case 'D':
            if(a->labirint[ex][ey+1]!=0){
                    a->labirint[ex][ey+1]=2;
                    a->labirint[ex][ey]=1;
                    ey=ey+1;
            }
            break;

        case 'W':
            if(a->labirint[ex-1][ey]!=0){
                    a->labirint[ex-1][ey]=2;
                    a->labirint[ex][ey]=1;
                    ex=ex-1;
            }
            break;
        }
        a->ex=ex;
        a->ey=ey;
}

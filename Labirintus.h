#ifndef LABIRINTUS_H_INCLUDED
#define LABIRINTUS_H_INCLUDED

typedef struct LAB{
    int n,m;
    int **labirint;
    int ex,ey;
    int sx,sy;
} LAB;

LAB *Create(const char *);
void destroy(LAB *);
void print(LAB *);
void printcsel(LAB *);
void Move(LAB *,char);
int Solved(LAB *);

#endif // LABIRINTUS_H_INCLUDED

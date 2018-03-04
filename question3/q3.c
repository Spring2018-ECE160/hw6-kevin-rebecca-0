#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#define MAX 100000

char *lineptr[MAX];
static char allocbuf[MAX];
static char *allocp = allocbuf;


int mygetline(char *, int);
int numcmp(char *s1, char *s2);
int strcmp_f(char *, char *);
int readlines(char *lineptr[], int nlines);
char *alloc(int);
void writelines(char *lineptr[], int nlines);
void qsort(void *lineptr[], int left, int right, 
           int (*comp)(void *, void *));

int main(int argc, char *argv[]) 
{
    int numeric = 0, fold = 0, reverse = 0;
    int nlines;
    int c;
	while ((c = getopt (argc, argv, "n::f::r::")) != -1) 
    {
	    switch (c) 
        {
			case 'n':
				numeric = 1;	
				break;
			case 'f':
				fold = 1;	
				break;
			case 'r':
				reverse = 1;	
				break;
		}
	}
    if ((nlines = readlines(lineptr, MAX)) >= 0) 
    {
		printf("Input:\n");
		writelines(lineptr, nlines);
        qsort((void **) lineptr, 0, nlines-1,
          (int (*)(void*, void*))(numeric ? numcmp : (fold ? strcmp_f : strcmp)));
		if(reverse == 1) 
        {
			for(int i = 0, j = nlines - 1; i < nlines/2 && j > 0; i++, j--) 
            {
				swap(lineptr, i, j);
			}
			printf("\nOutput:\n");
			writelines(lineptr, nlines);
		}
		else 
        {        
			printf("\nOutput:\n");			
			writelines(lineptr, nlines);
		}
        return 0;
    }
    else 
    {
        printf("Input too large.\n");
        return 1;
    }
    return 0;
}

int readlines(char *lineptr[], int maxlines)
{
    int len, nlines;
    char *p, line[MAX];

    nlines = 0;
    while ((len = mygetline(line, MAX)) > 0)
    {
        if (nlines >= maxlines || (p = alloc(len)) == NULL)
            return -1;
        else
        {
            line[len-1] = '\0';
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    }
    return nlines;
}



char *alloc(int n)
{
    if (allocbuf + MAX - allocp >= n)
    {
        allocp += n;
        return allocp - n;
    }
    else
        return 0;
}

void afree(char *p)
{
    if (p >= allocbuf && p < allocbuf + MAX)
        allocp = p;
}

int mygetline(char s[], int lim)
{
    int c, i;

    i = 0;
    while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}

void qsort(void *v[], int left, int right, int (*comp)(void *, void *))
{
    int i, last;
    void swap(void *v[], int, int);
    if (left >= right)
        return;
    swap(v, left, (left + right)/2);
    last = left;
    for (i = left+1; i <= right; i++)
        if ((*comp)(v[i], v[left]) < 0)
            swap(v, ++last, i);
    swap(v, left, last);
    qsort(v, left, last-1, comp);
    qsort(v, last+1, right, comp);
}

void swap(void *v[], int i, int j)
{
    void *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

void writelines(char *lineptr[], int nlines)
{
    int i;
    for (i = 0; i < nlines; i++)
        printf("%s\n", lineptr[i]);
}

int numcmp(char *s1, char *s2)
{
    double v1, v2;

    v1 = atof(s1);
    v2 = atof(s2);
    if (v1 < v2)
        return -1;
    else if (v1 > v2)
        return 1;
    else
        return 0;
}

int strcmp_f(char *s, char *t)
{
    for ( ; toupper(*s) == toupper(*t); s++, t++)
        if (*s == '\0')
            return 0;

    return toupper(*s) - toupper(*t);
}



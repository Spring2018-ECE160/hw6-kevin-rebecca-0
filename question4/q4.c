#include <stdio.h>
#include <math.h>

struct point{
	
	int x;
	int y;
};

struct coef{
	
	int a;
	int b;
	int c;

};

struct point compute_point(struct coef abc, int x){
	
	struct point p;
	p.x = x;
	p.y = abc.a*(pow(p.x, 2)) + abc.b*p.x + abc.c;
	
	return p;
};

void main(){
	
	struct coef abc;
	printf("Enter 3 coefficients: \n");
	scanf("%d%d%d", &abc.a, &abc.b, &abc.c);
	
	struct point compute_point(struct coef, int);
	struct point p;
	
	int n = 1;
	for (int i = -5; i < 6; i++){
		p = compute_point(abc, i);
        	printf("point %d: (%d, %d)\n", n, p.x, p.y);
		n++;
	}
}

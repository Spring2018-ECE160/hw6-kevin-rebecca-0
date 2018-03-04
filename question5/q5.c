#include <stdio.h>

struct earthquake{
	int year;
	float mag7; //number of earthquakes with magnitude 7-7.9
	float mag6; //number of earthquakes with magnitude 6-6.9
	float mag5; //number of earthquakes with magnitude 5-5.9
};

struct dataSet{	
	struct earthquake e1;
	struct earthquake e2;
	struct earthquake e3;
        struct earthquake e4;
	struct earthquake e5;
        struct earthquake e6;
        struct earthquake e7;
        struct earthquake e8;
	struct earthquake e9;
        struct earthquake e10;
	struct earthquake e11;
        struct earthquake e12;
        struct earthquake e13;
};

/* Returns average magnitude for a given year. */
float avgMag(struct earthquake e){
	float avg = ((e.mag7*7.5) + (e.mag6*6.5) + (e.mag5*5.5))/(7.5+6.5+5.5); //assuming avg of each range is halway between min and max
	return avg;
}

/* Returns average magnitude of all the years. */
float totalAvg(struct dataSet ds){

        float avgMagTot =
        (avgMag(ds.e1)+
        avgMag(ds.e2)+
        avgMag(ds.e3)+
        avgMag(ds.e4)+
        avgMag(ds.e5)+
        avgMag(ds.e6)+
        avgMag(ds.e7)+
        avgMag(ds.e8)+
        avgMag(ds.e9)+
        avgMag(ds.e10)+
        avgMag(ds.e11)+
        avgMag(ds.e12)+
        avgMag(ds.e13))/13;
	
	return avgMagTot;
}

/* Finds the year with greatest average magnitude*/
struct earthquake findGreatest(struct dataSet ds){
	
	struct earthquake e[13] = {ds.e1, ds.e2, ds.e3, ds.e4, ds.e5, ds.e6, ds.e7, ds.e8, ds.e9, ds.e10, ds.e11, ds.e12, ds.e13};
	struct earthquake max;
	int maxIndex = 0;
	for (int i = 0; i < 14; i++){
		if (avgMag(e[i]) > avgMag(e[maxIndex]))
			maxIndex = i;
	}
	max = e[maxIndex];
	return max;

}

void main(){
	
	struct dataSet ds;

	ds.e1.year = 2000;
	ds.e2.year = 2001;
	ds.e3.year = 2002;
	ds.e4.year = 2003;
	ds.e5.year = 2004;
	ds.e6.year = 2005;
	ds.e7.year = 2006;
	ds.e8.year = 2007;
	ds.e9.year = 2008;
	ds.e10.year = 2009;
	ds.e11.year = 2010;
	ds.e12.year = 2011;
	ds.e13.year = 2012;

	ds.e1.mag5 = 63;
        ds.e2.mag5 = 41;
        ds.e3.mag5 = 63;
        ds.e4.mag5 = 54;
        ds.e5.mag5 = 25;
        ds.e6.mag5 = 47;
        ds.e7.mag5 = 51;
        ds.e8.mag5 = 72;
        ds.e9.mag5 = 85;
        ds.e10.mag5 = 58;
        ds.e11.mag5 = 89;
        ds.e12.mag5 = 51;
        ds.e13.mag5 = 27;

	ds.e1.mag6 = 6;
        ds.e2.mag6 = 5;
        ds.e3.mag6 = 4;
        ds.e4.mag6 = 7;
        ds.e5.mag6 = 2;
        ds.e6.mag6 = 4;
        ds.e7.mag6 = 7;
        ds.e8.mag6 = 9;
        ds.e9.mag6 = 9;
        ds.e10.mag6 = 4;
        ds.e11.mag6 = 8;
        ds.e12.mag6 = 3;
        ds.e13.mag6 = 5;

	ds.e1.mag7 = 0;
        ds.e2.mag7 = 1;
        ds.e3.mag7 = 1;
        ds.e4.mag7 = 2;
        ds.e5.mag7 = 0;
        ds.e6.mag7 = 1;
        ds.e7.mag7 = 0;
        ds.e8.mag7 = 1;
        ds.e9.mag7 = 0;
        ds.e10.mag7 = 0;
        ds.e11.mag7 = 1;
        ds.e12.mag7 = 1;
        ds.e13.mag7 = 0;

	printf("The average earthquake magnitude in the US in %i was %f\n", ds.e1.year, avgMag(ds.e1));
	printf("The average earthquake magnitude in the US in %i was %f\n", ds.e2.year, avgMag(ds.e2));
	printf("The average earthquake magnitude in the US in %i was %f\n", ds.e3.year, avgMag(ds.e3));
	printf("The average earthquake magnitude in the US in %i was %f\n", ds.e4.year, avgMag(ds.e4));
        printf("The average earthquake magnitude in the US in %i was %f\n", ds.e5.year, avgMag(ds.e5));
        printf("The average earthquake magnitude in the US in %i was %f\n", ds.e6.year, avgMag(ds.e6));
	printf("The average earthquake magnitude in the US in %i was %f\n", ds.e7.year, avgMag(ds.e7));
        printf("The average earthquake magnitude in the US in %i was %f\n", ds.e8.year, avgMag(ds.e8));
        printf("The average earthquake magnitude in the US in %i was %f\n", ds.e9.year, avgMag(ds.e9));
        printf("The average earthquake magnitude in the US in %i was %f\n", ds.e10.year, avgMag(ds.e10));
        printf("The average earthquake magnitude in the US in %i was %f\n", ds.e11.year, avgMag(ds.e11));
        printf("The average earthquake magnitude in the US in %i was %f\n", ds.e12.year, avgMag(ds.e12));
	printf("The average earthquake magnitude in the US in %i was %f\n", ds.e13.year, avgMag(ds.e13));

	printf("\nThe year with the highest average earthquake magnitude was %i.\nThe magnitude was %f\n", findGreatest(ds).year, avgMag(findGreatest(ds)));
	
	printf("\nThe average earthquake magnitude in the US between 2000 and 2012 was %f\n", totalAvg(ds));
	
	return;
}


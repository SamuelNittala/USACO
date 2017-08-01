/*
 ID: nittala2
 PROB: friday
 LANG: CPP
 */
#include<cstdio>
/*
 * J-1,F-2,M-3,A-4,M-5,JUNE-6,July-7,Aug-8,Sep-9,Oct-10
 * Nov-10,Dec-12
 */
 bool isLeap(int year){
	 if(year%100==0){
		 return year%400==0;
	 }
	 else return year%4==0;
 }
int main(){
	int freq[7];
	for(int i=0;i<7;i++){
		freq[i]=0;
	}
	int year[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	int leap[12]={31,29,31,30,31,30,31,31,30,31,30,31};
	int current_day=0;
	FILE* fin = fopen("friday.in","r");
	FILE* fout = fopen("friday.out","w");
	int year_1;
	fscanf(fin,"%d",&year_1);
	for(int c_year=1900;c_year<1900+year_1;c_year++){
		for(int month=0;month<12;month++){
			int p_day = (current_day+12)%7;
			freq[p_day]++;
			current_day+=isLeap(c_year)?leap[month]:year[month];
		}
	}
	fprintf(fout,"%d %d",freq[5],freq[6]);
	for(int i=0;i<5;i++){
		fprintf(fout," %d",freq[i]);
	}
	fprintf(fout,"\n");
	return 0;
}

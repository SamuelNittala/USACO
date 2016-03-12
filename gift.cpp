/*
 ID: nittala2
 LANG: C++
 PROB: gift1
 */
#define MAX 20
#include<cstdio>
#include<cstring>
struct acc{
	char name[MAX];
	int given;
	int received;
};
int main(){
	FILE* fin = fopen("gift1.in","r");
	FILE* fout = fopen("gift1.out","w");
	int n;
	fscanf(fin,"%d",&n);
	struct acc users[n];
	for(int i=0;i<n;i++){
		users[i].given = 0;
		users[i].received = 0;
	}
	for(int i=0;i<n;i++)
		fscanf(fin,"%s",users[i].name);
	for(int i=0;i<n;i++){
		int j=0;
		char temp[MAX];
		fscanf(fin,"%s",temp);
		while(strcmp(temp,users[j].name)!=0) j++;
		int am,d;
		fscanf(fin,"%d %d",&am,&d);
		if(d!=0){
			char n_temp[MAX];
			int rec = am/d;
			users[j].given=rec*d;
			for(int k=0;k<d;k++){
				int p=0;
				fscanf(fin,"%s",n_temp);
				while(strcmp(n_temp,users[p].name)!=0) p++;
				users[p].received += rec;
			}
		}
		else
		{
			users[j].given = 0;
		}
	}
	for(int i=0;i<n;i++){
		fprintf(fout,"%s %d\n",users[i].name,(users[i].received-users[i].given));
	}
	return 0;
}
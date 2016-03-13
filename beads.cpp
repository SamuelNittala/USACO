/*
 ID: nittala2
 LANG: C++
 PROB: beads
 */
 #include<cstdio>
 #include<cstring>
 #include<cassert>
 #define MAX 350
 #define MIN 3
 int max(int a,int b){
	 if(a>=b) return a;
	 else return b;
 }
 int main(){
	FILE* fin = fopen("beads.in","r");
	FILE* fout = fopen("beads.out","w");
	int total,red,blue,red_op,blue_op;
	int size,max_val;
	max_val=0;
	fscanf(fin,"%d",&size);
	assert(size<=MAX);
	assert(size>=MIN);
	char beads[size];
	fscanf(fin,"%s",beads);
	for(int i=1;i<size;i++){
		char temp[size];
		int b_r,b_l;
		for(int j=0;j<size;j++) temp[j]=0;
		for(int j=0;j<size;j++)
			temp[j] = beads[(j+i)%size];
		//blue beads if white set to blue(->)
		int j=0;
		total=0;
		blue=0;
		while(temp[j] != 'r'&&j<size){
			blue++;
			j++;
		}
		j=0;
		red=0;
		//red beads(->)
		while(temp[j]!='b'&&j<size){
			red += 1;
			j++;
		}
		total+=max(blue,red);
		max(blue,red)==blue?b_r=1:b_r=-1;
		//opp blue b->w(<-)
		j=size-1;
		blue_op=0;
		while(temp[j] != 'r'&&j>=0){
			blue_op++;
			j--;
		}
		//red opp r->w
		j=size-1;
		red_op=0;
		while(temp[j]!='b'&&j>=0){
			red_op++;
			j--;
		}
		max(blue_op,red_op)==blue_op?b_l=1:b_l=-1;
		if(b_r==b_l) total=max(blue_op,red_op);
		else total+=max(blue_op,red_op);
		max_val = max(max_val,total);
	}
	fprintf(fout,"%d\n",max_val);
 }
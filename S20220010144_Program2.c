#include<stdio.h>

int main(){

	FILE *fp;
	FILE *rs;
	fp = fopen("S20220010144_cust.txt" , "r");
	rs = fopen("S20220010144_master.txt" , "w");

	char c;
	int line=1;
	int meter;
	int prevRed , currRed;
	while((c = fgetc(fp)) != EOF){

		if(c == '\n'){
			line++;
			
		}

		if(line == 1){
			fseek(fp , -1,1);
			
			fscanf(fp , "%d" , &meter);
			fprintf(rs , "Meter %d\n", meter);
		}else if(line == 2){
			fseek(fp , -1 , 1);
			char name[100];
			fscanf(fp , "%s" , name);
			fprintf(rs , "Name : %s\n" , name);
		}else if(line == 3){
			fseek(fp , -1,1);
			
			fscanf(fp , "%d" , &currRed);
			fprintf(rs , "Current Reading %d\n", currRed);
		}else if(line == 4){
			fseek(fp , -1,1);
			fscanf(fp , "%d" , &prevRed);
			fprintf(rs , "Previous Reading : %d\n", prevRed);
		}
	}

	float diff = currRed - prevRed;
	printf("%f" , diff);
	fprintf(rs , "UNIT : %f\n" , diff);

	float amt =0;
	if (diff <= 50) {
       amt = diff;
   } else if (diff <= 100) {
       amt = 50 + (diff - 50) * 1.5;
   } else {
       amt = 50 + 50 * 1.5 + (diff - 100) * 2;
   }

	
	

	fprintf(rs , "Amount : %f\n" , amt);

}
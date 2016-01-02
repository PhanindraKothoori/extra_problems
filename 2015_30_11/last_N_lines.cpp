#include<stdio.h>
#include<conio.h>
#include<malloc.h>
void last_N_lines(FILE *fp, int N){
	fseek(fp, 0, SEEK_END);
	char s[50];
	int p = ftell(fp);
	printf("%s", fgets(s, sizeof(s), fp));
	fseek(fp, -2, SEEK_SET);
	printf("%s", fgets(s, sizeof(s), --fp));
	while (N--){
		
		if (fgetc(fp) == '\n'){
			if (N-- == 0){
				break;
			}
		}
		printf("%s", fgets(s, sizeof(s), fp));
	}
}
int main(){
	FILE *fp = fopen("asdf.cpp", "r");
	char c, s[5];
	printf("%s", fgets(s, sizeof(s), fp));
	fseek(fp, -1, SEEK_END);
	int n = 9, i = n-1;
	while (n){
		c = fgetc(fp);
		
 		if (c == '\n'){
			n--;
			fseek(fp, -1, SEEK_CUR);
		}
		if (n){
			fseek(fp, -2, SEEK_CUR);
		}
	}
	while (fgets(s, sizeof(s), fp) != NULL){
		printf("%s",s);
	}
	getch();
	return 0;
}
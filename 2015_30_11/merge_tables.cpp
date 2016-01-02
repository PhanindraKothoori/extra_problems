#include<stdio.h>
#include<conio.h>
int merge_tables(int a, int b, int r){
	int i = 1, j = 1;
	int temp;
	//calculate temp as the required number
	while (r > 0){
		if (a*i < b*j){
			temp = a*i;
			i++;
		}
		else if (a*i == b*j){//for common multiples, we need to calculate only once
			temp = a*i;
			i++;
			j++;
		}
		else{
			temp = b*j;
			j++;
		}
		r--;
	}
	return temp;
}


int main(){
	printf("%d", merge_tables(3, 5, 5));
	getch();
	return 0;
}
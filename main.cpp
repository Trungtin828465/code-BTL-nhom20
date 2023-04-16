#include <iostream>
#include<string.h>
#include<ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include"tep.h"
int main(int argc, char** argv) {
	int A1[1000], A2[1000], A3[1000];
	int dem1 = 0, dem2 = 0, dem3 = 0;
	int tong = 0;
	SList sl1, sl2, sl3;
	KH a;
	Menu(a,&A1[1000],dem1,&A2[1000],dem2,&A3[1000], dem3, sl1,sl2, sl3, tong);
	Inbill();
	return 0;
}

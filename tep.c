#include"tep.h"
SNode* createSNode(ItemType x)
{
	SNode* p = new SNode;
	if (p == NULL)
	{
		printf("Khong the cap phat nut moi.");
		//getch();
		return NULL;
	}
	p->Info = x;
	p->Next = NULL;
	return p;
}

void showSNode(SNode* p)
{
	printf("%5d", p->Info);
}

void initSList(SList& sl)
{
	sl.Head = NULL;
	sl.Tail = NULL;
}

int isEmpty(SList sl)
{
	if (sl.Head == NULL)
		return 1;
	return 0;
}

int insertHead(SList& sl, SNode* p)
{
	if (p == NULL) return 0;
	if (isEmpty(sl) == 1)
	{
		sl.Head = p;
		sl.Tail = p;
	}
	else

	{
		p->Next = sl.Head;
		sl.Head = p;
	}
	return 1;
}

void showSList(SList sl)
{
	if (isEmpty(sl))
	{
		printf("Danh sach rong.");
		return;
	}
	SNode* p = sl.Head;
	while (p != NULL)
	{
		showSNode(p);
		p = p->Next;
	}

}

int deleteHead(SList& sl, ItemType& x)
{
	if (isEmpty(sl) == 1)
	{
		return 0;
	}
	SNode* p = sl.Head;
	sl.Head = sl.Head->Next;
	if (sl.Head == NULL)
	{
		sl.Tail == NULL;
	}
	x = p->Info;
	delete p;
	return 1;
}

void createSList(SList& sl, int A[], int dem)
{
	initSList(sl);
	for (int i = 0; i < dem; i++)
	{
		ItemType x = A[i];
		SNode* p = createSNode(x);
		insertHead(sl, p);
		//showSNode(p); 
	}
}

int Tinhtienmonnuong(SList sl, int tong, int dem) {
	for (int i = 0; i < dem; i++)
	{
		int x = 0;
		deleteHead(sl, x);
		if (x == 1)
			x = 120;
		if (x == 2)
			x = 70;
		if (x == 3)
			x = 210;
		if (x == 4)
			x = 150;
		if (x == 5)
			x = 120;
		if (x == 6)
			x = 140;
		tong = tong + x;
	}
	return tong;
}

int Tinhtienmonlau(SList sl, int tong, int dem) {
	for (int i = 0; i < dem; i++) {
		int x;
		deleteHead(sl, x);
		if (x == 1)
			x = 90;
		if (x == 2)
			x = 100;
		if (x == 3)
			x = 125;
		if (x == 4)
			x = 100;
		if (x == 5)
			x = 95;
		if (x == 6)
			x = 130;
		tong = tong + x;
	}
	return tong;
}

int Tinhtienmonnuoc(SList sl, int tong, int dem) {
	for (int i = 0; i < dem; i++) {
		int x;
		deleteHead(sl, x);
		if (x == 1)
			x = 15;
		if (x == 2)
			x = 13;
		if (x == 3)
			x = 10;
		if (x == 4)
			x = 10;
		if (x == 5)
			x = 10;
		if (x == 6)
			x = 10;
		tong = tong + x;
	}
	return tong;
}

void Tinhtientong(SList sl1, SList sl2, SList sl3, int tong, int dem1, int dem2, int dem3) {
	tong = Tinhtienmonnuong(sl1, tong, dem1) + Tinhtienmonlau(sl2, tong, dem2) + Tinhtienmonnuoc(sl3, tong, dem3);
	printf("Tong tien du kien la:%d", tong);
	FILE*f;
	f=fopen("tinhtong.txt","w");
	fputs("Tong Bill Cua Quy Khach La: ",f);
	fprintf(f,"%d",tong);
	fclose(f);
}

void  Danhsachmonnuong(int A1[], int &dem1) {
	FILE* f;
	f = fopen("anuong.txt", "r");
	if (f != NULL) {
		char c = fgetc(f); 
		while (c != EOF) {
			printf("%c", c);
			c = fgetc(f);
		}
	}
	printf("\n");
	int i;
	printf("Nhap mon can chon! Muon dung nhan 0");
	for (int i = 0; i < 20; i++) {
		printf("\nMon thu %d: ", i + 1);
		scanf("%d", &A1[i]);
		dem1++;
		if (A1[i] == 0) {
			dem1--;
			break;
		}
	}
		printf("\n");
	fclose(f);
}
	
void Xuatmonnuong(int A1[], int &dem1){
	printf("\n==Danh sach cac mon NUONG da chon==\n");
	for (int i = 0; i < dem1; i++) {
		if (A1[i] == 1)
			printf("1. Thit Ba Chi Nuong     120k\n");
		if (A1[i] == 2)
			printf("2. Tom Nuong Muoi Ot     70k\n");
		if (A1[i] == 3)
			printf("3. Thit Bo Nuong Tang    210k\n");
		if (A1[i] == 4)
			printf("4. Thit Bo Nuong Cay     1500k\n");
		if (A1[i] == 5)
			printf("5. Muc Nuong             120k\n");
		if (A1[i] == 6)
			printf("6. Suon Nuong Han Quoc   140k\n");
	}
	printf("\n");
}
	
void Innuong(int A1[], int &dem1){
	FILE *f;
    f = fopen("monnuong.txt","w");
    fprintf(f,"<<Danh sach mon nuong>>\n");
    if (f == NULL) {
        printf("Khong the mo file de ghi!");
        return;
    }
    for (int i = 0; i < dem1; i++) {
        if (A1[i] == 1)
            fprintf(f, "1. Thit Ba Chi Nuong     120k\n");
        if (A1[i] == 2)
            fprintf(f, "2. Tom Nuong Muoi Ot     70k\n");
        if (A1[i] == 3)
            fprintf(f, "3. Thit Bo Nuong Tang    210k\n");
        if (A1[i] == 4)
            fprintf(f, "4. Thit Bo Nuong Cay     150k\n");
        if (A1[i] == 5) 
            fprintf(f, "5. Muc Nuong             120k\n");
        if (A1[i] == 6)
            fprintf(f, "6. Suon Nuong Han Quoc   140k\n");
    }
    fclose(f);
}

void Danhsachmonlau(int A2[], int &dem2) {
	FILE* f;
	f = fopen("alau.txt", "r");
	if (f != NULL) {
		char c = fgetc(f);
		while (c != EOF) {
			printf("%c", c);
			c = fgetc(f);
		}
	}
	printf("\n");
	int i;
	printf("Nhap mon can chon! Muon dung nhan 0");
	for (int i = 0; i < 20; i++) {
		printf("\nMon thu %d: ", i + 1);
		scanf("%d", &A2[i]);
		dem2++;
		if (A2[i] == 0) {
			dem2--;
			break;
		}
	}
		printf("\n");
	fclose(f);
}

void Xuatmonlau(int A2[], int dem2) {
    printf("\n==Danh sach cac mon LAU da chon==\n");
    for (int i = 0; i < dem2; i++) {
        if (A2[i] == 1)
            printf("1. Lau Thap Cam          90k\n");
        if (A2[i] == 2)
            printf("2. Lau Thai Chua Cay     100k\n");
        if (A2[i] == 3)
            printf("3. Lau Ca Keo            125k\n");
        if (A2[i] == 4)
            printf("4. Lau Ech               100k\n");
        if (A2[i] == 5)
            printf("5. Lau Reu Cua           95k\n");
        if (A2[i] == 6)
            printf("6. Lau Bo                130k\n");
    }
    printf("\n");
}
    
void Inlau(int A2[], int &dem2){
    FILE *f;
    f = fopen("monlau.txt","w");
    fprintf(f,"<<Danh sach mon lau>>\n");
    if (f == NULL) {
        printf("Khong the mo file de ghi!");
        return;
    }
    for (int i = 0; i < dem2; i++) {
        if (A2[i] == 1)
            fprintf(f, "1. Lau Thap Cam          90k\n");
        if (A2[i] == 2)
            fprintf(f, "2. Lau Thai Chua Cay     100k\n");
        if (A2[i] == 3)
            fprintf(f, "3. Lau Ca Keo            125k\n");
        if (A2[i] == 4)
            fprintf(f, "4. Lau Ech               100k\n");
        if (A2[i] == 5)
            fprintf(f, "5. Lau Reu Cua           95k\n");
        if (A2[i] == 6)
            fprintf(f, "6. Lau Bo                130k\n");
    }
    fclose(f);
}

void Danhsachmonnuoc(int A3[], int &dem3) {
	FILE* f;
	f = fopen("anuoc.txt", "r");
	if (f != NULL) {
		char c = fgetc(f);
		while (c != EOF) {
			printf("%c", c);
			c = fgetc(f);
		}
	}
	printf("\n");
	int i;
	printf("Nhap mon can chon! Muon dung nhan 0");
	for (int i = 0; i < 20; i++) {
		printf("\nMon thu %d: ", i + 1);
		scanf("%d", &A3[i]);
		dem3++;
		if (A3[i] == 0) {
			dem3--;
			break;
		}
	}
		printf("\n");
	fclose(f);
}

void Xuatmonnuoc(int A3[], int &dem3){

	printf("\n==Danh sach cac mon NUOC da chon==\n");
	for (int i = 0; i < dem3; i++) {
		if (A3[i] == 1)
			printf("1. Bia Tiger              15k\n");
		if (A3[i] == 2)
			printf("2. Bia SaiGon             13k\n");
		if (A3[i] == 3)
			printf("3. Sting                  10k\n");
		if (A3[i] == 4)
			printf("4. 7up                    10k\n");
		if (A3[i] == 5)
			printf("5. Pepsi                  10k\n");
		if (A3[i] == 6)
			printf("6. Nuoc Suoi              10k\n");
	}
	printf("\n");
}
	
void Innuoc(int A3[], int &dem3){
    FILE *f;
    f = fopen("monnuoc.txt","w");
    fprintf(f,"<<Danh sach mon nuoc>>\n");
    if (f == NULL) {
        printf("Khong the mo file de ghi!");
        return;
    }
    for (int i = 0; i < dem3; i++) {
        if (A3[i] == 1)
            fprintf(f, "1. Bia Tiger             15k\n");
        if (A3[i] == 2)
            fprintf(f, "2. Bia SaiGon            13k\n");
        if (A3[i] == 3)
            fprintf(f, "3. Sting                 10k\n");
        if (A3[i] == 4)
            fprintf(f, "4. 7up                   10k\n");
        if (A3[i] == 5)
            fprintf(f, "5. Pepsi                 10k\n");
        if (A3[i] == 6)
            fprintf(f, "6. Nuoc Suoi             10k\n");
    }
    fclose(f);
}

KH Nhap(KH a){
    getchar();
	printf("Vui long nhap ten khach hang vao: ");        gets(a.ten);
	printf("Vui long nhap tuoi cua khach hang: ");       scanf("%d",&a.tuoi);
	getchar();
	printf("Vui long nhap gioi tinh cua khach hang: ");  gets(a.gioitinh);
	printf("Vui long nhap SDT: "); 	                     scanf("%s",&a.SDT);
	printf("\n");
	getchar();
	return a;
}

void Phanhoi(){
    char *dg;
    int sao;
    printf("nhap vao danh gia cua ban:\n");
    getchar();
    dg = (char*)malloc(1000 * sizeof(char));
    if (dg == NULL) {
        printf("Khong the cap phat bo nho dong.");
        return;
    }
    gets(dg);
    printf("nhap so sao ban muon danh gia:\n");
    scanf("%d", &sao);
    FILE*P;
    P=fopen("phanhoi.txt","w");
    fputs("Phan hoi cua khach la: ",P);
    fputs(dg,P);
    fputs("\n",P);
    fputs("So sao danh gia: ",P);
    fprintf(P,"%d",sao);
    fclose(P);
    free(dg);
}

void Xuat(KH a) {
	printf("-Ten : %s\n",a.ten);
	printf("-Tuoi: %d\n",a.tuoi);
	printf("-Gioi tinh: %s\n",a.gioitinh);
	printf("-SDT: %s\n",a.SDT);
}

void Infile(KH a) {
	FILE* f;
	f=fopen("thongtin.txt", "w");
	fprintf(f, "--Ten khach hang: %s", a.ten);  fputs("\n",f);
	fprintf(f, "--Tuoi khach hang: %d", a.tuoi);   fputs("\n",f);
	fprintf(f, "--Gioi tinh: %s", a.gioitinh);    fputs("\n",f);
	fprintf(f, "--SDT khach hang: %s", a.SDT);     fputs("\n",f);
	fclose(f);
}

void Goiymonnuong(){
	printf("Muc goi y giup khach hang la \n");
	printf("-----------------------------MON NUONG-----------------------------\n\n");
	printf("<<Thit ba chi tot cho tim mach, giam luong cholesterol trong mau.>>\n");
	printf("--300gr thit ba chi heo chua 49,5gam protein, 64,5gam mo, 27mg canxi,\n");
	printf(" 534mg phosphor, 4.5mg sat, 5.73mg kem, 855mg kali, 165mg natri.\n\n");
	printf("<<Tom giup thuc day suc khoe cua tim va nao, chat chong oxi hoa.>>\n");
	printf("--300g chua 297 calo, 0,9g chat beo, 72g protein.\n\n");
	printf("<<Thit bo giup chong oxi hoa hieu qua, bo tro tang cuong co bap.>>\n");
	printf("--300g thit bo chua 546calo, 64,5g protein, 32,1g lipid.\n\n");
	printf("<<Thit bo giup chong oxi hoa hieu qua, bo tro tang cuong co bap.>>\n");
	printf("--300g thit bo chua 546calo, 64,5g protein, 32,1g lipid.\n\n");
	printf("<<Muc bo sung nhieu chat dinh duong.>>\n");
	printf("--400g muc chua 368 calo, 62,4g dam.\n\n");
	printf("<<Suon bo sung chat dam.>>\n");
	printf("--300g suon chua 546calo, 64,5g protein, 32,1g lipid.\n\n");

}
void Goiymonlau(){
	printf("\n------------------------------MON LAU----------------------------------\n\n");
	printf("<<Lau thap cam bo sung nhieu chat dinh duong.>>\n");
	printf("-- 30g dam, 20g protein, 2mg kem, 2mg sat\n\n");
	printf("<<Lau thai chua cay bo sung nhieu chat dinh duong.>>\n");
	printf("--25g dam, 30,4g protein, 3mg kem, 2mg sat\n\n");
	printf("<<Lau ca keo giup tru dam, duong can than, giup gan xuong chac khoe, thong huyet mach.>>\n");
	printf("--300g ca keo chua 210 calo, 249,6g nuoc, 2400mg chat beo, 47,4g dam, 51mg canxi, \n");
	printf("2700mcg sat, 543mg photpho.\n\n");
	printf("<<Lau ech giup bo sung nhieu chat dinh duong.\n>>");
	printf("--500g ech chua 365 cal, 82g protein, 0,15g chat beo, 90mg canxi, 735mg photpho, 5mg kem.\n\n");
	printf("<<Lau bo chong oxy hoa hieu qua, bo tro tang cuong co bap.>>\n");
	printf("--200g thit bo chua 364calo, 43g protein, 21,4g lipid.\n\n");
	printf("<<Lau ca ba sa cung cap nhieu chat dam, chat beo.>>\n");
	printf("--300g ca ba sa chua 53,7g chat dam, 16,8g chat beo.\n\n");

}
void Inbill(){ 
 char ch;
   FILE *file1, *file2, *file3, *file4, *file5, *file6 ;
   file1 = fopen("thongtin.txt", "r");
   file2 = fopen("monnuong.txt", "r");
   file3 = fopen("monlau.txt", "r");
   file4 = fopen("monnuoc.txt", "r");
   file5 = fopen("tinhtong.txt", "r");
   file6 = fopen("BILL CUA QUY KHACH.txt", "w");
   fputs("<<<<<<<< Nha Hang TNPN >>>>>>>>\n",file6);
   while ((ch = fgetc(file1)) != EOF) {
      fputc(ch, file6);
   }
   while ((ch = fgetc(file2)) != EOF) {
      fputc(ch, file6);
   }
   while ((ch = fgetc(file3)) != EOF) {
      fputc(ch, file6);
   }
   while ((ch = fgetc(file4)) != EOF) {
      fputc(ch, file6);
   }
   while ((ch = fgetc(file5)) != EOF) {
      fputc(ch, file6);
   }
   fputs("\n",file6);
   fputs("---------Cam on quy khach------------",file6);
   fclose(file2);
   fclose(file3);
   fclose(file4);
   fclose(file5);
   fclose(file6);
}

void Goimenu() {
	printf("+-----------------------------------+\n");
	printf("|                                   |\n");
	printf("|             MENU                  |\n");
	printf("|                                   |\n");
	printf("| 1. Nhap thong tin khach hang.     |\n");
	printf("| 2. Xuat thong tin khach hang.     |\n");
	printf("| 3. Danh sach cac mon nuong.       |\n");
	printf("| 4. Danh sach cac mon lau.         |\n");
	printf("| 5. Danh sach cac mon nuoc.        |\n");
	printf("| 6. Muc goi y cho khach hang.      |\n");
	printf("| 7. Quy khach vui long xac nhan lai|\n");
	printf("|     mon an cua khach.             |\n");
	printf("| 8. Tong hoa don du kien cua khach |\n");
	printf("| 9. Danh gia cua khach hang.       |\n");
	printf("| 10. Chon 0 de thoat.              |\n");
	printf("|                                   |\n");
	printf("+-----------------------------------+\n");
	printf("Moi ban chon chuc nang: ");
}

void Menu(KH a,int A1[],int dem1,int A2[],int dem2,int A3[],int dem3,SList sl1,SList sl2,SList sl3,int tong) {
	int chon, flat = 1;
	while (flat) {
		Goimenu();
		scanf("%d", &chon);
		switch (chon) {
		case 1:
			a = Nhap(a);
			printf("\n");
			
			break;
		case 2:
			printf("--Thong tin khach hang la\n");
			Xuat(a);
			printf("\n\n\n");
			
			break;
		case 3:
			Danhsachmonnuong(A1, dem1);
			Xuatmonnuong( A1, dem1);
			break;

		case 4:
			Danhsachmonlau(A2, dem2);
			Xuatmonlau( A2, dem2);
	
			break;
		case 5:
			Danhsachmonnuoc(A3, dem3);
			Xuatmonnuoc( A3, dem3);
			break;
		case 6:
		   
		    int n;
		    printf("chon 1 la muc goi y mon nuong\n");
		    printf("chon 2 la muc goi y mon lau\n");
		    printf("chon 0 de thoat\n");
		    do{
		    printf("MUC GOI Y MON AN\n");
		    printf("Moi quy khach chon muc mon an\n");
		    scanf("%d",&n);
		    if(n==1)
		    Goiymonnuong();
		    else if(n==2)
			Goiymonlau();
			else 
			printf("vui long nhap lai muc\n");
			
		}
		while(n!=0);
		break;
		case 7:
		
		
		printf("---------Danh sach cac mon vua oder------------\n");
		
		Xuatmonnuong(A1, dem1);
		Xuatmonlau(A2, dem2);
		Xuatmonnuoc(A3, dem3);
	    printf("<<Neu quy khach muon doi mon vui long oder lai menu mon do>>\n");
		break;
		case 8:
			createSList(sl1, A1, dem1);
			createSList(sl2, A2, dem2);
			createSList(sl3, A3, dem3);
			Tinhtientong(sl1, sl2, sl3, tong, dem1, dem2, dem3);
			printf("\n\n\n");
			break;
		case 9:
		    Phanhoi();
			break;
		case 0:
			Infile(a);
			Innuong(A1, dem1);
		    Inlau(A2, dem2);
		    Innuoc(A3, dem3);
			
			
			printf("----------------Bill cua quy khach da duoc luu vao FILE---------------------\n ");
			printf("----------------------Cam on quy khach------------------------------");
			
			flat = 0;
			break;
		}
	}
}

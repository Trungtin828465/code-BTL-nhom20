#include <stdlib.h>
#include<stdio.h>
#ifndef TEP_H
#define TEP_H

struct KhachHang {
	char ten[50];
	int tuoi;
	char gioitinh[50];
	char SDT[50];
};

typedef struct  KhachHang KH;
typedef int ItemType;

struct SNode
{
	ItemType Info;
	 struct SNode* Next;
};
typedef struct SNode SNode;

struct SList
{
	struct SNode* Head;
	struct SNode* Tail;
};
typedef struct SList SList;

SNode* createSNode(ItemType x);
void showSNode( SNode* p);
void initSList(  SList& sl);
int isEmpty(SList sl);
int insertHead(SList& sl, SNode* p);
void showSList(SList sl);
int deleteHead(SList& sl, ItemType& x);
void createSList(SList& sl, int A[], int dem);
int Tinhtienmonnuong(SList sl, int tong, int dem);
int Tinhtienmonlau(SList sl, int tong, int dem);
int Tinhtienmonnuoc(SList sl, int tong, int dem);
void Tinhtientong(SList sl1, SList sl2, SList sl3, int tong, int dem1, int dem2, int dem3);
void  Danhsachmonnuong(int A1[], int &dem1);
void Xuatmonnuong(int A1[], int &dem1);
void Innuong(int A1[], int &dem1);
void Danhsachmonlau(int A2[], int &dem2);
void Xuatmonlau(int A2[], int dem2);
 void Inlau(int A2[], int &dem2);
 void Danhsachmonnuoc(int A3[], int &dem3);
 void Xuatmonnuoc(int A3[], int &dem3);
 void Innuoc(int A3[], int &dem3);
 KH Nhap(KH a);
 void Phanhoi();
 void Xuat(KH a);
 void Infile(KH a);
 void Goiymonnuong();
 void Goiymonlau();
 void Inbill();
 void Goimenu();
 void Menu(KH a,int A1[],int dem1,int A2[],int dem2,int A3[],int dem3,SList sl1,SList sl2,SList sl3,int tong);
 #endif // TEP_H

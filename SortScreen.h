#pragma once;
#include<iostream>
#include<math.h>
#include<string>
#include<string.h>
#include<algorithm>
#include"Console.h"
#include"Input.h"
#include"Interface.h"

using namespace std;

void Swap_change(THIETBI &ttb1, THIETBI &ttb2)
{
	THIETBI Temp;
	Temp = ttb1;
	ttb1 = ttb2;
	ttb2 = Temp;
}

void Swap(char& a, char& b){
	char temp;
	temp = a;
	a = b; 
	b = temp;
}


int SoSanhChuoi(char *s1, char *s2)
{
	int x, y, size;
	x = strlen(s1);
	y = strlen(s2);
	(x >= y) ? (size = x) : (size = y);

	for (int i = 0; i < size; i++)
	{
		if (s1[i]>s2[i]){ return 1; }
		if (s1[i] < s2[i]){ return -1; }
	}
	if (x > y){ return 1; }
	if (x < y){ return -1; }
	return 0;
}

void ReverseDate(char* s){
	strrev(s);
	Swap(s[0], s[3]);
	Swap(s[1], s[2]);
	Swap(s[5], s[6]);
	Swap(s[8], s[9]);
//	reverse(s1.begin(), s1.end());
//	reverse(s1.begin(), s1.begin()+4);
//	reverse(s1.begin()+5, s1.begin()+7);
//	reverse(s1.begin()+8, s1.begin()+10);
}



void VerseDate(char *s){
	strrev(s);
	Swap(s[0], s[1]);
	Swap(s[3], s[4]);
	Swap(s[6], s[9]);
	Swap(s[7], s[8]);
	
//	reverse(s1.begin(), s1.end());
//	reverse(s1.begin(), s1.begin()+2);
//	reverse(s1.begin()+3, s1.begin()+5);
//	reverse(s1.begin()+6, s1.begin()+10);
}

void BubblesortMaTTB(LIST_THIET_BI &list, int n){
	if (list.size() == 0){ return; }
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n - i - 1; j++)
		{
			if (SoSanhChuoi(list[j].maTTB, list[j + 1].maTTB) == 1)
			{
				Swap_change(list[j], list[j + 1]);
			}
		}
	}
	return;
}

/*---------------------------Sap xep ngay san xuat-------------------------------------*/

void ReverseNSX(LIST_THIET_BI &list){
	for(int i = 0; i<list.size(); i++){
		ReverseDate(list[i].nsx);
	}
}

void VerseNSX(LIST_THIET_BI &list){
	for(int i=0; i<list.size(); i++){
		VerseDate(list[i].nsx);
	}
}

void SelectionNSX(LIST_THIET_BI& list, int n)
{
	if (list.size() == 0){ return; }
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (SoSanhChuoi(list[i].nsx, list[j].nsx) == 1)
			{
				Swap_change(list[i], list[j]);
			}
		}
	}
	return;
}
void InsertionNSX(LIST_THIET_BI& list, int n)
{
	if (list.size() == 0){ return; }
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = i; j >0; j--)
		{
			if (SoSanhChuoi(list[j].nsx, list[j - 1].nsx) == -1)
			{
				Swap_change(list[j], list[j - 1]);
			}
		}
	}
	return;
}
void BubbleNSX(LIST_THIET_BI& list, int n)
{
	if (list.size() == 0){ return; }
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n - i - 1; j++)
		{
			if (SoSanhChuoi(list[j].nsx, list[j + 1].nsx) == 1)
			{
				Swap_change(list[j], list[j + 1]);
			}
		}
	}
	return;
}
void QuicksortNSX(LIST_THIET_BI& list, int left, int right)
{
	if (list.size() == 0){ return; }
	THIETBI ttb;
	int i = left;
	int j = right;
	int tg = int(left + right) / 2;
	ttb = list[tg];
	while (i <= j)
	{
		while (SoSanhChuoi(list[i].nsx, ttb.nsx) == -1 && i <= right)
		{
			i++;
		}
		while (SoSanhChuoi(list[j].nsx, ttb.nsx) == 1 && j >= left)
		{
			j--;
		}
		if (i <= j)
		{
			Swap_change(list[i], list[j]);
			i++;
			j--;
		}
	}
	if (left < j)
	{
		QuicksortNSX(list, left, j);
	}
	if (i < right)
	{
		QuicksortNSX(list, i, right);
	}
	return;
}

/*---------------------------Sap xep ngay su dung-------------------------------------*/

void ReverseNSD(LIST_THIET_BI &list){
	for(int i = 0; i<list.size(); i++){
		ReverseDate(list[i].nsd);
	}
}

void VerseNSD(LIST_THIET_BI &list){
	for(int i=0; i<list.size(); i++){
		VerseDate(list[i].nsd);
	}
}

void SelectionNSD(LIST_THIET_BI& list, int n)
{
	if (list.size() == 0){ return; }
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (SoSanhChuoi(list[i].nsd, list[j].nsd) == 1)
			{
				Swap_change(list[i], list[j]);
			}
		}
	}
	return;
}

void InsertionNSD(LIST_THIET_BI& list, int n)
{
	if (list.size() == 0){ return; }
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = i; j >0; j--)
		{
			if (SoSanhChuoi(list[j].nsd, list[j - 1].nsd) == -1)
			{
				Swap_change(list[j], list[j - 1]);
			}
		}
	}
	return;
}

void BubbleNSD(LIST_THIET_BI& list, int n){
	if (list.size() == 0){ return; }
	int i, j;
	for (i = 0; i < n; i++){
		for (j = 0; j < n - i - 1; j++)
		{
			if (SoSanhChuoi(list[j].nsd, list[j + 1].nsd) == 1)
			{
				Swap_change(list[j], list[j + 1]);
			}
		}
	}
	return;
}


void QuicksortNSD(LIST_THIET_BI& list, int left, int right){
	if (list.size() == 0){ return; }
	THIETBI ttb;
	int i = left;
	int j = right;
	int tg = int(left + right) / 2;
	ttb = list[tg];
	while (i <= j){
		while (SoSanhChuoi(list[i].nsd, ttb.nsd) == -1 && i <= right)	i++;
		while (SoSanhChuoi(list[j].nsd, ttb.nsd) == 1 && j >= left)		j--;
		if (i <= j){
			Swap_change(list[i], list[j]);
			i++;
			j--;
		}
	}
	if (left < j){
		QuicksortNSD(list, left, j);
	}
	if (i < right){
		QuicksortNSD(list, i, right);
	}
	return;
}

/*------------------------------------ Sap xep Cap do san pham ------------------------------------*/
void SelectionLevel(LIST_THIET_BI& list, int n){
	if (list.size() == 0){ return; }
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (SoSanhChuoi(list[i].cap, list[j].cap) == 1)
			{
				Swap_change(list[i], list[j]);
			}
		}
	}
	return;
}


void InsertionLevel(LIST_THIET_BI &list, int n){
	if (list.size() == 0){ return; }
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = i; j >0; j--)
		{
			if (SoSanhChuoi(list[j].cap, list[j - 1].cap) == -1)
			{
				Swap_change(list[j], list[j - 1]);
			}
		}
	}
	return;
}


void BubblesortLevel(LIST_THIET_BI &list, int n){
	if (list.size() == 0){ return; }
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n - i - 1; j++)
		{
			if (SoSanhChuoi(list[j].cap, list[j + 1].cap) == 1)
			{
				Swap_change(list[j], list[j + 1]);
			}
		}
	}
	return;
}


void QuicksortLevel(LIST_THIET_BI &list, int left, int right){
	if (list.size() == 0){ return; }
	THIETBI hoso_tg;
	int i = left;
	int j = right;
	int tg = int(left + right) / 2;
	hoso_tg = list[tg];
	while (i <= j){
		while (SoSanhChuoi(list[i].cap, hoso_tg.cap) == -1 && i <= right)	i++;
		while (SoSanhChuoi(list[j].cap, hoso_tg.cap) == 1 && j >= left)		j--;
		if (i <= j){
			Swap_change(list[i], list[j]);
			i++;
			j--;
		}
	}
	if (left < j)
	{
		QuicksortLevel(list, left, j);
	}
	if (i < right)
	{
		QuicksortLevel(list, i, right);
	}
	return;
}


/*------------------------------------ Sap xep ten TTB ------------------------------------*/

void SelectionName(LIST_THIET_BI& list, int n){
	if (list.size() == 0){ return; }
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (SoSanhChuoi(list[i].tenTTB, list[j].tenTTB) == 1)
			{
				Swap_change(list[i], list[j]);
			}
		}
	}
	return;
}


void InsertionName(LIST_THIET_BI &list, int n){
	if (list.size() == 0){ return; }
	int i, j;
	for (i = 0; i < n; i++){
		for (j = i; j >0; j--)
		{
			if (SoSanhChuoi(list[j].tenTTB, list[j - 1].tenTTB) == -1)
			{
				Swap_change(list[j], list[j - 1]);
			}
		}
	}
	return;
}


void BubblesortName(LIST_THIET_BI &list, int n){
	if (list.size() == 0){ return; }
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n - i - 1; j++)
		{
			if (SoSanhChuoi(list[j].tenTTB, list[j + 1].tenTTB) == 1)
			{
				Swap_change(list[j], list[j + 1]);
			}
		}
	}
	return;
}


void QuicksortName(LIST_THIET_BI &list, int left, int right){
	if (list.size() == 0){ return; }
	THIETBI hoso_tg;
	int i = left;
	int j = right;
	int tg = int(left + right) / 2;
	hoso_tg = list[tg];
	while (i <= j){
		while (SoSanhChuoi(list[i].tenTTB, hoso_tg.tenTTB) == -1 && i <= right)	i++;
		while (SoSanhChuoi(list[j].tenTTB, hoso_tg.tenTTB) == 1 && j >= left)		j--;
		if (i <= j){
			Swap_change(list[i], list[j]);
			i++;
			j--;
		}
	}
	if (left < j)
	{
		QuicksortLevel(list, left, j);
	}
	if (i < right)
	{
		QuicksortLevel(list, i, right);
	}
	return;
}


/*------------------------------------ Sap xep chung loai ------------------------------------*/
void SelectionType(LIST_THIET_BI& list, int n){
	if (list.size() == 0){ return; }
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (SoSanhChuoi(list[i].chung_loai, list[j].chung_loai) == 1)
			{
				Swap_change(list[i], list[j]);
			}
		}
	}
	return;
}


void InsertionType(LIST_THIET_BI &list, int n){
	if (list.size() == 0){ return; }
	int i, j;
	for (i = 0; i < n; i++){
		for (j = i; j >0; j--)
		{
			if (SoSanhChuoi(list[j].chung_loai, list[j - 1].chung_loai) == -1)
			{
				Swap_change(list[j], list[j - 1]);
			}
		}
	}
	return;
}


void BubblesortType(LIST_THIET_BI &list, int n){
	if (list.size() == 0){ return; }
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n - i - 1; j++)
		{
			if (SoSanhChuoi(list[j].chung_loai, list[j + 1].chung_loai) == 1)
			{
				Swap_change(list[j], list[j + 1]);
			}
		}
	}
	return;
}


void QuicksortType(LIST_THIET_BI &list, int left, int right){
	if (list.size() == 0){ return; }
	THIETBI hoso_tg;
	int i = left;
	int j = right;
	int tg = int(left + right) / 2;
	hoso_tg = list[tg];
	while (i <= j){
		while (SoSanhChuoi(list[i].chung_loai, hoso_tg.chung_loai) == -1 && i <= right)	i++;
		while (SoSanhChuoi(list[j].chung_loai, hoso_tg.chung_loai) == 1 && j >= left)		j--;
		if (i <= j){
			Swap_change(list[i], list[j]);
			i++;
			j--;
		}
	}
	if (left < j)
	{
		QuicksortLevel(list, left, j);
	}
	if (i < right)
	{
		QuicksortLevel(list, i, right);
	}
	return;
}



void HandleNSX(LIST_THIET_BI& list,int dex2, int dex3){
	ReverseNSX(list);
	if(dex2 == 0){
		NoticeSort("Selection Sort", "Ngay san xuat");
		SelectionNSX(list, list.size());
	}else if(dex2 == 1){
		NoticeSort("Insertion Sort","Ngay san xuat" );
		InsertionNSX(list, list.size());
	}else if(dex2 == 2){
		NoticeSort("Bubble Sort","Ngay san xuat");
		BubbleNSX(list, list.size());
	}else if(dex2 == 3){
		NoticeSort("Quick Sort","Ngay san xuat");
		QuicksortNSX(list, 0, list.size()-1);
	} 
	VerseNSX(list);
}

void HandleNSD(LIST_THIET_BI& list,int dex2, int dex3){
	ReverseNSD(list);
	if(dex2 == 0){
		NoticeSort("Selection Sort", "Ngay su dung");
		SelectionNSD(list, list.size());
	} 
	else if(dex2 == 1){
		NoticeSort("Insertion Sort","Ngay su dung" );
		InsertionNSD(list, list.size());
	} 
	else if(dex2 == 2){
		NoticeSort("Bubble Sort","Ngay su dung");
		BubbleNSD(list, list.size());
	} 
	else if(dex2 == 3){
		NoticeSort("Quick Sort","Ngay su dung");
		QuicksortNSD(list, 0, list.size()-1);
	} 
	VerseNSD(list);
}

void HandleName(LIST_THIET_BI& list,int dex2, int dex3){
	if(dex2 == 0){
		NoticeSort("Selection Sort", "Ten trang thiet bi");
		SelectionName(list, list.size());
	} 
	else if(dex2 == 1){
		NoticeSort("Insertion Sort","Ten trang thiet bi" );
		InsertionName(list, list.size());
	} 
	else if(dex2 == 2){
		NoticeSort("Bubble Sort","Ten trang thiet bi");
		BubblesortName(list, list.size());
	} 
	else if(dex2 == 3){
		NoticeSort("Quick Sort","Ten trang thiet bi");
		QuicksortName(list, 0, list.size()-1);
	} 
}

void HandleType(LIST_THIET_BI& list,int dex2, int dex3){
	if(dex2 == 0){
		NoticeSort("Selection Sort", "Chung loai");
		SelectionType(list, list.size());
	} 
	else if(dex2 == 1){
		NoticeSort("Insertion Sort","Chung loai");
		InsertionType(list, list.size());
	} 
	else if(dex2 == 2){
		NoticeSort("Bubble Sort","Chung loai");
		BubblesortType(list, list.size());
	} 
	else if(dex2 == 3){
		NoticeSort("Quick Sort","Chung loai");
		QuicksortType(list, 0, list.size()-1);
	} 
}

void HandleLevel(LIST_THIET_BI& list,int dex2, int dex3){
	if(dex2 == 0){
		NoticeSort("Selection Sort", "Cap do");
		SelectionLevel(list, list.size());
	} 
	else if(dex2 == 1){
		NoticeSort("Insertion Sort","Cap do" );
		InsertionLevel(list, list.size());
	} 
	else if(dex2 == 2){
		NoticeSort("Bubble Sort","Cap do");
		BubblesortLevel(list, list.size());
	} 
	else if(dex2 == 3){
		NoticeSort("Quick Sort","Cap do");
		QuicksortLevel(list, 0, list.size()-1);
	} 
}


void HandleSort(LIST_THIET_BI& list,int dex2, int dex3){
	switch(dex3){
		case 0:{
			HandleName(list, dex2, dex3);
			break;
		}
		case 1:{
			HandleNSX(list, dex2, dex3);
			break;
		}
		case 2:{
			HandleNSD(list, dex2, dex3);
			break;
		}
		case 3:{
			HandleType(list, dex2, dex3);
			break;
		}
		case 4:{
			HandleLevel(list, dex2, dex3);
			break;
		}	
	}
}

void HandleMouseMovedSort(MOUSE_EVENT_RECORD mer){
	An_tro_chuot();
	if(mer.dwMousePosition.X >=1 && mer.dwMousePosition.X <= 20 && mer.dwMousePosition.Y >=1 && mer.dwMousePosition.Y <= 3){
				Button(1,1,"     BACK", true);
			}else Button(1,1,"     BACK", false);
			
			if(mer.dwMousePosition.X >=115 && mer.dwMousePosition.X <= 130 && mer.dwMousePosition.Y >=33 && mer.dwMousePosition.Y <= 35){
				  Button(115, 33, "   < Save > ",true);
			}else Button(115, 33,"   < Save > ",false);
			
			if(mer.dwMousePosition.X >=55 && mer.dwMousePosition.X <= 85 && mer.dwMousePosition.Y >=33 && mer.dwMousePosition.Y <= 35){
				  Button(60, 33," < Exchange >",true);
			}else Button(60, 33," < Exchange >",false);
			
			if(mer.dwMousePosition.X >=155 && mer.dwMousePosition.X <= 170 && mer.dwMousePosition.Y >=18 && mer.dwMousePosition.Y <= 20){
				  Button(155, 18,"     Next >>",true);
			}else Button(155, 18,"     Next >>",false);
			
			if(mer.dwMousePosition.X >=5 && mer.dwMousePosition.X <= 20 && mer.dwMousePosition.Y >=18 && mer.dwMousePosition.Y <= 20){
				  Button(5, 18," << Previous",true);
			}else Button(5, 18," << Previous",false);
}


int ScreenSort_Mouse_event(MOUSE_EVENT_RECORD mer,LIST_THIET_BI* list, COORD &toado, int &page ){
	if(mer.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED){
		if(mer.dwMousePosition.X >=155 && mer.dwMousePosition.X <= 170 && mer.dwMousePosition.Y >=18 && mer.dwMousePosition.Y <= 20){
//			XoaDulieu();
			return 2;// NEXT 
		}
		if(mer.dwMousePosition.X >=5 && mer.dwMousePosition.X <= 20 && mer.dwMousePosition.Y >=18 && mer.dwMousePosition.Y <= 20){
			return 1;//PREVIOUS
		}
		if(mer.dwMousePosition.X >=1 && mer.dwMousePosition.X <= 25 && mer.dwMousePosition.Y >=1 && mer.dwMousePosition.Y <= 3) return -1;//BACK
		if(mer.dwMousePosition.X >=115 && mer.dwMousePosition.X <= 130 && mer.dwMousePosition.Y >=33 && mer.dwMousePosition.Y <= 35) return 4;// Save
		if(mer.dwMousePosition.X >=55 && mer.dwMousePosition.X <= 85 && mer.dwMousePosition.Y >=33 && mer.dwMousePosition.Y <= 35)	return 3;// Exchange
	}else if(mer.dwEventFlags == MOUSE_MOVED){
			HandleMouseMovedSort(mer);
	}
	else if(mer.dwEventFlags == MOUSE_WHEELED){
		if(mer.dwButtonState == 4287102976){
			return 2;
		}
		else if(mer.dwButtonState == 7864320){
			return 1;
		}
	} 
	return 0;
}


void ReverseList(LIST_THIET_BI &list){
	LIST_THIET_BI temp(list);
	list.clear();
	for(int i=temp.size()-1; i>=0; i--){
			list.push_back(temp[i]);
	}
}

int ScreenSort(HANDLE &hStdin, INPUT_RECORD &irInBuf){
	DWORD cNumRead, i; 
	
	LIST_THIET_BI list;
	COORD toado; toado.X=1; toado.Y =-1;
	int page = 1;
	DANHSACHSAPXEP(); 
	OutFile("Input.txt", list);
	HandleSort(list, index2, index3);
	PrintScreen(list, page);
    while(true){  
    	ReadConsoleInput( hStdin, &irInBuf, 1, &cNumRead);
			if(irInBuf.EventType == MOUSE_EVENT){
				switch(ScreenSort_Mouse_event(irInBuf.Event.MouseEvent,&list, toado, page)){
					case -1:{
						index3 = -1;
						index2 = -1;
						return -1;
					}
					case  2:{
						if(page <= (list.size()/10)){
							XoaDulieu();
							page++;	
						}
						PrintScreen(list, page);
						break;
					} 
					case  1:{
						page--;
						PrintScreen(list, page);
						break;
					}
					case 3:{
						ReverseList(list);
						page = 0;
						XoaDulieu();
						PrintScreen(list, page);
						break;
					}
					case 4:{
						InFile("Input.txt", &list, "w");
						break;
					}
				}
			}
	}
	
}                                                 




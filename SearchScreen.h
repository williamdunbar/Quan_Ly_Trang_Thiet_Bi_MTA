#pragma once;
#include<iostream>
#include<string.h>
#include"Console.h"
#include"SortScreen.h"
#include"Input.h"
#include"Interface.h"
using namespace std;

/*-------------------------------------subfunctions------------------------------------------*/
int compare_Search(char *xau,char *look);
/*-------------------------------------BinarySearch------------------------------------------*/
void BinarymaTTB(LIST_THIET_BI &list, LIST_THIET_BI &search, char look[]);
void BinarytenTTB(LIST_THIET_BI &list, LIST_THIET_BI &search, char look[]);
void BinaryNSX(LIST_THIET_BI &list, LIST_THIET_BI &search, char look[]);
void BinaryNSD(LIST_THIET_BI &list, LIST_THIET_BI &search, char look[]);
void BinarytenLoai(LIST_THIET_BI &list, LIST_THIET_BI &search, char look[]);
void BinaryCap(LIST_THIET_BI &list, LIST_THIET_BI &search, char look[]);
/*-------------------------------------SequenceSearch------------------------------------------*/
void SequencemaTTB(LIST_THIET_BI &list, LIST_THIET_BI &search, char look[]);
void SequencetenTTB(LIST_THIET_BI &list, LIST_THIET_BI &search, char look[]);
void SequenceNSX(LIST_THIET_BI &list, LIST_THIET_BI &search, char look[]);
void SequenceNSD(LIST_THIET_BI &list, LIST_THIET_BI &search, char look[]);
void SequenceChungLoai(LIST_THIET_BI &list, LIST_THIET_BI &search, char look[]);
void SequenceCap(LIST_THIET_BI &list, LIST_THIET_BI &search, char look[]);
/*-------------------------------------MouseEvent------------------------------------------*/
int MouseEventSearch(MOUSE_EVENT_RECORD mer,LIST_THIET_BI* list, COORD &toado, int &page);
void HandleMouseMovedSearch(MOUSE_EVENT_RECORD mer);
/*-------------------------------------General------------------------------------------*/
void HandleBinary(LIST_THIET_BI &list, LIST_THIET_BI &search , char look[]);
void HandleSequence(LIST_THIET_BI &list,LIST_THIET_BI &search, char look[]);
void HandleSearch(LIST_THIET_BI& list, LIST_THIET_BI &search , char *look);
void HandleKeyWord_Search(KEY_EVENT_RECORD ker,char *look);
void HandleKeyEvent_Search(KEY_EVENT_RECORD ker, LIST_THIET_BI& list, LIST_THIET_BI &search , char *look, int& page);
void FreeUpMemorySearch(LIST_THIET_BI &list, LIST_THIET_BI &search, char *look_for);
int ScreenSearch(HANDLE &hStdin, INPUT_RECORD &irInBuf);
/*-------------------------------------------------------------------------------------------*/


int compare_Search(char *xau,char *look)
{
	char *s = strstr(xau, look);
	if (s != NULL)
	{
		return 0;
	}
	return -1;
}


void BinarymaTTB(LIST_THIET_BI &list, LIST_THIET_BI &search, char look[]){
	BubblesortMaTTB(list, list.size());
	int left = 0, right = list.size() - 1;
	int i = 0;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (compare_Search(list[mid].maTTB, look) == 0)
		{
			for (int   i = mid + 1; (i<list.size()) ; i++){
				if (compare_Search(list[i].maTTB, look) == 0)
				search.push_back(list[i]);
			}
			search.push_back(list[mid]);
			for (int i = mid - 1; (i > 0); i--){
				if (compare_Search(list[i].maTTB, look) == 0)
				search.push_back(list[i]);
			}
			BubbleNSD(search, search.size());
			return;
		}
		else if (SoSanhChuoi(look, list[mid].maTTB) == -1)
			right = mid - 1;
		else if (SoSanhChuoi(look, list[mid].maTTB) == 1)
			left = mid + 1;
	} return;
}

void BinarytenTTB(LIST_THIET_BI &list, LIST_THIET_BI &search, char look[]){
	BubblesortName(list, list.size());
	int left = 0, right = list.size() - 1;
	int i = 0;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (compare_Search(list[mid].tenTTB, look) == 0)
		{
			for (int   i = mid + 1; (i<list.size()) ; i++){
				if (compare_Search(list[i].tenTTB, look) == 0)
				search.push_back(list[i]);
			}
			search.push_back(list[mid]);
			for (int i = mid - 1; (i > 0); i--){
				if (compare_Search(list[i].tenTTB, look) == 0)
				search.push_back(list[i]);
			}
			BubbleNSD(search, search.size());
			return;
		}
		else if (SoSanhChuoi(look, list[mid].tenTTB) == -1)
			right = mid - 1;
		else if (SoSanhChuoi(look, list[mid].tenTTB) == 1)
			left = mid + 1;
	} return;
}

void BinaryNSD(LIST_THIET_BI &list, LIST_THIET_BI &search, char look[]){
	BubbleNSD(list, list.size());
	int left = 0, right = list.size() - 1;
	int i = 0;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (compare_Search(list[mid].nsd, look) == 0)
		{
			for (int   i = mid + 1; (i<list.size()) ; i++){
				if (compare_Search(list[i].nsd, look) == 0)
				search.push_back(list[i]);
			}
			search.push_back(list[mid]);
			for (int i = mid - 1; (i > 0); i--){
				if (compare_Search(list[i].nsd, look) == 0)
				search.push_back(list[i]);
			}
			BubbleNSD(search, search.size());
			return;
		}
		else if (SoSanhChuoi(look, list[mid].nsd) == -1)
			right = mid - 1;
		else if (SoSanhChuoi(look, list[mid].nsd) == 1)
			left = mid + 1;
	} return;
}

void BinaryNSX(LIST_THIET_BI &list, LIST_THIET_BI &search, char look[]){
	BubbleNSX(list, list.size());
	int left = 0, right = list.size() - 1;
	int i = 0;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (compare_Search(list[mid].nsx, look) == 0)
		{
			for (int   i = mid + 1; (i<list.size()) ; i++){
				if (compare_Search(list[i].nsx, look) == 0)
				search.push_back(list[i]);
			}
			search.push_back(list[mid]);
			for (int i = mid - 1; (i > 0); i--){
				if (compare_Search(list[i].nsx, look) == 0)
				search.push_back(list[i]);
			}
			BubbleNSD(search, search.size());
			return;
		}
		else if (SoSanhChuoi(look, list[mid].nsx) == -1)
			right = mid - 1;
		else if (SoSanhChuoi(look, list[mid].nsx) == 1)
			left = mid + 1;
	} return;
}

void BinarytenLoai(LIST_THIET_BI &list, LIST_THIET_BI &search, char look[]){
	BubblesortType(list, list.size());
	int left = 0, right = list.size() - 1;
	int i = 0;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (compare_Search(list[mid].chung_loai, look) == 0)
		{
			for (int   i = mid + 1; (i<list.size()) ; i++){
				if (compare_Search(list[i].chung_loai, look) == 0)
				search.push_back(list[i]);
			}
			search.push_back(list[mid]);
			for (int i = mid - 1; (i > 0); i--){
				if (compare_Search(list[i].chung_loai, look) == 0)
				search.push_back(list[i]);
			}
			BubbleNSD(search, search.size());
			return;
		}
		else if (SoSanhChuoi(look, list[mid].chung_loai) == -1)
			right = mid - 1;
		else if (SoSanhChuoi(look, list[mid].chung_loai) == 1)
			left = mid + 1;
	} return;
}

void BinaryCap(LIST_THIET_BI &list, LIST_THIET_BI &search, char look[]){
	BubblesortLevel(list,list.size());
	int left = 0, right = list.size() - 1, i = 0;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (compare_Search(list[mid].cap, look) == 0){
			for (int i = mid + 1; i<list.size(); i++){
				if (compare_Search(list[i].cap, look) == 0)
				search.push_back(list[i]);
			}
			search.push_back(list[mid]);
			for (int i = mid - 1; i >= 0; i--){			
				if (compare_Search(list[i].cap, look) == 0)
				search.push_back(list[i]);
			}
			BubblesortLevel(search, search.size());
			return;
		}
		else if (SoSanhChuoi(look, list[mid].cap) == -1)
			right = mid - 1;
		else if (SoSanhChuoi(look, list[mid].cap) == 1)
			left = mid + 1;
	}return;
}


void SequencemaTTB(LIST_THIET_BI &list, LIST_THIET_BI &search, char look[]){
	search.clear();
	for (int   i = 0; i < list.size(); i++)
	{
		char *s = strstr(list[i].maTTB, look);
		if (s != NULL)
		{
			search.push_back(list[i]);
		}
	}
}


void SequencetenTTB(LIST_THIET_BI &list, LIST_THIET_BI &search, char look[]){
	search.clear();
	for (int   i = 0; i < list.size(); i++)
	{
		char *s = strstr(list[i].tenTTB, look);
		if (s != NULL)
		{
			search.push_back(list[i]);
		}
	}
}


void SequenceNSX(LIST_THIET_BI &list, LIST_THIET_BI &search, char look[]){
	search.clear();
	for (int   i = 0; i < list.size(); i++)
	{
		char *s = strstr(list[i].nsx, look);
		if (s != NULL)
		{
			search.push_back(list[i]);
		}
	}
}


void SequenceNSD(LIST_THIET_BI &list, LIST_THIET_BI &search, char look[]){
	search.clear();
	for (int   i = 0; i < list.size(); i++)
	{
		char *s = strstr(list[i].nsd, look);
		if (s != NULL)
			{
			search.push_back(list[i]);
		}
	}
}


void SequenceChungLoai(LIST_THIET_BI &list, LIST_THIET_BI &search, char look[]){
	search.clear();
	for (int   i = 0; i < list.size(); i++)
	{
		char *s = strstr(list[i].chung_loai, look);
		if (s != NULL)
		{
			search.push_back(list[i]);
		}
	}
}


void SequenceCap(LIST_THIET_BI &list, LIST_THIET_BI &search, char look[]){
	search.clear();
	for (int   i = 0; i < list.size(); i++)
	{
		char *s = strstr(list[i].cap,look );
		if (s != NULL)
		{
			search.push_back(list[i]);
		}
	}
}

void HandleBinary(LIST_THIET_BI &list, LIST_THIET_BI &search , char look[]){
	switch(index3){
		case 0:{
			NoticeSearch("Nhi Phan", "Ma Trang Thiet Bi");
			BinarymaTTB(list, search, look);
			break;
		}case 1:{
			NoticeSearch("Nhi Phan", "Ten Trang Thiet Bi");
			BinarytenTTB(list, search, look);
			break;
		}case 2:{
			NoticeSearch("Nhi Phan", "Ngay san xuat");
			BinaryNSX(list, search, look);
			break;
		}case 3:{
			NoticeSearch("Nhi Phan", "Ngay su dung");
			BinaryNSD(list, search, look);
			break;
		}case 4:{
			NoticeSearch("Nhi Phan", "Chung loai");
			BinarytenLoai(list, search, look);
			break;
		}case 5:{
			NoticeSearch("Nhi Phan", "Cap do");
			BinaryCap(list, search, look);
			break;
		}
	}
}


void HandleSequence(LIST_THIET_BI &list,LIST_THIET_BI &search, char look[]){
	switch(index3){
		case 0:{
			NoticeSearch("Tuan Tu", "Ma Trang Thiet Bi");
			SequencemaTTB(list, search, look);
			break;
		}case 1:{
			NoticeSearch("Tuan Tu", "Ten Trang Thiet Bi");
			SequencetenTTB(list, search, look);
			break;
		}case 2:{
			NoticeSearch("Tuan Tu", "Ngay san xuat");
			BinaryNSX(list, search, look);
			break;
		}case 3:{
			NoticeSearch("Tuan Tu", "Ngay su dung");
			SequenceNSD(list, search, look);
			break;
		}case 4:{
			NoticeSearch("Tuan Tu", "Chung loai");
			SequenceChungLoai(list, search, look);
			break;
		}case 5:{
			NoticeSearch("Tuan Tu", "  Cap do");
			SequenceCap(list, search, look);
			break;
		}
	}
}


void HandleSearch(LIST_THIET_BI& list, LIST_THIET_BI &search , char *look){
	switch(index2){
		case 0:{
			HandleSequence(list ,search, look);
			break;
		}
		case 1:{
			HandleBinary(list ,search, look); 
			break;
		}
	}
}


void HandleKeyWord_Search(KEY_EVENT_RECORD ker,char *look){
	COORD local_coord;
	local_coord.X = 77; 
	local_coord.Y = 6;
//	gotoXY(77+strlen(look)+1, 6);
//	cout << "_";
	switch(index3){
		case 0: case 1: case 4:{
			KeyEventSearch(ker, local_coord, look, 25);
			break;
		}
		case 2: case 3: case 5:{
			KeyNumberSearch(ker, local_coord,look, 25);
			break;
		}
	}
}

void HandleKeyEvent_Search(KEY_EVENT_RECORD ker, LIST_THIET_BI& list, LIST_THIET_BI &search , char *look, int& page){
	char *key = new char;
	*key = ker.uChar.AsciiChar;
	if(( *key >= 'A' && *key <= 'Z') || ( *key <= '9' && *key >= '0') || ( *key >='a' && *key <= 'z' ) || (*key == SPACE) || (*key == BACKSPACE)){
		if(ker.bKeyDown){
			HandleKeyWord_Search(ker, look);
			search.clear();
			HandleSearch(list, search, look);
			XoaDulieu();
			PrintScreen(search, page);
		}
		
	}
}

void HandleMouseMovedSearch(MOUSE_EVENT_RECORD mer){
	An_tro_chuot();
	if(mer.dwMousePosition.X >=1 && mer.dwMousePosition.X <= 20 && mer.dwMousePosition.Y >=1 && mer.dwMousePosition.Y <= 3){
				Button(1,1,"     BACK", true);
			}else Button(1,1,"     BACK", false);
			
			if(mer.dwMousePosition.X >=80 && mer.dwMousePosition.X <= 105 && mer.dwMousePosition.Y >=33 && mer.dwMousePosition.Y <= 35){
				  Button(83, 33, "   < Save > ",true);
			}else Button(83, 33,"   < Save > ",false);
			
			if(mer.dwMousePosition.X >=155 && mer.dwMousePosition.X <= 170 && mer.dwMousePosition.Y >=18 && mer.dwMousePosition.Y <= 20){
				  Button(155, 18,"     Next >>",true);
			}else Button(155, 18,"     Next >>",false);
			
			if(mer.dwMousePosition.X >=5 && mer.dwMousePosition.X <= 20 && mer.dwMousePosition.Y >=18 && mer.dwMousePosition.Y <= 20){
				  Button(5, 18," << Previous",true);
			}else Button(5, 18," << Previous",false);
}


int MouseEventSearch(MOUSE_EVENT_RECORD mer,LIST_THIET_BI* list, COORD &toado, int &page){
	if(mer.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED){
		if(mer.dwMousePosition.X >=155 && mer.dwMousePosition.X <= 170 && mer.dwMousePosition.Y >=18 && mer.dwMousePosition.Y <= 20){
//			XoaDulieu();
			return 2;// NEXT 
		}
		if(mer.dwMousePosition.X >=5 && mer.dwMousePosition.X <= 20 && mer.dwMousePosition.Y >=18 && mer.dwMousePosition.Y <= 20) return 1;//PREVIOUS
		if(mer.dwMousePosition.X >=1 && mer.dwMousePosition.X <= 25 && mer.dwMousePosition.Y >=1 && mer.dwMousePosition.Y <= 3) return -1;//BACK
		if(mer.dwMousePosition.X >=80 && mer.dwMousePosition.X <= 105 && mer.dwMousePosition.Y >=33 && mer.dwMousePosition.Y <= 35) return 3;// SAVE
	}else if(mer.dwEventFlags == MOUSE_MOVED){
			HandleMouseMovedSearch(mer);
	}else if(mer.dwEventFlags == MOUSE_WHEELED){
		if(mer.dwButtonState == 4287102976){
			return 2;
		}
		else if(mer.dwButtonState == 7864320){
			return 1;
		}
	} return 0;
}

void FreeUpMemorySearch(LIST_THIET_BI &list, LIST_THIET_BI &search, char *look_for){
	index3 = -1;
	index2 = -1;
	delete look_for;
	LIST_THIET_BI().swap(list);  //Tao mot vector trong tam thoi. Hoan doi no voi vector hien tai. Sau do vector tam thoi se bi huy
	LIST_THIET_BI().swap(search);
}


int ScreenSearch(HANDLE &hStdin, INPUT_RECORD &irInBuf){
	DWORD cNumRead; 
	LIST_THIET_BI list, search;
	COORD toado; toado.X=1; toado.Y =-1;
	int page = 1;
	char *look_for = new char[25];
	
	DANHSACHTIMKIEM(); 
	OutFile("Input.txt", list);
	HandleSearch(list, search, look_for);
	Hien_tro_chuot(); 
	
    while(true){  
    	ReadConsoleInput( hStdin, &irInBuf, 1, &cNumRead);
			if(irInBuf.EventType == MOUSE_EVENT){
				switch(MouseEventSearch(irInBuf.Event.MouseEvent,&list, toado, page)){
					case -1:{
						FreeUpMemorySearch(list, search, look_for);
						return -1;
					}
					case 2:{
						if(page <= (search.size()/10)){
							XoaDulieu();
							page++;	
						}
						PrintScreen(search, page);
						break;
					} 
					case  1:{
						page--;
						PrintScreen(search, page);
						break;
					}
					case 3:{
						InFile("Searchlist.txt", &search, "w");
						break;
					}
				}
			}
			else if(irInBuf.EventType == KEY_EVENT) 
					HandleKeyEvent_Search(irInBuf.Event.KeyEvent, list, search, look_for, page);
	}
}

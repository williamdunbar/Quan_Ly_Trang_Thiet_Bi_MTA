#pragma once
#include<iostream>
#include<string.h>
#include<math.h>
#include"Console.h"
#include"SearchScreen.h"
#include"Interface.h"
using namespace std;
 
string LabelDate[5] = {"2000-2005","2005-2010","2010-2015","2015-2020","  >=2020"};
string LabelLevel[5] = {"  Level 1","  Level 2","  Level 3","  Level 4","  Level 5"};

struct STATISTIC{
	string label = "";
	int quantity =0 ;
	float percent = 0;
};

typedef vector<STATISTIC> LIST_STATISTIC;

float LamTronSo(float a);
/*Cac ham crawl du lieu tu file text*/
void HandleCrawl(LIST_THIET_BI &list, STATISTIC *statis);//Ham dieu khien luong cao
void CrawlLevel(LIST_THIET_BI &list, STATISTIC *statis);
void CrawlType(LIST_THIET_BI &list);
void CrawlNSX(LIST_THIET_BI &list, STATISTIC *statis);
void CrawlNSD(LIST_THIET_BI &list, STATISTIC *statis);
void PrintData(STATISTIC *statis);

void Percentage(STATISTIC *statis);//Quy doi so lieu sang phan tram
void CotDoThi(STATISTIC *statis);//The hien do thi dua vao du lieu trich xuat
void ChuThich(STATISTIC *statis);
void ChuThichSolieu(STATISTIC *statis);
/*Khoi lenh dieu khien: bat chuot, ban phim, dieu khien giao dien-----------General Function-------------------- */
void HandleMouseMovedStatis(MOUSE_EVENT_RECORD mer);
int ScreenStatis_Mouse_event(MOUSE_EVENT_RECORD mer, LIST_THIET_BI, COORD &toado);
int ScreenStatistic(HANDLE &hStdin, INPUT_RECORD &irInBuf);


int Year(char s[]){
	char year[4];
		year[0] = s[6];
		year[1] = s[7];
		year[2] = s[8];
		year[3] = s[9];
	return atoi(year);
}


void CotDoThi(STATISTIC *statis){
	COORD OXY;
	int Color_column[5] = {11,12,10,14,13};
	OXY.X = 25, OXY.Y = 36;
	int max  = 0;
	for (int i = 0; i<5; i++){
		if(max<statis[i].percent)
			max = statis[i].percent;
	}
	float count = ((float)10/(float)28);
//	gotoXY(30,0); cout << count;
	for(int i= 0; i<5; i++){
		TextColor(Color_column[i]);
		for(float j = 0; j<statis[i].percent/2-1; j += count ){
				gotoXY(OXY.X+15*i,OXY.Y-j);
				cout << (char)432<<(char)433<<(char)434;
		}	
	}
}

void ChuThich(STATISTIC *statis){
	int Color_column[5] = {11,12,10,14,13};
	TextColor(3);
	for(int i = 0; i<5; i++){
		gotoXY(21+15*i,38);
		cout << statis[i].label;
		gotoXY(51+20*i,4);
		cout << statis[i].label;
		gotoXY(133,21+2*i); 
		cout << statis[i].label;
	}
	for(int i =0; i<5; i++){
		gotoXY(127,21+2*i);
		TextColor(Color_column[i]);
		cout << (char)432<<(char)433<<(char)434;
	}
}

void ChuThichSolieu(STATISTIC *statis){
	float max_quantity = 0;
	float max_percent = 0;
	TextColor(3);
	for (int i = 0; i<5; i++){
		if(max_quantity < statis[i].quantity){
			max_quantity = statis[i].quantity;
			max_percent = statis[i].percent;
		}
	}
	max_percent = round(max_percent/6);
//	gotoXY(30,0); cout << max_quantity<<"    "<< max_percent;
	int delta = round((max_quantity)/max_percent); 
	for(int i=0; i<=8; i++){
		gotoXY(13,37-3*i); cout << delta*i;
	}
}



//void CrawlType(LIST_THIET_BI &list){
//	LIST_STATISTIC statis;
//	STATISTIC temp_statis;
//	
//	BubblesortLevel(list, list.size());
//	
//	temp_statis.label = list[0].chung_loai;
//	temp_statis.quantity++;
//	for(int i = 1; i<list.size(); i++){
//		char *s = strstr(list[i-1].chung_loai, list[i].chung_loai);
//		if(s == NULL){
//			statis.push_back(temp_statis);
//			temp_statis.quantity = 1;
//			temp_statis.label = list[i].chung_loai;
//		}else{
//			temp_statis.quantity++;
//		}
//	}
//	statis.push_back(temp_statis);
//	PrintDynamicData(statis);
//}

void CrawlLevel(LIST_THIET_BI &list, STATISTIC *statis){
	
	BubblesortLevel(list, list.size());
	for(int i = 0; i<5; i++){
		statis[i].label = LabelLevel[i];
	}
	for(int i = 0; i<list.size(); i++){
		int level = atoi(list[i].cap);
		if(level == 1) statis[0].quantity++;
		else if(level == 2 ) statis[1].quantity++;
		else if(level == 3 ) statis[2].quantity++;
		else if(level == 4 ) statis[3].quantity++;
		else if(level == 5 ) statis[4].quantity++;
	}
	Percentage(statis);
	PrintData(statis);

}
   
void CrawlNSX(LIST_THIET_BI &list, STATISTIC *statis){
	
	BubbleNSX(list, list.size());
	for(int i = 0; i<5; i++){
		statis[i].label = LabelDate[i];
	}
	for(int i = 0; i<list.size(); i++){
		int year = Year(list[i].nsx);
		if(year >= 2020) statis[4].quantity++; 
		else if(year >= 2000 && year < 2005) statis[0].quantity++;
		else if(year >= 2005 && year < 2010) statis[1].quantity++;
		else if(year >= 2010 && year < 2015) statis[2].quantity++;
		else if(year >= 2015 && year < 2020) statis[3].quantity++;
	}
	Percentage(statis);
	PrintData(statis);
}

void CrawlNSD(LIST_THIET_BI &list, STATISTIC *statis){
	
	BubbleNSX(list, list.size());
	
	for(int i = 0; i<5; i++){
		statis[i].label = LabelDate[i];
	}
	for(int i = 0; i<list.size(); i++){
		int year = Year(list[i].nsd);
		if(year >= 2020) statis[4].quantity++; 
		else if(year >= 2000 && year < 2005) statis[0].quantity++;
		else if(year >= 2005 && year < 2010) statis[1].quantity++;
		else if(year >= 2010 && year < 2015) statis[2].quantity++;
		else if(year >= 2015 && year < 2020) statis[3].quantity++;
	}
	Percentage(statis);
	PrintData(statis);
}
 
void HandleCrawl(LIST_THIET_BI &list, STATISTIC *statis){
//	gotoXY(50,0); cout << index2;
	switch (index2){
		case 0:{
			CrawlNSX(list, statis);
			break;
		}
		case 1:{
			CrawlNSD(list, statis);
			break;
		}
		case 2:{
			CrawlLevel(list, statis);
			break;
		}
	}
	CotDoThi(statis);
	ChuThich(statis);
	ChuThichSolieu(statis);
}


void PrintData(STATISTIC *statis){
	int x = 25, y = 3, z = 24;
	for(int i = 0; i<5; i++){
		gotoXY(x+30+i*20, y+3);
	    cout << statis[i].quantity;
	    gotoXY(x+30+i*20, y+5);
	    cout << statis[i].percent<<" %";
	}
}

void Percentage(STATISTIC *statis){
	int sum = 0;
	for(int i = 0; i<5; i++){
		sum += statis[i].quantity;	
	}
	for(int i = 0; i<5; i++){
		statis[i].percent = (statis[i].quantity*100)/sum;
	}
}

void HandleMouseMovedStatis(MOUSE_EVENT_RECORD mer){
	An_tro_chuot();
	if(mer.dwMousePosition.X >=1 && mer.dwMousePosition.X <= 20 && mer.dwMousePosition.Y >=1 && mer.dwMousePosition.Y <= 3){
				Button(1,1,"     BACK", true);
			}else Button(1,1,"     BACK", false);
}

int ScreenStatis_Mouse_event(MOUSE_EVENT_RECORD mer,LIST_THIET_BI* list, COORD &toado ){
	if(mer.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED){
		if(mer.dwMousePosition.X >=1 && mer.dwMousePosition.X <= 25 && mer.dwMousePosition.Y >=1 && mer.dwMousePosition.Y <= 3) return -1;//BACK
	}else if(mer.dwEventFlags == MOUSE_MOVED){
			HandleMouseMovedStatis(mer);
	}
	return 0;
}

int ScreenStatistic(HANDLE &hStdin, INPUT_RECORD &irInBuf){
	DWORD cNumRead, i; 
	
	LIST_THIET_BI list;
	STATISTIC statis[5];
	COORD toado; toado.X=1; toado.Y =-1;
	
	DANHSACHTHONGKE(); 
	OutFile("Input.txt", list);
	HandleCrawl(list, statis);
    while(true){  
    	ReadConsoleInput( hStdin, &irInBuf, 1, &cNumRead);
			if(irInBuf.EventType == MOUSE_EVENT){
				switch(ScreenStatis_Mouse_event(irInBuf.Event.MouseEvent,&list, toado)){
					case -1:{
						index3 = -1;
						index2 = -1;
						return -1;
					}
				}
			}
	}
	
}                               








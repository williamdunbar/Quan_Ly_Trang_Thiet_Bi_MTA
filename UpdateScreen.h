#pragma once
#include<iostream>
#include<windows.h>
#include<vector>
#include"Update.h"
#include"Interface.h"
using namespace std;



THIETBI ReadInfo(ifstream &filein){
	THIETBI ttb;
	string temp;
	getline(filein, temp, '*');
	getline(filein, temp, '*');
	strcpy(ttb.maTTB,temp.c_str());
	getline(filein, temp, '*');
	strcpy(ttb.tenTTB,temp.c_str());
	getline(filein, temp, '*');
	strcpy(ttb.nsx,temp.c_str());
	getline(filein, temp, '*');
	strcpy(ttb.nsd,temp.c_str());
	getline(filein, temp, '*');
	strcpy(ttb.chung_loai,temp.c_str());
	filein >> ttb.cap;
	return ttb;
}

void OutFile(char *Filename, LIST_THIET_BI& list){
	ifstream filein;
	filein.open(Filename, ios_base::in);
	while(!filein.eof()){
		THIETBI ttb = ReadInfo(filein);
		list.push_back(ttb);
		gotoXY(10,0);
	}
	filein.close();
}				



int HandleChoose(MOUSE_EVENT_RECORD mer, LIST_THIET_BI& list, int &page){
	int k;
	PrintScreen(list, page);
	for(int i = 0; i<10; i++){
		TextColor(14);
			if(mer.dwMousePosition.X >=24 && mer.dwMousePosition.X <= 150 && mer.dwMousePosition.Y >=(11+2*i) && mer.dwMousePosition.Y <= (12+2*i)){
				TextColor(4);
				k = 10*(page-1)+i;
				if(k < list.size()){ 
				gotoXY(26,12+i*2); printf("%3d",(k+1));
				gotoXY(40,12+i*2); cout<< list[k].maTTB<<"   ";
				gotoXY(65,12+i*2); cout<< list[k].tenTTB<<"    ";
				gotoXY(90,12+i*2); cout << list[k].nsx;
				gotoXY(110,12+i*2);cout << list[k].nsd;
				gotoXY(127,12+i*2);cout << list[k].chung_loai<<"   ";
				gotoXY(145,12+i*2);cout << list[k].cap;
				return k;
				}
			}
	}
	return -1;
}

void HandleMouseMovedScreen3(MOUSE_EVENT_RECORD mer){
	An_tro_chuot();
	if(mer.dwMousePosition.X >=1 && mer.dwMousePosition.X <= 20 && mer.dwMousePosition.Y >=1 && mer.dwMousePosition.Y <= 3){
				Button(1,1,"     BACK", true);
			}else Button(1,1,"     BACK", false);
			
			if(mer.dwMousePosition.X >=115 && mer.dwMousePosition.X <= 130 && mer.dwMousePosition.Y >=33 && mer.dwMousePosition.Y <= 35){
				Button(115, 33, "    DELETE",true);
			}else Button(115, 33,"    DELETE",false);
			
			if(mer.dwMousePosition.X >=45 && mer.dwMousePosition.X <= 60 && mer.dwMousePosition.Y >=33 && mer.dwMousePosition.Y <= 35){
				Button(45, 33,"      ADD",true);
			}else Button(45, 33,"      ADD",false);
			
			if(mer.dwMousePosition.X >=80 && mer.dwMousePosition.X <= 95 && mer.dwMousePosition.Y >=33 && mer.dwMousePosition.Y <= 35){
				Button(80, 33, "     EDIT",true);
			}else Button(80, 33, "     EDIT",false);
			
			if(mer.dwMousePosition.X >=155 && mer.dwMousePosition.X <= 170 && mer.dwMousePosition.Y >=18 && mer.dwMousePosition.Y <= 20){
				Button(155, 18,"     Next >>",true);
			}else Button(155, 18,"     Next >>",false);
			
			if(mer.dwMousePosition.X >=5 && mer.dwMousePosition.X <= 20 && mer.dwMousePosition.Y >=18 && mer.dwMousePosition.Y <= 20){
				Button(5, 18," << Previous",true);
			}else Button(5, 18," << Previous",false);
}

int Screen3_Mouse_click(MOUSE_EVENT_RECORD mer,LIST_THIET_BI* list, COORD &toado, int &page ){
	if(mer.dwMousePosition.X >=24 && mer.dwMousePosition.X <= 150 && mer.dwMousePosition.Y >=11 && mer.dwMousePosition.Y <= 30){
			toado.Y = HandleChoose(mer, *list, page);
		}
		if(mer.dwMousePosition.X >=155 && mer.dwMousePosition.X <= 170 && mer.dwMousePosition.Y >=18 && mer.dwMousePosition.Y <= 20){
			XoaDulieu(); 
			return 2;// NEXT 
		}
		if(mer.dwMousePosition.X >=5 && mer.dwMousePosition.X <= 20 && mer.dwMousePosition.Y >=18 && mer.dwMousePosition.Y <= 20) return 1;//PREVIOUS
		if(mer.dwMousePosition.X >=1 && mer.dwMousePosition.X <= 25 && mer.dwMousePosition.Y >=1 && mer.dwMousePosition.Y <= 3) return -1;//BACK
		if(mer.dwMousePosition.X >=115 && mer.dwMousePosition.X <= 130 && mer.dwMousePosition.Y >=33 && mer.dwMousePosition.Y <= 35)	
			HandleDelete(list, toado, page);//DELETE
		if(mer.dwMousePosition.X >=45 && mer.dwMousePosition.X <= 60 && mer.dwMousePosition.Y >=33 && mer.dwMousePosition.Y <= 35)	return 3;// ADD
		if(mer.dwMousePosition.X >=80 && mer.dwMousePosition.X <= 95 && mer.dwMousePosition.Y >=33 && mer.dwMousePosition.Y <= 35){
			if(toado.Y != -1) return 4;//EDIT
		}
}


int Screen3_Mouse_event(MOUSE_EVENT_RECORD mer,LIST_THIET_BI* list, COORD &toado, int &page ){
	if(mer.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED){
		int i;
		i = Screen3_Mouse_click(mer,list, toado, page);
		return i;
	}else if(mer.dwEventFlags == MOUSE_MOVED){
			HandleMouseMovedScreen3(mer);
	}else if(mer.dwEventFlags == MOUSE_WHEELED){
		if(mer.dwButtonState == 4287102976){
			return 2;
		}
		else if(mer.dwButtonState == 7864320){
			return 1;
		}
	}  return 0;
}


int Screen3(HANDLE &hStdin, INPUT_RECORD &irInBuf){
	LIST_THIET_BI list;
	DWORD cNumRead, i;
	COORD toado; toado.X=1; toado.Y =-1;
	int page = 1;
	int vitri = 0;
	Xoa_Full_Man_hinh();  
	CAPNHATDANHSACH(); 
	Table();
	OutFile("Input.txt", list);
	PrintScreen(list, page);
    while(true){  
    	ReadConsoleInput( hStdin, &irInBuf, 1, &cNumRead);
			if(irInBuf.EventType == MOUSE_EVENT){
				switch(Screen3_Mouse_event(irInBuf.Event.MouseEvent,&list, toado, page)){
					case -1:	return -1;
					case  2:{ //Next 
						if(page <= (list.size()/10)){
							XoaDulieu();
							page++;	
						}
						PrintScreen(list, page);
						break;
					} 
					case  1:{//Previous
						page--;
						gotoXY(50,0); cout << page;
						PrintScreen(list, page);
						break;
					}
					case 3:{//ADD
						THIETBI temp;
						page = (list.size())/10 +1 ; 
						XoaDulieu();
						PrintScreen(list, page);
						toado.Y = list.size()%10;
						gotoXY(26,12+toado.Y*2);
						printf("%3d", list.size()+1);
						while(true){  
    						ReadConsoleInput( hStdin, &irInBuf, 1, &cNumRead); 
    						if(HandleAddInput(irInBuf, list, toado, temp) == true) {
    							PrintScreen(list, page);
    						break;
							}
    					}
						break;
					}
					case 4:{ //EDIT
						int temp = toado.Y;
						toado.Y = toado.Y % 10;
//						gotoXY(30,0); cout << temp;
						while(true){
							ReadConsoleInput( hStdin, &irInBuf, 1, &cNumRead); 
							if(HandleEdit(irInBuf, list, toado, temp) == true){
								PrintScreen(list, page);
								break;
							}
						} An_tro_chuot();
						break;
					}
				}
			}
	}
}



















































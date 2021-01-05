#pragma once
#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <vector>
#include <string.h>
#include <string>
#include <fstream>
#include "Console.h"
//#include "Screen2.h"
//#include "Input.h"
using namespace std;

/*----------------------------------------Delete---------------------------------------------------*/

void HandleDelete(LIST_THIET_BI *list, COORD &toado, int &page){
	if(toado.Y != -1){
		LIST_THIET_BI &temp_list(*list);
		int temp_num = list->size();
		list->clear();
		gotoXY(30,0);
		for(int i=0; i<temp_num; i++){
			if(i != toado.Y) list->push_back(temp_list[i]);
		}
		XoaDulieu();
 		PrintScreen(*list, page);
		Note_Frame("                  ELEMENT HAS BEEN DELETED     "); 
		InFile("Input.txt", list, "w");
		toado.Y = -1;
	}
}  

/*------------------------------------------Add-----------------------------------------------------*/

bool HandleEnterAdd(KEY_EVENT_RECORD ker,LIST_THIET_BI& list,THIETBI &ttb, COORD &toado){
	char key = ker.uChar.AsciiChar;
	if(ker.bKeyDown){
		if(key == ENTER){
			if(toado.X == 7){
				if(SaveList(&list,ttb, toado) == false) return false;
				else{
					InFile("Input.txt",&list, "w");
					return true;
				}
			}else {
				toado.X++;	
			}
		} 
	}
	return false;  
}

int Screen3_Mouse_add(MOUSE_EVENT_RECORD mer,LIST_THIET_BI& list, COORD &toado){
	if(mer.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED){
		if(mer.dwMousePosition.X >=1 && mer.dwMousePosition.X <= 25 && mer.dwMousePosition.Y >=1 && mer.dwMousePosition.Y <= 3){
			XoaDulieu();
			return -1;
		}
				if(mer.dwMousePosition.X >= 32 && mer.dwMousePosition.X <= 57) toado.X = 1;
				if(mer.dwMousePosition.X >= 58 && mer.dwMousePosition.X <= 86) toado.X = 2;
				if(mer.dwMousePosition.X >= 87 && mer.dwMousePosition.X <= 105) toado.X = 3;
				if(mer.dwMousePosition.X >= 106 && mer.dwMousePosition.X <= 123) toado.X = 4;
				if(mer.dwMousePosition.X >= 124 && mer.dwMousePosition.X <= 141) toado.X = 5;
				if(mer.dwMousePosition.X >= 142 && mer.dwMousePosition.X <= 152) toado.X = 6;
	}else if(mer.dwEventFlags == MOUSE_MOVED){
		if(mer.dwMousePosition.X >=0 && mer.dwMousePosition.X <= 30 && mer.dwMousePosition.Y >=0 && mer.dwMousePosition.Y <= 9){
			An_tro_chuot();
			if(mer.dwMousePosition.X >=1 && mer.dwMousePosition.X <= 25 && mer.dwMousePosition.Y >=1 && mer.dwMousePosition.Y <= 3){
				Button(1,1,"     BACK", true);
			}else Button(1,1,"     BACK", false);
			Hien_tro_chuot();
		}
	}
	return 0;
} 

void HandleCoordAdd(KEY_EVENT_RECORD ker,LIST_THIET_BI& list,THIETBI &ttb, COORD &toado){
	COORD local_coord;
	char key = ker.uChar.AsciiChar;
	for(int i = 0; i<10;i++){
		TextColor(11);
		if(toado.Y == i) local_coord.Y = 12+i*2;
	}
	if(toado.X == 0){
		gotoXY(27,local_coord.Y);
		gotoXY(35,local_coord.Y);
		toado.X = 1;
	}else if(toado.X == 1){
		local_coord.X = 40 ;
		Screen2_key_event(ker, local_coord, ttb.maTTB,10);
	}else if(toado.X == 2){
		local_coord.X = 65;
		Screen2_key_event(ker, local_coord, ttb.tenTTB,20);
	}else if(toado.X == 3){
		local_coord.X = 90;
		Screen2_key_number(ker,local_coord, ttb.nsx,11);
	}else if(toado.X == 4){
		local_coord.X = 110;
		Screen2_key_number(ker,local_coord, ttb.nsd, 11);
	}else if(toado.X == 5){
		local_coord.X = 128;
		Screen2_key_alphabet(ker,local_coord, ttb.chung_loai,10);
	}else if(toado.X == 6){
		local_coord.X = 145;
		Screen2_key_number(ker,local_coord, ttb.cap,2);
	}
}

bool HandleAddInput(INPUT_RECORD &irInBuf, LIST_THIET_BI& list, COORD &toado, THIETBI &ttb){
	if(irInBuf.EventType == MOUSE_EVENT){
		if(Screen3_Mouse_add(irInBuf.Event.MouseEvent,list, toado) == -1) 
			return true;
	}
	Hien_tro_chuot();		
	HandleCoordAdd(irInBuf.Event.KeyEvent, list, ttb,toado);
	if(HandleEnterAdd(irInBuf.Event.KeyEvent, list,ttb, toado) == true) 
		return true;
	return false;
}


/*------------------------------------------Edit-----------------------------------------------------*/


bool HandleEnterEdit(KEY_EVENT_RECORD ker,LIST_THIET_BI& list,int temp, COORD &toado){
	char key = ker.uChar.AsciiChar;
	if(ker.bKeyDown){
		if(key == ENTER){
			if(toado.X == 7){
				if(Check_Full(&list, list[temp], toado) == false) return false;
				else{
					InFile("Input.txt",&list, "w");
					return true;
				}
			}else {
				toado.X++;	
			}
		} 
	}
	return false;  
}

int Screen3_Mouse_edit(MOUSE_EVENT_RECORD mer,LIST_THIET_BI& list, COORD &toado){
	if(mer.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED){
		if(mer.dwMousePosition.X >=1 && mer.dwMousePosition.X <= 25 && mer.dwMousePosition.Y >=1 && mer.dwMousePosition.Y <= 3){
			XoaDulieu();
			return -1;
		}
				if(mer.dwMousePosition.X >= 32 && mer.dwMousePosition.X <= 57) toado.X = 1;
				if(mer.dwMousePosition.X >= 58 && mer.dwMousePosition.X <= 86) toado.X = 2;
				if(mer.dwMousePosition.X >= 87 && mer.dwMousePosition.X <= 105) toado.X = 3;
				if(mer.dwMousePosition.X >= 106 && mer.dwMousePosition.X <= 123) toado.X = 4;
				if(mer.dwMousePosition.X >= 124 && mer.dwMousePosition.X <= 141) toado.X = 5;
				if(mer.dwMousePosition.X >= 142 && mer.dwMousePosition.X <= 152) toado.X = 6;
				
	}else if(mer.dwEventFlags == MOUSE_MOVED){
		if(mer.dwMousePosition.X >=0 && mer.dwMousePosition.X <= 30 && mer.dwMousePosition.Y >=0 && mer.dwMousePosition.Y <= 9){
			An_tro_chuot();
			if(mer.dwMousePosition.X >=1 && mer.dwMousePosition.X <= 25 && mer.dwMousePosition.Y >=1 && mer.dwMousePosition.Y <= 3){
				Button(1,1,"     BACK", true);
			}else Button(1,1,"     BACK", false);
			Hien_tro_chuot();
		}
	}
	return 0;
} 
	

void HandleCoordEdit(KEY_EVENT_RECORD ker,LIST_THIET_BI& list,int temp, COORD &toado){
	COORD local_coord;
	char key = ker.uChar.AsciiChar;
	for(int i = 0; i<10;i++){
		TextColor(11);
		if(toado.Y == i) local_coord.Y = 12+i*2;
	}
	if(toado.X == 0){
		gotoXY(27,local_coord.Y);
		gotoXY(35,local_coord.Y);
		toado.X = 1;
	}else if(toado.X == 1){
		local_coord.X = 40 ;
		Screen2_key_event(ker, local_coord, list[temp].maTTB,10);
	}else if(toado.X == 2){
		local_coord.X = 65 ;
		Screen2_key_event(ker,local_coord, list[temp].tenTTB,25);
	}else if(toado.X == 3){
		local_coord.X = 90 ;
		Screen2_key_number(ker,local_coord, list[temp].nsx,11);
	}else if(toado.X == 4){
		local_coord.X = 110;
		Screen2_key_number(ker,local_coord, list[temp].nsd, 11);
	}else if(toado.X == 5){
		local_coord.X = 127;
		Screen2_key_alphabet(ker,local_coord, list[temp].chung_loai,13);
	}else if(toado.X == 6){
		local_coord.X = 145;
		Screen2_key_number(ker,local_coord, list[temp].cap,2);
	}
}



bool  HandleEdit(INPUT_RECORD &irInBuf, LIST_THIET_BI& list, COORD &toado, int temp){
	if(irInBuf.EventType == MOUSE_EVENT){
		if(Screen3_Mouse_edit(irInBuf.Event.MouseEvent,list, toado) == -1) return true;
	}
	Hien_tro_chuot();
	HandleCoordEdit(irInBuf.Event.KeyEvent, list, temp, toado);
	if(HandleEnterEdit(irInBuf.Event.KeyEvent, list,temp, toado) == true) 
		return true;
	return false;
}


















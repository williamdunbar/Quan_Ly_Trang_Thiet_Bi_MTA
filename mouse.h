#include <windows.h>
#include <stdio.h>
#include <iostream>
using namespace std;


//
//VOID KeyEventProc(KEY_EVENT_RECORD ker)
//{
//	char key = (char)ker.uChar.UnicodeChar;
//	int num = ker.uChar.UnicodeChar;
//	if(ker.bKeyDown ){
//		if(num == 32) cout <<key;
//		if(num >= 47 && num <= 126 )
//		cout << key;	
//	}
//}

//void MouseEventProc(MOUSE_EVENT_RECORD mer,  DWORD mouse)
//{
//#ifndef MOUSE_HWHEELED
//#define MOUSE_HWHEELED 0x0008
//#endif
////    printf("Mouse event: ");
//	if(mer.dwButtonState == mouse){
//		cout << mer.dwMousePosition.X<<", "<<mer.dwMousePosition.Y<<"   ";}
//	else
//	if(mer.dwEventFlags == mouse){
//		switch(mer.dwEventFlags)
//		{
//			case DOUBLE_CLICK:
//				cout << mer.dwMousePosition.X<<", "<<mer.dwMousePosition.Y<<endl;
//			case MOUSE_MOVED:
//				cout << mer.dwMousePosition.X<<", "<<mer.dwMousePosition.Y<<endl;
//		}
//	}
//}
	
bool Is_mouse_click(){
	DWORD fdwSaveOldMode, fdwMode, cNumRead,i; 
	INPUT_RECORD irInBuf[128];
	HANDLE hStdin;
	hStdin = GetStdHandle(STD_INPUT_HANDLE); 
	fdwMode = ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT; 
    while(true){
    	ReadConsoleInput( 
                hStdin,      // input buffer handle 
                irInBuf,     // buffer to read into 
                128,         // size of read buffer 
                &cNumRead); // number of records read 
    
    for(int i = 0; i< cNumRead; i++){
    	if(irInBuf[i].Event.MouseEvent.dwControlKeyState == FROM_LEFT_1ST_BUTTON_PRESSED){
    		cout << "dsjdngsff";
    		return true;
		}else return false;
	}
	}
	
}

//void Mouse_click(){
//	HANDLE hStdin; 
//	DWORD fdwSaveOldMode, fdwMode, cNumRead,i; 
//	INPUT_RECORD irInBuf[128];
//		hStdin = GetStdHandle(STD_INPUT_HANDLE); 
//	fdwMode = ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT; 
//    
//	ReadConsoleInput( 
//                hStdin,      // input buffer handle 
//                irInBuf,     // buffer to read into 
//                128,         // size of read buffer 
//                &cNumRead); // number of records read 
//    
//    for(int i = 0; i< cNumRead; i++){
//    	if(irInBuf[i].EventType == MOUSE_EVENT){
//    		MouseEventProc(irInBuf[i].Event.MouseEvent, FROM_LEFT_1ST_BUTTON_PRESSED);
//		}
//	}
//}

//COORD Input_Console(DWORD mouse) 
//{ 
//    DWORD cNumRead, fdwMode,i; 
//    INPUT_RECORD irInBuf[128]; 
// 
//    // Get the standard input handle. 
// 
//    hStdin = GetStdHandle(STD_INPUT_HANDLE); 
//
// 
//    fdwMode = ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT; 
//
//    while (true) 
//    { 
//        // Wait for the events. 
// 
//        ReadConsoleInput( 
//                hStdin,      // input buffer handle 
//                irInBuf,     // buffer to read into 
//                128,         // size of read buffer 
//                &cNumRead); // number of records read 
// 
//        // Dispatch the events to the appropriate handler. 
// 
//        for (i = 0; i < cNumRead; i++) 
//        {
//            switch(irInBuf[i].EventType) 
//            { 
//                case KEY_EVENT: // keyboard input 
//                    KeyEventProc(irInBuf[i].Event.KeyEvent); 
//                    break; 
// 
//                case MOUSE_EVENT: // mouse input 
//                    MouseEventProc(irInBuf[i].Event.MouseEvent,mouse); 
//                    break; 
//            } 
//        }
//    } 
//    // Restore input mode on exit.
//
//    SetConsoleMode(hStdin, fdwSaveOldMode);
// 
//    return 0; 
//}

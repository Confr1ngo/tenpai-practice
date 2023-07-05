#ifndef _COLORFUL_PRINTER_H_
#define _COLORFUL_PRINTER_H_
// #pragma message("Some headers (cstdarg, string, cstdio, vector, cmath) are already included.")
#include<cstdarg>
#include<string>
#include<cstdio>
#include<vector>
#include<cmath>
namespace ColorfulPrinter{
    long long lowbit(long long n){
        return n&(~n+1);
    }
    const long long FG_BLACK=       (1ll<<0);
    const long long FG_RED=         (1ll<<1);
    const long long FG_GREEN=       (1ll<<2);
    const long long FG_YELLOW=      (1ll<<3);
    const long long FG_BLUE=        (1ll<<4);
    const long long FG_PURPLE=      (1ll<<5);
    const long long FG_DARKGREEN=   (1ll<<6);
    const long long FG_WHITE=       (1ll<<7);
    const long long BG_BLACK=       (1ll<<8);
    const long long BG_RED=         (1ll<<9);
    const long long BG_GREEN=       (1ll<<10);
    const long long BG_YELLOW=      (1ll<<11);
    const long long BG_BLUE=        (1ll<<12);
    const long long BG_PURPLE=      (1ll<<13);
    const long long BG_DARKGREEN=   (1ll<<14);
    const long long BG_WHITE=       (1ll<<15);
    const long long NONE=           (1ll<<16);
    const long long BOLD=           (1ll<<17);
    const long long UNDERLINE=      (1ll<<18);
    const long long BLINK=          (1ll<<19);
    const long long REVERSE=        (1ll<<20);
    const long long HIDE=           (1ll<<21);
    const long long FG_BLACK_BR=    (1ll<<22);
    const long long FG_RED_BR=      (1ll<<23);
    const long long FG_GREEN_BR=    (1ll<<24);
    const long long FG_YELLOW_BR=   (1ll<<25);
    const long long FG_BLUE_BR=     (1ll<<26);
    const long long FG_PURPLE_BR=   (1ll<<27);
    const long long FG_DARKGREE_BR= (1ll<<28);
    const long long FG_WHITE_BR=    (1ll<<29);
    const long long BG_BLACK_BR=    (1ll<<30);
    const long long BG_RED_BR=      (1ll<<31);
    const long long BG_GREEN_BR=    (1ll<<32);
    const long long BG_YELLOW_BR=   (1ll<<33);
    const long long BG_BLUE_BR=     (1ll<<34);
    const long long BG_PURPLE_BR=   (1ll<<35);
    const long long BG_DARKGREEN_BR=(1ll<<36);
    const long long BG_WHITE_BR=    (1ll<<37);
    const long long CLEARSCREEN=    (1ll<<38);
    const long long DELTOEND=       (1ll<<39);
    const long long SAVECURSOR=     (1ll<<40);
    const long long RECOVERCURSOR=  (1ll<<41);
    const long long SHOWCURSOR=     (1ll<<42);
    const long long HIDECURSOR=     (1ll<<43);
    const std::string strs[44]={
        "\033[30m","\033[31m","\033[32m","\033[33m",
        "\033[34m","\033[35m","\033[36m","\033[37m",
        "\033[40m","\033[41m","\033[42m","\033[43m",
        "\033[44m","\033[45m","\033[46m","\033[47m",
        "\033[0m","\033[1m","\033[4m","\033[5m",
        "\033[7m","\033[8m",
        "\033[90m","\033[91m","\033[92m","\033[93m",
        "\033[94m","\033[95m","\033[96m","\033[97m",
        "\033[100m","\033[101m","\033[102m","\033[103m",
        "\033[104m","\033[105m","\033[106m","\033[107m",
        "\033[2J","\033[K","\033[s","\033[u",
        "\033[?25l]","\033[?25h"
    };
    void printer(long long state,int sum,...){
        if (sum!=0){
            va_list pArgs;
            va_start(pArgs,sum);
            while (state){
                long long t=lowbit(state);state-=t;
                printf("%s",strs[(long long)(round(log(t)/log(2)))].c_str());
            }
            for (int i=1;i<=sum;i++){
                printf("%s",va_arg(pArgs,char*));
            }
            printf("%s",strs[16].c_str());
        }
        else{
            while (state){
                long long t=lowbit(state);state-=t;
                printf("%s",strs[(long long)(round(log(t)/log(2)))].c_str());
            }
            printf("%s",strs[16].c_str());
        }
    }
};
#define CP ColorfulPrinter
#endif
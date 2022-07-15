#include "ConsoleLib.h"

/*单位：秒*/
void sleep_second(int time) {
#if defined(__linux__)// Linux系统
    sleep(time);
#elif defined(_WIN32)// Windows系统
    Sleep((time * 1000));
#endif
}

/*单位：毫秒*/
void sleep_micro(int time) {
#if defined(__linux__)// Linux系统
    usleep(time * 1000);
#elif defined(_WIN32)// Windows系统
    Sleep(time);
#endif
}

void SetTitle(const char* title)
{
    WCHAR wchar_title[255];
    memset(wchar_title, 0, sizeof(wchar_title));
    MultiByteToWideChar(CP_ACP, 0, title, strlen(title) + 1, wchar_title, sizeof(wchar_title) / sizeof(wchar_title[0]));
    SetConsoleTitle(wchar_title);
    //SetConsoleTitle(title);
}

void SetColor(int ForeColor, int BackGroundColor)
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);                    //获取当前窗口句柄
    //Windows函数
    SetConsoleTextAttribute(handle, ForeColor + BackGroundColor * 0x10);//设置颜色
}
void SetConsoleWindowSize(int width, int height)
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    //设置控制台窗口的缓冲区大小 COORD
    COORD size = { width, height };
    SetConsoleScreenBufferSize(handle, size);
    //设置控制台窗口大小,最大坐标是缓冲区大小-1
    SMALL_RECT rect = { 0, 0, width - 1, height - 1 };
    SetConsoleWindowInfo(handle, 1, &rect);
}
void SetPosition(int x, int y)
{
    COORD cursorPosition;   //光标的坐标
    HANDLE handle;          //当前窗口句柄
    handle = GetStdHandle(STD_OUTPUT_HANDLE);
    cursorPosition.X = x;   //设置x、y坐标
    cursorPosition.Y = y;
    SetConsoleCursorPosition(handle, cursorPosition);
}
void PrintString(const char* msgString)
{
    int length = strlen(msgString);
    int i = 0;
    for (; i < length; i++)
    {
        char tempChar = msgString[i];
        printf("%c", tempChar);
        sleep_micro(1000 * 20);//20毫秒
        fflush(stdout);
    }
}
void Read(char* Buffer, int BufferSize)
{
    DWORD Read;
    HANDLE handle;          //当前窗口句柄
    handle = GetStdHandle(STD_INPUT_HANDLE);
    ReadConsole(handle, Buffer, BufferSize, &Read, NULL);
}

int GetKey()
{
    HANDLE handle;          //当前窗口句柄
    handle = GetStdHandle(STD_INPUT_HANDLE);
    DWORD Read;
    INPUT_RECORD Event;
    //得到控制台的输入
    ReadConsoleInput(handle, &Event, 1, &Read);
    //如果输入事件是一个键盘事件，就进行判断，返回按下键的虚拟键码
    if (Event.EventType == KEY_EVENT)
    {
        if (Event.Event.KeyEvent.bKeyDown)//返回值为true，表示有键被按下
        {
            return Event.Event.KeyEvent.wVirtualKeyCode;//返回按下键的虚拟键码
        }
    }
    return 0;
}
char* GetTime()
{
    time_t rawtime;
    struct tm* timeinfo;
    static char buffer[128];

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", timeinfo);
    return buffer;
}
void Clear(int X, int Y)
{
    DWORD written;
    COORD start;    //开始坐标
    HANDLE handle;  //当前窗口句柄
    handle = GetStdHandle(STD_OUTPUT_HANDLE);
    start.X = X;
    start.Y = Y;
    FillConsoleOutputAttribute(handle, 15, 80 * 25, start, &written);
    FillConsoleOutputCharacter(handle, '0', 80 * 25, start, &written);
    SetConsoleCursorPosition(handle, start);
}
void ClearMessage()
{
    //清空信息显示区
    COORD coordStart = { 0, 12 };
    DWORD written;
    HANDLE handle;  //当前窗口句柄
    handle = GetStdHandle(STD_OUTPUT_HANDLE);
    FillConsoleOutputAttribute(handle, 15, 120 * 7, coordStart, &written);
    FillConsoleOutputCharacter(handle, ' ', 120 * 7, coordStart, &written);
    SetConsoleCursorPosition(handle, coordStart);
}

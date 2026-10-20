#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    int a =19;
    cout << "a=" << a <<"大小"<<sizeof(a)<< endl;
    return 0;
}
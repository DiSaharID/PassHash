#include <iostream>
#include <conio.h>
#include <string>

unsigned int strhashing(std::string pwd)
{
    std::hash<std::string> hash_obj;
    return hash_obj(pwd);
}
int main()
{
    setlocale(LC_ALL, "Russian");
    std::string pwd;
    std::cout<<"������� ������:\n";
    int ch = 0;               // ���������� ��� �������.
    while (true)                // �������� ������������ �����.
    {
        ch = _getch();        // �������� ��� ������� ������� � ����������.
        if (ch == 13)         // ��������� Enter �� ���������� �����.
        {
            break;         // ���������� �����.
        }
        if (ch == 27)   // ��������� Esc �� �������� �������.
        {
            exit (0);      // ����� �� �������.
        }
        if (ch == 8)     // ��������� Backspace �� �������� ��������.
        {
            std::cout << (char)8 << ' ' <<char(8);
            if (!pwd.empty())
                pwd.erase(pwd.length()-1);
        }
        else
        {
            std::cout << '*';            // ������ �������� �� *
            pwd += (char)ch;       // ����������� ���� �� ������ ����� � ������.
        }
    }
    unsigned int hash_pwd = strhashing(pwd);
    if (hash_pwd == 769277631)
        std::cout<<"\n���������� ������";
    else
        std::cout<<"\n������������ ������";
}

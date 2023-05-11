#include <bits/stdc++.h>

using namespace std;

int to_int(const char& c)
{
    if( isalpha(c) )
        return c - 'A' + 10;

    return c - '0';
}

char to_char(const long long& number)
{
    if( number >= 10 )
        return 'A' - 10 + number;

    return number + '0';
}

bool check_invalid(const string& number, const int& base)
{
    for( char n: number )
        if( to_int(n) >= base )
            return true;

    return false;
}

long long base_10(const string& number, const int& base)
{
    long long ans = to_int(number[0]);

    for( int i = 1; i < number.size(); i++ )
        ans = ans * base + to_int(number[i]);

    return ans;
}

string to_base(const long long& number, const int& base)
{
    string ans = "";
    long long divisoes = number;
    long long resto = 0;
    while( divisoes >= base )
    {
        resto = divisoes % base;
        ans = to_char(resto) + ans;
        divisoes = divisoes / base;
    }
    ans = to_char(divisoes) + ans;
    return ans;
}

int main() {
    int base, nxt_base;
    string number;

    while( cin >> base >> nxt_base >> number, !cin.eof())
    {
        if( check_invalid(number, base) )
            cout << number << " is an illegal base " << base  <<" number\n";
        else
            cout << number << " base "<< base <<" = "<< to_base(base_10(number,base),nxt_base)<<" base "<< nxt_base << '\n';
    }

    return 0;
}


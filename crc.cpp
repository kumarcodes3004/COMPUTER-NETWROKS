#include <bits/stdc++.h>
using namespace std;
string xor1(string a, string b)
{
    string res = "";
    int n = b.length();
    for (int i = 1; i < n; i++)
    {
        if (a[i] == b[i])
            res += "0";
        else
            res += "1";
    }
    return res;
}
string div(string message, string divisor)
{
    int k = divisor.length();
    string mid = message.substr(0, k);
    int n = message.length();
    while (k < n)
    {
        if (mid[0] == '1')
        {
            mid = xor1(divisor, mid) + message[k];
        }
        else
        {
            mid = xor1(string(k, '0'), mid) + message[k];
        }
        k++;
    }
    if (mid[0] == '1')
        mid = xor1(divisor, mid);
    else
        mid = xor1(string(k, '0'), mid);
    return mid;
}
void encodeData(string data, string key)
{
    int l_key = key.length();
    string appended_data = (data + string(l_key - 1, '0'));
    string remainder = div(appended_data, key);
    string codeword = data + remainder;
    cout << "Remainder: " << remainder << endl
         << "Encoded Data(Data+ Remainder): " << codeword << endl;
}
int main()
{
    string data = "100100";
    string key = "1101";
    encodeData(data, key);
    return 0;
}
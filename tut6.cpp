#include <bits/stdc++.h>
#include <bitset>
#include "opcodes.h"

using namespace std;
typedef long long ll;
typedef vector<long long> vi;
typedef pair<long long, long long> pi;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define mod 1000000007
#define f(i, m, n) for (ll i = m; i < n; i++)
#define arrange(a) sort(a.begin(), a.end())
#define rarrange(a) sort(a.rbegin(), a.rend())
#define endl '\n'

#define f1 opc.f1
#define f2 opc.f2
#define f3 opc.f3
#define reg opc.reg
#define dne " does not exist" << endl;
// struct P {
// int x, y;
// bool operator<(const P &p) {
// if (x != p.x) return x < p.x;
// else return y < p.y;
// }
// };

int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);
    Opcodes opc = Opcodes();
    // cout << opc.f1["11000100"];
    int t;
    cin >> t;
    while (t--)
    {
        string hexNumber;
        cin >> hexNumber;

        string binaryNumber = "";
        for (char c : hexNumber)
        {
            switch (c)
            {
            case '0':
                binaryNumber += "0000";
                break;
            case '1':
                binaryNumber += "0001";
                break;
            case '2':
                binaryNumber += "0010";
                break;
            case '3':
                binaryNumber += "0011";
                break;
            case '4':
                binaryNumber += "0100";
                break;
            case '5':
                binaryNumber += "0101";
                break;
            case '6':
                binaryNumber += "0110";
                break;
            case '7':
                binaryNumber += "0111";
                break;
            case '8':
                binaryNumber += "1000";
                break;
            case '9':
                binaryNumber += "1001";
                break;
            case 'A':
            case 'a':
                binaryNumber += "1010";
                break;
            case 'B':
            case 'b':
                binaryNumber += "1011";
                break;
            case 'C':
            case 'c':
                binaryNumber += "1100";
                break;
            case 'D':
            case 'd':
                binaryNumber += "1101";
                break;
            case 'E':
            case 'e':
                binaryNumber += "1110";
                break;
            case 'F':
            case 'f':
                binaryNumber += "1111";
                break;
            default:
                cout << "Invalid hexadecimal number!" << endl;
                return 0;
            }
        }
        int format = binaryNumber.length() % 8 == 0 ? (binaryNumber.length()) / 8 : -1;
        // cout << binaryNumber << endl;
        if (format == 1)
        {
            auto temp = f1.find(binaryNumber.substr(0, 8));
            if (temp != f1.end())
            {
                cout << "Instruction is" << temp->S << endl;
            }
            else
            {
                cout << "Operation is invalid because the assembly code for the following opcode does not exist" << endl;
            }
        }
        else if (format == 2)
        {
            string first_opcode = binaryNumber.substr(0, 8);
            string reg1 = binaryNumber.substr(8, 12);
            string reg2 = binaryNumber.substr(12, 16);
            auto tempop = f2.find(first_opcode);
            auto tempreg1 = reg.find(reg1);
            auto tempreg2 = reg.find(reg2);

            if (tempop != f2.end())
            {
                if (tempreg1 != reg.end())
                {
                    if (tempreg2 != reg.end())
                    {
                        cout << "Instruction is: " << tempop->S << " " << tempreg1->S << "," << tempreg2->S << endl;
                    }
                    else
                    {
                        cout << "Invalid Instruction. Register " << reg2 << dne
                    }
                }
                else
                {
                    cout << "Invalid Instruction. Register " << reg1 << dne
                }
            }
            else
            {
                cout << "Invalid Instruction. Assembly Instruction " << dne
            }
        }
        else if (format == 3)
        {
            string opcode = binaryNumber.substr(0, 6);
            char n = binaryNumber[6];
            char i = binaryNumber[7];
            char x = binaryNumber[8];
            char b = binaryNumber[9];
            char p = binaryNumber[10];
            char e = binaryNumber[11];
            string address = binaryNumber.substr(12, 24);
            auto tempop = f3.find(opcode);

            if (tempop != f3.end())
            {
                if (n == '0' && i == '0')
                {
                    if (tempop->S == "RSUB")
                    {
                        if (e == '0' && x == '0' && n == '0' && i == '0' && b == '0' && p == '0')
                        {
                            cout << "Instruction is Valid" << endl;
                        }
                        else
                        {
                            cout << "RSUB instruction must have operand 00" << endl;
                        }
                    }
                    else
                    {
                        cout << "Instruction is Valid" << endl;
                    }
                }
                else
                {
                    if (e != '0')
                    {
                        cout << "Invalid Instruction. Invalid Value of register E. It should be 0" << endl;
                    }
                    else
                    {
                        if (b == '1' && p == '1')
                        {
                            cout << "Invalid Instruction. Both Base and PC relative addressing" << endl;
                        }
                        else
                        {
                            if ((n == '1' && i == '0' && x == '1') || (n == '0' && i == '1' && x == '1'))
                            {
                                cout << "Invalid Instruction. x must be zero in indirect and immediate mode of addressing" << endl;
                            }
                            else
                            {
                                if (tempop->S == "RSUB")
                                {
                                    if (e == '0' && x == '0' && n == '0' && i == '0' && b == '0' && p == '0' && address == "000000000000")
                                    {
                                        cout << "Instruction is Valid" << endl;
                                    }
                                    else
                                    {
                                        cout << "RSUB instruction must have operand 00" << endl;
                                    }
                                }
                                else
                                {
                                    cout << "Instruction is Valid" << endl;
                                }
                            }
                        }
                    }
                }
            }
            else
            {
                cout << "Invalid Instruction. Opcode in this format" << dne
            }
        }
        else if (format == 4)
        {
            string opcode = binaryNumber.substr(0, 6);
            char n = binaryNumber[6];
            char i = binaryNumber[7];
            char x = binaryNumber[8];
            char b = binaryNumber[9];
            char p = binaryNumber[10];
            char e = binaryNumber[11];
            string address = binaryNumber.substr(12, 24);
            auto tempop = f3.find(opcode);
            if (tempop != f3.end())
            {
                if (n == '0' && i == '0')
                {
                    cout << "Invalid Instruction. Value of n and i both can't be zero in extended mode of addressing" << endl;
                }
                else
                {
                    if (e == '0')
                    {
                        cout << "Invalid Instruction. Invalid Value of register E. It should be 1 in  format 4." << endl;
                    }
                    else
                    {
                        if (b != '0' || p != '0')
                        {
                            cout << "Invalid Instruction. b and p should be zero" << endl;
                        }
                        else
                        {
                            if (b == '1' && p == '1')
                            {
                                cout << "Invalid Instruction. Both Base and PC relative addressing" << endl;
                            }
                            else
                            {
                                if ((n == '1' && i == '0' && x == '1') || (n == '0' && i == '1' && x == '1'))
                                {
                                    cout << "Invalid Instruction. x must be zero in indirect and immediate mode of addressing" << endl;
                                }
                                else
                                {
                                    if (tempop->S == "RSUB")
                                    {
                                        if (e == '0' && x == '0' && n == '0' && i == '0' && b == '0' && p == '0' && address == "00000000000000000000")
                                        {
                                            cout << "Instruction is Valid" << endl;
                                        }
                                        else
                                        {
                                            cout << "RSUB instruction must have operand 00" << endl;
                                        }
                                    }
                                    else
                                    {
                                        cout << "Instruction is Valid" << endl;
                                    }
                                }
                            }
                        }
                    }
                }
            }

            else
            {
                cout << "Invalid Instruction. Opcode in this format" << dne
            }
        }
        else
        {
            cout << "Invalid Opcode -- No format matched" << endl;
        }
    }
    return 0;
}
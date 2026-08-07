
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
using namespace std;

bool isDelimiter(char c)
{
    return c==';' || c==',' || c=='(' || c==')' ||
           c=='{' || c=='}' || c=='[' || c==']';
}

bool isInteger(string s)
{
    if(s.empty()) return false;

    int i=0;

    if(s[0]=='-' || s[0]=='+')
        i=1;

    if(i==s.size()) return false;

    for(; i<s.size(); i++)
    {
        if(!isdigit(s[i]))
            return false;
    }

    return true;
}

bool isReal(string s)
{
    if(s.empty()) return false;

    int i=0;
    bool dot=false;

    if(s[0]=='-' || s[0]=='+')
        i=1;

    if(i==s.size()) return false;

    for(; i<s.size(); i++)
    {
        if(s[i]=='.')
        {
            if(dot)
                return false;
            dot=true;
        }
        else if(!isdigit(s[i]))
        {
            return false;
        }
    }

    return dot;
}

int main()
{
    ifstream file("input.txt");

    if(!file)
    {
        cout<<"File not found!";
        return 0;
    }

    string line;

    while(getline(file,line))
    {
        string token="";

        for(int i=0;i<=line.size();i++)
        {
            char c=(i==line.size())?' ':line[i];

            if(isspace(c))
            {
                if(!token.empty())
                {
                    if(isInteger(token))
                        cout<<token<<" -> Integer"<<endl;
                    else if(isReal(token))
                        cout<<token<<" -> Real Number"<<endl;

                    token="";
                }
            }
            else if(isDelimiter(c))
            {
                if(!token.empty())
                {
                    if(isInteger(token))
                        cout<<token<<" -> Integer"<<endl;
                    else if(isReal(token))
                        cout<<token<<" -> Real Number"<<endl;

                    token="";
                }

                cout<<c<<" -> Delimiter"<<endl;
            }
            else
            {
                token+=c;
            }
        }
    }

    file.close();

    return 0;
}

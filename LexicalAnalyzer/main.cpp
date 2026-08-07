#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
using namespace std;

bool isKeyword(string s)
{
    string keywords[] = {"int","float","char","double","if","else","for","while","return","void"};

    for(string k : keywords)
    {
        if(s == k)
        return true;
    }
    return false;
}

bool isOperator(string s)
{
    string op[] = {"+","-","*","/","=","<",">","==","!=","<=",">=","%"};

    for(string o : op)
    {
        if(s == o)
            return true;
    }
    return false;
}

bool isSeparator(char c)
{
    return c==';' || c==',' || c=='(' || c==')' || c=='{' || c=='}';
}

bool isNumber(string s)
{
    if(s.empty())
        return false;

    for(char c : s)
    {
        if(!isdigit(c))
            return false;
    }
    return true;
}

bool isIdentifier(string s)
{
    if(s.empty())
        return false;

    if(!(isalpha(s[0]) || s[0]=='_'))
        return false;

    for(int i=1; i<s.size(); i++)
    {
        if(!(isalnum(s[i]) || s[i]=='_'))
            return false;
    }

    return true;
}

int main()
{
    ifstream file("input.txt");

    if(!file)
    {
        cout << "File not found!" << endl;
        return 0;
    }

    string line;

    while(getline(file, line))
    {
        string token = "";

        for(int i=0; i<=line.size(); i++)
        {
            char c = (i==line.size()) ? ' ' : line[i];

            if(isspace(c))
            {
                if(!token.empty())
                {
                    if(isKeyword(token))
                        cout << token << " = Keyword" << endl;
                    else if(isOperator(token))
                        cout << token << " = Operator" << endl;
                    else if(isNumber(token))
                        cout << token << " = Constant" << endl;
                    else if(isIdentifier(token))
                        cout << token << " = Valid Identifier" << endl;
                    else
                        cout << token << " = Invalid Identifier" << endl;

                    token = "";
                }
            }
            else if(isSeparator(c))
            {
                if(!token.empty())
                {
                    if(isKeyword(token))
                        cout << token << " = Keyword" << endl;
                    else if(isOperator(token))
                        cout << token << " = Operator" << endl;
                    else if(isNumber(token))
                        cout << token << " = Constant" << endl;
                    else if(isIdentifier(token))
                        cout << token << " = Valid Identifier" << endl;
                    else
                        cout << token << " = Invalid Identifier" << endl;

                    token = "";
                }

                cout << c << " = Separator" << endl;
            }
            else if(c=='+' || c=='-' || c=='*' || c=='/' || c=='=' || c=='<' || c=='>' || c=='%')
            {
                if(!token.empty())
                {
                    if(isKeyword(token))
                        cout << token << " = Keyword" << endl;
                    else if(isNumber(token))
                        cout << token << " = Constant" << endl;
                    else if(isIdentifier(token))
                        cout << token << " = Valid Identifier" << endl;
                    else
                        cout << token << " = Invalid Identifier" << endl;

                    token = "";
                }

                string op = "";
                op += c;
                cout << op << " = Operator" << endl;
            }
            else
            {
                token += c;
            }
        }
    }

    file.close();

    return 0;
}

#include <iostream>

using namespace std;

int main()
{
    char text[37]="hello world , hhhello everyone helll";
    char pattern[6]="hello";
    for(int i=0;i<37-5;++i)
    {
        if(text[i]==pattern[0])
        {
            bool match=true;
            for(int j=1;j<=4;++j)
            {
                if(pattern[j]!=text[i+j])
                {
                    match=false;
                    break;
                }
            }
            if(match)
                cout<<"The pattern is founded in index :"<<i<<endl;

        }
    }
    cout << "Hello world!" << endl;
    return 0;
}

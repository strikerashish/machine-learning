#include <iostream>
#include<fstream>
#include<math.h>
#include<sstream>
using namespace std;
int main()
{
    ofstream sr;
    string line;
    sr.open("item.txt");
    /*while(sr)
    {
        getline(cin,line);
        sr<<line<<endl;
    }
    sr.close();*/

        // above code reptesent to insert in file
    ifstream s;
    s.open("ex1data1.txt");
    char ch;
    int c=0;
    while(s)
    {
        s.get(ch);
        if(ch==',')
            ch='\n';
        else if(ch==' ')
            ch='\0';
        else if(ch=='\n')
            c++;
        sr<<ch;
    }
    s.close();
    sr.close();
    s.open("item.txt");
    float x[c+1][2],y[c+1][1];
    int i=0;
    int j=0;
    while(s)
    {
        getline(s,line);
        stringstream num(line);
        if(j%2==0)
        num>>x[i][1];
        else{
            num>>y[i][0];
            i++;
        }
        j++;
    }
    cout<<c<<endl<<endl;
    for(int k=0;k<c;k++)
        x[k][0]=1;

    float theta[2][1]={{0.0},{0.0}};
    int iteration=1500;
    float alpha=0.01;
    cout<<"testing the cost fns"<<endl;

    //cost computing
    float h[c+1][1];
    for(int i=0;i<c;i++)
    {
        h[i][0]=x[i][0]*theta[0][0] + x[i][1]*theta[1][0];
    }
    float squarederrors[c][1],a=0;
    for(int i=0;i<c;i++)
    {
        squarederrors[i][0]=pow((h[i][0]-y[i][0]),2);
        a=a+squarederrors[i][0];
    }
    float k=(a/(2*(c+1)));
    cout<<"compute cost="<<k<<endl;
    //for(int i=0;i<c;i++)
    //  cout<<x[i][0]<<"    "<<x[i][1]<<"   "<<y[i][0]<<"   "<<h[i][0]<<"   "<<squarederrors[i][0]<<endl;


     // gradient descent calculation
//cout<<theta[0][0]<<" "<<theta[1][0]<<endl;
        for(int z=0;z<iteration;z++)
        {
            for(int i=0;i<c;i++)
            {
                h[i][0]=x[i][0]*theta[0][0] + x[i][1]*theta[1][0];
                //cout<<h[i][0]<<"    "<<x[i][0]<<"   "<<theta[0][0]<<endl;
            }

            float q[2];
            for(int i=0;i<2;i++)
            {
                q[i]=0;
                for(int j=0;j<c;j++)
                {
                    q[i]+=x[j][i]*(h[j][0]-y[j][0]);
                    //cout<<q[i]<<"   "<<x[j][i]<<"   "<<y[j][0]<<endl;
                }
            }
            for(int i=0;i<2;i++)
            {
                theta[i][0]=theta[i][0]-(alpha*q[i]/c);
            }
        }
        cout<<theta[0][0]<<" "<<theta[1][0]<<endl;
     cout<<"prediction cost"<<10000*((1*theta[0][0])+(7*theta[1][0]));
}

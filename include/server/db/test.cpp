#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<vector>
#include<iostream>
#include<stack>
using namespace std;
int to_int(string s)
{
    int n=0;
    for(int i=0;i<s.size();i++)
    {
        n=n*10+(s[i]-'0');
    }
    return n;
}
int main()
{
    vector<string>S_num;
    string s;
    cin>>s;
    string num="";
    for(int i=0;i<s.size();i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            num+=s[i];
        }
        else
        {
            if(num!="")S_num.push_back(num);
            num="";
            num+=s[i];
            S_num.push_back(num);
            num="";
        }
    }
    if(num!="")S_num.push_back(num);
    stack<string>fuhao;
    stack<int>shuzhi;
    //int flog=0;
    for(int i=0;i<S_num.size();i++)
    {
        //if(flog)continue;
        if(S_num[i]=="(")
        {
            fuhao.push(S_num[i]);
        }
        else if(S_num[i]=="+"||S_num[i]=="-")
        {
            fuhao.push(S_num[i]);
        }
        else if(S_num[i]=="*"||S_num[i]=="/")
        {
            if(S_num[i+1][0]>='0'&&S_num[i+1][0]<='9')
            {
                int a=to_int(S_num[i+1]);
                int b=shuzhi.top();
                shuzhi.pop();
               // if(S_num[i]=="*")
                shuzhi.push(a*b);
                /*
                else
                {
                    if(a==0){
                        flog=1;
                        break;
                    }
                    else{
                        shuzhi.push(a/b);
                    }
                }
                */
                i++;

            }
            else{
                fuhao.push(S_num[i]);
            }

        }
        else if(S_num[i]==")")
        {
            int ans=0;
            while(fuhao.top()!="(")
            {
                int a=0;
                if(!shuzhi.empty())a=shuzhi.top();
                shuzhi.pop();
                int b=0;
                if(!shuzhi.empty())b=shuzhi.top();
                shuzhi.pop();
                string s1=fuhao.top();
                fuhao.pop();
                if(s1=="+")
                {
                    ans=a+b;
                }
                else
                {
                    ans=b-a;
                }
                shuzhi.push(ans);
            }
            fuhao.pop();
            
            while(!fuhao.empty()&&fuhao.top()=="*")
            {
                int a=0;
                if(!shuzhi.empty())a=shuzhi.top();
                shuzhi.pop();
                int b=0;
                if(!shuzhi.empty())b=shuzhi.top();
                shuzhi.pop();
                fuhao.pop();
                shuzhi.push(a*b);
                
            }
        }
        else
        {
            shuzhi.push(to_int(S_num[i]));
        }
    }
    int res=0;
    while(!fuhao.empty())
    {
        int a=0;
        a=shuzhi.top();
        shuzhi.pop();
        int b=0;
        b=shuzhi.top();
        shuzhi.pop();
        string s1=fuhao.top();
        fuhao.pop();
        if(s1=="+")
        {
            res=a+b;
        }
        else
        {
            res=b-a;
        }
        shuzhi.push(res);
    }
    //if(flog)cout<<"eror"<<endl;
    //else
    cout<<shuzhi.top()<<endl;
    return 0;
}
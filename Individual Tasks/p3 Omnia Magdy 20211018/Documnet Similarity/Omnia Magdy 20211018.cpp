#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class StringSet
{
public :
    StringSet () {len=0;} ;
    StringSet (string s)
    {
        len = 0 ;
        string suffix = s.substr(s.size()-4,4);
        if (suffix==".txt")
        {
            fstream f ;
            f.open ( s , ios::in ) ;
            string initia , fina ;
            while (!f.eof())
            {
                fina="";
                f>>initia;
                for (int i=0 ; i<initia.size(); i++)
                {
                    if ( (initia[i] <= 'z' && initia[i] >= 'a' ) || (initia[i]<= 'Z' && initia[i] >= 'A' )  )
                    {
                        fina+=towlower(initia[i]);
                    }
                }
                content.push_back(fina);
                counter[fina]++;
                len ++;
            }
        }
        else
        {
            s+=' ';
            string initia="" , fina="" ;
            for (int i =0 ; i<s.size() ; i++)
            {
                if(s[i]==' ')
                {
                    if (initia.size())
                    {
                        for (int i=0 ; i<initia.size(); i++)
                        {
                            if ( (initia[i] <= 'z' && initia[i] >= 'a' ) || (initia[i]<= 'Z' && initia[i] >= 'A' )  )
                            {
                                fina+=towlower(initia[i]);
                            }
                        }
                        content.push_back(fina);
                        counter[fina]++;
                        len++;
                        initia="";
                        fina="";
                    }
                    else
                    {
                        continue ;
                    }
                }
                else
                {
                    initia+=s[i];
                }

            }
        }
    }
    void display ()
    {
        for (int i=0 ; i<len ; i++)
        {
            cout<<content[i]<<endl;
        }
    }
    void length ()
    {
        cout<<len<<endl;
    }
    void add (string New )
    {
        content.push_back(New);
        counter[New]++;
        len++;
    }
    void del (string des )
    {
        if (counter[des])
        {
            auto location  = find(content.begin(),content.end(),des);
            content.erase(location);
            counter[des]--;
            len--;
        }
        else
        {
            cout<<"no such string in this set called "<<des<<"\n";
        }
    }
    void clr ()
    {
        len = 0 ;
        content.clear();
        counter.clear();
    }
    StringSet operator + (StringSet r)
    {
        StringSet result ;
        result.len = len + r.len ;
        for (int i=0 ; i<len ; i++)
        {
            result.content.push_back(content[i]);
            if (!result.counter[content[i]])
            {
                result.counter[ content[i] ]+= counter[ content[i] ];
            }
        }
        for (int i=0 ; i<r.len ; i++)
        {
            result.content.push_back(r.content[i]);
            if (!result.counter[r.content[i]])
            {
                result.counter[r.content[i] ]+= r.counter[ r.content[i] ];
            }
        }
        return result ;
    }
    StringSet operator * (StringSet r)
    {
        StringSet result ;
        for (int i=0 ; i<len ; i++)
        {
            if (!result.counter[content[i]])
            {
                result.counter[ content[i] ] = min ( counter[ content[i] ]  , (r.counter[ content[i] ] ?  r.counter[ content[i] ] : 0)  ) ;
                result.len+=result.counter[ content[i] ];
                for (int j =0 ; j<result.counter[content [i] ] ; j++)
                {
                    result.content.push_back(content[i]);
                }
            }
        }
        for (int i=0 ; i<r.len ; i++)
        {
            if (!result.counter[r.content[i]])
            {
                result.counter[r.content[i] ]= min (r.counter[ r.content[i] ],(counter[ r.content[i] ] ?  counter[ r.content[i] ] : 0)) ;
                result.len+=result.counter[r.content[i] ];
                for (int j =0 ; j<result.counter[r.content [i] ] ; j++)
                {
                    result.content.push_back(r.content[i]);
                }
            }
        }
        return result ;
    }
    double similar (StringSet a , StringSet b)
    {
        StringSet intersection ;
        intersection = a * b ;
        int common = intersection.len ;
        return ( (double)common / ( sqrt( a.len ) *  sqrt( b.len  )  ) );
    }
private :
    vector <string> content ;
    map  < string , int  > counter ;
    int len ;
};

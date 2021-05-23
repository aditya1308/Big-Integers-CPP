#include<bits/stdc++.h>
using namespace std;
//---------------------maxlenadditionITION-------------------------//

/**
 * <b>add()</b> takes two arguments and returns a string value.
 * @param s a string argument.
 * @param t a string argument.
 * \code{.c}
       string s="999999999999";
       string t="1";
       string ans=maxlenaddition(s,t);
       cout<<ans;
   \endcode
 * <b>Output</b> is **1000000000000**.
 */
string maxlenaddition(string s,string t)
{
	if((s[0]=='-'&&(t[0]>='0'&&t[0]<='9'))||((s[0]>='0'&&s[0]<='9')&&t[0]=='-'))
	{
		string a,b;
		for(int i=0;i<s.length();i++)
		{
			if(s[i]!='-')
			a.push_back(s[i]);
		}
		for(int i=0;i<t.length();i++)
		{
			if(t[i]!='-')
			b.push_back(t[i]);
		}
		string str = "";
	    int alen=a.length(), blen=b.length();
	 
	    reverse(a.begin(),a.end());
	    reverse(b.begin(),b.end());
 		int brrw=0;
	    for(int i=0;i<blen;i++) 
		{
	        int maxlensub=((a[i]-'0')-(b[i]-'0')-brrw);
	 
	        if (maxlensub<0)
			{
	            maxlensub=maxlensub+10;
	            brrw=1;
	        }
	        else
	        brrw=0;
	 
	        str.push_back(maxlensub+'0');
	    }
	    for (int i=blen;i<alen;i++)
		{
	        int maxlensub=((a[i]-'0')-brrw);
	 
	        if(maxlensub<0) 
			{
	            maxlensub=maxlensub+10;
	            brrw=1;
	        }
	        else
	        brrw=0;
	        str.push_back(maxlensub+'0');
    	}
 		reverse(str.begin(),str.end());
 		string::iterator itr;
	    itr=str.begin();
	    while(*itr=='0')
	    str.erase(itr);
		return str;
	}
	else
	{
		int val;
		string anss;
		int slen=s.length();
		int tlen=t.length();
		int a[slen];
		int b[tlen];
		
		for(int i=0;i<slen;i++)
		{
			val=s[i]-'0';
			a[i]=val;
		}
		for(int i=0;i<tlen;i++)
		{
			val=t[i]-'0';
			b[i]=val;
		}
	
		int n=max(slen,tlen);
		int i=slen-1,j=tlen-1,k=n;
		int sum[n+1];
		int ss=0,carry=0;
		
		while (j>=0)
		{
	        ss=a[i]+b[j]+carry;
	        sum[k]=(ss%10);
	 
	        carry=ss/10;
	 
	        k--;
	        i--;
	        j--;
	    }
	    while (i>=0)
		{
	        ss=a[i]+carry;
	        sum[k]=(ss%10);
	        carry=ss/10;
	 
	        i--;
	        k--;
	    }
	 
	    int ans=0;
	    
	    if(carry)
	    {
	    	ans=10;
	    	sum[0]=1;
	    	for(int i=0;i<=n;i++)
	    	anss.push_back(sum[i]+'0');
		}
	    else	
	    for(int i=1;i<=n;i++)
	    anss.push_back(sum[i]+'0');
	    
	    return anss;	
	}
}
//-------------------------------Subtract-----------------------------------//

/**
 * <b>sub()</b> takes two arguments and returns a string value.
 * @param a a string argument.
 * @param b a string argument.
 * \code{.c}
       string s="999999999999";
       string t="100000000000";
       string ans=maxlensub(s,t);
       cout<<ans;
   \endcode
 * <b>Output</b> is **899999999999**.
 */
string maxlensub(string a,string b)
{   
    if(a[0]=='-'&&b[0]=='-')
    {
    	int val;
		string anss="-";
		int slen=a.length();
		int tlen=b.length();
		int arr[slen];
		int brr[tlen];
		int it=0,jt=0;
		for(int i=1;i<=slen;i++)
		{
			val=a[i]-'0';
			arr[it++]=val;
		}
		for(int i=1;i<=tlen;i++)
		{
			val=b[i]-'0';
			brr[jt++]=val;
		}
	
		int n=max(slen,tlen);
		int i=slen-2,j=tlen-2,k=n-1;
		int sum[n+1];
		int ss=0,carry=0;
		
		while (j>=0)
		{
	        ss=arr[i]+brr[j]+carry;
	        sum[k]=(ss%10);
	 
	        carry=ss/10;
	 
	        k--;
	        i--;
	        j--;
	    }
	    while (i>=0)
		{
	        ss=arr[i]+carry;
	        sum[k]=(ss%10);
	        carry=ss/10;
	 
	        i--;
	        k--;
	    }
	 
	    int ans=0;
	    
	    if(carry)
	    {
	    	ans=10;
	    	sum[0]=1;
	    	for(int i=0;i<n;i++)
	    	anss.push_back(sum[i]+'0');
		}
	    else	
	    for(int i=1;i<n;i++)
	    anss.push_back(sum[i]+'0');
	    
	    string::iterator itr;
	    itr=anss.begin();
	    while(*itr=='0')
	    anss.erase(itr);
	    
	    return anss;
	}
 	else
 	{
 		string str = "";
	    int alen=a.length(), blen=b.length();
	 
	    reverse(a.begin(),a.end());
	    reverse(b.begin(),b.end());
 		int brrw=0;
	    for(int i=0;i<blen;i++) 
		{
	        int maxlensub=((a[i]-'0')-(b[i]-'0')-brrw);
	 
	        if (maxlensub<0)
			{
	            maxlensub=maxlensub+10;
	            brrw=1;
	        }
	        else
	        brrw=0;
	 
	        str.push_back(maxlensub+'0');
	    }
	    for (int i=blen;i<alen;i++)
		{
	        int maxlensub=((a[i]-'0')-brrw);
	 
	        if(maxlensub<0) 
			{
	            maxlensub=maxlensub+10;
	            brrw=1;
	        }
	        else
	        brrw=0;
	        str.push_back(maxlensub+'0');
    	}
 		reverse(str.begin(),str.end());
 		string::iterator itr;
	    itr=str.begin();
	    while(*itr=='0')
	    str.erase(itr);
		return str;
	}
    
}

//------------------------------FACTORIAL------------------------------//

/**
 * <b>fact()</b> takes only one argument and returns a string value.
 * @param n an integer argument.
 * \code{.c}
       long long n=30;
       string ans=maxlenfact(n);
       cout<<ans;
   \endcode
 * <b>Output</b> is **265252859812191058636308480000000**.
 */
string fact(long long n)
{
	if(n==0)
	return "1";
	int j,carry;
    int arr[2000];
    arr[0]=1;
    j=0;
    string factans;
    for(;n>=2;n--)
    {
        carry=0;
        for(int i=0;i<=j;i++)
        {
            carry=(arr[i]*n)+carry;
            arr[i]=carry%10;
            carry=carry/10;
        }
        while(carry)
        {
            arr[++j]=carry%10;
            carry=carry/10;
        }
    }
    for(int i=j;i>=0;i--)
	factans.push_back(arr[i]+'0');

	return factans;
}
//-----------------Power--------------------//

/**
 * <b>bigpow()</b> takes two arguments as integers and returns a string value.
 * @param b an integer argument which is the base.
 * @param p an integer argument which is the power of that base
 * \code{.c}
       long long b="100000";
       long long p="2";
       string ans=maxlenpow(b,p);
       cout<<ans;
   \endcode
 * <b>Output</b> is **10000000000**.
 */
string bigpow(long long b,long long p)
{
	long long x=b;
	long long ind=0;
	long long mul[10001];
	if(p==0)
	return "1";
	string powans;
	while(x!=0)
	{
		mul[ind++]=x%10;
		x=x/10;
	}
	long long carry=0;
	for(int i=2;i<=p;i++)
	{
		for(int j=0;j<ind;j++)
		{
			int	product=mul[j]*b+carry;
			mul[j]=product%10;
			carry=product/10;
		}
		while(carry)
		{
			mul[ind]=carry%10;
			carry/=10;
			ind++;
		}	
	}
	for(int i=ind-1;i>=0;i--)
	powans.push_back(mul[i]+'0');
	
	return powans;
//	cout<<mul[i];
}

//--------------Multiplication-------------------//

/**
 * <b>multiply()</b> takes two arguments as string and returns a string value.
 * @param a a string argument.
 * @param b a string argument.
 * \code{.c}
       string a="1623908;
       string b="1678";
       string ans=maxlenmul(a,b);
       cout<<ans;
   \endcode
 * <b>Output</b> is **2724917624**.
 */
string maxlenmul(string a,string b)
{
	string ss;
	int c = 0;
	for(int i=b.length()-1;i>=0;i--)
	{
		int carry=0;
		string s;
		for(int j=a.length()-1;j>=0;j--)
		{
			int n=((a[j]-'0')*(b[i]-'0'))+carry;
			s.push_back((n%10)+'0');
			carry=n/10;
		}
		while(carry)
		{
			s.push_back((carry % 10)+'0');
			carry/=10;
		}
		c++;
		if (c>1) 
		{
			for(int m=0;m<c-1;m++)
			s.insert(s.begin(), '0');
			carry = 0;
			for (int i =0,j=0;i<s.length();i++,j++)
			{
				if (j<ss.length())
				{
					int n=(ss[j]-'0')+(s[i]-'0')+carry;
					ss[j]=(n%10)+'0';
					carry=n/10;
				}
				else
				{
					int n=(s[i]-'0')+carry;
					ss.push_back((n%10)+'0');
					carry=n/10;
				}
			}
			while(carry) 
			{
				ss.push_back((carry%10)+'0');
				carry/=10;
			}
		}
		if (c==1) 
		{
			ss=s;
		}
	}
	reverse(ss.begin(), ss.end());
	return ss;
}

//----------------------Utility Function-----------------//
string sub(string a,string b)
{
	string ns="";
	string subans="-";
	string str="";
	string ps="";
	int alen=a.length(),blen=b.length();
	
	if(a[0]=='-'&&b[0]=='-')
	{
		for(int i=0;i<alen;i++)
		{
			if(a[i]!='-')
			ns.push_back(a[i]);
		}
		for(int i=0;i<blen;i++)
		{
			if(b[i]!='-')
			ps.push_back(b[i]);
		}
		if(alen>blen)
		{
			str=maxlensub(ns,ps);
			subans=subans+str;
			return subans;
		}
		else
		if(alen<blen)
		{
			str=maxlensub(ps,ns);
			return str;
		}
		else
		if(alen==blen)
		{
			if(ns>ps)
			{
				str=maxlensub(ns,ps);
				subans=subans+str;
				return subans;
			}
			else
			if(ns<ps)
			{
				str=maxlensub(ps,ns);
				return str;
			}
			else
			return "0";
		}
	}
	else
	if(a[0]=='-'&&(b[0]>='0'&&b[0]<='9'))
	{
		for(int i=0;i<a.length();i++)
		{
			if(a[i]!='-')
			ns.push_back(a[i]);
		}
		if(ns.length()>b.length())
		{
			str=maxlensub(ns,b);
			subans=subans+str;
			return subans;
		}
		else
		if(ns.length()<blen)
		return maxlensub(b,ns);
		else
		if(ns.length()==blen)
		{
			if(ns>b)
			{
				str=maxlensub(ns,b);
				subans=subans+str;
				return subans;
			}
			else
			if(ns<b)
			return maxlensub(b,ns);
			else
			return "0";
		}
	}
	else
	if(b[0]=='-'&&(a[0]>='0'&&a[0]<='9'))
	{
		for(int i=0;i<b.length();i++)
		{
			if(b[i]!='-')
			ns.push_back(b[i]);		
		}
		if(ns.length()>a.length())
		{
			cout<<ns.length()<<"  "<<a.length()<<endl;
			str=maxlensub(ns,a);
			subans=subans+str;
			return subans;
		}
		else
		if(ns.length()<alen)
		{
			return maxlensub(a,ns);
		}
		else
		if(ns.length()==alen)
		{
			if(ns>a)
			{
				str=maxlensub(ns,a);
				subans=subans+str;
				return subans;
			}
			else
			if(ns<a)
			{
				return maxlensub(a,ns);
			}
			else
			return "0";
		}
	}
	else
	{
		if(alen>blen)
		return maxlensub(a,b);
		else
		if(alen<blen)
		return maxlensub(b,a);
		else
		if(alen==blen)
		{
			if(a<b)
			{
				subans=subans+maxlensub(b,a);
				return subans;
			}
			if(a>b)
			return maxlensub(a,b);
			else
			return "0";
		}
	}
}
string add(string a,string b)
{
	string ans;
	int alen=a.length(),blen=b.length();
	string ns="";
	string ps="";
	string minus="-";
	if(a[0]=='-'&&(b[0]>='0'&&b[0]<='9'))
	{
		for(int i=0;i<alen;i++)
		{
			if(a[i]!='-')
			ns.push_back(a[i]);
		}
		if(ns.length()>blen)
		{
			minus=minus+maxlenaddition(a,b);
			return minus;
		}
		else
		if(ns.length()<blen)
		{
			return maxlenaddition(b,a);
		}
		else
		if(ns.length()==blen)
		{
			if(ns>b)
			{
				minus=minus+maxlenaddition(a,b);
				return minus;
			}
			else
			if(ns<b)
			return maxlenaddition(a,b);
			else
			return "0";
		}	
	}
	else
	if((a[0]>='0'&&a[0]<='9')&&b[0]=='-')
	{
		for(int i=0;i<blen;i++)
		{
			if(b[i]!='-')
			ns.push_back(b[i]);
		}
		if(ns.length()>alen)
		{
			minus=minus+maxlenaddition(b,a);
			return minus;
		}
		else
		if(ns.length()<alen)
		{
			return maxlenaddition(a,b);
		}
		else
		if(alen==ns.length())
		{
			if(ns>a)
			{
				minus=minus+maxlenaddition(b,a);
				return minus;
			}
			else
			if(ns<a)
			return maxlenaddition(b,a);
			else
			return "0";
		}		
	}
	else
	if(a[0]=='-'&&b[0]=='-')
	{
		for(int i=0;i<alen;i++)
		{
			if(a[i]!='-')
			ns.push_back(a[i]);
		}
		for(int i=0;i<blen;i++)
		{
			if(b[i]!='-')
			ps.push_back(b[i]);
		}
		if(alen>blen)
		{
			minus=minus+maxlenaddition(ns,ps);
			return minus;
		}
		else
		if(alen<blen)
		{
			minus=minus+maxlenaddition(ps,ns);
			return minus;
		}
		else
		if(alen==blen)
		{
			if(ns>=ps)
			{
				minus=minus+maxlenaddition(ns,ps);
				return minus;
			}
			else
			{
				minus=minus+maxlenaddition(ps,ns);
				return minus;
			}
		}
	}
	else
	if(a[0]!='-'&&b[0]!='-')
	{
		if(alen>=blen)
		return maxlenaddition(a,b);
		else
		return maxlenaddition(b,a);
	}	
}
string multiply(string a,string b)
{
	int al=a.length(),bl=b.length();
	string str="-";
	string mulans="";
	string aa,bb;
	if(a[0]=='-'&&b[0]=='-')
	{
		for(int i=0;i<al;i++)
		{
			if(a[i]!='-')
			aa.push_back(a[i]);
		}
		for(int i=0;i<bl;i++)
		{
			if(b[i]!='-')
			bb.push_back(b[i]);
		}
		if(al>=bl)
		{
			mulans=maxlenmul(aa,bb);
			return mulans;
		}
		else
		{
			mulans=maxlenmul(bb,aa);
			return mulans;
		}
	}
	if(((a[0]=='-')&&(b[0]>='0'&&b[0]<='9'))||((b[0]=='-')&&(a[0]>='0'&&a[0]<='9')))
	{
		for(int i=0;i<al;i++)
		{
			if(a[i]!='-')
			aa.push_back(a[i]);
		}
		for(int i=0;i<bl;i++)
		{
			if(b[i]!='-')
			bb.push_back(b[i]);
		}
		if(al>=bl)
		{
			mulans=maxlenmul(aa,bb);
			str=str+mulans;
			return str;
		}
		else
		{
			mulans=maxlenmul(bb,aa);
			str=str+mulans;
			return str;
		}
	}
	else
	{
		mulans=maxlenmul(a,b);
		return mulans;
	}
}


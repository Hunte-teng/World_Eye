#include<iostream.h>
#include<stdlib.h>
#define maxsize 32
typedef struct
{
	char ch[maxsize];
	int curlen;
} seqstring;
seqstring *S,*T;
int INDEX(seqstring *S,seqstring *T)
{
	int i=0,j=0;
	while((i<S->curlen)&&(j<T->curlen))
		if(S->ch[i]==T->ch[j])
		{
			i++;
			j++;
		}
		else
		{
			i=i-j+1;
			j=0;
		}
	if(j==T->curlen)
		return(i-T->curlen);
	else
		return(-1);
}
void main()
{
	S=(seqstring *)malloc(sizeof(seqstring));
	T=(seqstring *)malloc(sizeof(seqstring));
	S->curlen=0;
    T->curlen=0;
	int i=0,j=0;
	cout<<"ÇëÊäÈë×Ö·û´®SÒÔ¡°#¡±½áÊø£º";
	cin>>S->ch[i];
	while(S->ch[i]!='#')
	{
		S->curlen++;
		cin>>S->ch[++i];
	}
	cout<<"ÇëÊäÈë×Ö·û´®TÒÔ¡°#¡±½áÊø£º";
	cin>>T->ch[j];
	while(T->ch[j]!='#')
	{
		T->curlen++;
		cin>>T->ch[++j];
	}
    if(INDEX(S,T)==-1)
		cout<<"Æ¥ÅäÊ§°Ü";
	else
		cout<<"Æ¥Åä³É¹¦";
}
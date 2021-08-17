#if defined _k_string
	#endinput
#endif
#define _k_string

#define MAX_STRING_LENGHT 512

//*****************************************************************************
stock void FillChar(char[] buffer, int maxlength,const char Filler,int CharCount/*,Bool:align=false*/){	
//*****************************************************************************
int maxChar;
maxChar=min(maxlength,CharCount);
for (int i=0;i!=maxChar;i++)buffer[i]=Filler;	
}
//*****************************************************************************
stock void FillString(char[] buffer, int maxlength,const char[] Filler,int CharCount/*,Bool:align=false*/){	
//*****************************************************************************
}
//*****************************************************************************
stock int CutWord(const char[] source, const char[] split,int Number,char[] Word,int WordLen){	
//******************************************************************************
if (WordLen==0) return -1;
int StringLen=strlen(source);
int i=0;
int w=0; //Word counter
int StartChar;
Word[0]=0;
// Skip leading chars
while (i<StringLen)
	{
	while (FindCharInString(split, source[i], false)!=-1) 
		{
		i++;
		if (i==StringLen)return 0;		
		}	
	w++;
	if (w==Number) {StartChar=i;}
	// Skip word
	while (FindCharInString(split, source[i], false)==-1)
		{		
		i++;
		if (i==StringLen){break;}
		}
	if (w==Number) 
		{
		int j=0;
		while (StartChar<i)
			{
			Word[j]=source[StartChar];
			j++;
			StartChar++;
			}
		Word[j]=0;	
		j--;
		return (j);
		}
	}	

return 0;
}
//*****************************************************************************


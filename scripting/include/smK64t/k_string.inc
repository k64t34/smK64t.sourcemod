#if defined _k_string
	#endinput
#endif
#define _k_string

#define MAX_STRING_LENGHT 512

//*****************************************************************************
stock Fill(String:buffer[], maxlength,const String:Char[1],count/*,Bool:align=false*/){	
//*****************************************************************************
new maxChar;
maxChar=min(maxlength,count);
for (new i=0;i!=maxChar;i++)
	{
	buffer[i]=Char[0];
	}
}
//*****************************************************************************
stock CutWord(const String:source[], const String:split[],Number,String:Word[], WordLen){	
//******************************************************************************
if (WordLen==0) return -1;
new StringLen=strlen(source);
new i=0;
new w=0; //Word counter
new StartChar;
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
		new j=0;
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


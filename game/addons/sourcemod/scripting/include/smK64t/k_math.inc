#if defined _k_math
 #endinput
#endif
#define _k_math
#define min(%1,%2) ((%1) < (%2) ? (%1) : (%2))
#endinput
//*****************************************************************************
stock void GetRandomList(const source_size, list[], const list_size){	
//******************************************************************************
new i,j;
for (i=0; i<list_size; i++)
	{
	list[i]=GetRandomInt(0,source_size-1);
	for (j=i-1; j>=0; j--)
		if (list[i]==list[j])i--;
	}	
}
//*****************************************************************************
stock void SortArray(a[],const a_size){	
//******************************************************************************
new i,j,swap;
for (i=0;i<a_size;i++)
	{	
	if (i<a_size-1)  //pool down
		{
		j=i+1;		
		while (a[j-1]>a[j])
			{		
			swap=a[j-1];
			a[j-1]=a[j];
			a[j]=swap;
			j++;
			if (j==a_size) break;
			}			
		}
	if (i>0)	//pool up
		{
		j=i;		
		while (a[j-1]>a[j])
			{		
			swap=a[j-1];
			a[j-1]=a[j];
			a[j]=swap;
			j--;
			if (j==0) break;
			}			
		
		}
	}	
}
//*****************************************************************************
// Find first max  element in integer  1 dimension array
// Return index  of element
stock GetMaxIntegerArray(const a[],const a_size){
//******************************************************************************
decl i,index,MaxValue;
index=0;
MaxValue=a[0];
for (i=1;i!=a_size;i++)
	{	
	if (a[i]>MaxValue)
		{
		index=i;
		MaxValue=a[i];
		}
	}	
return index;
}
//*****************************************************************************
stock GetMinIntegerArray(const a[],const a_size){
//******************************************************************************
decl i,index,MinValue;
index=0;
MinValue=a[0];
for (i=1;i!=a_size;i++)
	{	
	if (a[i]<MinValue)
		{
		index=i;
		MinValue=a[i];
		}
	}	
return index;
}


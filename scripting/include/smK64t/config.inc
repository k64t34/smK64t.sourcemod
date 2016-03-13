#if defined _k_config
	#endinput
#endif
#define _k_config

new String:cfgFileName[]="cfg\\sourcemod\\kom64t.cfg";
new Handle:kv = INVALID_HANDLE;
//*****************************************************************************	
CFGFileExist(client){
//*****************************************************************************	
new bool:result=FileExists(cfgFileName);
if (result)	
	{
	kv=CreateKeyValues("Profile");
	if (kv!=INVALID_HANDLE)
		{
		if (!FileToKeyValues(kv, cfgFileName)) 
			{
			ReplyToCommand(client,"Error reading keys from %s",cfgFileName);
			result=false;	
			}
			
		}
	else
		{
		result=false;	
		ReplyToCommand(client,"CreateKeyValues FAILED");			
		}	
	}
else	
	{
	result=false;	
	ReplyToCommand(client,"File %s not found",cfgFileName);		
	}
return (result);	
}

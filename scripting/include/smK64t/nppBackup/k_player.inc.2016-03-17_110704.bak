#if defined _k_players
 #endinput
#endif
#define _k_players 1
//*****************************************************************************
stock CountOfRealPlayers(){
//*****************************************************************************
new result=0;
new i_max=GetMaxClients();
for (new i = 1; i<=i_max ; i++)	
	if (IsClientConnected(i) && IsClientInGame(i) && !IsFakeClient(i)) result++;
return result;
}
//*****************************************************************************
stock SetClientHealth(client, amount){
//*****************************************************************************
    new HPOffs = FindDataMapOffs(client,"m_iHealth");
    SetEntData(client,HPOffs,amount,true);
}
//*****************************************************************************
stock SetClientFrag(client, amount){
//*****************************************************************************
SetEntProp(client, Prop_Data, "m_iFrags", amount,4);	
}
//*****************************************************************************
stock SetClientDeaths(client, amount){
//*****************************************************************************
SetEntProp(client, Prop_Data, "m_iDeaths", amount, 4);
}

//*****************************************************************************
stock IsValidClient (client){
//*****************************************************************************
if (client == 0)
	return false;    
if (!IsClientConnected(client))
	return false;    
if (!IsClientInGame(client))
	return false;                
return true;
}  
//*****************************************************************************
stock IsValidAliveClient (client){
//*****************************************************************************
    if (client == 0)
        return false;    
    if (!IsClientConnected(client))
        return false;    
    if (!IsClientInGame(client))
        return false;            
    if (IsClientObserver(client))
        return false;    
    return true;
}  
//*****************************************************************************
stock IsValidAliveOrDeadClient(client){
//*****************************************************************************
    if (client == 0)
        return false;    
    if (!IsClientConnected(client))
        return false;    
    if (!IsClientInGame(client))
        return false;                
    return true;
}  


//*****************************************************************************
stock GetHour(Ctime, ...){
//*****************************************************************************
decl String:Hour[3];
if (true)
	Ctime=GetTime();
FormatTime(Hour, 3, "%H",Ctime);
return StringToInt(Hour);
}
//*****************************************************************************
new g_iAccount = -1; // Add folow code to OnPluginStart
/*
g_iAccount = FindSendPropOffs("CCSPlayer", "m_iAccount");
if (g_iAccount == -1)LogError("Error - Unable to get offset for CCSPlayer::m_iAccount");
*/
stock SetMoney(client, amount)
//*****************************************************************************
{
if (g_iAccount != -1)
{
	SetEntData(client, g_iAccount, amount);
}	
}
#if defined _k_players
 #endinput
#endif
#define _k_players 1

#if !defined TEAM_SPECTATOR
#define TEAM_SPECTATOR 1
#endif
//*****************************************************************************
stock bool IsValidClient (int client){
//*****************************************************************************
if (client < 1)					return false;    
//if (client > MAX_PLAYERS)
if (client > MaxClients)	return false; 
if (!IsClientConnected(client))	return false;    
if (!IsClientInGame(client))	return false;    
//if (!IsPlayerAlive(client))		return false;    
if (GetClientTeam(client) <= TEAM_SPECTATOR)return false;    
return true;
}  
//*****************************************************************************
stock bool IsValidAliveClient (int client){
//*****************************************************************************
if (!IsValidClient(client)) return false;
/*if (client == 0)
	return false;    
if (!IsClientConnected(client))
	return false;    
if (!IsClientInGame(client))
	return false;            */
if (IsClientObserver(client)) //Note: a dead player is considered an observer; it does not need to be in the spectators team (at least for CSS).
	return false;    
return true;
}  
//*****************************************************************************
stock void SetClientHealth(int client, int Health){
//*****************************************************************************
SetEntityHealth(client,Health);
//int HPOffs = FindDataMapOffs(client,"m_iHealth");
//FindDataMapInfo
//int FindDataMapInfo(int entity, const char[] prop, PropFieldType& type, int& num_bits, int& local_offset)
//SetEntData(client,HPOffs,Health,true);
}

//*****************************************************************************
int g_iAccount = -1; // Add folow code to OnPluginStart
/*
g_iAccount = FindSendPropOffs("CCSPlayer", "m_iAccount");
if (g_iAccount == -1)LogError("Error - Unable to get offset for CCSPlayer::m_iAccount");
*/
//*****************************************************************************
stock void SetClientFrag(int client, int amount){SetEntProp(client, Prop_Data, "m_iFrags", amount,4);}
//*****************************************************************************
stock void SetClientDeaths(int client, int amount){SetEntProp(client, Prop_Data, "m_iDeaths", amount, 4);}
//*****************************************************************************
stock void SetMoney(int client, int amount){if (g_iAccount != -1)SetEntData(client, g_iAccount, amount);}
//*****************************************************************************


#endinput
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -





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


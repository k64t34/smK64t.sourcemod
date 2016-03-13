#if defined _k_k64t
	#endinput
#endif
#define _k_k64t
#pragma semicolon 1
#include <sourcemod>
#include <sdktools>
//#include <cstrike>
#include <clientprefs>

//smlib
#include <smlib.inc>
#include <color.inc> 

//myIncludes
#include "k_math.inc"
#include "k_string.inc"
#include "player.k64t.inc"
#include "k_file.inc" 
#include "k_cstrike.inc"


#define MAX_PLAYERS 33
#define MAX_CLIENT_NAME 32

#if defined DEBUG 	
	#if defined PLUGIN_VERSION
		#undef PLUGIN_VERSION
	#endif		
#endif
#include "datetimecomp.inc"
#if defined DEBUG 
	new gPLUGIN_NAME[]=PLUGIN_NAME;
	#include "Debug.k64t.inc"
#endif

stock SetClientScreenFade( index, red, green, blue, alpha, delay )
{
	new duration = delay * 1000;
	
	new  Handle:MsgFade = StartMessageOne( "Fade", index );
	BfWriteShort( MsgFade, 500 );
	BfWriteShort( MsgFade, duration );
	BfWriteShort( MsgFade, FFADE_IN );
	BfWriteByte( MsgFade, red );
	BfWriteByte( MsgFade, green );
	BfWriteByte( MsgFade, blue );	
	BfWriteByte( MsgFade, alpha );
	EndMessage();
}
stock GetEntityVelocity(ent,Float:velocity[3]) 
{
    // m_vecVelocity
    return GetEntPropVector(ent,Prop_Data,"m_vecVelocity",velocity);
}
//*****************************************************************************
Explode_Player(client){
//*****************************************************************************
if (!IsValidAliveClient(client) ) return;
new ExplosionIndex = CreateEntityByName("env_explosion"); 
if (ExplosionIndex != -1) 
	{ 
	//DispatchKeyValue(ExplosionIndex,"classname",ReplaceNade); 

	SetEntProp(ExplosionIndex, Prop_Data, "m_spawnflags", 6146); 
	SetEntProp(ExplosionIndex, Prop_Data, "m_iMagnitude", 512); 
	SetEntProp(ExplosionIndex, Prop_Data, "m_iRadiusOverride", 100); 

	DispatchSpawn(ExplosionIndex); 
	ActivateEntity(ExplosionIndex); 
	
	new Float:ClientOrigin[3];
	//ClientOrigin[0]+=100;
	//ClientOrigin[1]+=100;
	ClientOrigin[2]+=100;
	GetClientAbsOrigin(client, ClientOrigin);		
	TeleportEntity(ExplosionIndex, ClientOrigin, NULL_VECTOR, NULL_VECTOR); 
	//SetEntPropEnt(ExplosionIndex, Prop_Send, "m_hOwnerEntity", MissileOwner); 
	//SetEntProp(ExplosionIndex, Prop_Send, "m_iTeamNum", MissileOwnerTeam);
	AcceptEntityInput(ExplosionIndex, "Explode");
	DispatchKeyValue(ExplosionIndex,"classname","env_explosion"); 
	AcceptEntityInput(ExplosionIndex, "Kill"); 
	}
if (IsValidAliveClient(client)) ForcePlayerSuicide(client);
} 
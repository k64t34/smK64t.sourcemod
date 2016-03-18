#pragma semicolon 1
#if defined _k_k64t
	#endinput
#endif
#define _k_k64t
#define K64T_INCLUDE_PATH "smk64t\scripting\include\smK64t"
#define SM_INCLUDE_PATH  "smk64t\sourcemod-1.7.3-git5301\include" 
#define SMLIB_INCLUDE_PATH  "smlib\scripting\include" 

#define MAX_PLAYERS 33
#define MAX_CLIENT_NAME 32

#include <sourcemod>
#include <sdktools>
#pragma newdecls required ////https://wiki.alliedmods.net/SourcePawn_Transitional_Syntax#Enforcing_new_syntax
#if defined GAME_CSS
	#include "smk64t\k_cstrike.inc" 
#endif

//#include <sdktools>
//#include <clientprefs>
//smlib
//#include <smlib.inc>
//#include <color.inc> 

//myIncludes
//#include "smk64t\k_math.inc"
#include "smk64t\k_string.inc"
//#include "smk64t\player.k64t.inc"
//#include "smk64t\k_file.inc" 
//#include "smk64t\k_cstrike.inc"

#if defined DEBUG 	
	#if defined PLUGIN_VERSION
		#undef PLUGIN_VERSION
	#endif		
#endif
#include "game\addons\sourcemod\scripting\datetimecomp.inc"
#if defined DEBUG 	
	#include "smk64t\k_Debug.inc"
#endif
//*****************************************************************************
stock int  GetEntityVelocity(int ent,float velocity[3]) {
//*****************************************************************************	
// m_vecVelocity
return GetEntPropVector(ent,Prop_Data,"m_vecVelocity",velocity);
}

#endinput
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
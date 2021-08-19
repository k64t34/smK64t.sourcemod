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
//#include <smlib>
#pragma newdecls required ////https://wiki.alliedmods.net/SourcePawn_Transitional_Syntax#Enforcing_new_syntax
//#include <sdktools>
//#include <clientprefs>
//smlib
//#include <smlib.inc>
//#include <color.inc> 
#if defined DEBUG 	
	#if defined PLUGIN_VERSION
		#undef PLUGIN_VERSION
	#endif		
#endif
//#include "game\addons\sourcemod\scripting\datetimecomp.inc"
#include "datetimecomp.inc"
#if defined DEBUG 	
	#include "smk64t\k_Debug.inc"
#endif
//myIncludes
#if defined GAME_CSS
	#include "smk64t\k_cstrike.inc" 
#endif
#if defined GAME_DOD
	#include "smk64t\k_DODs.inc" 
#endif	
#if defined USE_PLAYER
	#include "smk64t\k_player.inc"
#endif
#include "smk64t\k_math.inc"
#include "smk64t\k_string.inc"
//#include "smk64t\player.k64t.inc"
#include "smk64t\k_file.inc" 
#include "smk64t\k_color.inc" 
//#include "smk64t\k_cstrike.inc"

//*****************************************************************************
stock void GetTimeHMS(int[] HMS){
//*****************************************************************************
char strBuff[3];
int t=GetTime();
FormatTime(strBuff, 3, "%H",t);
HMS[0]=StringToInt(strBuff);
FormatTime(strBuff, 3, "%M",t);
HMS[1]=StringToInt(strBuff);
FormatTime(strBuff, 3, "%S",t);
HMS[2]=StringToInt(strBuff);
//https://sm.alliedmods.net/new-api/sourcemod/GetTime
//int GetTime(int bigStamp[2])
//Parameters
//int[2] bigStamp
//Optional array to store the 64bit timestamp in.
//Return Value
//32bit timestamp (number of seconds since unix epoch).00:00:00 UTC) 1 םגאנ //1970 דמהא 
/*
FormatTime
%a abbreviated weekday name (Sun) 
%A full weekday name (Sunday) 
%b abbreviated month name (Dec) 
%B full month name (December) 
%c date and time (Dec 2 06:55:15 1979) 
%d day of the month (02) 
%H hour of the 24-hour day (06) 
%I hour of the 12-hour day (06) 
%j day of the year, from 001 (335) 
%m month of the year, from 01 (12) 
%M minutes after the hour (55) 
%p AM/PM indicator (AM) 
%S seconds after the minute (15) 
%U Sunday week of the year, from 00 (48) 
%w day of the week, from 0 for Sunday (6) 
%W Monday week of the year, from 00 (47) 
%x date (Dec 2 1979) 
%X time (06:55:15) 
%y year of the century, from 00 (79) 
%Y year (1979) 
*/	
}

//*****************************************************************************
stock int  GetEntityVelocity(int ent,float velocity[3]) {
//*****************************************************************************	
// m_vecVelocity
return GetEntPropVector(ent,Prop_Data,"m_vecVelocity",velocity);
}
//*****************************************************************************
stock char GetConVarChar(Handle cvarHandle){
//*****************************************************************************
char buff[2];
GetConVarString(cvarHandle, buff,2);
return (buff[0]);
}


//https://wiki.alliedmods.net/User_Messages
//
//hese may not be correct...
#define FFADE_IN            0x0001        // Just here so we don't pass 0 into the function
#define FFADE_OUT           0x0002        // Fade out (not in)
#define FFADE_MODULATE      0x0004        // Modulate (don't blend)
#define FFADE_STAYOUT       0x0008        // ignores the duration, stays faded out until new ScreenFade message received
#define FFADE_PURGE         0x0010        // Purges all other fades, replacing them with this one
//*****************************************************************************
stock void SetClientScreenFade( int index, int red, int green, int blue, int alpha, int duration ){
//*****************************************************************************	
//int duration = delay * 1000;
Handle MsgFade = StartMessageOne( "Fade", index );
BfWriteShort( MsgFade, 500 );
BfWriteShort( MsgFade, duration );
BfWriteShort( MsgFade, FFADE_OUT );
BfWriteByte( MsgFade, red );
BfWriteByte( MsgFade, green );
BfWriteByte( MsgFade, blue );	
BfWriteByte( MsgFade, alpha );
EndMessage();
}
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
#endinput
//*****************************************************************************
stock Explode_Player(client){
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
//*****************************************************************************
stock int GetHour(){
//*****************************************************************************
char Hour[3];
Ctime=GetTime();
FormatTime(Hour, 3, "%H",Ctime);
return StringToInt(Hour);
}
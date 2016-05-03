#define DEBUG  1
#define INFO 1
#define SMLOG 1
#define DEBUG_LOG 1
//#define DEBUG_PLAYER "K64t"
#define DEBUG_PLAYER "Kom64t"
#define PLUGIN_NAME  "k64t_css_counter"
#define PLUGIN_VERSION "0.1" //Init
#include <k64t>

#define MENU_TITLE "VoteMenuTitle"
#define ITEM_DO_NOT_CHANGE "Dont Change"

//Constvar
// CVar
// Global Var
//***********************************************
public Plugin myinfo = {
	name = PLUGIN_NAME,
	author = PLUGIN_AUTHOR,
	description = "Provides list of index CSS",
	version = PLUGIN_VERSION,
	url = ""};
//***********************************************
public void OnPluginStart(){
//***********************************************
#if defined DEBUG
PrintToServer("[%s] OnPluginStart",PLUGIN_NAME);
#endif 
HookEvent("round_end",		EventRoundEnd);
HookEvent("round_start",	EventRoundStart);
}
//***********************************************
public void OnMapStart(){
//***********************************************
#if defined DEBUG
PrintToServer("[%s] OnMapStart",PLUGIN_NAME);
#endif 
AutoExecConfig(true, "k64_css_counter");
}
//***********************************************
public void OnConfigsExecuted(){
//***********************************************
#if defined DEBUG
DebugPrint("OnConfigsExecuted");
#endif
}
//***********************************************
public void EventRoundEnd(Handle event, const char[] name,bool dontBroadcast){
//***********************************************
}
//***********************************************
public void EventRoundStart(Handle event, const char[] name,bool dontBroadcast){
//***********************************************
}
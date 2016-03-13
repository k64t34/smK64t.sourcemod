#if defined _k_menu
 #endinput
#endif
#define _k_menu

//*****************************************************************************
stock DisplayMenuToAll(Handle:menu,time=0){
//*****************************************************************************
new i_max=GetMaxClients();
for (new i=1;i<=i_max;i++)		
	if (IsClientConnected(i) && IsClientInGame(i) && !IsFakeClient(i)) 
		DisplayMenu(menu,i,time); 	
}
//*****************************************************************************
stock CancelClientMenuToAll(bool:autoIgnore=false, Handle:hStyle=INVALID_HANDLE){
//*****************************************************************************
new i_max=GetMaxClients();
for (new i=1;i<=i_max;i++)		
		CancelClientMenu(i,autoIgnore,hStyle);
}



#if defined _k_define
 #endinput
#endif
#define _k_define

/*
#define MAXPLAYERS 64		client.inc
#define MAX_NAME_LENGTH 32	client.inc
#define MAX_STRING  512
*/
#define MAX_CLIENT_NAME 32
#define MAX_PLAYERS 33 // Максимальное количество игроков  = 32, но нумерация массива начинается с нуля, а нумирация игроков с 1, 0 - это сам сервер. Что бы не вычислять индекс при каждом обращении к массиву, проще пожертвовать нескольикими байтами памяти первого нулевого элемента.


#define MAX16	16
#define MAX32	32
#define MAX64	64
#define MAX128	128	
#define MAX256	256
#define MAX512	512

#define MAX_MAPNAME 64
#define MAX_WEAPON_NAME 64


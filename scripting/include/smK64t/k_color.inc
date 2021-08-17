#if defined _k_color
	#endinput
#endif
#define _k_color
//#include "colors.inc"
//Regular colors: default, green (yellow in L4D), olive.
//Team colors: lightgreen, red, blue.

//new String:g_ColorNames[13][10] = {"White", "Red", "Green", "Blue", "Yellow", "Purple", "Cyan", "Orange", "Pink", "Olive", "Lime", "Violet", "Lightblue"};
//new g_Colors[13][3] = {{255,255,255},{255,0,0},{0,255,0},{0,0,255},{255,255,0},{255,0,255},{0,255,255},{255,128,0},{255,0,128},{128,255,0},{0,255,128},{128,0,255},{0,128,255}};

#define YELLOW                  '\1'
#define NAME_TEAMCOLOR          0x02
#define TEAMCOLOR               0x03
#define GREEN                   '\4'

#define cDEFAULT "{default}"
#define cGREEN  "{green}"
#define cLIGHTGREEN "{lightgreen}"
#define cRED       "{red}"
#define cBLUE      "{blue}"
#define cOLIVE     "{olive}"


//**************************************************************
//stock spectrum_ocg(value,range1,range2,range3){
//**************************************************************
//decl _c;
//if (0<=value && value<range1) _c=Color_Default;
//else if (range1<=value && value<range2) _c=Color_Lightgreen;
//else if (range2<=value && value<range3) _c=Color_Green;
//else if (value>range2) _c=Color_Red; 
//else _c=Color_Default;
//return _c;
//}
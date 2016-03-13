#if defined _k_char
	#endinput
#endif
#define _k_char
#define chr_empty	0 
#define chr_space	1 
#define chr_skull	2 //☠;
#define Full_Block	3 //█
#define Left_Half_Block	4 //▌
#define chr_bar_space	5 //
#define White_Frowing_Face 6//☹
new String:k_char[7][5]={
/*empty*/"",
/*space*/" ",
"☠"/*{'\xe2','\x98','\xa0'}*/,/*☠☺*/
"#"/*{'\xe2','\x96','\x88'}*/,/*██*/
"▌"/*{'\xe2','\x96','\x88'}*/,/*▌*/
"_"/*{'_','\x0','\x0'}*/,/* */
"-"
};

/*
[5][4];
k_char[chr_skull][0]='\xe2';
k_char[chr_skull][1]='\x98';
k_char[chr_skull][2]='\xa0';
k_char[chr_skull][3]=0;


k_char[chr_bar][0]='\xe2';
k_char[chr_bar][1]='\x96';
k_char[chr_bar][2]='\x88';
k_char[chr_bar][3]=0;

#define chr_bar_space 2 //█
k_char[chr_bar_space][0]='\xe2';
k_char[chr_bar_space][1]='\x96';
k_char[chr_bar_space][2]='\x88';
k_char[chr_bar_space][3]=0;
*/

//☆☠☠●✖⅓½█▌❢";
//Lucida Console
//▌▌▬░▒▲☻☺☼∙ █▌  ☻ ¤¤
/***
 *              _____                  _______                  _____                    _____                    _____                    _____          
 *             /\    \                /::\    \                /\    \                  /\    \                  /\    \                  /\    \         
 *            /::\    \              /::::\    \              /::\____\                /::\    \                /::\    \                /::\    \        
 *           /::::\    \            /::::::\    \            /::::|   |               /::::\    \               \:::\    \              /::::\    \       
 *          /::::::\    \          /::::::::\    \          /:::::|   |              /::::::\    \               \:::\    \            /::::::\    \      
 *         /:::/\:::\    \        /:::/~~\:::\    \        /::::::|   |             /:::/\:::\    \               \:::\    \          /:::/\:::\    \     
 *        /:::/  \:::\    \      /:::/    \:::\    \      /:::/|::|   |            /:::/__\:::\    \               \:::\    \        /:::/  \:::\    \    
 *       /:::/    \:::\    \    /:::/    / \:::\    \    /:::/ |::|   |           /::::\   \:::\    \              /::::\    \      /:::/    \:::\    \   
 *      /:::/    / \:::\    \  /:::/____/   \:::\____\  /:::/  |::|   | _____    /::::::\   \:::\    \    ____    /::::::\    \    /:::/    / \:::\    \  
 *     /:::/    /   \:::\    \|:::|    |     |:::|    |/:::/   |::|   |/\    \  /:::/\:::\   \:::\    \  /\   \  /:::/\:::\    \  /:::/    /   \:::\ ___\ 
 *    /:::/____/     \:::\____\:::|____|     |:::|    /:: /    |::|   /::\____\/:::/  \:::\   \:::\____\/::\   \/:::/  \:::\____\/:::/____/  ___\:::|    |
 *    \:::\    \      \::/    /\:::\    \   /:::/    /\::/    /|::|  /:::/    /\::/    \:::\   \::/    /\:::\  /:::/    \::/    /\:::\    \ /\  /:::|____|
 *     \:::\    \      \/____/  \:::\    \ /:::/    /  \/____/ |::| /:::/    /  \/____/ \:::\   \/____/  \:::\/:::/    / \/____/  \:::\    /::\ \::/    / 
 *      \:::\    \               \:::\    /:::/    /           |::|/:::/    /            \:::\    \       \::::::/    /            \:::\   \:::\ \/____/  
 *       \:::\    \               \:::\__/:::/    /            |::::::/    /              \:::\____\       \::::/____/              \:::\   \:::\____\    
 *        \:::\    \               \::::::::/    /             |:::::/    /                \::/    /        \:::\    \               \:::\  /:::/    /    
 *         \:::\    \               \::::::/    /              |::::/    /                  \/____/          \:::\    \               \:::\/:::/    /     
 *          \:::\    \               \::::/    /               /:::/    /                                     \:::\    \               \::::::/    /      
 *           \:::\____\               \::/____/               /:::/    /                                       \:::\____\               \::::/    /       
 *            \::/    /                ~~                     \::/    /                                         \::/    /                \::/____/        
 *             \/____/                                         \/____/                                           \/____/                                  
 *                                                                                                                                                        
 */



/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 3;        /* border pixel of windows */
static const unsigned int gappx     = 12;        /* gaps between windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int swallowfloating    = 0;        /* 1 means swallow floating windows by default */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = { "Anonymous Pro:style=Regular:size=13", "JoyPixels:style=Regular:size=13", "Noto Color Emoji:style=Regular:size=13" };
static const char dmenufont[]       = "Anonymous Pro:style=Regular:size=13";
static const char normbgcolor[]     = "#222222";
static const char normbordercolor[] = "#444444";
static const char normfgcolor[]     = "#bbbbbb";
static const char selfgcolor[]      = "#eeeeee";
static const char selbgcolor[]      = "#006633";
static const char selbordercolor[]  = "#66cdaa";
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { normfgcolor, normbgcolor, normbordercolor },
	[SchemeSel]  = { selfgcolor, selbgcolor,  selbordercolor },
};

static const char *const autostart[] = {
	NULL /* terminate */
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "X" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class     instance  title           tags mask  isfloating  isterminal  noswallow  monitor */
	{ "Gimp",    NULL,     NULL,           0,         1,          0,           0,        -1 },
	{ "Firefox", NULL,     NULL,           1 << 8,    0,          0,          -1,        -1 },
	{ "kitty",   NULL,     NULL,           0,         0,          1,           0,        -1 },
	{ NULL,      NULL,     "Event Tester", 0,         0,          0,           1,        -1 }, /* xev */
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

#include "fibonacci.c"
static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "[404]",    NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
	{ "[@]",      spiral },
	{ "[\\]",     dwindle}, 
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[]  = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", normbgcolor, "-nf", normfgcolor, "-sb", selbgcolor, "-sf", selfgcolor, NULL };
static const char *termcmd[]     = { "kitty", NULL };
static const char *nvimcmd[]     = { "kitty", "nvim", NULL };
static const char *volmute[]     = { "amixer", "set", "Master", "toggle", NULL };
static const char *volup[]       = { "amixer", "set", "Master", "5%+", NULL };
static const char *voldown[]     = { "amixer", "set", "Master", "5%-", NULL };
static const char *brightup[]    = { "brightnessctl", "-d", "amdgpu_bl0", "set", "5%+", NULL};
static const char *brightdown[]  = { "brightnessctl", "-d", "amdgpu_bl0", "set", "5%-", NULL};
static const char *furryfox[]    = { "firefox", NULL };
static const char *retroarch[]   = { "retroarch", NULL };
static const char *blueman[]     = { "blueman-manager", NULL };
static const char *passmenu[]    = { "passmenu", NULL };
static const char *discord[]     = { "/home/jd/Programs/Discord/Discord", NULL };
static const char *steam[]       = { "steam", NULL};
static const char *ranger[]      = { "kitty", "ranger", "/home/jd", NULL };
static const char *moc[]         = { "kitty", "mocp", NULL };

static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_p,       spawn,          {.v = dmenucmd } },
	{ MODKEY|ShiftMask,             XK_Return,  spawn,          {.v = termcmd } },
	{ MODKEY,		                    XK_v,	      spawn,	        {.v = nvimcmd } },
	{ 0,		                        0x1008ff12, spawn,          {.v = volmute } }, /* laptop keyboard */ 
	{ 0,                            0x1008ff15, spawn,          {.v = volmute } }, /* External Keyboard */ 
	{ 0,				                    0x1008ff13, spawn,	        {.v = volup } }, /* laptop keyboard */
	{ 0,                            0x1008ff14, spawn,          {.v = volup } }, /* External Keyboard */ 
	{ 0,				                    0x1008ff11, spawn,	        {.v = voldown } }, /* laptop keyboard */ 
	{ 0,                            0x1008ff16, spawn,          {.v = voldown } }, /* External Keyboard */ 
  { 0,                            0x1008ff02, spawn,          {.v = brightup } }, /* laptop Keyboard */
  { 0,                            0x1008ff03, spawn,          {.v = brightdown } }, /* laptop Keyboard */
	{ MODKEY,                       XK_w,       spawn,          {.v = furryfox } },
	{ MODKEY|ShiftMask,             XK_l,       spawn,          {.v = retroarch } },
	{ MODKEY|ShiftMask,             XK_b,       spawn,          {.v = blueman } },
	{ MODKEY|ShiftMask,             XK_p,       spawn,          {.v = passmenu } },
	{ MODKEY|ShiftMask,             XK_d,       spawn,          {.v = discord } },
	{ MODKEY|ShiftMask,             XK_s,       spawn,          {.v = steam } },
  { MODKEY,                       XK_r,       spawn,          {.v = ranger} },
  { MODKEY|ShiftMask,             XK_m,       spawn,          {.v = moc} },
	{ MODKEY,                       XK_b,       togglebar,      {0} },
	{ MODKEY,                       XK_j,       focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,       focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,       incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,       incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,       setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,       setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_Return,  zoom,           {0} },
	{ MODKEY,                       XK_Tab,     view,           {0} },
	{ MODKEY,                       XK_q,       killclient,     {0} },
	{ MODKEY,                       XK_t,       setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,       setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,       setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_y,       setlayout,      {.v = &layouts[3]} },
	{ MODKEY,                       XK_c,       setlayout,      {.v = &layouts[4]} },
	{ MODKEY,                       XK_space,   setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,   togglefloating, {0} },
	{ MODKEY,                       XK_z,       togglefullscr,  {0} },
	{ MODKEY,                       XK_0,       view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,       tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,   focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period,  focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,   tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period,  tagmon,         {.i = +1 } },
  { MODKEY,                       XK_minus,  setgaps,         {.i = -1 } },
  { MODKEY,                       XK_equal,  setgaps,         {.i = +1 } },
  { MODKEY|ShiftMask,             XK_equal,  setgaps,         {.i = 0  } },
	{ MODKEY|ShiftMask,             XK_q,       quit,           {0} },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};
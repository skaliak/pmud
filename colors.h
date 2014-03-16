#ifndef COLORS_H
#define COLORS_H


#define _COLOR_RESET   "\x1b[0m"

#define BRED(s)     "\x1b[31;1m" + s + _COLOR_RESET
#define BGREEN(s)   "\x1b[32;1m" + s + _COLOR_RESET
#define BYELLOW(s)  "\x1b[33;1m" + s + _COLOR_RESET
#define BBLUE(s)    "\x1b[34;1m" + s + _COLOR_RESET
#define BMAGENTA(s) "\x1b[35;1m" + s + _COLOR_RESET
#define BCYAN(s)    "\x1b[36;1m" + s + _COLOR_RESET

#define RED(s)     "\x1b[31m" + s + _COLOR_RESET
#define GREEN(s)   "\x1b[32m" + s + _COLOR_RESET
#define YELLOW(s)  "\x1b[33m" + s + _COLOR_RESET
#define BLUE(s)    "\x1b[34m" + s + _COLOR_RESET
#define MAGENTA(s) "\x1b[35m" + s + _COLOR_RESET
#define CYAN(s)    "\x1b[36m" + s + _COLOR_RESET

#endif

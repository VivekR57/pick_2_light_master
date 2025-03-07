
#ifndef MAIN_H
#define	MAIN_H

#include <xc.h>
#include "can.h"
#include "uart.h"
#include <ctype.h>

#define _XTAL_FREQ 20000000

/* Defines the data */
#define TRUE			1
#define FALSE			0


void display_tera_term(char n_id[], char u_st[]);
void handle_no_can_data(void);
#endif	/* MAIN_H */


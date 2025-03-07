#include "main.h"

unsigned char ch;
static char flag = 0;
static int index = 0;
char n_id[4] = {'0','0','0','0'};
char u_st[4] = {'0','0','0','0'};
void init_config(void) 
{
    init_can();
    init_uart();
    PEIE = 1;
    GIE = 1;
}

void main(void) 
{
    init_config();
    
    puts("Enter the N_ID [Max 4 digits]: ");
    while (1) 
    {
        if (can_receive()) 
        {
            char n_id[4];
            char u_st[4];
            n_id[0] = can_payload[D0];
            n_id[1] = can_payload[D1];
            n_id[2] = can_payload[D2];
            n_id[3] = can_payload[D3];

            u_st[0] = can_payload[D4];
            u_st[1] = can_payload[D5];
            u_st[2] = can_payload[D6];
            u_st[3] = can_payload[D7];

            // Display on Tera Term
            display_tera_term(n_id, u_st);
            flag = 0;
            index = 0;
            puts("Enter the N_ID [Max 4 digits]: ");
             
        } 
        else 
        {
            handle_no_can_data();
            
        }
        
    }
}

void display_tera_term(char n_id[], char u_st[])
{
    puts("Received data N_ID: ");
    for (int i = 0; i < 4; i++) 
    {
        putch(n_id[i]);
    }

    puts(" U_ST: ");
    for (int i = 0; i < 4; i++) 
    {
        putch(u_st[i]);
    }
    puts("\n\r");
}

void handle_no_can_data(void) 
{
    
    
    static char temp_input[4] = {'0','0','0','0'};
    
    
  
  /*  if (flag == 0) 
    {
      //  puts("\n\r");
        //        change_flag = 4;
    } */
    if (ch != '\0' && ch != 13) 
    {
        if (isdigit(ch) && index < 4) 
        {
            temp_input[index] = ch;
            index++;
            putch(ch);
        }
        ch = 0;
    }
    else if(ch == '\r')
    {
        if(flag == 0)
        {
            int i;
            for(i=0;i<4-index;i++)
            {
                n_id[i]='0';
            }
            int k = 0;
            for(;i<4;i++,k++)
            {
                n_id[i] = temp_input[k];
            }
            flag=1;
            puts("\n\r");
            puts("Enter the U_ST [Max 4 digits]: ");
            
        }
        else if(flag == 1)
        {
            int i;
            for(i=0;i<4-index;i++)
            {
                u_st[i]='0';
            }
            int k=0;
            for(;i<4;i++,k++)
            {
                u_st[i]=temp_input[k];
            }
            flag = 0;
            can_transmit();
            puts("\n\r");
            puts("Enter the N_ID [Max 4 digits]: ");
        }
        index=0;
        ch=0;
    }
   
    
  
      
}
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int DFA_float(char *lexeme)
{
	int state = 1;
	for (int i = 0;i<strlen(lexeme);i++)
	{
		switch(state)
	{
		
		case 1:
		{
		if ((lexeme[i] >= 48) && (lexeme[i] <= 57))
		{
			state = 2;
			break;
		}
		else
		{
			state = -1;
			break;
		}
		}
		case 2:
		{
		if ((lexeme[i] >= 48) && (lexeme[i] <= 57))
		{ 
			state = 2;
			break;
		}
		else if (lexeme[i] == 46)
		{
			state = 3;
			break;
		}
		else
		{
			state = -1;
			break;
		}
		}
		case 3:
		{
		if ((lexeme[i] >= 48) && (lexeme[i] <= 57))
		{
			state = 3;
			break;
		}
		else
		{
			state = -1;
			break;
		}
		}
	}
	}
	if ((state == 2) || (state == 3)) return 0;
	else { return -1; }
}

int DFA_IDENT(char *lexeme)
{
	int state = 1;
	for (int i = 0;i<strlen(lexeme);i++)
	{
	switch(state)
	{
		case 1:
		{
			if ((lexeme[i] >= 65) && (lexeme[i] <= 122))
			{
				state = 2;
				break;
			}
			else
			{
				state = -1;
				break;
			}
		}
		case 2:
		{
			if ( (lexeme[i] >= 65) && (lexeme[i] <= 122) || (lexeme[i] >= 48) && (lexeme[i] <= 57) )
			{
				state = 2;
				break;
			}
			else
			{
				state = -1;
				break;
			}
		}
	}
	}
	if (state == 2) { return 0; }
	else { return -1; }
}

int DFA_reserved(char *lexeme)
{
	int state = 1;
	for (int i = 0;i<strlen(lexeme);i++)
	{
	switch(state)
	{
		case 1: { 
			if (lexeme[i] == 'p') {state = 2; break;} 
			if (lexeme[i] == 'w') {state = 7; break;}
			if (lexeme[i] == 'b') {state = 12;break;}
			if (lexeme[i] == 'i') {state = 17;break;}
			else { return -1; }
			}
		case 2: { if (lexeme[i] == 'r') {state = 3;break;} }
		case 3: { if (lexeme[i] == 'i') {state = 4;break;} }
		case 4: { if (lexeme[i] == 'n') {state = 5;break;} }
		case 5: { if (lexeme[i] == 't') {state = 6;break;} } //print ending state = 6
		case 7: { if (lexeme[i] == 'h') {state = 8;break;} }
		case 8: { if (lexeme[i] == 'i') {state = 9;break;} }
		case 9:  { if (lexeme[i] == 'l') {state = 10;break;}}
		case 10: { if (lexeme[i] == 'e') {state = 11;break;}} //while ending state = 11
		case 12: { if (lexeme[i] == 'r') {state = 13;break;}}
		case 13: { if (lexeme[i] == 'e') {state = 14;break; }}
		case 14: { if (lexeme[i] == 'a') {state = 15;break; }}
		case 15: { if (lexeme[i] == 'k') {state = 16;break; }} //break ending state = 16
		case 17: { if (lexeme[i] == 'f') {state = 18;break; }} //if ending state = 18
	}
	}
	if (state == 6) { return state; }
	if (state == 11) { return state; }
	if (state == 18) { return state; }
	if (state == 16) { return state; }
	else { return -1; }
}

int DFA_comp(char *lexeme)
{
	int state = 1;
	for (int i = 0;i<strlen(lexeme);i++)
	{
	switch(state)
	{
		case 1: 
		{
			if (lexeme[i] == '=') {state = 2;break; }	//assigning operator
			if (lexeme[i] == '<') {state = 4;break; }	// less than or greater than
			if (lexeme[i] == '>') {state = 4;break; }	// less than or greater than
			if (lexeme[i] == '+') {state = 6;break; }	//plus operator
			if (lexeme[i] == '-') {state = 7;break; }	//- minus operator
			if (lexeme[i] == '*') {state = 8;break; }	// multi operator
			if (lexeme[i] == '/') {state = 9;break; }	// division operator
		}
		case 2:
		{
			if (lexeme[i] == '=') {state = 3;break;}	//camparasim operator
		}
		case 4:
		{
			if (lexeme[i] == '=') {state = 5;break;}	//less than and equal too and vice versa
		}
		
	}
	}
	if ((state >= 2) && (state <= 9))
	{
		return state;
	}
	else { return -1; }
}
int DFA_bracket(char *lexeme)
{
 	int state = 1;
 	for (int i = 0;i<strlen(lexeme);i++)
 	{
 	switch(state)
 	{
 	case 1: 
 	{
 		if (lexeme[i] == '(') {state = 2; break; }
 		if (lexeme[i] == ')') {state = 3; break; }
 		if (lexeme[i] == '{') {state = 4; break; }
 		if (lexeme[i] == '}') {state = 5;break;  }
 	}
 	}
 	}
 	if ((state >= 2) && (state <= 5))
 	{
 		return state;
 	}
 	else { return -1; }
 }

int check_table(char *lexeme,char *buffer)
{
	int n = 0; int notEqual = 0;
	for (int i;i<sizeof(buffer);i++)
	{
		if ((notEqual == 1) && (buffer[i]!='#'))
		{
			n = 0;
			continue;
		}
		if (buffer[i] != lexeme[n])
		{
			notEqual = 1;
		}
		else 
		{
			notEqual = 0;
		}
		n++;
	}
	if (notEqual == 1)
	return -1;
	if (notEqual == 0)
	return 0;
}

int check_array(char array[100][100], char *lexem)
{
    int check;
    for (int row = 0; row <= 100; row++)
    {
        check = 0;
        for (int col = 0; col <= strlen(lexem); col++)
        {
            // printf("in array -->%c   lexeme -->%c\n", array[row][col], lexem[col]);
            if (array[row][col] != lexem[col])
            {
                check = 1;
            }
        }
        if (check == 0)
        {
            break;
        }
    }
    if (check == 1)
    {
        return 1;
    }
    return 0;
}
 	
int main()
{
    FILE *ptrSource;
    ptrSource = fopen("input.txt","r");
    FILE *token;
    token = fopen("token.txt","w");
    FILE *sym;
	sym = fopen("symbolTable.txt","w");
	char IDENT[100][100];

    if (ptrSource == NULL) //if file doesnt open
    {
        fputs("Failed to open the file\n", stderr);
        return -1;
    }
    char cur,*buffer,*lexeme;
    int i,L,R,l,count_of_IDENT =0;
    while(1)
    {
    	if (cur == EOF ) {break;}
    	buffer = malloc(100);
    	L = 0; R = 0;
    	while(1)
    	{
	    	cur = fgetc(ptrSource);
	    	
	    	//printf(" %c:%d ",cur,cur);
	    	if (cur == EOF ) {break;}
	    	//if (cur == '\n') {break;}
	    	if (cur == 32) {continue;} if(cur == 0) {continue;}
	    	buffer[R] = cur;
		if ((buffer[R-1]=='/') && (buffer[R]=='/'))
		{
			while(1)
			{
				cur = fgetc(ptrSource);
				if (cur == '\n')
				{
					break;
				}
			}
			break;
		}
	    	if ((((buffer[R-1] >= 65) && (buffer[R-1] <= 122)) || ((buffer[R-1] >= 48) && (buffer[R-1] <= 57)) || buffer[R-1] == 46) &&(((buffer[R] < 65) || (buffer[R] > 122)) && ((buffer[R] <= 48) || (buffer[R] >= 57)) && buffer[R] != 46))
	    	{
	    		l = 0;
	    		lexeme = malloc(R-L);
	    		while(L!=R)
	    		{	
	    			lexeme[l] = buffer[L];
	    			L++;l++;
	    		}
	    		//send lexeme to DFA here
	    		int res = DFA_reserved(lexeme);
	    		if (res == 6) {fprintf(token,"%s","T_print_function\n");}
	    		if (res == 11) {fprintf(token,"%s","T_while_word\n");}
	    		if (res == 16) {fprintf(token,"%s","T_break_function\n");}
	    		if (res == 18) {fprintf(token,"%s","T_if_word\n");}
	    		if (res == -1) 
	    		{
	    			int isIdent = DFA_IDENT(lexeme);int isFloat = DFA_float(lexeme);
	    			if (isIdent == 0)
	    			{
	    				fprintf(token,"%s",lexeme);
	    				fprintf(token,"%s"," IDENTIFIER\n");
	    				//starting symbol table part
						int check = check_array(IDENT, lexeme);

                    	if (check == 1)
                    	{
							for (int i = 0; i < strlen(lexeme); i++)
							{
								IDENT[count_of_IDENT][i] = lexeme[i];
							}

							fprintf(sym, "id_no:%d\t\t\t%s id_token\n", count_of_IDENT, lexeme);
							count_of_IDENT++;
                    	}
	    				//ending symbol table part
	    				}
	    	        	else if (isFloat == 0) 
	    	        	{
	    	        		fprintf(token,"%s",lexeme);
	    					fprintf(token,"%s"," FLOAT\n");
	    	        	}
	    		}

	    		free(lexeme);
	    		L = R;
	    	}
	    	if (cur == '(') {  fprintf(token,"%s","T_starting_circle_bracket\n"); continue; }
	    	if (cur == '{') {  fprintf(token,"%s","T_starting_curly_bracket\n"); continue; }
	    	if (cur == ')') {  fprintf(token,"%s","T_ending_circle_bracket\n"); continue; }
	    	if (cur == '}') {  fprintf(token,"%s","T_ending_curly_bracket\n"); continue; }
	        if((((buffer[R] >= 65) && (buffer[R] <= 122)) || ((buffer[R] >= 48) && (buffer[R] <= 57)) || buffer[R] == 46) &&
	    	(((buffer[R-1] < 65) || (buffer[R-1] > 122)) && ((buffer[R-1] < 48) || (buffer[R-1] > 57)) && buffer[R-1] != 46))
	    	{
	    		l = 0;
	    		lexeme = malloc(R-L);
	    		while(L<R)
	    		{	
	    			lexeme[l] = buffer[L];
	    			L++;l++;
	    		}
	    		//send exeme to DFA here
	    		int value = DFA_comp(lexeme);
    	        	if (value != -1)
    	        	{
		    	        if (value == 2) fprintf(token,"%s","T_assiging_operator\n");
		    	        if (value == 4) fprintf(token,"%s","T_less/greater Operator\n"); 
		    	        if (value == 6) fprintf(token,"%s","T_plus_operator\n"); 
		    	        if (value == 7) fprintf(token,"%s","T_minus_operator\n");
		    	        if (value == 8) fprintf(token,"%s","T_multi_operator\n");
		    	        if (value == 9) fprintf(token,"%s","T_division_operator\n");;
		    	        if (value == 3) fprintf(token,"%s","T_is_equal_operator\n");
		    	        if (value == 5) fprintf(token,"%s","T_equal_or_less/greater_than\n"); 
		    	}
	    		//free lexeme here
	    		free(lexeme);
	    		L = R;
	    	}
	        if (buffer[R] == '\n')
	    	{
	    		if (R-L == 0) {fprintf(token,"%s","end_of_line_mark_\n");  break;}
	    		L = R;
	    		break;
	    	}
	    	R++;
	}
	//memset(buffer,32,'\0');
	//printf("%s end of line\n",buffer);
	free(buffer);
    }
	for (int x = 0; x <= 50; x++)
    {
        if (IDENT[x][0] == '\0')
        {
            break;
        }
        else
        {
            fprintf(sym, " %d       %s\n", x, IDENT[x]);
        }
    }
	fclose(sym);
    fclose(ptrSource);
    fclose(token);
    return 0;
}







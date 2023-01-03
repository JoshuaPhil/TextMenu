#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>


//settings for the menu
#define MENU_WIDTH 40
#define MENU_VERTICAL_BORDER '|'
#define METHOD_SUCCESS 0
#define METHOD_FAIL -1

//define functions for use beneath the main function
int put_horizontal_border();
int add_filler_row();
int add_element_to_window(char* element, int centered);



//this function essentially draws a straight line in the menu.
int put_horizontal_border(){
	// create the storage space for the string 
	char MENU_HORIZONTAL_BORDER[MENU_WIDTH+1] = "";
	// fill the string with dashes to create a straight line
	memset(MENU_HORIZONTAL_BORDER, '-', MENU_WIDTH);
	// add a null terminator at the end of the string
	MENU_HORIZONTAL_BORDER[MENU_WIDTH] = '\0';
	// display the line on the menu
	printf(MENU_HORIZONTAL_BORDER);
	// add a new line
	printf("\n");
	// tell program it was a success
	return METHOD_SUCCESS;
}

// this function is for creating blank spaces in the menu
int add_filler_row(){
	// create storage space for the string
	char FILLER_LINE[MENU_WIDTH+1] = "";
	//fill the string with spaces
	memset(FILLER_LINE, ' ', MENU_WIDTH);
	//add a pipe at the start and end of the string
	FILLER_LINE[0] = MENU_VERTICAL_BORDER;
	FILLER_LINE[MENU_WIDTH-1] = MENU_VERTICAL_BORDER;
	//include the null terminator
	FILLER_LINE[MENU_WIDTH] = '\0';
	//draw row on the menu
	printf(FILLER_LINE);
	//add a new line
	printf("\n");
	// tell program it was a success
	return METHOD_SUCCESS;
}

int add_element_to_window(char* element, int centered){
	// add blank space to the menu
	add_filler_row();
	//create storage space for the string
	char MAIN_CONTENT_ROW[MENU_WIDTH+1] = {};
	//if the string is longer than the number of characters available then tell the program the method has failed
	if(strlen(element) > MENU_WIDTH-2){
		return METHOD_FAIL;
	}
	//add a pipe to the start of the row
	MAIN_CONTENT_ROW[0] = MENU_VERTICAL_BORDER;
	//define variables for padding
	int delta = 0;
	int first_padding = 0;
	int second_padding = 0;
	//if centered
	if(centered == 1){
		//calculate the difference between the width and the length of the element
		delta = MENU_WIDTH+1 - strlen(element);
		//set the padding to the floor of delta over 2 (floor = round down the input decimal number)
		first_padding = floorf(delta/2);
		//copy the first_padding value over to the second
		second_padding = first_padding;
	} else if(centered == 0){
		//otherwise set all controls to zero
		delta = 0;
		first_padding = 0;
		second_padding = 0;
	} else{
		return METHOD_FAIL;
	}
	//increase or decrease the second padding based on the total sum of all elements
	if(1+first_padding+strlen(element)+second_padding+1 < MENU_WIDTH){
		int error = MENU_WIDTH - 1+first_padding+strlen(element)+second_padding+1;
		second_padding = second_padding + error;
	} else if(1+first_padding+strlen(element)+second_padding+1 > MENU_WIDTH){
		int error = 1+first_padding+strlen(element)+second_padding+1 - MENU_WIDTH;
		second_padding = second_padding - error;
	}
	//allocate string space for the padding
	char fpad[first_padding+1];
	char spad[second_padding+1];
	//fill both strings with spaces
	memset(fpad, ' ', first_padding);
	memset(spad, ' ', second_padding);
	//add null terminators at the end
	fpad[first_padding] = '\0';
	spad[second_padding] = '\0'; 
	//add all the snippets together into the string
	strcat(MAIN_CONTENT_ROW, fpad);
	strcat(MAIN_CONTENT_ROW, element);
	strcat(MAIN_CONTENT_ROW, spad);
	MAIN_CONTENT_ROW[MENU_WIDTH-1] = MENU_VERTICAL_BORDER;
	//add the null terminator
	MAIN_CONTENT_ROW[MENU_WIDTH] = '\0';
	//display on menu and add new line
	printf(MAIN_CONTENT_ROW);
	printf("\n");
	//add a filler row beneath for presentation
	add_filler_row();
	
	//tell the program the method was a success
	return METHOD_SUCCESS;
}


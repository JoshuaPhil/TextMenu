#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#include "menu_utils.h"

//the main function acts as a drawing function for the menu.
int main(){
	// draw features onto screen
	put_horizontal_border();
	add_element_to_window("EC-20 Test", 1);
	put_horizontal_border();
	add_element_to_window("APC: Result:", 0);
	add_element_to_window("I2C: Result:", 0);
	add_element_to_window("IO: Result:", 0);
	add_element_to_window("Serial: Result:", 0);
	put_horizontal_border();
	//on exit tell the program that the code exited without failing
	return METHOD_SUCCESS;
}

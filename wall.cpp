#include "wall.hpp"

wall::wall( ILI9481 & LCD, const int & x_start, const int & y_start, const int & x_end, const int & y_end, int color, std::array< int, 2> bounce, const int & name):
		Drawable(LCD, x_start, y_start, x_end - x_start, y_end - y_start +2, color, bounce),
		left(   LCD,x_start, y_start, x_start, y_end, color, bounce),
		right(  LCD, x_end, y_start, x_end, y_end, color, bounce),
		top(    LCD, x_start, y_start, x_end , y_start, color, bounce),
		bottom( LCD, x_start, y_end, x_end , y_end, color, bounce),
		name(name),
		color(color)
{}

void wall::draw() {
		left.draw();
		right.draw();
		top.draw();
		bottom.draw();
}

void wall::say_name(){
	hwlib::cout<<"wall"<<name;
}

void wall::set_color(const int & new_color){
	left.set_color( new_color);
	right.set_color(new_color);
	top.set_color(new_color);
	bottom.set_color(new_color);
}

void wall::update() {
	
}

void wall::interact( Drawable & other ){
	
}
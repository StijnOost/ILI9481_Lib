#include "line.hpp"

Line::Line(ILI9481 & LCD,int x_start, int y_start,int x_end,int y_end, int color, std::array< int, 2> bounce):
Drawable(LCD, x_start , y_start,x_start-x_end , y_start-y_end, color, bounce),
LCD(LCD),
x_start(x_start),
y_start(y_start),
x_end(x_end),
y_end(y_end),
color(color)
{}

//	line(int x_start, int y_start,int x_end,int y_end, int color=0xFFFFF);
void Line::draw(){
	
	int x_dist = x_start-x_end;
	int y_dist = y_start-y_end;
	
	if(x_dist==0){
		for(int i=y_start; i<y_end; i++){
			LCD.drawPixel(x_start, i, color);
			hwlib::wait_ms(1);
		}
	}
	else if(y_dist==0){
		for (int i=x_start; i<x_end; i++){
			LCD.drawPixel(i, y_start, color);
		}
	}
}


//	void change_color(new_color);
//	void change_x(int new_x);
//	void change_y(int new_y);
void Line::move(int x, int y){
	x_start+=x;
	x_end+=x;
	y_start+=y;
	y_end+=y;
}

void Line::update(){
	
}

void Line::say_name(){
	hwlib::cout<<"Line";
}

void Line::set_color(const int & new_color){
	color=new_color;
}

void Line::interact( Drawable & other ){
	
}
//	void teleport(int x, int y);
//	int get
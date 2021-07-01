#include "Peddle.hpp"

Peddle::Peddle(ILI9481 & LCD,  int x_start, int y_start, int w, int h, int color,int min, int max, hwlib::target::pin_in & up_pin, hwlib::target::pin_in & down_pin, int background, int updatetimer, std::array< int, 2> bounce ) :
Drawable(LCD, x_start, y_start, w, h, color, bounce),
LCD(LCD),
x_start(x_start),
y_start(y_start),
w(w),
h(h),
color(color), 
min(min),
max(max),
up_pin(up_pin),
down_pin(down_pin),
background(background),
updatetimer(updatetimer)

{update_start=updatetimer;}

void Peddle::draw(){
	LCD.fillRect(x_start,y_start,w,h,color);
}



void Peddle::update(){
	if(updatetimer<=0){
		if(!y_speed==0){
			LCD.fillRect(x_start,y_start,w,h,background);
			y_start= y_start + y_speed;
			y_higher(y_speed);
			LCD.fillRect(x_start,y_start,w,h,color);
			updatetimer= update_start;
		}
	}else{
		updatetimer--;
	}
}


void Peddle::buttons(){
	y_speed=0;
	if(up_pin.read()==true){
		if(y_start<min+5){
			y_speed=0;
		}else{
			y_speed=-5;
		}
	}
	if(down_pin.read()==true){
		if((y_start+h)>max-4){
			y_speed=0;
		}else{
			y_speed=5;
		}
	}
}

void Peddle::interact( Drawable & other ){
	
}

void Peddle::say_name(){
	hwlib::cout<<"Peddle";
}


void Peddle::setpos(const int & x, const int & y){
	x_start=x;
	y_start=y;
	x_set(x);
	y_set(y);
}
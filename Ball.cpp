#include "Ball.hpp"

Ball::Ball(ILI9481 & LCD,  int x_start, int y_start, int w, int h, int color, int background , int x_speed, int y_speed, std::array< int, 2> bounce):
	Drawable(LCD, x_start, y_start, w, h, color, bounce),
	LCD(LCD),
	x_start(x_start),
	y_start(y_start),
	w(w),
	h(h),
	color(color),
	background(background),
	x_speed(x_speed),
	y_speed(y_speed)
{}

void Ball::draw(){
	LCD.fillRect(x_start,y_start,w,h,color);
}

void Ball::update(){
	if(true){
		
		LCD.fillRect(x_start,y_start,w,h,background);
		x_start= x_start + x_speed;
		x_higher(x_speed);
		y_start= y_start + y_speed;
		y_higher(y_speed);
		if(x_start>480){
			goal_right=true;
			LCD.fillRect(x_start,y_start,w,h,background);
		}
		if(x_start<0){
			goal_left=true;
			LCD.fillRect(x_start,y_start,w,h,background);
		}
		if(!goal_left||!goal_right){
			LCD.fillRect(x_start,y_start,w,h,color);
		}
		
	
	}
}

void Ball::reset_goal_bool(){
	goal_left=false;
	goal_right=false;
}

bool Ball::check_goal_left(){
	return goal_left;
}

bool Ball::check_goal_right(){
	return goal_right;
}


void Ball::say_name(){
	hwlib::cout<<"ball";
}

void Ball::setpos(const int & x, const int & y){
	x_start=x;
	y_start=y;
	x_set(x);
	y_set(y);
}


void Ball::interact(Drawable & other ){
  if( this != & other){
	if( Drawable::overlaps( other )){
		x_speed *= other.get_bounce_x();
		y_speed *= other.get_bounce_y();
	}
  }
}   
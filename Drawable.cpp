#include "Drawable.hpp"

Drawable::Drawable(ILI9481 & LCD, int x, int y, int sizex, int sizey, int color, std::array< int, 2> bounce):
LCD(LCD),
x(x),
y(y),
sizex(sizex),
sizey(sizey),
color(color),
bounce(bounce)
{
}


bool Drawable::within( const int & x, const int & a, const int & b ){
   return ( x >= a ) && ( x <= b );
}

bool Drawable::overlaps( const Drawable & other ){
   bool x_overlap = within( x, other.x, other.x + other.sizex) || within( other.x, x, x + sizex);
   
     
   bool y_overlap = within( y, other.y, other.y + other.sizey) || within( other.y, y, y + sizey);
   
   return x_overlap && y_overlap;
}

void Drawable::x_higher(const int & num){
	 x+=num;
}

void Drawable::y_higher(const int & num){
	 y+=num;
}

void Drawable::x_set(const int & num){
	 x=num;
}

void Drawable::y_set(const int & num){
	 y=num;
}


int Drawable::get_bounce_x(){
	return bounce[0];
}

int Drawable::get_bounce_y(){
	return bounce[1];
}



#ifndef PEDDLE_HPP
#define PEDDLE_HPP

#include "Drawable.hpp"

/// @file
/// \brief
/// Peddle class
/// \details
/// This class Peddle is used to make Peddles on a display
class Peddle : public Drawable{
private:
ILI9481 & LCD;
int x_start;
int y_start;
int w;
int h;
int color;
int min;
int max;
hwlib::target::pin_in & up_pin;
hwlib::target::pin_in & down_pin;
int background;
int y_speed;
int updatetimer;
int update_start;


public:
	/// \brief
	/// Peddle constructor 
	/// \details
	/// Needs the screen to write to x_start and y_start also the width and height values color and the bounce of the Peddle also needs max and min boundries of the ball.
	Peddle(ILI9481 & LCD,  int start_x, int start_y, int w, int h, int color,int min, int max, hwlib::target::pin_in & up_pin, hwlib::target::pin_in & down_pin, int background,int updatetimer, std::array< int, 2> bounce) ;
	/// \brief
	/// draw draws a peddle 
	/// \details
	/// Draws a Peddle with xy start and width and height and color
	void draw();
	/// \brief
	/// Updates the position of the Peddle and draws it.
	/// \details
	/// It overrides the class drawable update funcion
	/// And makes it so that a Peddle is drawn and that it cant be drawn out of max and min
	void update() override;
	/// \brief
	/// Checks if the Peddle interacts with another object
	/// \details
	/// It overrides the class drawable interact funcion
	/// it is empty
	void interact( Drawable & other ) override;
	/// \brief
	/// Says the name of the object
	/// \details
	/// mostly used for debugging It overrides the class drawable say_name funcion
	/// and used to say the drawable objects name
	void say_name() override;
	/// \brief
	/// setpos sets the position 
	/// \details
	/// setpos sets the position of the peddle with the x and y position
	void setpos(const int & x, const int & y);
	/// \brief
	/// Checks if a button is pressed 
	/// \details
	/// Checks if button up and down is pressed with both peddless
	void buttons();
};

#endif // PEDDLE_HPP

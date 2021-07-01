#ifndef LINE_HPP
#define LINE_HPP
#include "Drawable.hpp"
/// @file
/// \brief
/// Line class
/// \details
/// This class line is used to make lines on a display
class Line : public Drawable{
private:
ILI9481 & LCD;
int x_start;
int y_start;
int x_end;
int y_end;
int color;
public:
	/// \brief
	/// Line constructor 
	/// \details
	/// Needs the screen to write to x_start and y_start als the x and y end values color and the bounce of the line
	Line(ILI9481 & LCD, int x_start, int y_start,int x_end,int y_end, int color, std::array< int, 2> bounce);
	/// \brief
	/// draw draws a line 
	/// \details
	/// Draws a line with xy start and xy end
	void draw();
	/// \brief
	/// Updates the position of the line and draws it.
	/// \details
	/// It can be used to override the class drawable update funcion
	/// And can make it so that a line is drawn
	/// it is empty
	void update() override;
	/// \brief
	/// Checks if the line interacts with an object
	/// \details
	/// It can be used to override the class drawable interact funcion
	/// to check if there is an interact
	/// it is empty
	void interact( Drawable & other ) override;
	/// \brief
	/// Says the name of the object
	/// \details
	/// mostly used for debugging It overrides the class drawable say_name funcion
	/// and used to say the drawable objects name
	void say_name() override;
	/// \brief
	/// Move moves the line in a x and y amount
	/// \details
	/// moves the lin in a x and y amount to moves the line.
	void move(int x, int y);
	/// \brief
	/// set_color sets the  color of the line
	/// \details
	/// set the color of a lin with a int color
	void set_color(const int & new_color);

};

#endif // LINE_HPP

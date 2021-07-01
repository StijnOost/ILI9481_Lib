#ifndef WALL_HPP
#define WALL_HPP
#include "line.hpp"
class wall : public Drawable
{
private:

	Line left,right,top,bottom;
	const int & name;
	const int & color;
public:
	/// \brief
	/// Construct wall 
	/// \details
	/// needs the screen xy start and xy end also needs color end bounce and name
	/// makes top down left right line objects and fills those values
	wall(ILI9481 & LCD, const int & x_start, const int & y_start, const int & x_end, const int & y_end,  int  color , std::array< int, 2> bounce, const int & name);
	/// \brief
	/// draw draws all the lines
	/// \details
	/// Draw draws the line object top right bottom left
	void draw();
	/// \brief
	/// Updates the position of the wall and draws it.
	/// \details
	/// It can be used to override the class drawable update funcion
	/// And you can makes it so that a wall is drawn
	/// it is empty
	void update() override;
	/// \brief
	/// Checks if the wall interacts with an object
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
	/// set_color sets the  color of the wall
	/// \details
	/// set the color of all lines with the function line.set_color
	void set_color(const int & new_color);
};

#endif // WALL_HPP

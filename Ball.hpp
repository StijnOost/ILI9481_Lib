#ifndef BALL_HPP
#define BALL_HPP

#include "Drawable.hpp"

/// @file
/// \brief
/// Ball class
/// \details
/// This ball class check if a goal is scored (when ball go past 0 or 480)
/// And updates its position
class Ball : public Drawable
{
private:
ILI9481 & LCD;
int x_start;
int y_start;
int w;
int h;
int color;
int background;
int x_speed;
int y_speed;
bool goal_right = false;
bool goal_left = false;

public:
	 /// \brief
    /// Constructor of ball 
    /// \details
    /// Needs start position the color background color its speed and bounce amount.
	Ball(ILI9481 & LCD,  int x_start, int y_start, int w, int h, int color, int background , int x_speed, int y_speed, std::array< int, 2> bounce);
	 /// \brief
    /// Draws the ball object
    /// \details
    /// Uses the privat x,y position width height and color
	void draw();
	/// \brief
	/// Updates the position of the ball and draws it.
	/// \details
	/// It overrides the class drawable update funcion
	/// And makes it so that a ball is drawn
	void update() override;
	/// \brief
	/// Checks if the ball interacts with an object
	/// \details
	/// It overrides the class drawable interact funcion
	/// And makes it so that if the ball is inside another object it collides using the bounce amount
	void interact( Drawable & other ) override;
	/// \brief
	/// Says the name of the object
	/// \details
	/// mostly used for debugging It overrides the class drawable say_name funcion
	/// and used to say the drawable objects name
	void say_name() override;
	/// \brief
	/// Resets the goal bools 
	/// \details
	/// sets goal_right and goal_left bool to false
	void reset_goal_bool();
	/// \brief
	/// Sets the position to a given x,y
	/// \details
	/// Sets positon withg an x and y. 
	void setpos(const int & x, const int & y);
	/// \brief
	/// Returns bool goal_left
	/// \details
	/// Returns the bool goal_left. Mostly used for other files to acces this bool.
	bool check_goal_left();
	/// \brief
	/// Returns bool goal_right
	/// \details
	/// Returns the bool goal_right. Mostly used for other files to acces this bool.
	bool check_goal_right();
};

#endif // BALL_HPP

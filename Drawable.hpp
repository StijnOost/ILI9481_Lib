#ifndef DRAWABLE_HPP
#define DRAWABLE_HPP

#include "ILI9481.hpp"
#include <array>

/// @file
/// \brief
/// Drawable class
/// \details
/// This Drawable class is used by other classes and is an objects hitbox
class Drawable
{
	ILI9481 & LCD;
	int x;
	int y;
	int sizex;
	int sizey;
	int color;
	std::array< int, 2> bounce;
public:

	/// \brief
	/// Construct
	/// \details
	/// Constructs the class for everything for the Drawable class
	/// Needs the screen x y
	Drawable(ILI9481 & LCD, int x,int y,int sizex, int sizey, int color, std::array< int, 2> bounce);
	
	/// \brief
	/// Checks if a int within two ints
	/// \details
	/// Checks if int x is between int a and int b and gives a bool return
	bool within( const int & x, const int & a, const int & b );
	
	/// \brief
	/// Checks if a Drawable object overlaps another
	/// \details
	/// Checks if the given Drawable overlaps the one where its used.
	/// If so returns bool.
	bool overlaps( const Drawable & other );
	
	/// \brief
	/// update used to make the objects update
	/// \details
	/// Empty update function used by all drawable classes as override
	/// Used oto update the object
	virtual void update()=0;
	
	/// \brief
	/// Interact used to make objects interact
	/// \details
	/// Empty interact function used by all drawable classes as override.
	/// Needs another drawable object to work
	/// Used to check if an object interacts with another
	virtual void interact( Drawable & other )=0;
	
	/// \brief
	/// Say_name says anme of objec t
	/// \details
	/// Empty Say_name function used by all drawable classes as override.
	/// Used to cout the objects name
	virtual void say_name()=0;
	
	/// \brief
	/// x_higher makes x higher with num
	/// \details
	/// Makes the private int x higher with a given num amount
	void x_higher(const int & num);
	
	/// \brief
	/// y_higher makes y higher with num
	/// \details
	/// Makes the private int y higher with a given num amount
	void y_higher(const int & num);
	
	/// \brief
	/// x_set makes x num
	/// \details
	/// Makes the private int x the given num
	void x_set(const int & num);
	
	/// \brief
	/// y_set makes y num
	/// \details
	/// Makes the private int y the given num
	void y_set(const int & num);
	
	/// \brief
	/// get_bounce_x returns x from bounce
	/// \details
	/// Makes array int return its first value which is the x of the bounce trajectory. 
	int get_bounce_x();
	/// \brief
	/// get_bounce_y returns y from bounce
	/// \details
	/// Makes array int return its second value which is the y of the bounce trajectory.
	int get_bounce_y();
};

#endif // DRAWABLE_HPP

#include "ILI9481.hpp"
#include "wall.hpp"
#include "Peddle.hpp"
#include "Ball.hpp"

	
#define RESET_DRAWS 	LCD.fillRect(0,0,480,320,0x0);wall_1.draw();wall_2.draw();player_blue.draw();player_red.draw();
	
int main(int argc, char **argv){
	int white=0xFFFF;
	int black=0x0;
	auto a1 = hwlib::target::pin_out( hwlib::target::pins::d29 );
	auto a2 =hwlib::target::pin_out( hwlib::target::pins::d28 );
	auto a3 =hwlib::target::pin_out( hwlib::target::pins::d27 );
	auto a4 =hwlib::target::pin_out( hwlib::target::pins::d26 );
	auto a5 =hwlib::target::pin_out( hwlib::target::pins::d25 );
	auto a6 =hwlib::target::pin_out( hwlib::target::pins::d24 );
	auto a7 =hwlib::target::pin_out( hwlib::target::pins::d23 );
	auto a8 =hwlib::target::pin_out( hwlib::target::pins::d22 );
	
	auto a9 =hwlib::target::pin_out( hwlib::target::pins::d30 );
	auto a10 =hwlib::target::pin_out( hwlib::target::pins::d31 );
	auto a11 =hwlib::target::pin_out( hwlib::target::pins::d32 );
	auto a12 =hwlib::target::pin_out( hwlib::target::pins::d33 );
	auto a13 =hwlib::target::pin_out( hwlib::target::pins::d34 );
	auto a14 =hwlib::target::pin_out( hwlib::target::pins::d35 );
	auto a15 =hwlib::target::pin_out( hwlib::target::pins::d36 );
	auto a16 =hwlib::target::pin_out( hwlib::target::pins::d37 );
	
	auto ad =hwlib::target::pin_out( hwlib::target::pins::d38 );
	auto af =hwlib::target::pin_out( hwlib::target::pins::d39 );
	auto ag =hwlib::target::pin_out( hwlib::target::pins::d40 );
	auto ah =hwlib::target::pin_out( hwlib::target::pins::d41 );
	
	auto blue_but_up = hwlib::target::pin_in( hwlib::target::pins::d8);
	auto blue_but_down = hwlib::target::pin_in( hwlib::target::pins::d9);
	
	auto red_but_up = hwlib::target::pin_in( hwlib::target::pins::d10 );
	auto red_but_down = hwlib::target::pin_in( hwlib::target::pins::d11 );
	
	ILI9481 LCD( 480, 
	320,
	a1,
	a2,
	a3,
	a4,
	a5,
	a6,
	a7,
	a8,
	a9,
	a10,
	a11,
	a12,
	a13,
	a14,
	a15,
	a16,
	ad,
	af,
	ag,
	ah
	
	);
	LCD.init();
	LCD.setRotation();

	wall wall_1(LCD,0,0,479,10, white, std::array< int, 2>{1,-1},1);
	wall wall_2(LCD,0,309,479,319, white, std::array< int, 2>{1,-1},2);
	
	
	Peddle player_blue(LCD, 20, 150, 5,40,0x001F,11,308,blue_but_up,blue_but_down,0,4,std::array< int, 2>{-1,1});
	Peddle player_red(LCD, 459, 150, 5,40,0xF800,11,308,red_but_up,red_but_down,0,4,std::array< int, 2>{-1,1});
	Ball ball_1(LCD, 30, 160, 5,5,white,black,1,-1,std::array< int, 2>{1,1});
	RESET_DRAWS
	
	std::array< Drawable *, 3> objects = { &ball_1, &player_blue, &player_red };
	std::array< Drawable *, 5> interacts = { &ball_1, &player_red, &player_blue, &wall_1, &wall_2};
	
	enum state_t {GAME,LGOAL,RGOAL};
	state_t state = GAME;
	for(;;){
		switch(state){
			case GAME:
				for( auto & p : interacts ){ //p is eerst b dan left etc
					for( auto & other : interacts ){ //p
						p->interact( *other );
					} 
				}
				player_blue.buttons();
				player_red.buttons();
				hwlib::wait_ms(10);
				for( auto & p : objects ){
					p->update();
					
				}
				
				if(ball_1.check_goal_left()){state=LGOAL;}
				if(ball_1.check_goal_right()){state=RGOAL;}
				break;
			case LGOAL:
				ball_1.reset_goal_bool();
				LCD.fillRect(0,0,480,320,0x0);
				player_blue.setpos(20,150);
				player_red.setpos(459,150);
				player_blue.draw();
				player_red.draw();
				hwlib::cout<<"GOAL red!";
				wall_1.set_color(0xF800);
				wall_2.set_color(0xF800);
				wall_1.draw();
				wall_2.draw();
				hwlib::wait_ms(1000);
				wall_1.set_color(white);
				wall_2.set_color(white);
				wall_1.draw();
				wall_2.draw();
				hwlib::wait_ms(1000);
				ball_1.setpos(30,160);
				state=GAME;
				break;
			case RGOAL:
				ball_1.reset_goal_bool();
				LCD.fillRect(0,0,480,320,0x0);
				player_blue.setpos(20,150);
				player_red.setpos(459,150);
				player_blue.draw();
				player_red.draw();
				hwlib::cout<<"GOAL blue" ;
				wall_1.set_color(0x001F);
				wall_2.set_color(0x001F);
				wall_1.draw();
				wall_2.draw();
				hwlib::wait_ms(1000);
				wall_1.set_color(white);
				wall_2.set_color(white);
				wall_1.draw();
				wall_2.draw();
				hwlib::wait_ms(1000);
				ball_1.setpos(30,160);
				state=GAME;
				break;
		}
	}
}
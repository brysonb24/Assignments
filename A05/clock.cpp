/**
* Course: CMPS 2143 - OOP

* Purpose: Create a class 'Clock' that increments and decrements 

* @author Bryson Brown

* @version 1.1 11/2/2018

@github username: brysonb24 

*/

//libraries

#include <SFML/Graphics.hpp>

#include <iostream>

#include <string>

#include<cstdlib>

using namespace std;

////////////////////////////

// //

// Class //

// Definition //

// //

////////////////////////////

class Counter {

//Private variables in Counter class 

private:

sf::Font font;  

int fontSize;  //pixels in font- 80 

sf::Text time;

sf::Clock clock;  //SFML clock

sf::Time start;

sf::Time end;

sf::Time elapsed;

sf::Color textColor;  // Color of text

sf::Color backgroundColor;  // Background Color

sf::Vector2f clockPosition;  //Where to print clock

sf::RectangleShape Rectangle; //Back of counter

////////////////////////////

// //

// Class //

// Implementation //

// //

////////////////////////////

// public methods to work on private variables. 

public:

/**

* Method: Counter - Constructor 

* @param {int} s, e. start and end time

* @return void

*/

Counter(int s, int e) {

fontSize = 80;

start = sf::seconds(s);

end = sf::seconds(e);

elapsed = clock.getElapsedTime();

if(!font.loadFromFile("Segment7Standard.otf"))

{

cout << "Error loading font: Segment7Standard.otf";

}

Rectangle.setSize(sf::Vector2f(200.f, 100.f));

Rectangle.setFillColor(backgroundColor.Black);

time.setFont(font);

time.setString("0");

time.setCharacterSize(fontSize);

time.setFillColor(textColor.Red);

time.setStyle(sf::Text::Bold);

setCounter();  //calls function to center clock

}

/**

* Method: setTime

* sets our time for our counter. 

* @param {int} t time. 

* @return void

*/

void setTime(int t) {

string txt = to_string(t);

time.setString(txt);

}

/**

* Method: setCounter

* sets our counter for SFML window

* @param none

* @return void

*/

void setCounter() {

time.setPosition(sf::Vector2f(300.f, 300.f));

Rectangle.setPosition(sf::Vector2f(250.f, 300.f));

}

/**

* Method: drawCounter

* Draws out clock to SFML window 

* @param Our window 

* @return void

*/

void drawCounter(sf::RenderWindow &window) {

window.draw(Rectangle);

window.draw(time);

}

/**

* Method: incrementOrDecrement

* Decided whether to make incrment or decremented clock

* @param {int} s,e : start int, end int 

* @return void

*/

void incrementOrDecrement(int s, int e) {

elapsed = clock.getElapsedTime();

if (s < e)

setTime(elapsed.asSeconds());

else if (s > e)

setTime(start.asSeconds() - elapsed.asSeconds());

}

};

// End of Class Counter 

////////////////////////////

// //

// Main //

// Function //

// //

////////////////////////////

int main()

{

sf::RenderWindow window(sf::VideoMode(700, 700), "Increment Timer");

int start = 0;

int end = 20;

Counter C(start, end);

while (window.isOpen())

{

sf::Event event;

while (window.pollEvent(event))

{

if (event.type == sf::Event::Closed)

window.close();

}

C.incrementOrDecrement(start, end);

window.clear();

C.drawCounter(window);

window.display();

}

return 0;

}

#include <iostream>
#include <string>
#include <cmath>

#include <SFML/Config.hpp>
#include <SFML/Graphics.hpp>


class CelestialBody
{
private:
  std::string name;

  float mass;

  sf::Vector2f R;
  sf::Vector2f V;
  sf::Vector2f A;

  sf::RectangleShape shape;
  sf::Texture texture;

public:
  CelestialBody(std::string name)
  {
    this->name = name;
  };

  std::string getName()
  {
    return this->name;
  };

  void setName(std::string newName)
  {
    this->name = newName;
  };

  float getMass()
  {
    return this->mass;
  };

  void setMass(float newMass)
  {
    this->mass = newMass;
  };

  sf::Texture getTexture()
  {
    return this->texture;
  };

  void setTexture(sf::Texture newTexture)
  {
    this->texture = newTexture;
  };

  sf::RectangleShape getShape()
  {
    return this->shape;
  };

  void setShape(sf::RectangleShape newShape)
  {
    this->shape = newShape;
  };
};


int main()
{
  const sf::Color Black(0, 0, 0, 255);

  const float windowWidth = 800.f;
  const float windowHeight = 600.f;

  sf::ContextSettings settings;
  settings.antialiasingLevel = 10;

  std::string programName = "Planetary Solar System";

  sf::RenderWindow window(
    sf::VideoMode(windowWidth, windowHeight, 32),
    programName,
    sf::Style::Titlebar | sf::Style::Close,
    settings
  );

  window.setVerticalSyncEnabled(true);

  const float PI = 3.14159265358979;
  const float G = 4 * std::pow(PI, 2);
  const float time_step = 0.0027397260273972603; //1 dia
  const int steps = 10 * 365;                    // 10 años

  sf::RectangleShape auxShape;
  sf::Texture auxTexture;

  // El Sol
  CelestialBody Sun("Sun");
  Sun.setMass(1);
  auxTexture = Sun.getTexture();

  if (!auxTexture.loadFromFile("images/sun.png"))
  {
    return EXIT_FAILURE;
  }

  auxTexture.setSmooth(true);
  auxTexture.setRepeated(false);
  Sun.setTexture(auxTexture);

  auxShape.setSize(sf::Vector2f(60, 60));
  auxShape.setOrigin(sf::Vector2f(30,30));
  auxShape.setPosition(0.5 * windowWidth, 0.5 * windowHeight);
  auxShape.setTexture(&auxTexture);
  auxShape.setTextureRect(sf::IntRect(0, 0, 60, 60));
  Sun.setShape(auxShape);

  while (window.isOpen())
  {
    // Recivimos todos los eventos en el bucle de la animacion
    sf::Event event;

    while (window.pollEvent(event))
    {
      // "Window closed" o "ESC": exit (salir)
      if ((event.type == sf::Event::Closed) ||
          ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape)))
      {
        window.close();
        break;
      }
    }

    window.clear(Black);
    window.draw(Sun.getShape());
  }

  /*
  if(Sun.loadTextureFromFile("images/sun.png")) {
    return EXIT_FAILURE;
  }

  sunTexture.setSmooth(true);
  sunTexture.setRepeated(false);

  float sunRadius = 30;
  sf::CircleShape sun(sunRadius);
  sun.setFillColor(Amber);
  sun.setOrigin(sunRadius, sunRadius);
  sun.setPosition(0.5 * windowWidth, 0.5 * windowHeight);
  sun.setTexture(&sunTexture);
  sun.setTextureRect(sf::IntRect(0, 0, sunRadius, sunRadius));



  CelestialBody planet("Mercury");

  std::cout << planet.getName() << std::endl;

  planet.setName("Mars");

  std::cout << planet.getName() << std::endl;
  */
    return 0;
}

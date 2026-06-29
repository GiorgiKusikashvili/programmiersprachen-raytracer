#define DOCTEST_CONFIG_IMPLEMENT
#define GLM_ENABLE_EXPERIMENTAL
#include <doctest.h>
#include <iostream>
#include <glm/vec3.hpp>

#include "sphere.h"
#include "box.h"
#include "color.hpp"
#include "hitpoint.h"

#include <glm/glm.hpp>
#include <glm/gtx/intersect.hpp>

TEST_CASE("Aufgabe 6.5: Konsolenausgabe von Sphere und Box")
{
  std::cout << "\n========================================\n";
  std::cout << "Aufgabe 6.5: Konsolenausgabe startet...\n";
  std::cout << "========================================\n";

  // 1. Instanziieren einer Kugel (Sphere)
  glm::vec3 sphere_center{0.0f, 0.0f, 0.0f};
  float sphere_radius = 3.5f;
  Color red{1.0f, 0.0f, 0.0f};
  Sphere meine_kugel{sphere_center, sphere_radius, "Kugel_6.5", red};

  // 2. Instanziieren einer Box
  glm::vec3 box_min{-1.0f, -1.0f, -1.0f};
  glm::vec3 box_max{1.0f, 1.0f, 1.0f};
  Color blue{0.0f, 0.0f, 1.0f};
  Box meine_box{box_min, box_max, "Box_6.5", blue};

  // 3. Ausgabe auf der Konsole mithilfe des Out-Stream-Operators <<
  std::cout << meine_kugel << std::endl;
  std::cout << meine_box << std::endl;

  std::cout << "========================================\n\n";

  // doctest-Check,
  CHECK(true);
  /*Das Wird ausgegenem
========================================
Aufgabe 6.5: Konsolenausgabe startet...
========================================
Name : Kugel_6.5, Farbe: (1,0,0) --------->Das ist die Methode von Basisklasse also das hat jeder Children-klasse
, Typ: Kugel, Zentrum: (0,0,0), Radius: 3.5--------->Das ist überschriebene Methoden von Children-klasse Sphere
Name : Box_6.5, Farbe: (0,0,1)
, Typ: Box, Min: (-1,-1,-1), Max: (1,1,1)--------->Das ist überschriebene Methoden von Children-klasse Box
========================================*/
}
/*
TEST_CASE("intersect_ray_sphere")
{
  // Ray
  glm::vec3 ray_origin{0.0f, 0.0f, 0.0f};
  // ray direction has to be normalized !
  // you can use:
  // v = glm::normalize(some_vector)
  glm::vec3 ray_direction{0.0f, 0.0f, 1.0f};
  // Sphere
  glm::vec3 sphere_center{0.0f ,0.0f, 5.0f};
  float sphere_radius{1.0f};
  float distance = 0.0f;
  auto result = glm::intersectRaySphere(
  ray_origin, ray_direction,
  sphere_center,
  sphere_radius * sphere_radius, // squared radius !!!
  distance);
  REQUIRE(distance == doctest::Approx(4.0f));
}*/

TEST_CASE("intersect_ray_sphere")
{
  // 1. Test mit den Original-Werten aus der Aufgabenstellung [cite: 63, 69]
  glm::vec3 ray_origin{0.0f, 0.0f, 0.0f};
  glm::vec3 ray_direction{0.0f, 0.0f, 1.0f};

  glm::vec3 sphere_center{0.0f, 0.0f, 5.0f};
  float sphere_radius{1.0f};

  float distance = 0.0f;

  // GLM-Direkttest aus der Aufgabe
  bool result = glm::intersectRaySphere(
      ray_origin, ray_direction,
      sphere_center,
      sphere_radius * sphere_radius, // Quadrierter Radius!
      distance
  );

  REQUIRE(result == true);
  REQUIRE(distance == doctest::Approx(4.0f));

  // 2. Test unserer eigenen neuen Methode mit den DTOs
  Color green{0.0f, 1.0f, 0.0f};
  Sphere test_sphere{sphere_center, sphere_radius, "Kugel_6.6", green};
  Ray test_ray{ray_origin, ray_direction};

  HitPoint hit = test_sphere.intersect(test_ray);

  // Validierung aller geforderten Attribute
  REQUIRE(hit.intersected == true);
  REQUIRE(hit.distance == doctest::Approx(4.0f));
  REQUIRE(hit.name == "Kugel_6.6");
  REQUIRE(hit.point.z == doctest::Approx(4.0f)); // Strahl trifft bei z=4 
  REQUIRE(hit.direction.z == doctest::Approx(1.0f));
}

int main(int argc, char *argv[])
{
  doctest::Context ctx;
  ctx.applyCommandLine(argc, argv);
  return ctx.run();
}

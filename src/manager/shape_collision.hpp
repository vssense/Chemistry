#include "shape_manager.hpp"

bool DetectCollisionCC(Circle* lhs, Circle* rhs);
void ResponseCollisionCC(ShapeManager* manager, Circle* first, Circle* second);
void ResponseCollisionCS(ShapeManager* manager, Circle* circle, Square* square);
void ResponseCollisionSC(ShapeManager* manager, Square* square, Circle* circle);
void ResponseCollisionSS(ShapeManager* manager, Square* first, Square* second);

#include "shape_manager.hpp"

bool DetectCollisionCC(Circle* lhs, Circle* rhs);
void ResponseCollisionCC(CollisionInfo& info);
void ResponseCollisionCS(CollisionInfo& info);
void ResponseCollisionSC(CollisionInfo& info);
void ResponseCollisionSS(CollisionInfo& info);

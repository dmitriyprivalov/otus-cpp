#pragma once

#include "astnode.hpp"

class Div : public ASTNode {
  public:

    Div(ASTNode *lhs, ASTNode *rhs) : ASTNode("/", lhs, rhs) {}

    Div(const ASTNode &other) = delete;

    Div &operator=(const ASTNode &other) = delete;

    ~Div() {}
};
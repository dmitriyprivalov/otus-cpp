#pragma once

#include "astnode.hpp"

class Sub : public ASTNode {
  public:

    Sub(ASTNode *lhs, ASTNode *rhs) : ASTNode("-", lhs, rhs) {}

    Sub(const ASTNode &other) = delete;

    Sub &operator=(const ASTNode &other) = delete;

    ~Sub() {}
};
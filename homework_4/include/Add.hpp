#pragma once

#include "astnode.hpp"

class Add : public ASTNode {
  public:

    Add(ASTNode *lhs, ASTNode *rhs) : ASTNode("+", lhs, rhs) {}

    Add(const ASTNode &other) = delete;

    Add &operator=(const ASTNode &other) = delete;

    ~Add() {}
};
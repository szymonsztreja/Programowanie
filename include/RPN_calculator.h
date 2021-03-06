#ifndef STUDENT_RPN_CALCULATOR_H
#define STUDENT_RPN_CALCULATOR_H

#include <memory>
#include <queue>
#include <stack>


namespace student { namespace rpn_calculator {
using stack_type = std::stack<double>;

struct Element {
    virtual auto evaluate(stack_type&) const -> void = 0;   // funkcja struktury
    virtual ~Element();                                     // destruktor
};

struct Literal : public Element {                           // literal dziedziczy po klasie element
    double const value{0.0};

    auto evaluate(stack_type&) const -> void override;      // stack_type = stack

    Literal(double const);                                  // konstruktor
};

struct Print : public Element {                             // ^^
    auto evaluate(stack_type&) const -> void override;
};

struct Addition : public Element {                          // ^^
    auto evaluate(stack_type&) const -> void override;
};

struct Substraction : public Element {                          // ^^
    auto evaluate(stack_type&) const -> void override;
};

struct Multiplication : public Element {                         
    auto evaluate(stack_type&) const -> void override;
};

struct Division : public Element {                         
    auto evaluate(stack_type&) const -> void override;
};

struct Division_WR : public Element {                         
    auto evaluate(stack_type&) const -> void override;
};

struct Modulo : public Element {                         
    auto evaluate(stack_type&) const -> void override;
};

struct Square : public Element {                         
    auto evaluate(stack_type&) const -> void override;
};

struct Square_root : public Element {                         
    auto evaluate(stack_type&) const -> void override;
};

struct Delta : public Element {                         
    auto evaluate(stack_type&) const -> void override;
};


struct Calculator {
    stack_type stack;
    std::queue<std::unique_ptr<Element>> ops;

    /*
     * Schedule operation for evaluation.
     */
    auto push(std::unique_ptr<Element>) -> void;

    /*
     * Convert string to element and push it on the queue of operations to
     * perform.
     */
    auto push(std::string) -> void;

    /*
     * Evaluate scheduled operations.
     */
    auto evaluate() -> void;

    Calculator() = default;
    Calculator(stack_type);
};
}}  // namespace student::rpn_calculator

#endif

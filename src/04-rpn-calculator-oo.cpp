/*
 * A reverse-polish notation calculator.
 */

#include <RPN_calculator.h>

#include <algorithm>
#include <iostream>
#include <iterator>
#include <stack>
#include <stdexcept>
#include <string>
#include <vector>
#include <cmath>


static auto pop_top(std::stack<double>& stack) -> double
{
    if (stack.empty()) {                                    //sprawdza czy stack jest pusty                                    
        throw std::logic_error{"empty stack"};              // obsługa błędu
    }
    auto element = std::move(stack.top());                  // przypisuje element wartość na górze stacka 
    stack.pop();                                            // usuwa doubla ze szczytu stacka
    return element;                                        
}


namespace student { namespace rpn_calculator {
Element::~Element()
{}

Literal::Literal(double const v) : value{v}                 // value dziedziczy po literal
{}

auto Literal::evaluate(stack_type& stack) const -> void     
{
    stack.push(value);                                      // wyrzuca value na samą górę stacka
}

auto Print::evaluate(stack_type& stack) const -> void       // wyświetla szczyt stacka
{
    std::cout << stack.top() << "\n";                       
}

auto Addition::evaluate(stack_type& stack) const -> void
{
    if (stack.size() < 2) {
        throw std::logic_error{"not enough operands for +"};
    }
    auto const b = pop_top(stack);
    auto const a = pop_top(stack);
    stack.push(a + b);
}
auto Substraction::evaluate(stack_type& stack) const -> void
{
    if (stack.size() < 2) {
        throw std::logic_error{"not enough operands for -"};
    }
    auto const b = pop_top(stack);
    auto const a = pop_top(stack);
    stack.push(a - b);
}

auto Multiplication::evaluate(stack_type& stack) const -> void
{
    if (stack.size() < 2) {
        throw std::logic_error{"not enough operands for -"};
    }
    auto const b = pop_top(stack);
    auto const a = pop_top(stack);
    stack.push(a * b);
}

auto Division::evaluate(stack_type& stack) const -> void
{
    if (stack.size() < 2) {
        throw std::logic_error{"not enough operands for -"};
    }
    auto const b = pop_top(stack);
    auto const a = pop_top(stack);
    stack.push(a / b);
}

auto Division_WR::evaluate(stack_type& stack) const -> void     // without remainders
{
    if (stack.size() < 2) {
        throw std::logic_error{"not enough operands for -"};
    }
    auto const b = pop_top(stack);
    auto const a = pop_top(stack);
    stack.push( (int)(a / b) );
}

auto Modulo::evaluate(stack_type& stack) const -> void
{
    if (stack.size() < 2) {
        throw std::logic_error{"not enough operands for -"};
    }
    auto const b = pop_top(stack);
    auto const a = pop_top(stack);
    stack.push( (int)a % (int)b );
}

auto Square::evaluate(stack_type& stack) const -> void
{
    if (stack.size() < 2) {
        throw std::logic_error{"not enough operands for -"};
    }

    auto const a = pop_top(stack);
    stack.push(a * a);
}

auto Delta::evaluate(stack_type& stack) const -> void
{
    if (stack.size() < 3) {
        throw std::logic_error{"not enough operands for -"};
    }
    auto const b = pop_top(stack);
    auto const a = pop_top(stack);
    auto const c = pop_top(stack);
    stack.push( b*b-4*a*c );
}

auto Square_root::evaluate(stack_type& stack) const -> void
{
    if (stack.size() < 2) {
        throw std::logic_error{"not enough operands for -"};
    }
    auto const a = pop_top(stack);
    stack.push( sqrt(a) );
}
  
Calculator::Calculator(stack_type s) : stack{std::move(s)}
{}

auto Calculator::push(std::unique_ptr<Element> op) -> void
{
    ops.push(std::move(op));
}

auto Calculator::evaluate() -> void
{
    while (not ops.empty()) {
        auto op = std::move(ops.front());
        ops.pop();

        op->evaluate(stack);
    }
}
}}  // namespace student::rpn_calculator


auto make_args(int argc, char* argv[], bool const with_exec = false)
    -> std::vector<std::string>
{
    auto args         = std::vector<std::string>{};
    auto const offset = static_cast<size_t>(not with_exec);
    std::copy_n(argv + offset, argc - offset, std::back_inserter(args));
    return args;
}

auto main(int argc, char* argv[]) -> int
{
    using student::rpn_calculator::Calculator;
    auto calculator = Calculator{};

    for (auto const& each : make_args(argc, argv)) {
        try {
            using student::rpn_calculator::Substraction;
            using student::rpn_calculator::Addition;
            using student::rpn_calculator::Multiplication;
            using student::rpn_calculator::Division;
            using student::rpn_calculator::Division_WR;
            using student::rpn_calculator::Square;
            using student::rpn_calculator::Square_root;
            using student::rpn_calculator::Modulo;
            using student::rpn_calculator::Delta;
            using student::rpn_calculator::Literal;
            using student::rpn_calculator::Print;            

            if (each == "p") {
                calculator.push(std::make_unique<Print>());
            } else if (each == "+") {
                calculator.push(std::make_unique<Addition>());
            } else if (each == "-") {
                calculator.push(std::make_unique<Substraction>());
            } else if (each == "*") {
                calculator.push(std::make_unique<Multiplication>());
            } else if (each == "/") {
                calculator.push(std::make_unique<Division>());
            } else if (each == "//") {
                calculator.push(std::make_unique<Division_WR>());
            } else if (each == "%") {
                calculator.push(std::make_unique<Modulo>());
            } else if (each == "**") {
                calculator.push(std::make_unique<Square>());
            } else if (each == "sqrt") {
                calculator.push(std::make_unique<Square_root>());
            } else if (each == "qe") {
                calculator.push(std::make_unique<Delta>());
            } else {
                calculator.push(std::make_unique<Literal>(std::stod(each)));
            }
        } catch (std::logic_error const& e) {
            std::cerr << "error: " << each << ": " << e.what() << "\n";
            return 1;
        }
    }

    try {
        calculator.evaluate();
    } catch (std::logic_error const& e) {
        std::cerr << "error: during evaluation: " << e.what() << "\n";
    }

    return 0;
}

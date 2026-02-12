# Shopping Cart System

A simple command-line shopping cart application written in C++ as part of Programming Fundamentals course (1st Semester).

## Features

- **Add Items**: Add products with names and prices to your cart
- **Remove Items**: Remove unwanted items from your cart
- **Display Cart**: View all items currently in your cart
- **Checkout**: Calculate total with automatic 10% discount and 7% tax
- **Cart Limit**: Maximum 10 items per cart

## How to Compile

```bash
g++ shopping_cart.cpp -o shopping_cart
```

## How to Run

```bash
./shopping_cart
```

## Menu Options

1. **Add Item** - Enter item name and price
2. **Remove Item** - Enter item name to remove
3. **Display Cart** - View all cart items
4. **Calculate Total and Checkout** - See final price with discount and tax
5. **Exit** - Close the program

## Pricing Details

- **Discount**: 10% off subtotal
- **Tax**: 7% on discounted amount
- **Formula**: `Final Price = (Subtotal - 10% Discount) + 7% Tax`

## Requirements

- C++ compiler (g++, clang++, or similar)
- C++11 or higher

## Example Usage

```
1. Add "Apple" for $2.50
2. Add "Banana" for $1.50
3. Display cart to see items
4. Checkout to see total: $4.00 → $3.60 (after discount) → $3.85 (after tax)
```

## Notes

- Item names are case-sensitive when removing
- Cart has a maximum capacity of 10 items
- Prices must be entered as numbers (e.g., 5.99)

## Programming Concepts Demonstrated

This project demonstrates fundamental programming concepts including:

- **Arrays**: Storing multiple items and prices in parallel arrays
- **Functions**: Modular code design with function prototypes and definitions
- **Loops**: `while` loop for menu, `for` loops for iteration
- **Conditionals**: `if/else` statements and `switch-case` for menu handling
- **Pass by Reference**: Using `&` to modify variables in functions
- **Constants**: Using `const` for fixed values (tax rate, discount rate)
- **Input/Output**: User interaction with `cin`, `cout`, and `getline()`
- **String Handling**: Working with string arrays and comparisons

## Course Information

**Course**: Programming Fundamentals  
**Semester**: 1st Semester  
**Language**: C++

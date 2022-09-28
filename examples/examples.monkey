let age = 1;
let name = "Monkey";
let result = 10 * (20 / 2);

let myArray = [ 1, 2, 3, 4, 5 ];

let thorsten = {"name" : "Thorsten", "age" : 28};

myArray[0]           // => 1
    thorsten["name"] // => "Thorsten"

    // bind functions to names
    let add = fn(a, b) {
  return a + b;
};

// implicit return values
let add = fn(a, b) { a + b; };

// call function
add(1, 2);

// fibonnaci function
let fibonnaci = fn(x) {
  if (x == 0) {
    0
  } else {
    if (x == 1) {
      1
    } else {
      fibonnaci(x - 1) + fibonnaci(x - 2);
    }
  }
};

// higher order functions (functions that take functions as arguments)
let twice = fn(f, x) {
    return f(f(x));
};

let addTwo = fn(x) {
    return x + 2;
};

twice(addTwo, 2); // => 6

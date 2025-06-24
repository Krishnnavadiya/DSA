/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */

// 2665. Counter II

var createCounter = function (init) {
  let counter = init;
  return {
    increment: () => {
      counter++;
      return counter;
    },
    reset: () => {
      counter = init;
      return counter;
    },
    decrement: () => {
      counter--;
      return counter;
    },
  };
};

const counter = createCounter(5);
console.log(counter.increment()); // 6
console.log(counter.reset()); // 5
console.log(counter.decrement()); // 4

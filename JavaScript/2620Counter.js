/**
 * @param {number} n
 * @return {Function} counter
 */

// 2620. Counter

var createCounter = function (n) {
  return () => n++;
};

const counter = createCounter(10);
console.log(counter()); // 10
console.log(counter()); // 11
console.log(counter()); // 12

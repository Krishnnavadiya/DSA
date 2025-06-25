/**
 * @param {Function} fn
 * @return {Function}
 */

// 2666. Allow One Function Call

var once = function (fn) {
  var count = true;
  return function (...args) {
    if (count) {
      count = false;
      return fn(...args);
    }
    return undefined;
  };
};

let fn = (a, b, c) => a + b + c;
let onceFn = once(fn);

console.log(onceFn(1, 2, 3)); // 6
console.log(onceFn(2, 3, 6)); // returns undefined without calling fn

/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */

// 2635. Apply Transform Over Each Element in Array

var map = function (arr, fn) {
  const result = [];
  for (let i = 0; i < arr.length; i++) {
    result.push(fn(arr[i], i));
  }
  return result;
};

function plusone(n) {
  return n + 1;
}

function plusI(n, i) {
  return n + i;
}

function constant() {
  return 42;
}

console.log(map([1, 2, 3], (n) => n + 1)); // [2, 3, 4]
console.log(map([1, 2, 3], (n, i) => n + i)); // [1, 3, 5]
console.log(map([10, 20, 30], () => 42)); // [42, 42, 42]

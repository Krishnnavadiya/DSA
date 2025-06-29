/**
 * @param {number[]} nums
 * @param {Function} fn
 * @param {number} init
 * @return {number}
 */

// 2626. Array Reduce Transformation

var reduce = function (nums, fn, init) {
  let res = init;
  for (let i = 0; i < nums.length; i++) {
    res = fn(res, nums[i]);
  }
  return res;
};



function sum(acc, curr) {
    return acc + curr;
}

function sumSquare(acc, curr) {
    return acc + curr * curr;
}

console.log(reduce([1, 2, 3, 4], sum, 0));        // Output: 10
console.log(reduce([1, 2, 3, 4], sumSquare, 100)); // Output: 130
console.log(reduce([], sum, 25));                // Output: 25
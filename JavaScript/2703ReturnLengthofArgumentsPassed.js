/**
 * @param {...(null|boolean|number|string|Array|Object)} args
 * @return {number}
 */

// 2703. Return Length of Arguments Passed

var argumentsLength = function (...args) {
  return args.length;
  /*
  let count = 0;
  for (const i of args) {
    count++;
  }
  return count;
  */
};

console.log(argumentsLength(1, 2, 3)); // 3

/**
 * @param {Array} arr
 * @param {Function} fn
 * @return {Array}
 */

// 2724. Sort By

var sortBy = function (arr, fn) {
  return arr.sort((a, b) => fn(a) - fn(b));
};

console.log(
  sortBy(
    [
      [3, 4],
      [5, 2],
      [10, 1],
    ],
    (x) => x[1]
  )
);

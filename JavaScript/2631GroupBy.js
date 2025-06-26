/**
 * @param {Function} fn
 * @return {Object}
 */

// 2631. Group By

Array.prototype.groupBy = function (fn) {
  const grouped = {};

  for (let item of this) {
    const key = fn(item);
    if (!grouped.hasOwnProperty(key)) {
      grouped[key] = [];
    }
    grouped[key].push(item);
  }

  return grouped;
};

console.log([1, 2, 3].groupBy(String)); // {"1":[1],"2":[2],"3":[3]}

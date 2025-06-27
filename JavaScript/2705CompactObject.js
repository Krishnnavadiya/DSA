/**
 * @param {Object|Array} obj
 * @return {Object|Array}
 */

// 2705. Compact Object

var compactObject = function (obj) {
  if (Array.isArray(obj)) {
    return obj
      .map(compactObject) // recursively visit items
      .filter(Boolean); // remove falsy elements
  } else if (typeof obj === "object" && obj !== null) {
    const result = {};
    for (const key in obj) {
      const value = compactObject(obj[key]);
      if (Boolean(value)) {
        result[key] = value;
      }
    }
    return result;
  } else {
    return obj;
  }
};

console.log(compactObject([null, 0, false, 1])); // Output: [1]

console.log(compactObject({ a: null, b: [false, 1] })); // Output: { b: [1] }

console.log(compactObject([null, 0, 5, [0], [false, 16]])); // Output: [5, [], [16]]

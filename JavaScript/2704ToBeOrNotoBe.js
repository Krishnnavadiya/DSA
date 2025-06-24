/**
 * @param {string} val
 * @return {Object}
 */

// 2704. To Be Or Not To Be

var expect = function (val) {
  return {
    toBe: (other) => {
      if (val === other) return true;
      throw new Error("Not Equal");
    },
    notToBe: (other) => {
      if (val !== other) return true;
      throw new Error("Equal");
    },
  };
};

try {
  console.log(expect(5).toBe(5));        // true
} catch (e) {
  console.log(e.message);
}

try {
  console.log(expect(5).notToBe(5));     // throws Error: "Equal"
} catch (e) {
  console.log(e.message);               // prints "Equal"
}

// console.log(expect(5).toBe(5)); // true
// console.log(expect(5).notToBe(5)); // throws "Equal"

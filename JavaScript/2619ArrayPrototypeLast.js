/**
 * @return {null|boolean|number|string|Array|Object}
 */

// 2619. Array Prototype Last

Array.prototype.last = function () {
  //   if (this.length != 0) {
  //     return this[this.length - 1];
  //   }
  //   return -1;

  return this.length != 0 ? this[this.length - 1] : -1;
};

const arr = [1, 2, 3];
console.log(arr.last()); // 3

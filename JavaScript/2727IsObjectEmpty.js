/**
 * @param {Object|Array} obj
 * @return {boolean}
 */

// 2727. Is Object Empty

var isEmpty = function (obj) {
    let count = 0;
    for (let ket in obj) {
        count++;
    }
    if (count === 0) {
        return true;
    }
    return false;
};

console.log(isEmpty({})); // true
console.log(isEmpty({ a: 1 })); // false
console.log(isEmpty([])); // true
console.log(isEmpty([1, 2, 3])); // false
console.log(isEmpty("")); // true (because "" has no enumerable properties)
console.log(isEmpty(0)); // true (0 has no enumerable properties)
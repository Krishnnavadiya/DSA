/**
 * @param {Array} arr
 * @param {number} depth
 * @return {Array}
 */

// 2625. Flatten Deeply Nested Array

var flat = function (arr, n) {
    const result = [];

    const dfs = (array, depth) => {
        for (const el of array) {
            if (Array.isArray(el) && depth < n) {
                dfs(el, depth + 1);
            } else {
                result.push(el);
            }
        }
    };
    dfs(arr, 0);
    return result;
};

console.log(flat([1, 2, 3, [4, 5], [6, [7, 8]], 9], 1));
// Output: [1, 2, 3, 4, 5, 6, [7, 8], 9]

console.log(flat([[1], [2, [3, [4]]]], 2));
// Output: [1, 2, 3, [4]]
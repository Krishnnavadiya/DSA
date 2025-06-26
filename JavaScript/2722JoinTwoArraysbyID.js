/**
 * @param {Array} arr1
 * @param {Array} arr2
 * @return {Array}
 */

// 2722. Join Two Arrays by ID

var join = function (arr1, arr2) {
    const combinedArray = arr1.concat(arr2);
    const merged = {};

    combinedArray.forEach((obj) => {
        const id = obj.id;
        if (!merged[id]) {
            merged[id] = { ...obj };
        } else {
            merged[id] = { ...merged[id], ...obj };
        }
    });

    const joinedArray = Object.values(merged);
    joinedArray.sort((a, b) => a.id - b.id);

    return joinedArray;
};

console.log(join([{"id": 1,"x": 1},{"id": 2,"x": 9}],[{"id": 3,"x": 5}]));
/**
 * @param {Array<Function>} functions
 * @return {Promise<any>}
 */
var promiseAll = function (functions) {
    return new Promise((resolve, reject) => {
        const results = [];
        let resolvedCount = 0;
        const n = functions.length;

        functions.forEach((fn, i) => {
            fn()
                .then(res => {
                    results[i] = res;
                    resolvedCount++;
                    if (resolvedCount === n) {
                        resolve(results);
                    }
                })
                .catch(err => {
                    reject(err);
                });
        });
    });
};


const promise = promiseAll([() => new Promise(res => res(42))])
promise.then(console.log); // [42]

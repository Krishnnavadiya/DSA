// 2622. Cache With Time Limit

var TimeLimitedCache = function () {
  this.cache = new Map();
};

/**
 * @param {number} key
 * @param {number} value
 * @param {number} duration time until expiration in ms
 * @return {boolean} if un-expired key already existed
 */
TimeLimitedCache.prototype.set = function (key, value, duration) {
  const existsAndNotExpired =
    this.cache.has(key) && this.cache.get(key).expire > Date.now();

  const expireTime = Date.now() + duration;
  this.cache.set(key, { value, expire: expireTime });

  return existsAndNotExpired;
};

/**
 * @param {number} key
 * @return {number} value associated with key
 */
TimeLimitedCache.prototype.get = function (key) {
  if (this.cache.has(key)) {
    const { value, expire } = this.cache.get(key);
    if (Date.now() < expire) {
      return value;
    } else {
      this.cache.delete(key);
    }
  }
  return -1;
};

/**
 * @return {number} count of non-expired keys
 */
TimeLimitedCache.prototype.count = function () {
  const now = Date.now();
  let validCount = 0;

  for (const [key, { expire }] of this.cache.entries()) {
    if (now < expire) {
      validCount++;
    } else {
      this.cache.delete(key);
    }
  }

  return validCount;
};

const timeLimitedCache = new TimeLimitedCache();
console.log(timeLimitedCache.set(1, 42, 1000)); // false
console.log(timeLimitedCache.get(1)); // 42
console.log(timeLimitedCache.count()); // 1

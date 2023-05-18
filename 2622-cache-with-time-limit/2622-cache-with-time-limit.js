var TimeLimitedCache = function () {
  this.cache = {};
};

/**
 * @param {number} key
 * @param {number} value
 * @param {number} time until expiration in ms
 * @return {boolean} if un-expired key already existed
 */
TimeLimitedCache.prototype.set = function (key, value, duration) {
  let currTime = new Date();
  currTime.setTime(currTime.getTime() + duration);
    
  if (this.cache[key]) {
    this.cache[key] = { value: value, expired_at: currTime.getTime() };
    return true;
  } else {
    this.cache[key] = { value: value, expired_at: currTime.getTime() };
    return false;
  }
};

/**
 * @param {number} key
 * @return {number} value associated with key
 */
TimeLimitedCache.prototype.get = function (key) {
  key = key.toString();
  if (this.cache[key] && this.cache[key].expired_at >= new Date().getTime()) {
      return this.cache[key].value;
  }  
  return -1;
};

/**
 * @return {number} count of non-expired keys
 */
TimeLimitedCache.prototype.count = function () {
  let time = new Date().getTime();
  let el = Object.keys(this.cache).filter((key) => {
    if (this.cache[key].expired_at >= time) return true;
    else return false;
  });
  return el.length;
};

/**
 * Your TimeLimitedCache object will be instantiated and called as such:
 * var obj = new TimeLimitedCache()
 * obj.set(1, 42, 1000); // false
 * obj.get(1) // 42
 * obj.count() // 1
 */

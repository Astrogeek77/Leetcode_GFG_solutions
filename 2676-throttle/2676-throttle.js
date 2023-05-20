/**
 * @param {Function} fn
 * @param {number} t
 * @return {Function}
 */
var throttle = function (fn, t) {
  var prev = -1;
  var time = null;

  return function (...args) {
    var currTime = Date.now();
    if (currTime - prev >= t) {
      fn(...args);
      prev = currTime;
    } else {
      clearTimeout(time);
      time = setTimeout(() => {
        fn(...args);
        time = null;
        prev += t;
      }, prev + t - currTime);
    }
  };
};

/**
 * const throttled = throttle(console.log, 100);
 * throttled("log"); // logged immediately.
 * throttled("log"); // logged at t=100ms.
 */

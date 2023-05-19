/**
 * @param {Function} fn
 * @param {number} t milliseconds
 * @return {Function}
 */
var debounce = function (fn, t) {
  let timer; // to store previous setTimeout key
  return function (...args) {
    clearTimeout(timer); // clear any previously existing timer
    timer = setTimeout(() => {
      // start a new timer to call after `t` time
      fn(...args); // call the function
    }, t);
  };
};
/**
 * const log = debounce(console.log, 100);
 * log('Hello'); // cancelled
 * log('Hello'); // cancelled
 * log('Hello'); // Logged at t=100ms
 */

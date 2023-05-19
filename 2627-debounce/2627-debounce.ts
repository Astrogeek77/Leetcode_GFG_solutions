type F = (...p: any[]) => any

function debounce(fn: F, t: number): F {
  let timer: ReturnType<typeof setTimeout>; // to store previous setTimeout key
  return function (...args) {
    clearTimeout(timer); // clear any previously existing timer
    timer = setTimeout(() => {
      // start a new timer to call after `t` time
        // console.log(typeof(timer))
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
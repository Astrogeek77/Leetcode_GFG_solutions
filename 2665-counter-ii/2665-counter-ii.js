/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */
const createCounter = (init) => {
  let cnt = init;

  return {
    increment: () => {
      return ++cnt;
    },

    decrement: () => {
      return --cnt;
    },

    reset: () => {
      return cnt = init;
    }
  };
}

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */
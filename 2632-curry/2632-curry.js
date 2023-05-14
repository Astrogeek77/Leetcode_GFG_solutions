/**
 * @param {Function} fn
 * @return {Function}
 */
var curry = function(fn) {
    return function curried(...args) {
        
        if(args.length >= fn.length) return fn(...args)
        else {
            return (...Nargs) => curried(...args, ...Nargs)
        }
    };
};

/**
 * function sum(a, b) { return a + b; }
 * const csum = curry(sum);
 * csum(1)(2) // 3
 */

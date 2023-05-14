function curry(fn: Function): Function {
     return function curried(...args) {
        
        if(args.length >= fn.length) return fn(...args)
        else {
            return (...Nargs): Function => curried(...args, ...Nargs)
        }
    };
};

/**
 * function sum(a, b) { return a + b; }
 * const csum = curry(sum);
 * csum(1)(2) // 3
 */

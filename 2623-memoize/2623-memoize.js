/**
 * @param {Function} fn
 */
function memoize(fn) {
    const memo = {}
    return function(...args) {
        const params = JSON.stringify(args)
        
        if (params in memo)
            return memo[params]
        
        const result = fn(...args)
        memo[params] = result
        return result
    }
}


/** 
 * let callCount = 0;
 * const memoizedFn = memoize(function (a, b) {
 *	 callCount += 1;
 *   return a + b;
 * })
 * memoizedFn(2, 3) // 5
 * memoizedFn(2, 3) // 5
 * console.log(callCount) // 1 
 */
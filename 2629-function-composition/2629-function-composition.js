/**
 * @param {Function[]} functions
 * @return {Function}
 */
var compose = function(functions) {
	
    // check for empty functions array
    if(functions.length == 0) {
        return function(x) {return x}
    }

    // we will use reduceRight to resolve fn from right to left
    return functions.reduceRight((prevFn, nextFn) => {
        return function(x) {
            return nextFn(prevFn(x))
        }
    })
};

/**
 * const fn = compose([x => x + 1, x => 2 * x])
 * fn(4) // 9
 */
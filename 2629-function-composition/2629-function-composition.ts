type F = (x: number) => number;

function compose(functions: F[]): F {
	 // check for empty functions array
    if(functions.length == 0) {
        return function(x: number) {return x}
    }

    // we will use reduceRight to resolve fn from right to left
    return functions.reduceRight((prevFn, nextFn) => {
        return function(x: number) {
            return nextFn(prevFn(x))
        }
    })
};

/**
 * const fn = compose([x => x + 1, x => 2 * x])
 * fn(4) // 9
 */
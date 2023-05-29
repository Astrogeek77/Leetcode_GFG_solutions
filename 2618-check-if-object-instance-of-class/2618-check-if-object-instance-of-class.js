/**
 * @param {Object} object
 * @param {Function} classFunction
 * @return {boolean}
 */
var checkIfInstanceOf = function(obj, classFunction) {
    if (obj == null || typeof classFunction !== 'function' ) return false;
    return Object(obj) instanceof classFunction;
};

/**
 * checkIfInstanceOf(new Date(), Date); // true
 */
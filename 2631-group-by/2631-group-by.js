/**
 * @param {Function} fn
 * @return {Array}
 */
Array.prototype.groupBy = function(fn) {
     return this.reduce((grouped,item)=> (grouped[fn(item)] ||= []).push(item) && grouped,{})
};

/**
 * [1,2,3].groupBy(String) // {"1":[1],"2":[2],"3":[3]}
 */
/**
 * @param {any} o1
 * @param {any} o2
 * @return {boolean}
 */
var areDeeplyEqual = function(o1, o2) {
    
    if (typeof o1 !== typeof o2) return false;

    if (typeof o1 !== 'object' || o1 === null || o2 === null) return o1 === o2;
  
    if (Array.isArray(o1) !== Array.isArray(o2)) return false;
   
    const keys1 = Object.keys(o1).sort();
    const keys2 = Object.keys(o2).sort();
    
    if (keys1.length !== keys2.length) return false;
    
    for (let i = 0, len = keys1.length; i < len; i++) {
        const key1 = keys1[i];
        const key2 = keys2[i];
      
        if (key1 !== key2) return false;
       
        const value1 = o1[key1];
        const value2 = o2[key2];

        if (!areDeeplyEqual(value1, value2)) return false;
    }
    
    return true;
};
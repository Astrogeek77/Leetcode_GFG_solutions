/**
 * @param {any[]} arr
 * @param {number} depth
 * @return {any[]}
 */
var flat = function (arr, n) {
    // edge cases
    if(n == 0 || arr.every((item) => !Array.isArray(item))) 
        return arr;
    
    const result = [];
    for(let i = 0; i < arr.length; i++)
      if(Array.isArray(arr[i]))
          // if array, spread and push elements to result
        result.push(...arr[i]);
      else
          // else no need to spread
        result.push(arr[i]);
    return flat(result, n-1);
};
/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var filter = function(arr, fn) {
    var filterdArr = [];
    for(var i = 0; i < arr.length; i++) {
        if(fn(arr[i], i)) 
            filterdArr.push(arr[i])
    }
    return filterdArr;
};
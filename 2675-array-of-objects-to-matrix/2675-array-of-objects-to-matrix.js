/**
 * @param {Array} arr
 * @return {Matrix}
 */
var jsonToMatrix = function(arr) {
    var matrixMap = new Map();
    var numObjects = arr.length;

    // Recursive function that sets the matrix map with proper key-value pairs
    function setMatrixMap(arr, key, index) {
        if (typeof arr !== 'object' || arr === null) {
            if (!matrixMap.has(key)) {
                matrixMap.set(key, Array(numObjects).fill(""));         
            }
            matrixMap.get(key)[index] = arr;
            return;
        }

        Object.keys(arr).forEach(objKey => {
            var newKey = key.length === 0 ? objKey + '' : key + '.' + objKey;   
            setMatrixMap(arr[objKey], newKey, index);
        });
    }
    
    for (let i = 0; i < numObjects; i++) {
        setMatrixMap(arr[i], '', i);
    }
    
    if (matrixMap.size === 0) {
        return Array(numObjects + 1).fill(new Array().fill([]));
    }

    var finalMatrix = Array(numObjects + 1).fill(false);
    var matrixKeys = Array.from(matrixMap.keys()).sort();
    finalMatrix[0] = [...matrixKeys];
    
    matrixKeys.forEach((matrixKey, index) => {
        var temp = matrixMap.get(matrixKey);
        for (let j = 1; j <= numObjects; j++) {
            if (!finalMatrix[j]) {
                finalMatrix[j] = [];
            }
            finalMatrix[j].push(temp.shift());
        }
    });

    return finalMatrix;
};
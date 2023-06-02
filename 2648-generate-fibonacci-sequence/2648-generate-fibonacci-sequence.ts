function* fibGenerator(): Generator<number, any, number> {
     let prev1:number = 0, prev2:number = 1;

        while (true) {
          yield prev1;
          [prev1, prev2] = [prev2, prev1+prev2];
        }
};

/**
 * const gen = fibGenerator();
 * gen.next().value; // 0
 * gen.next().value; // 1
 */
type F = (...args: any[]) => void

function throttle(fn: F, t: number): F {
  var prev:number = -1;
  var time:ReturnType<typeof setTimeout> = null;

  return function (...args) {
    var currTime:any = Date.now();
    if (currTime - prev >= t) {
      fn(...args);
      prev = currTime;
    } else {
      clearTimeout(time);
      time = setTimeout(() => {
        fn(...args);
        time = null;
        prev += t;
      }, prev + t - currTime);
    }
  };
};

/**
 * const throttled = throttle(console.log, 100);
 * throttled("log"); // logged immediately.
 * throttled("log"); // logged at t=100ms.
 */
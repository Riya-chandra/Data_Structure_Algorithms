// Question: Limit function calls to once every interval.

function Throttle(fn, limit){
    let lastcall=0;
    return function(...args){
        const now=Date.now();  //20-0
        if(now-lastcall>=limit){
            lastCall=now;
            fn.apply(this,args);
        }
    };
}
const log=throttle(()=>console.log("Throttled!"),1000);
setInterval(log,200);



//Throttle ensures function runs at most once per interval.
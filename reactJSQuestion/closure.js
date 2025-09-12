// Question: Implement closure with a private counter.

function createCounter(){
    let count =0; //priavte var
    return function(){
 count++;
 return count;
    };

}


const counter=createCounter();
console.log(counter());
console.log(counter());
console.log(counter());
//we use closure when their is the priavte var and want it to be access 
//console.log(counter.count);  this count var cannot be accessed outside 
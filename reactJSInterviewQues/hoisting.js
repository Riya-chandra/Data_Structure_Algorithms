//Question: Explain hoisting with functions and variables.


console.log(a);  //here the var is accessed before definaton
var a=10;  // a is defined with undefined value

console.log(yep());  //function is defined in the global scope with undefined value
function yep(){
    return "hello";
}



// console.log(bar()); // Error, bar not hoisted
var bar=function(){
    return "hi";
};
//show "this" in object vs function

const obj={
    name:"Riya",
    greet(){
        console.log("hello" + this.name);
    }
};

obj.greet(); //hello Riya 
// Yahan greet ko obj call kar raha hai (obj.greet()).
// Isliye this obj ko refer karega.
// Output: "Hello Riya".
// 👉 Rule: Agar function object ke method ke taur pe call hua hai, to this us object ko point karega.


//regular function

function example(){
    console.log(this);
}
example(); //in browser:window , in strcut mode:undefined
//Browser me (non-strict mode) → this window object hoga.
// Strict mode ("use strict") me → this undefined hoga.
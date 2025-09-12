//Question: Explain scope chain with nested function.

let a=10 ///global

function outer(){
    let b=20;

    function inner(){
        let c=30;  //inner scope
        console.log(a+b+c);  //60 inner function can acess the outer declared var
    }

    inner();
}

outer();

//Inner function can access variables of outer scopes → this is scope chain.
//Inner cannot modify 'a' unless declared with var/let/const inside inner.
Array.prototype.myMap = function(callback) {
  console.log("Inside myMap, this is:", this);
};
const arr = [1,2,3];
arr.myMap(x => x * 2);

//output
//Inside myMap, this is: [1,2,3]






//Question: Implement custom map function.cust not using built in







Array.prototype.customMap=function(callback){
    const result=[];
    for(let i=0;i<this.length;i++){
result.push(callback(this[i],i),this);
    }
return result;
}

const arr1=[1,2,3,4];
const squre=arr1.customMap(x=>x*x);
console.log(squre);
//Question: Limit function call frequency (useful for search input).



//Debounce ek technique hai jo function calls ko delay karta hai aur ensure karta hai ki function baar-baar na chale jab tak last call ke baad specified time (delay) na beet jaaye. 
function debounce(func, delay) {
    let timer;
    return function(...args) {
        clearTimeout(timer);
        timer = setTimeout(() => func.apply(this, args), delay);
    };
}

const search=debounce((query)=>console.log("searching",query),500);

search("a");
search("ab");
search("abc");  //onlky this will run after 500ms
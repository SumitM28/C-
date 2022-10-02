let s="abc";
let ans=[];

function swap(a,b){
    let temp=a;
    a=b;
    b=a;
}
function permutation(s,i){

    if(i>=s.length){
        ans.push(s);
        return 
    }


    for(let j=i;j<s.length;j++){
        swap(s[i],s[j]);
        permutation(s,i+1)
        swap(s[i],s[j]);
    }
}

let out=[];

permutation(s,0,out,ans);
console.log(ans)
function robEm( arr ){
  var indexes = [];
  for ( var i = 0, len = arr.length; i < len; i++) {
    var fcomp = 0; //if this number is larger, don't rob this house.
    var tcomp = arr[i]; //if this number is larger, rob these suckas.
   
    if (arr[i+1]){ //well, if there isn't a house here, don't add it.
      fcomp+=arr[i+1];
    }
    if (arr[i+2]){ //but we still need to check the neighbors neighbor to see if this house is worth robbin'.
      tcomp+=arr[i+2];
      console.log(tcomp);
    }
    if ( tcomp > fcomp ){ //now we see who has the better bling.
      indexes.push(i);
      i++; // if the house is better, no need to check the neighbor, so let's skip it.
    } else {
      indexes.push(i+1);
      i+=2; // if the neighbor is better, no need to check the neighbors neighbor, so let's skip both.
    }
  }
  return indexes;
}

var houses = [20,10,50,5,1]; //should be 0,2,4
var robThese = robEm(houses);
console.log(robThese);
 
houses = [20,50,10,1,5];//should be 1,4
robThese = robEm(houses);
console.log(robThese);

houses = [90, 100, 90, 20, 90, 50, 100, 70]; //should be 0,2,4,6
robThese = robEm(houses);
console.log(robThese);
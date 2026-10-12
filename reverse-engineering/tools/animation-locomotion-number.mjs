// PC FUN_4f28e0, reproduced from its original scalar arithmetic.
// Multiply and addition each store float32; optional minus and decimal dot only.
// Trailing nonnumeric text terminates conversion. This is deliberately not Number().
export function parseNativeFloat(token) {
  token=String(token);let i=0,n=0,d=1;
  if(token[i]==='-'){d=-1;i++;}
  const digit=()=>i<token.length&&token.charCodeAt(i)>=48&&token.charCodeAt(i)<=57;
  while(digit()){n=Math.fround(Math.fround(n*10)+(token.charCodeAt(i)-48));i++;}
  if(token[i]==='.') {i++;while(digit()){d=Math.fround(d*10);n=Math.fround(Math.fround(n*10)+(token.charCodeAt(i)-48));i++;}}
  return {value:Math.fround(n/d),consumed:i,unconsumed:token.slice(i)};
}

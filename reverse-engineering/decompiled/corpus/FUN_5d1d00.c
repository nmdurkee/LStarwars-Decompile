/* Ghidra analysis pseudocode, not original source.
 * ev_7d8e2999f2f8a3752dbaff0aac6d4e5497e59d04af9d3c1072d39c32106cee2b
 * Entry: 0x5d1d00; label: FUN_005d1d00
 */

undefined4 FUN_005d1d00(undefined4 param_1)

{
  int in_EAX;
  int in_ECX;
  
  switch(param_1) {
  case 0:
    if (in_ECX == in_EAX) {
      return 1;
    }
    break;
  case 1:
    if (in_ECX < in_EAX) {
      return 1;
    }
    break;
  case 2:
    if (in_EAX < in_ECX) {
      return 1;
    }
    break;
  case 3:
    if (in_ECX <= in_EAX) {
      return 1;
    }
    break;
  case 4:
    if (in_EAX <= in_ECX) {
      return 1;
    }
    break;
  case 5:
    if (in_ECX != in_EAX) {
      return 1;
    }
  }
  return 0;
}


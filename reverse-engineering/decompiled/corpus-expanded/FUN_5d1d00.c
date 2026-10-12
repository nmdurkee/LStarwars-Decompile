/* Ghidra pseudocode, not original source.
 * ev_e6f703959aeb52fdf2ce751bd65c36cac7164cfc40610a61221749966f801066
 * Entry: 0x5d1d00; label: FUN_005d1d00
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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


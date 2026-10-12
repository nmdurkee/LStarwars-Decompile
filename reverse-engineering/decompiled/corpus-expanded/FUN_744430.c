/* Ghidra pseudocode, not original source.
 * ev_0a8198a66e8ec6a1eea085c3401beb2c994e6aa9b143cc409d97940c91a3eeae
 * Entry: 0x744430; label: FUN_00744430
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00744430(undefined4 param_1)

{
  int *in_ECX;
  
  switch(param_1) {
  case 0:
    return 1;
  case 1:
    if (((*(byte *)(*in_ECX + 0x1b8) & 0x40) != 0) && (*(char *)(*in_ECX + 0x44) != -1)) {
      return 1;
    }
    break;
  case 2:
    if (((*(byte *)(*in_ECX + 0x1b8) & 0x80) != 0) && (*(char *)(*in_ECX + 0x45) != -1)) {
      return 1;
    }
    break;
  case 3:
    if (((*(uint *)(*in_ECX + 0x1b8) & 0x100) != 0) && (*(char *)(*in_ECX + 0x46) != -1)) {
      return 1;
    }
    break;
  default:
    return 0;
  }
  return 0;
}


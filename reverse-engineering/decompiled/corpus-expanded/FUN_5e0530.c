/* Ghidra pseudocode, not original source.
 * ev_a87fd181e19a595ed696a9e48a76c3177ea695d31392ba84c3867c15109a72c3
 * Entry: 0x5e0530; label: FUN_005e0530
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005e0530(int param_1,int param_2,undefined4 param_3,undefined4 param_4,int param_5)

{
  char cVar1;
  char *in_ECX;
  
  if (*in_ECX == -0x71) {
    FUN_005e0490();
    return;
  }
  if (param_5 == 0) {
    if ((((*(uint *)(param_1 + 0xb4) & 0x80000000) != 0) && (1 < param_2)) &&
       ((cVar1 = in_ECX[-0x20], cVar1 == -0x50 || ((cVar1 == -0x52 || (cVar1 == -0x51)))))) {
      FUN_005e02b0();
      return;
    }
    FUN_005e0200();
    return;
  }
  FUN_005e0390();
  return;
}


/* Ghidra pseudocode, not original source.
 * ev_0a8198a66e8ec6a1eea085c3401beb2c994e6aa9b143cc409d97940c91a3eeae
 * Entry: 0x7445b0; label: FUN_007445b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_007445b0(int param_1)

{
  char cVar1;
  undefined4 uVar2;
  int *in_ECX;
  
  if (in_ECX[3] == 0) {
    uVar2 = FUN_00744430(param_1);
    return uVar2;
  }
  cVar1 = FUN_00744430(param_1);
  if (((cVar1 != '\0') && (param_1 == 0)) && ((*(byte *)(*in_ECX + 0x1b4) & 1) != 0)) {
    return 1;
  }
  return 0;
}


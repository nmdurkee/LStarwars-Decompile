/* Ghidra pseudocode, not original source.
 * ev_168b65d5705473c04d5f4e526193e1abf552a66e90d2db36f509f2a3124060c2
 * Entry: 0x60e120; label: FUN_0060e120
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0060e120(undefined4 param_1,undefined1 param_2,int param_3)

{
  undefined1 *puVar1;
  undefined4 *in_ECX;
  
  if (in_ECX != (undefined4 *)0x0) {
    *in_ECX = 0;
    in_ECX[1] = 0;
  }
  *(undefined1 *)(in_ECX + 3) = param_2;
  puVar1 = (undefined1 *)((int)in_ECX + 0xd);
  in_ECX[2] = param_1;
  FUN_0060df50(puVar1);
  if (param_3 != 0) {
    FUN_004f1f40(puVar1,param_3,0x20);
    return;
  }
  *puVar1 = 0;
  return;
}


/* Ghidra pseudocode, not original source.
 * ev_bef7beff20bbab7c70650c6f9f545113d8e67786c96c5ee03f6ff15c7c5049ec
 * Entry: 0x748460; label: FUN_00748460
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00748460(int param_1,int param_2)

{
  int iVar1;
  int *in_ECX;
  
  iVar1 = *(int *)(param_1 + 4);
  *(int *)(param_1 + 4) = iVar1 + param_2;
  *in_ECX = iVar1;
  in_ECX[2] = param_2;
  in_ECX[1] = 0;
  *(undefined1 *)(in_ECX + 3) = 0;
  return;
}


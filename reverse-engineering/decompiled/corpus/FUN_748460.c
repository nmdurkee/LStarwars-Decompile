/* Ghidra analysis pseudocode, not original source.
 * ev_7afb5199773593ea980580d1c3e319946e9fb0192a7e36f1658c723ed800643d
 * Entry: 0x748460; label: FUN_00748460
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


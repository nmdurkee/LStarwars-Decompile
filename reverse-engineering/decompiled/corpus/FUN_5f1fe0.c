/* Ghidra analysis pseudocode, not original source.
 * ev_d2450bc109eaeb7c56e41eff2a553a3360ea1f4e9492b44c9e06060604e12c53
 * Entry: 0x5f1fe0; label: FUN_005f1fe0
 */

void FUN_005f1fe0(undefined4 param_1,undefined4 param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  int *in_ECX;
  
  if (-1 < *in_ECX) {
    piVar1 = (int *)(in_ECX[1] + 0x24 + *in_ECX * 0x28);
    *piVar1 = *piVar1 + -1;
  }
  in_ECX[1] = param_3;
  iVar2 = FUN_005c51c0(param_1,param_2);
  *in_ECX = iVar2;
  return;
}


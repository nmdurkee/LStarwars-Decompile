/* Ghidra analysis pseudocode, not original source.
 * ev_2697994747b9808d778082a46d5d52329d06fdf80cefad3ab22f972b93f6240a
 * Entry: 0x441ea0; label: FUN_00441ea0
 */

float10 FUN_00441ea0(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  
  if (((param_3 != 0) && (iVar1 = *(int *)(param_3 + 0xd0), iVar1 != 0)) &&
     (*(int *)(iVar1 + 0x1f0) != 0 || *(int *)(iVar1 + 500) != 0)) {
    return (float10)1;
  }
  return (float10)0;
}


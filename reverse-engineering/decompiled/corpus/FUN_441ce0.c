/* Ghidra analysis pseudocode, not original source.
 * ev_2697994747b9808d778082a46d5d52329d06fdf80cefad3ab22f972b93f6240a
 * Entry: 0x441ce0; label: FUN_00441ce0
 */

float10 FUN_00441ce0(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  
  if (((param_3 != 0) && (*(int **)(param_3 + 0xd0) != (int *)0x0)) &&
     (iVar1 = **(int **)(param_3 + 0xd0), iVar1 != 0)) {
    if (((*(uint *)(PTR_PTR_007fb0e4 + *(char *)(iVar1 + 0x7b5) * 0x10 + 8) & 0x4000000) != 0) ||
       (((*(uint *)(PTR_PTR_007fb0e4 + *(char *)(iVar1 + 0x7b5) * 0x10 + 8) & 0x8000000) != 0 &&
        ((*(uint *)(iVar1 + 0x7bc) & 0x20000) != 0)))) {
      return (float10)1;
    }
  }
  return (float10)0;
}


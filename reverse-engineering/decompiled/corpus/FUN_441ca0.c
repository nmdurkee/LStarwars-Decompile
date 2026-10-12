/* Ghidra analysis pseudocode, not original source.
 * ev_2697994747b9808d778082a46d5d52329d06fdf80cefad3ab22f972b93f6240a
 * Entry: 0x441ca0; label: FUN_00441ca0
 */

float10 FUN_00441ca0(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4,
                    int param_5)

{
  int iVar1;
  
  if ((param_5 != 0) || (param_5 = *(int *)(param_2 + 0xa4), param_5 != 0)) {
    iVar1 = FUN_005d6620(param_5 + 0x10,0,&DAT_00806680);
    if (iVar1 == 0) {
      return (float10)1;
    }
  }
  return (float10)0;
}


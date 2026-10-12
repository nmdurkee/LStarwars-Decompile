/* Ghidra analysis pseudocode, not original source.
 * ev_023debdfa9c039acf518a8e1f05c99a974f400faccf57ad72851f9420ef75a11
 * Entry: 0x440c30; label: FUN_00440c30
 */

float10 FUN_00440c30(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4,
                    int param_5)

{
  int iVar1;
  
  if (((param_5 != -1) && (param_3 != 0)) && (*(undefined4 **)(param_3 + 0xd0) != (undefined4 *)0x0)
     ) {
    iVar1 = FUN_0055bc80(**(undefined4 **)(param_3 + 0xd0),param_5);
    if (iVar1 != 0) {
      return (float10)1;
    }
  }
  return (float10)0;
}


/* Ghidra analysis pseudocode, not original source.
 * ev_28935bb75220519b9cd6c8dd2893feffbabc6fed0a1828833445fdd6a861260d
 * Entry: 0x684d30; label: FUN_00684d30
 */

int FUN_00684d30(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  int iVar1;
  
  iVar1 = FUN_00684790(param_1,param_8);
  if (iVar1 != -1) {
    FUN_00684be0(iVar1,param_2,param_3,param_4,param_5,param_6,param_7);
  }
  return iVar1;
}


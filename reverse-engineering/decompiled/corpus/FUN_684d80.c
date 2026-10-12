/* Ghidra analysis pseudocode, not original source.
 * ev_28935bb75220519b9cd6c8dd2893feffbabc6fed0a1828833445fdd6a861260d
 * Entry: 0x684d80; label: FUN_00684d80
 */

int FUN_00684d80(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  int iVar1;
  
  iVar1 = FUN_00684790(param_1,param_7);
  if (iVar1 != -1) {
    FUN_00656d40(iVar1,param_2,&DAT_0095e5c8,param_3,param_4,param_5,param_6);
  }
  return iVar1;
}


/* Ghidra pseudocode, not original source.
 * ev_e184d5b1c01771fdc7fcde98b9e576adf0de0b497982e0e92263394112c13494
 * Entry: 0x684d80; label: FUN_00684d80
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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


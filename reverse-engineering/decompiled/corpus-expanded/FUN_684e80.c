/* Ghidra pseudocode, not original source.
 * ev_e184d5b1c01771fdc7fcde98b9e576adf0de0b497982e0e92263394112c13494
 * Entry: 0x684e80; label: FUN_00684e80
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_00684e80(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                undefined4 param_9,undefined4 param_10,undefined4 param_11)

{
  int iVar1;
  
  iVar1 = FUN_00684790(param_1,param_11);
  if (iVar1 != -1) {
    FUN_006561d0(iVar1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9,param_10);
  }
  return iVar1;
}


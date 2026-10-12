/* Ghidra pseudocode, not original source.
 * ev_6fa6af6f6c20542b4b3f476ed9727be59ab920ff8cd58abbde73c8c49552840b
 * Entry: 0x5ce7e0; label: FUN_005ce7e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_005ce7e0(undefined4 param_1,undefined4 param_2,float param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  uVar1 = *(undefined4 *)(DAT_00973880 + 8);
  FUN_005ce350(param_1,param_3 - 1.0,uVar1,param_2,param_4);
  return uVar1;
}


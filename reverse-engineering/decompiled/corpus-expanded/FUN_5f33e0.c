/* Ghidra pseudocode, not original source.
 * ev_120f2dbe0ae7ec1f4fb84f9bb605c17bea6e5ad9085d38dd392f35fbf38da278
 * Entry: 0x5f33e0; label: FUN_005f33e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_005f33e0(int *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  if ((*param_1 != 0) && (param_1[2] != 0)) {
    uVar1 = FUN_005f0f00(param_1,param_3,2,param_2,0);
    return uVar1;
  }
  return 0;
}


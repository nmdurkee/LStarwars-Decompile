/* Ghidra pseudocode, not original source.
 * ev_120f2dbe0ae7ec1f4fb84f9bb605c17bea6e5ad9085d38dd392f35fbf38da278
 * Entry: 0x5f3440; label: FUN_005f3440
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_005f3440(int *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined1 local_40 [64];
  
  if (*param_1 == 0) {
    return 0;
  }
  if (param_1[2] != 0) {
    FUN_005b5430(local_40,param_1[2],param_2);
    uVar1 = FUN_005f0f00(param_1,local_40,0,0,0);
    return uVar1;
  }
  FUN_005b5430(local_40,param_1[1],param_2);
  uVar1 = FUN_005fe970(*(undefined4 *)
                        (*(int *)(*param_1 + 0x18) +
                        *(short *)(*(int *)(param_1[1] + 0x40) + 0x40) * 4),local_40);
  return uVar1;
}


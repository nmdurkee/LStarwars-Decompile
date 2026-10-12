/* Ghidra pseudocode, not original source.
 * ev_ca5ea7f3b5788154105ce78c12a6b4d3dd45520787e3b427f0542ab309566885
 * Entry: 0x62c610; label: FUN_0062c610
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4
FUN_0062c610(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5)

{
  int iVar1;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  if (((-1 < param_2) && (param_2 < *(int *)(param_1 + 4))) &&
     (iVar1 = param_2 * 0x14, *(int *)(*(int *)(param_1 + 8) + param_2 * 0x14) != -1)) {
    local_c = param_3;
    param_2 = 0xffffffff;
    local_8 = param_4;
    local_4 = param_5;
    FUN_00690460(&param_2,*(undefined4 *)(*(int *)(param_1 + 8) + iVar1),&local_c,1);
    return 1;
  }
  return 0;
}


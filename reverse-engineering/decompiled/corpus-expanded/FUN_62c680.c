/* Ghidra pseudocode, not original source.
 * ev_ca5ea7f3b5788154105ce78c12a6b4d3dd45520787e3b427f0542ab309566885
 * Entry: 0x62c680; label: FUN_0062c680
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4
FUN_0062c680(int param_1,int param_2,undefined4 param_3,int param_4,undefined4 param_5,
            undefined4 param_6)

{
  int iVar1;
  
  if ((((-1 < param_2) && (param_2 < *(int *)(param_1 + 4))) &&
      (iVar1 = *(int *)(*(int *)(param_1 + 8) + param_2 * 0x14), iVar1 != -1)) && (0 < param_4)) {
    FUN_00684c90(iVar1,param_3,param_4,param_5,param_6);
    return 1;
  }
  return 0;
}


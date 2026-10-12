/* Ghidra pseudocode, not original source.
 * ev_5f8bd7f02bbfa9819b1ea6d4f28ed7de24e0304b6779d959c9b1888bbc6517da
 * Entry: 0x5b6fa0; label: FUN_005b6fa0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_005b6fa0(float *param_1,int param_2)

{
  int iVar1;
  
  iVar1 = 0;
  param_2 = param_2 - (int)param_1;
  while( true ) {
    if (*param_1 < *(float *)(param_2 + (int)param_1)) {
      return 0xffffffff;
    }
    if (*(float *)(param_2 + (int)param_1) < *param_1) break;
    iVar1 = iVar1 + 1;
    param_1 = param_1 + 1;
    if (0xf < iVar1) {
      return 0;
    }
  }
  return 1;
}


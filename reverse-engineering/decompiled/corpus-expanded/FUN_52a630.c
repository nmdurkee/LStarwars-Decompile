/* Ghidra pseudocode, not original source.
 * ev_86be5d0b29c9dd19f96c33e6e07bf1c9a03b071eda0eb4c5bb2270815bb5be61
 * Entry: 0x52a630; label: FUN_0052a630
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0052a630(int param_1,int param_2,undefined4 *param_3,int param_4)

{
  uint uVar1;
  float local_28 [3];
  undefined4 local_1c [7];
  
  if (param_2 == 0) {
    *param_3 = *(undefined4 *)(param_1 + 0x28);
    param_3[1] = *(undefined4 *)(param_1 + 0x2c);
    param_3[2] = *(undefined4 *)(param_1 + 0x30);
    return 1;
  }
  uVar1 = param_2 % (int)(uint)*(byte *)(param_1 + 0x5c);
  local_28[0] = (float)((int)(uVar1 + 1) / 2) * *(float *)(param_1 + 0x60);
  if ((uVar1 & 1) != 0) {
    local_28[0] = -local_28[0];
  }
  local_28[1] = 0.0;
  local_28[2] = -*(float *)(param_1 + 100) * (float)(param_2 / (int)(uint)*(byte *)(param_1 + 0x5c))
  ;
  FUN_005b3620(local_28,local_28,*(undefined4 *)(param_1 + 0x34));
  FUN_005b37d0(param_3,local_28,param_1 + 0x28);
  if (param_4 != 0) {
    FUN_00524900(param_3,local_1c,*(undefined4 *)(param_1 + 0x3c),0);
    return local_1c[0];
  }
  return 1;
}


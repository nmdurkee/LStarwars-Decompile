/* Ghidra pseudocode, not original source.
 * ev_7e454dac1a79555432f813726d68bcfcf5762a505a2d8dbf5e6e5fb42bc98c3e
 * Entry: 0x54d6a0; label: FUN_0054d6a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0054d6a0(float param_1,undefined4 param_2,int param_3,float *param_4)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 local_4;
  
  iVar2 = param_3;
  uVar1 = param_2;
  if (*(int *)((int)param_1 + 0x5080) == 0) {
    return 0;
  }
  local_4 = 0;
  if (param_3 == 0) {
    param_1 = 1e+09;
  }
  else {
    param_1 = *(float *)(param_3 + 0x1dc);
    if ((*(char *)(param_3 + 0x281) == '\0') && (DAT_00927038 == 0)) {
      param_1 = param_1 + param_1;
    }
    param_1 = (param_1 + 0.25) * (param_1 + 0.25);
  }
  FUN_0054d4a0(param_2,&local_4,&param_1);
  if (iVar2 != 0) {
    FUN_0054d4a0(uVar1,&local_4,&param_1);
  }
  if (param_4 != (float *)0x0) {
    *param_4 = param_1;
  }
  return local_4;
}


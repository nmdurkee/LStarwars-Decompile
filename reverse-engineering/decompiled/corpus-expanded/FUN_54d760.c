/* Ghidra pseudocode, not original source.
 * ev_7e454dac1a79555432f813726d68bcfcf5762a505a2d8dbf5e6e5fb42bc98c3e
 * Entry: 0x54d760; label: FUN_0054d760
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_0054d760(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  float10 fVar3;
  float local_14;
  int local_10;
  float local_c;
  float local_8;
  float local_4;
  
  local_14 = 1e+09;
  iVar1 = *(int *)(param_1 + 0x5080);
  iVar2 = 0;
  local_10 = 0;
  if (iVar1 != 0) {
    if (0 < *(int *)(param_1 + 0x5084)) {
      do {
        local_c = (*(float *)(iVar1 + 0x30) + *(float *)(iVar1 + 0x24)) * 0.5;
        local_8 = (*(float *)(iVar1 + 0x34) + *(float *)(iVar1 + 0x28)) * 0.5;
        local_4 = (*(float *)(iVar1 + 0x38) + *(float *)(iVar1 + 0x2c)) * 0.5;
        fVar3 = (float10)FUN_005b3c50(&local_c,param_2,0);
        if ((float)fVar3 < local_14) {
          local_14 = (float)fVar3;
          local_10 = iVar1;
        }
        iVar2 = iVar2 + 1;
        iVar1 = iVar1 + 0xf8;
      } while (iVar2 < *(int *)(param_1 + 0x5084));
    }
    return local_10;
  }
  return 0;
}


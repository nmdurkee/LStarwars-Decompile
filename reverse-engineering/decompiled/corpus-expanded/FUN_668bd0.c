/* Ghidra pseudocode, not original source.
 * ev_649900f3c82336bf94a875d1c19b8123e0c4482fbb0765088d6a26c91e5b98b7
 * Entry: 0x668bd0; label: FUN_00668bd0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00668bd0(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if ((DAT_029231a8 != -1) && ((&DAT_02924b60)[DAT_029231a8 * 0x16] != -1)) {
    iVar1 = *(int *)(DAT_0296209c +
                    *(short *)((&DAT_02924b60)[DAT_029231a8 * 0x16] * 0x330 + 0x182 + DAT_029620a4)
                    * 4);
    *(float *)(iVar1 + 0x298) = *(float *)(param_2 + 0x4c) * 256.0 + 524288.0;
    *(float *)(iVar1 + 0x29c) = *(float *)(param_2 + 0x54) * 256.0 + 524288.0;
    *(float *)(iVar1 + 0x2a0) = *(float *)(param_2 + 0x50) * 256.0 + 524288.0;
    *(float *)(iVar1 + 0x2a4) = *(float *)(param_2 + 0x58) * 256.0 + 524288.0;
    iVar2 = *(int *)(param_1 + 0x40);
    iVar3 = 0;
    if (iVar2 != 0) {
      FUN_006279f0(param_1);
      iVar3 = iVar2;
    }
    if (*(code **)(param_1 + 0x30) != (code *)0x0) {
      (**(code **)(param_1 + 0x30))(param_1,iVar3);
    }
    FUN_00600260(iVar1);
  }
  return;
}


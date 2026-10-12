/* Ghidra pseudocode, not original source.
 * ev_649900f3c82336bf94a875d1c19b8123e0c4482fbb0765088d6a26c91e5b98b7
 * Entry: 0x6671d0; label: FUN_006671d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006671d0(undefined4 param_1,int param_2)

{
  float fVar1;
  int iVar2;
  uint uVar3;
  bool bVar4;
  
  uVar3 = *(byte *)(param_2 + 0x11) & 1;
  bVar4 = DAT_00810ae4 == 0;
  DAT_00810ae4 = uVar3;
  if ((bVar4) && (uVar3 == 1)) {
    iVar2 = *(int *)(DAT_0296209c +
                    *(short *)((&DAT_02924b60)[DAT_029231a8 * 0x16] * 0x330 + 0x182 + DAT_029620a4)
                    * 4);
    fVar1 = *(float *)(iVar2 + 0x2f8);
    *(float *)(iVar2 + 0x300) = fVar1;
    iVar2 = DAT_02962b24;
    *(float *)(DAT_02962b24 + 0x54) = fVar1;
    *(float *)(iVar2 + 0x50) = (fVar1 - *(float *)(iVar2 + 0x58)) / *(float *)(iVar2 + 0x5c);
  }
  return;
}


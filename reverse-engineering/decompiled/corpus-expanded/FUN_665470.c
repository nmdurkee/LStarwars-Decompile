/* Ghidra pseudocode, not original source.
 * ev_1085323f9a3cb798a23dfec0c4468a06f744be49385e8c8d18d4e2ca61b2546b
 * Entry: 0x665470; label: FUN_00665470
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00665470(undefined4 param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  
  DAT_02962a5c = 0;
  uVar2 = *(uint *)(param_2 + 0xc) >> 0x10;
  iVar1 = *(uint *)(param_2 + 0xc) + uVar2 * -0x10000;
  if (iVar1 == 9999) {
    iVar1 = -1;
  }
  if ((DAT_029231a8 != -1) && ((&DAT_02924b60)[DAT_029231a8 * 0x16] != -1)) {
    *(int *)(*(int *)(DAT_0296209c +
                     *(short *)((&DAT_02924b60)[DAT_029231a8 * 0x16] * 0x330 + 0x182 + DAT_029620a4)
                     * 4) + 0x3e0 + uVar2 * 0xc) = iVar1;
  }
  piVar3 = &DAT_02924b60;
  do {
    iVar1 = *piVar3;
    if ((iVar1 != -1) && (iVar1 != 99999)) {
      *(undefined1 *)(iVar1 * 0x330 + 0x2f5 + DAT_029620a4) = 0;
      iVar1 = *piVar3 * 0x330 + DAT_029620a4;
      if (*(int *)(*(int *)(DAT_0296209c + *(short *)(iVar1 + 0x182) * 4) + 0x3e0) != -1) {
        *(undefined1 *)(iVar1 + 0x2f5) = 1;
      }
      iVar1 = *piVar3 * 0x330 + DAT_029620a4;
      if (*(int *)(*(int *)(DAT_0296209c + *(short *)(iVar1 + 0x182) * 4) + 0x3ec) != -1) {
        *(undefined1 *)(iVar1 + 0x2f5) = 1;
      }
      iVar1 = *piVar3 * 0x330 + DAT_029620a4;
      if (*(int *)(*(int *)(DAT_0296209c + *(short *)(iVar1 + 0x182) * 4) + 0x3f8) != -1) {
        *(undefined1 *)(iVar1 + 0x2f5) = 1;
      }
      iVar1 = *piVar3 * 0x330 + DAT_029620a4;
      if (*(int *)(*(int *)(DAT_0296209c + *(short *)(iVar1 + 0x182) * 4) + 0x404) != -1) {
        *(undefined1 *)(iVar1 + 0x2f5) = 1;
      }
    }
    piVar3 = piVar3 + 0x16;
  } while ((int)piVar3 < 0x292fb60);
  FUN_006279f0(param_1);
  FUN_00624220(param_1);
  return;
}


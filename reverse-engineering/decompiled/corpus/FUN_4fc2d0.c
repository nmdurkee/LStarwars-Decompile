/* Ghidra analysis pseudocode, not original source.
 * ev_fde8b55f02fe7b53f1a00cfd799b40252fec9b79621de4d26dfdea385167393c
 * Entry: 0x4fc2d0; label: FUN_004fc2d0
 */

uint FUN_004fc2d0(int *param_1)

{
  undefined1 uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  uVar2 = param_1[0x14b];
  if ((int)uVar2 < param_1[0x149]) {
    uVar3 = uVar2 + 1;
    if ((int)uVar3 <= param_1[0x15d]) {
      iVar4 = param_1[0x15d] - (((int)uVar2 < 0) - 1 & uVar2);
      if (0x1000 < iVar4) {
        iVar4 = 0x1000;
      }
      iVar4 = FUN_004fb550(param_1[1],*param_1,iVar4);
      param_1[0x14a] = param_1[0x14b] + 1;
      param_1[0x14b] = param_1[0x14b] + iVar4;
      uVar3 = 0;
      if (iVar4 != 0) goto LAB_004fc33b;
    }
    return uVar3 & 0xffffff00;
  }
LAB_004fc33b:
  iVar4 = param_1[0x149] - param_1[0x14a];
  uVar1 = *(undefined1 *)(iVar4 + *param_1);
  param_1[0x149] = param_1[0x149] + 1;
  return CONCAT31((int3)((uint)iVar4 >> 8),uVar1);
}


/* Ghidra analysis pseudocode, not original source.
 * ev_82de32114f0a758998fb1b139028178946084d97602e6dd81f3d90db1eb3e6aa
 * Entry: 0x5b0c80; label: FUN_005b0c80
 */

void FUN_005b0c80(void)

{
  int iVar1;
  float fVar2;
  uint uVar3;
  int iVar4;
  int unaff_EDI;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  iVar4 = 0;
  if (0 < *(int *)(unaff_EDI + 0x14)) {
    do {
      local_c = 0;
      local_8 = 0;
      local_4 = *(undefined4 *)(*(int *)(unaff_EDI + 0x10) + 0x30 + iVar4 * 0x44);
      iVar1 = *(int *)(unaff_EDI + 0x10) + iVar4 * 0x44;
      FUN_005b35a0(&local_c,&local_c,*(undefined2 *)(iVar1 + 0x34));
      FUN_005b3620(&local_c,&local_c,*(undefined2 *)(iVar1 + 0x36));
      FUN_005b37d0(&local_c,&local_c,*(undefined4 *)(iVar1 + 0x20));
      uVar3 = 0x8f;
      if (iVar4 == 0) {
        uVar3 = 0x28f;
      }
      if (iVar4 == *(int *)(unaff_EDI + 0x14) + -1) {
        uVar3 = uVar3 | 0x400;
      }
      fVar2 = *(float *)(iVar1 + 0x3c);
      if (!NAN(fVar2) && 0.0 < fVar2 != (fVar2 == 0.0)) {
        uVar3 = uVar3 | 0x800;
      }
      if (0.0 < *(float *)(iVar1 + 0x40)) {
        uVar3 = uVar3 | 0x1000;
      }
      FUN_00578140(uVar3,*(undefined4 *)(iVar1 + 0x30),*(undefined2 *)(iVar1 + 0x34),
                   *(undefined2 *)(iVar1 + 0x36),*(undefined2 *)(iVar1 + 0x38),
                   *(undefined4 *)(iVar1 + 0x20),0,&local_c,*(undefined4 *)(unaff_EDI + 0x1c),
                   *(undefined4 *)(unaff_EDI + 0x24),*(undefined4 *)(unaff_EDI + 0x20),
                   *(undefined4 *)(unaff_EDI + 0x28),*(undefined4 *)(iVar1 + 0x3c),
                   *(undefined4 *)(iVar1 + 0x40),*(undefined4 *)(unaff_EDI + 0x2c),0,0,0xffffffff,2)
      ;
      if (DAT_0087b4d8 == 0) {
        *(undefined1 *)(unaff_EDI + 0x18) = 1;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < *(int *)(unaff_EDI + 0x14));
  }
  return;
}


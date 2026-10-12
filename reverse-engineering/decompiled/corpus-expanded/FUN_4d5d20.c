/* Ghidra pseudocode, not original source.
 * ev_7cce3243898a12dda79e95a496780a4d79cb1010b8a976b902fd46336e9989b6
 * Entry: 0x4d5d20; label: FUN_004d5d20
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004d5d20(void)

{
  int iVar1;
  float fVar2;
  undefined2 uVar3;
  int unaff_ESI;
  float10 fVar4;
  
  iVar1 = unaff_ESI + 0x38;
  FUN_005b35a0(iVar1,&DAT_007ffc14,*(undefined2 *)(unaff_ESI + 0x34));
  FUN_005b3620(iVar1,iVar1,*(undefined2 *)(unaff_ESI + 0x36));
  FUN_005b37d0(iVar1,unaff_ESI + 0x1c,iVar1);
  FUN_0067a6d0();
  fVar4 = (float10)FUN_005506f0(0,(float *)(unaff_ESI + 0x10),0x40a00000,0xffffffff);
  fVar2 = (float)fVar4;
  *(float *)(unaff_ESI + 0x6c) = fVar2;
  if (fVar2 != 2e+06) {
    *(float *)(unaff_ESI + 0x6c) = fVar2 + 0.005;
    FUN_0054fec0(&DAT_0292fdb8,unaff_ESI + 0x74,unaff_ESI + 0x78);
  }
  FUN_0067a6d0();
  fVar4 = (float10)FUN_005506f0(0,(float *)(unaff_ESI + 0x28),0x40a00000,0xffffffff);
  fVar2 = (float)fVar4;
  *(float *)(unaff_ESI + 0x70) = fVar2;
  if (fVar2 != 2e+06) {
    *(float *)(unaff_ESI + 0x70) = fVar2 + 0.005;
    FUN_0054fec0(&DAT_0292fdb8,unaff_ESI + 0x76,unaff_ESI + 0x7a);
  }
  uVar3 = FUN_005be2d0(*(float *)(unaff_ESI + 0x28) - *(float *)(unaff_ESI + 0x10),
                       *(float *)(unaff_ESI + 0x30) - *(float *)(unaff_ESI + 0x18));
  *(undefined2 *)(unaff_ESI + 100) = uVar3;
  *(undefined4 *)(unaff_ESI + 0x5c) = 0;
  *(ushort *)(unaff_ESI + 0x68) = *(ushort *)(unaff_ESI + 0x68) & 0xfeff | 0xc0;
  return;
}


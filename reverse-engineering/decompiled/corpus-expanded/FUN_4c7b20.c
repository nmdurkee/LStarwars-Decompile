/* Ghidra pseudocode, not original source.
 * ev_e691f105e7e9df146417299401ecc100ef54520e911e9eb278e110fa7bbc9740
 * Entry: 0x4c7b20; label: FUN_004c7b20
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004c7b20(void)

{
  int iVar1;
  int iVar2;
  char cVar3;
  int iVar4;
  int unaff_ESI;
  float10 fVar5;
  
  FUN_0067a6d0();
  iVar1 = unaff_ESI + 0x50;
  fVar5 = (float10)FUN_005506f0(0,iVar1,0x40a00000,0xffffffff);
  if ((float)fVar5 != 2e+06) {
    *(float *)(unaff_ESI + 0x54) = (float)fVar5;
    FUN_0054fec0(&DAT_0292fdb8,unaff_ESI + 0x5e,unaff_ESI + 0x60);
  }
  *(undefined4 *)(unaff_ESI + 0x6c) = 0x3f59999a;
  iVar4 = unaff_ESI + 0x74;
  *(undefined4 *)(unaff_ESI + 0x70) = 0x3f800000;
  FUN_005b3690(iVar4,&DAT_00802500,*(undefined2 *)(unaff_ESI + 0x60));
  FUN_005b35a0(iVar4,iVar4,*(undefined2 *)(unaff_ESI + 0x5e));
  iVar2 = unaff_ESI + 0x84;
  FUN_005b3830(iVar2,iVar4,0x3f19999a);
  FUN_005b37d0(iVar2,iVar2,iVar1);
  iVar4 = FUN_004cc950(*(undefined1 *)(unaff_ESI + 0x69));
  *(int *)(unaff_ESI + 0x80) = iVar4;
  if (iVar4 == 0) {
    *(undefined ***)(unaff_ESI + 0x80) = &PTR_s_batman_007fcfb8;
  }
  cVar3 = *(char *)(*(int *)(unaff_ESI + 0x80) + 0xe);
  *(char *)(unaff_ESI + 0x68) = cVar3;
  *(undefined1 *)(unaff_ESI + 0x69) = *(undefined1 *)(*(int *)(unaff_ESI + 0x80) + 0xf);
  if (cVar3 == 'r') {
    *(undefined2 *)(unaff_ESI + 0x62) = 0x3a;
    *(undefined2 *)(unaff_ESI + 100) = 0x3b;
    *(undefined2 *)(unaff_ESI + 0x66) = 0x3c;
  }
  else {
    *(undefined2 *)(unaff_ESI + 0x62) = 0x37;
    *(undefined2 *)(unaff_ESI + 100) = 0x38;
    *(undefined2 *)(unaff_ESI + 0x66) = 0x39;
  }
  iVar4 = unaff_ESI + 0x10;
  *(byte *)(unaff_ESI + 0x6a) = *(byte *)(unaff_ESI + 0x6a) & 0xfb | 3;
  FUN_005b4670(iVar4,*(undefined2 *)(unaff_ESI + 0x5c));
  FUN_005b5160(iVar4,*(undefined2 *)(unaff_ESI + 0x60));
  FUN_005b4cf0(iVar4,*(undefined2 *)(unaff_ESI + 0x5e));
  FUN_005b4900(iVar4,iVar1);
  return;
}


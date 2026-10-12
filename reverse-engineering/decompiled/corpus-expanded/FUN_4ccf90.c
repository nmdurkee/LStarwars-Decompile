/* Ghidra pseudocode, not original source.
 * ev_8be83d5a314ed06484cc1a00e0611cd4a1346ac66c548b102291ab30b68096a0
 * Entry: 0x4ccf90; label: FUN_004ccf90
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004ccf90(void)

{
  int iVar1;
  float fVar2;
  int in_EAX;
  float10 fVar3;
  
  *(undefined4 *)(in_EAX + 0x20) = 0;
  *(undefined4 *)(in_EAX + 0x1c) = 0;
  iVar1 = in_EAX + 0x1c;
  *(undefined4 *)(in_EAX + 0x24) = _DAT_007fd118;
  FUN_005b3620(iVar1,iVar1,*(undefined2 *)(in_EAX + 0x30));
  FUN_005b37d0(iVar1,iVar1,in_EAX + 0x10);
  FUN_0067a6d0();
  fVar3 = (float10)FUN_005506f0(0,iVar1,0x40a00000,0xffffffff);
  fVar2 = (float)fVar3;
  *(float *)(in_EAX + 0x20) = fVar2;
  if (fVar2 != 2e+06) {
    *(float *)(in_EAX + 0x20) = fVar2 + 0.005;
    FUN_0054fec0(&DAT_0292fdb8,in_EAX + 0x32,in_EAX + 0x34);
  }
  *(undefined4 *)(in_EAX + 0x28) = 0;
  *(byte *)(in_EAX + 0x3c) = *(byte *)(in_EAX + 0x3c) & 0xfb | 3;
  FUN_004f1f10(in_EAX + 0x3d,in_EAX + 0x4d);
  return;
}


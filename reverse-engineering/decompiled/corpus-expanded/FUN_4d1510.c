/* Ghidra pseudocode, not original source.
 * ev_dd26b1472d11f86911997a5210ef83804c7265178bcab9b4c8b40141cd7b855f
 * Entry: 0x4d1510; label: FUN_004d1510
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_004d1510(void)

{
  float fVar1;
  float fVar2;
  int in_EAX;
  int iVar3;
  uint uVar4;
  float10 fVar5;
  undefined4 local_c;
  float local_8;
  undefined4 local_4;
  
  iVar3 = FUN_004d09a0();
  if (iVar3 == 0) {
    return 0;
  }
  *(int *)(in_EAX + 0x798) = iVar3;
  *(undefined1 *)(in_EAX + 0x7b5) = 0x44;
  *(uint *)(in_EAX + 0x7bc) =
       *(uint *)(in_EAX + 0x7bc) ^
       (~(*(uint *)(*(int *)(*(int *)(in_EAX + 0x54) + 0x24) + 0x90) >> 8) ^
       *(uint *)(in_EAX + 0x7bc)) & 0x800;
  if ((*(int *)(*(int *)(*(int *)(in_EAX + 0x50) + 0xc) + 0x23c) == 0) ||
     (((*(uint *)(*(int *)(*(int *)(in_EAX + 0x54) + 0x24) + 0x90) & 0x80000) != 0 &&
      (local_8 <=
       (*(float *)(in_EAX + 0x194) - *(float *)(in_EAX + 0x1a0)) * 0.25 + *(float *)(in_EAX + 0x1a0)
      )))) {
    *(undefined2 *)(in_EAX + 0x7aa) = 0x88;
  }
  else {
    *(undefined2 *)(in_EAX + 0x7aa) = 0x8f;
    fVar5 = (float10)FUN_0062e040((int)*(short *)(in_EAX + 0x1064),0x8f,0,0,1);
    *(float *)(in_EAX + 0x77c) = (float)fVar5;
  }
  *(undefined4 *)(in_EAX + 0x754) = local_c;
  *(float *)(in_EAX + 0x758) = local_8;
  *(undefined4 *)(in_EAX + 0x75c) = local_4;
  uVar4 = FUN_00550040(*(undefined2 *)(*(int *)(in_EAX + 0x798) + 0x44),
                       *(undefined2 *)(in_EAX + 0x5a));
  iVar3 = *(int *)(in_EAX + 0x798);
  if ((int)((uVar4 ^ (int)uVar4 >> 0x1f) - ((int)uVar4 >> 0x1f)) < 0x4001) {
    *(undefined2 *)(in_EAX + 0x5a) = *(undefined2 *)(iVar3 + 0x44);
  }
  else {
    *(short *)(in_EAX + 0x5a) = *(short *)(iVar3 + 0x44) + -0x8000;
  }
  fVar5 = (float10)FUN_005bed80(in_EAX + 0x80,iVar3 + 0x10,0);
  *(float *)(in_EAX + 0x778) = (float)fVar5;
  fVar1 = *(float *)(*(int *)(in_EAX + 0x798) + 0x3c);
  fVar2 = *(float *)(*(int *)(in_EAX + 0x798) + 0x34);
  fVar5 = (float10)FUN_005c0240(fVar2 * fVar2 + fVar1 * fVar1);
  iVar3 = FUN_005be2d0(*(undefined4 *)(*(int *)(in_EAX + 0x798) + 0x38),(float)fVar5);
  FUN_005b35a0(&local_c,&DAT_00802500,-iVar3);
  FUN_005b3620(&local_c,&local_c,*(undefined2 *)(*(int *)(in_EAX + 0x798) + 0x44));
  FUN_0054fec0(&local_c,(undefined2 *)(in_EAX + 0x7a4),(undefined2 *)(in_EAX + 0x7a8));
  if ((*(uint *)(*(int *)(*(int *)(in_EAX + 0x54) + 0x24) + 0x90) & 0x10000000) != 0) {
    local_4 = 0;
    local_c = 0;
    local_8 = *(float *)(in_EAX + 0x194) - *(float *)(in_EAX + 0x1a0);
    iVar3 = in_EAX + 0x760;
    FUN_005b3690(iVar3,&local_c,*(undefined2 *)(in_EAX + 0x7a8));
    FUN_005b35a0(iVar3,iVar3,*(undefined2 *)(in_EAX + 0x7a4));
    FUN_005b3800(iVar3,&local_c,iVar3);
    return 1;
  }
  *(undefined4 *)(in_EAX + 0x760) = DAT_0093b0cc;
  *(undefined4 *)(in_EAX + 0x764) = DAT_0093b0d0;
  *(undefined4 *)(in_EAX + 0x768) = DAT_0093b0d4;
  return 1;
}


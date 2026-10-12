/* Ghidra analysis pseudocode, not original source.
 * ev_d9778a7e5954a243ecb5357ce6ca10d0e931dd6eaae906e14f50961a2e2268e2
 * Entry: 0x4bd090; label: FUN_004bd090
 */

void FUN_004bd090(void)

{
  int iVar1;
  float fVar2;
  int in_EAX;
  float10 fVar3;
  
  *(undefined4 *)(in_EAX + 0xa8) = 0;
  *(undefined4 *)(in_EAX + 0xa4) = 0;
  iVar1 = in_EAX + 0xa4;
  *(undefined4 *)(in_EAX + 0xac) = 0x3ecccccd;
  FUN_005b3620(iVar1,iVar1,*(undefined2 *)(in_EAX + 0xa0));
  FUN_005b37d0(iVar1,iVar1,in_EAX + 0x90);
  FUN_0067a6d0();
  fVar3 = (float10)FUN_005506f0(0,iVar1,0x40a00000,0xffffffff);
  fVar2 = (float)fVar3;
  *(float *)(in_EAX + 0xa8) = fVar2;
  if (fVar2 != 2e+06) {
    *(float *)(in_EAX + 0xa8) = fVar2 + 0.005;
    FUN_0054fec0(&DAT_0292fdb8,in_EAX + 0xb0,in_EAX + 0xb2);
  }
  *(undefined4 *)(in_EAX + 0xb4) = 0;
  *(undefined1 *)(in_EAX + 0xa3) = 0;
  *(byte *)(in_EAX + 0xa2) = *(byte *)(in_EAX + 0xa2) & 0xf3 | 3;
  FUN_004bce60(0);
  FUN_0067c7b0((int)*(short *)(in_EAX + 0x9c),1);
  FUN_0067c7b0((int)*(short *)(in_EAX + 0x9e),1);
  return;
}


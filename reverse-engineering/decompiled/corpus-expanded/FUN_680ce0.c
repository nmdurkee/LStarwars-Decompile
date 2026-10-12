/* Ghidra pseudocode, not original source.
 * ev_32eeff13403f2b0416c64559eab438b182c65995ce85fb3a27dd5c4451fc4fee
 * Entry: 0x680ce0; label: FUN_00680ce0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00680ce0(void)

{
  float fVar1;
  int iVar2;
  
  DAT_0292fb68 = 0xffffffff;
  DAT_0292fdc8 = 0xffffffff;
  DAT_02947d88 = 0;
  DAT_0292125e = 0;
  DAT_02921834 = 0;
  _DAT_02921258 = 0;
  iVar2 = FUN_006de8d0(0x948);
  *(undefined4 *)(iVar2 + 0x5c) = 0x3f800000;
  *(undefined4 *)(iVar2 + 0x60) = 0x3f800000;
  *(undefined4 *)(iVar2 + 100) = 0x3f800000;
  *(undefined4 *)(iVar2 + 0x68) = 0x3f800000;
  DAT_0292186c = iVar2;
  *(undefined4 *)(iVar2 + 0x50) = 0x3dcccccd;
  *(undefined4 *)(iVar2 + 0x58) = 0x41200000;
  *(undefined4 *)(iVar2 + 0x54) = 0x3c23d70b;
  fVar1 = DAT_00973718 - 2.0;
  *(float *)(iVar2 + 0x1c) = fVar1;
  *(float *)(iVar2 + 4) = fVar1;
  fVar1 = DAT_0097371c - 2.0;
  *(float *)(iVar2 + 0x20) = fVar1;
  *(float *)(iVar2 + 8) = fVar1;
  fVar1 = DAT_00973720 - 2.0;
  *(undefined2 *)(iVar2 + 0x36) = 0;
  *(undefined4 *)(iVar2 + 0x40) = 0;
  *(undefined1 *)(iVar2 + 0x34) = 0;
  *(float *)(iVar2 + 0x24) = fVar1;
  *(float *)(iVar2 + 0xc) = fVar1;
  *(undefined4 *)(iVar2 + 0x28) = 0x40800000;
  *(undefined4 *)(iVar2 + 0x10) = 0x40800000;
  *(undefined4 *)(iVar2 + 0x2c) = 0x40800000;
  *(undefined4 *)(iVar2 + 0x14) = 0x40800000;
  *(undefined4 *)(iVar2 + 0x30) = 0x40800000;
  *(undefined4 *)(iVar2 + 0x18) = 0x40800000;
  *(undefined4 *)(iVar2 + 0x38) = 0;
  *(undefined4 *)(iVar2 + 0xa0) = 0x3c23d70a;
  *(undefined4 *)(iVar2 + 0xa4) = 0x3727c5ac;
  FUN_00675f60(1,1,0);
  FUN_006de960();
  return;
}


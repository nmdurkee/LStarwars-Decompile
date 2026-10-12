/* Ghidra pseudocode, not original source.
 * ev_96889fd8ad85600c7e65ee5089ba5210c04395d98557e70e963bff93f64702f9
 * Entry: 0x67b280; label: FUN_0067b280
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined1 FUN_0067b280(undefined4 *param_1,undefined4 *param_2,float param_3,int param_4)

{
  undefined4 uVar1;
  float fVar2;
  int iVar3;
  
  DAT_0292fb68 = 0xffffffff;
  DAT_0292fdc8 = 0xffffffff;
  DAT_02947d88 = 0;
  DAT_0292125e = 0;
  DAT_02961fdc = 0xffff;
  if (DAT_0292fc68 == 0) {
    return 0;
  }
  iVar3 = FUN_006de8d0(0x948);
  *(undefined4 *)(iVar3 + 0x5c) = 0x3f800000;
  *(undefined4 *)(iVar3 + 0x60) = 0x3f800000;
  *(undefined4 *)(iVar3 + 100) = 0x3f800000;
  DAT_0292186c = iVar3;
  *(undefined4 *)(iVar3 + 0x68) = 0x3f800000;
  DAT_02948edc = 0;
  *(float *)(iVar3 + 0x50) = param_3;
  fVar2 = 0.0;
  if (param_3 != 0.0) {
    fVar2 = 1.0 / param_3;
  }
  *(float *)(iVar3 + 0x58) = fVar2;
  *(float *)(iVar3 + 0x54) = param_3 * param_3;
  uVar1 = *param_1;
  *(undefined4 *)(iVar3 + 0x1c) = uVar1;
  *(undefined4 *)(iVar3 + 4) = uVar1;
  uVar1 = param_1[1];
  *(undefined4 *)(iVar3 + 0x20) = uVar1;
  *(undefined4 *)(iVar3 + 8) = uVar1;
  uVar1 = param_1[2];
  *(undefined4 *)(iVar3 + 0x24) = uVar1;
  *(undefined4 *)(iVar3 + 0xc) = uVar1;
  *(undefined4 *)(iVar3 + 0x28) = *param_2;
  *(undefined4 *)(iVar3 + 0x2c) = param_2[1];
  *(undefined4 *)(iVar3 + 0x30) = param_2[2];
  *(undefined4 *)(iVar3 + 0x10) = *param_2;
  *(undefined4 *)(iVar3 + 0x14) = param_2[1];
  uVar1 = param_2[2];
  *(undefined4 *)(iVar3 + 0xa0) = 0x3c23d70a;
  *(undefined4 *)(iVar3 + 0xa4) = 0x3727c5ac;
  *(undefined4 *)(iVar3 + 0x18) = uVar1;
  *(undefined2 *)(iVar3 + 0x36) = 0xffff;
  *(undefined4 *)(iVar3 + 0x40) = 0;
  *(undefined1 *)(iVar3 + 0x34) = 1;
  FUN_00675f60(1,0,-(param_4 != 0) & 0x40);
  FUN_0066f8f0();
  FUN_00675240();
  if (*(char *)(DAT_0292186c + 0x88) != '\0') {
    FUN_00678580(param_2);
    FUN_00678410();
    DAT_0292fdb8 = *(undefined4 *)(DAT_0292186c + 0xa8);
    DAT_0292fdbc = *(undefined4 *)(DAT_0292186c + 0xac);
    DAT_0292fdc0 = *(undefined4 *)(DAT_0292186c + 0xb0);
  }
  FUN_006de960();
  return *(undefined1 *)(DAT_0292186c + 0x88);
}


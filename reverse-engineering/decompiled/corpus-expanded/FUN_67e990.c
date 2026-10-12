/* Ghidra pseudocode, not original source.
 * ev_32eeff13403f2b0416c64559eab438b182c65995ce85fb3a27dd5c4451fc4fee
 * Entry: 0x67e990; label: FUN_0067e990
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4
FUN_0067e990(undefined4 *param_1,undefined4 *param_2,float param_3,undefined4 param_4,int param_5)

{
  float fVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (DAT_0292fc68 == 0) {
    return 0;
  }
  DAT_00810b2c = 0xffffffff;
  iVar2 = FUN_006de8d0(0x948);
  *(undefined4 *)(iVar2 + 0x5c) = 0x3f800000;
  *(undefined4 *)(iVar2 + 0x60) = 0x3f800000;
  *(undefined4 *)(iVar2 + 100) = 0x3f800000;
  DAT_0292186c = iVar2;
  *(undefined4 *)(iVar2 + 0x68) = 0x3f800000;
  *(float *)(iVar2 + 0x50) = param_3;
  fVar1 = 0.0;
  if (param_3 != 0.0) {
    fVar1 = 1.0 / param_3;
  }
  *(float *)(iVar2 + 0x58) = fVar1;
  *(float *)(iVar2 + 0x54) = param_3 * param_3;
  uVar3 = *param_1;
  *(undefined4 *)(iVar2 + 0x1c) = uVar3;
  *(undefined4 *)(iVar2 + 4) = uVar3;
  uVar3 = param_1[1];
  *(undefined4 *)(iVar2 + 0x20) = uVar3;
  *(undefined4 *)(iVar2 + 8) = uVar3;
  uVar3 = param_1[2];
  *(undefined4 *)(iVar2 + 0x24) = uVar3;
  *(undefined4 *)(iVar2 + 0xc) = uVar3;
  *(undefined4 *)(iVar2 + 0x28) = *param_2;
  *(undefined4 *)(iVar2 + 0x2c) = param_2[1];
  *(undefined4 *)(iVar2 + 0x30) = param_2[2];
  *(undefined4 *)(iVar2 + 0x10) = *param_2;
  *(undefined4 *)(iVar2 + 0x14) = param_2[1];
  *(undefined4 *)(iVar2 + 0x18) = param_2[2];
  *(undefined2 *)(iVar2 + 0x36) = 0xffff;
  *(undefined4 *)(iVar2 + 0x40) = 0;
  *(undefined1 *)(iVar2 + 0x34) = 1;
  if (param_5 == 0) {
    uVar3 = FUN_0067cb40(param_1,param_2,param_3,param_4);
    FUN_006de960();
    return uVar3;
  }
  uVar3 = FUN_0067dca0(param_5,param_1,param_2,param_3,0xff);
  FUN_006de960();
  return uVar3;
}


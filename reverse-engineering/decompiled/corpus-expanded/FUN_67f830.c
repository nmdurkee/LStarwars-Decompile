/* Ghidra pseudocode, not original source.
 * ev_32eeff13403f2b0416c64559eab438b182c65995ce85fb3a27dd5c4451fc4fee
 * Entry: 0x67f830; label: FUN_0067f830
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined1
FUN_0067f830(undefined4 *param_1,undefined4 *param_2,float param_3,undefined4 param_4,
            undefined4 param_5,int param_6,undefined4 param_7)

{
  undefined4 uVar1;
  int iVar2;
  int extraout_ECX;
  float10 fVar3;
  
  DAT_0292fb68 = 0xffffffff;
  DAT_0292fdc8 = 0xffffffff;
  DAT_02947d88 = 0;
  DAT_0292125e = 0;
  DAT_02961fdc = 0xffff;
  if (DAT_0292fc68 == 0) {
    return 0;
  }
  if (param_6 != 0) {
    iVar2 = FUN_006de8d0(0x948);
    *(undefined4 *)(iVar2 + 0x5c) = 0x3f800000;
    *(undefined4 *)(iVar2 + 0x60) = 0x3f800000;
    *(undefined4 *)(iVar2 + 100) = 0x3f800000;
    DAT_0292186c = iVar2;
    *(undefined4 *)(iVar2 + 0x68) = 0x3f800000;
    DAT_02948edc = 0;
    *(float *)(iVar2 + 0x50) = param_3;
    fVar3 = (float10)0;
    if (fVar3 != (float10)param_3) {
      fVar3 = (float10)FUN_0064fde0(0x3f800000,param_3);
      iVar2 = extraout_ECX;
    }
    *(float *)(iVar2 + 0x58) = (float)fVar3;
    *(float *)(iVar2 + 0x54) = *(float *)(iVar2 + 0x50) * *(float *)(iVar2 + 0x50);
    uVar1 = *param_1;
    *(undefined4 *)(iVar2 + 0x1c) = uVar1;
    *(undefined4 *)(iVar2 + 4) = uVar1;
    uVar1 = param_1[1];
    *(undefined4 *)(iVar2 + 0x20) = uVar1;
    *(undefined4 *)(iVar2 + 8) = uVar1;
    uVar1 = param_1[2];
    *(undefined4 *)(iVar2 + 0x24) = uVar1;
    *(undefined4 *)(iVar2 + 0xc) = uVar1;
    *(undefined4 *)(iVar2 + 0x28) = *param_2;
    *(undefined4 *)(iVar2 + 0x2c) = param_2[1];
    *(undefined4 *)(iVar2 + 0x30) = param_2[2];
    *(undefined4 *)(iVar2 + 0x10) = *param_2;
    *(undefined4 *)(iVar2 + 0x14) = param_2[1];
    uVar1 = param_2[2];
    *(undefined4 *)(iVar2 + 0xa0) = param_4;
    *(undefined4 *)(iVar2 + 0xa4) = param_5;
    *(undefined4 *)(iVar2 + 0x18) = uVar1;
    *(undefined2 *)(iVar2 + 0x36) = 0xffff;
    *(undefined4 *)(iVar2 + 0x40) = 0;
    *(undefined1 *)(iVar2 + 0x34) = 1;
    FUN_0067eac0(param_7,param_6);
    FUN_0066f8f0();
    FUN_00675240();
    if (*(char *)(DAT_0292186c + 0x88) != '\0') {
      FUN_00678580(param_2);
      FUN_00678410();
      DAT_0292fdb8 = *(undefined4 *)(DAT_0292186c + 0xa8);
      DAT_0292fdbc = *(undefined4 *)(DAT_0292186c + 0xac);
      DAT_0292fdc0 = *(undefined4 *)(DAT_0292186c + 0xb0);
      DAT_02947d88 = *(undefined4 *)(DAT_0292186c + 0x90);
    }
    FUN_006de960();
    return *(undefined1 *)(DAT_0292186c + 0x88);
  }
  return 0;
}


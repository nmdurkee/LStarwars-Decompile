/* Ghidra analysis pseudocode, not original source.
 * ev_6fbd3af984a39447bc9fe9dd191dc75e4e15fa1d77defc2a7b40b22f43e8d294
 * Entry: 0x67f9e0; label: FUN_0067f9e0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_0067f9e0(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                    undefined4 param_5,int param_6)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 local_c;
  float local_8;
  undefined4 local_4;
  
  if (DAT_0292fc68 == 0) {
    return (float10)2e+06;
  }
  if (param_6 == 0) {
    return (float10)0;
  }
  _DAT_02924b08 = 0x49f42400;
  _DAT_02920d84 = 0x49f42400;
  _DAT_0292fdc8 = 0xffffffff;
  _DAT_02962004 = 0x3f800000;
  DAT_02961fdc = 0xffff;
  _DAT_0292fbf4 = 0xffff;
  _DAT_02921864 = 0x49f42400;
  _DAT_02920ab0 = 0;
  _DAT_0292fdcc = 0;
  DAT_0292fd44 = 0;
  DAT_0292fdbc = 0x3f800000;
  DAT_0292182c = 0;
  _DAT_02947d90 = 0;
  DAT_0292fbf0 = 0;
  iVar2 = FUN_006de8d0(0x948);
  *(undefined4 *)(iVar2 + 0x5c) = 0x3f800000;
  *(undefined4 *)(iVar2 + 0x60) = 0x3f800000;
  DAT_0292186c = iVar2;
  *(undefined4 *)(iVar2 + 100) = 0x3f800000;
  *(undefined4 *)(iVar2 + 0x68) = 0x3f800000;
  *(undefined4 *)(iVar2 + 0x50) = 0x3dcccccd;
  *(undefined4 *)(iVar2 + 0x58) = 0x41200000;
  *(undefined4 *)(iVar2 + 0x54) = 0x3c23d70b;
  *(undefined4 *)(iVar2 + 0x1c) = *param_1;
  *(float *)(iVar2 + 0x20) = (float)param_1[1] - 20.0;
  uVar1 = param_1[2];
  *(undefined2 *)(iVar2 + 0x36) = 0xffff;
  *(undefined4 *)(iVar2 + 0x24) = uVar1;
  *(undefined1 *)(iVar2 + 0x34) = 1;
  *(undefined4 *)(iVar2 + 0x30) = 0;
  *(undefined4 *)(iVar2 + 0x28) = 0;
  *(undefined4 *)(iVar2 + 0x2c) = 0x42200000;
  local_c = *param_1;
  DAT_02924b34 = DAT_02962b30;
  local_8 = (float)param_1[1];
  local_4 = param_1[2];
  FUN_0067eac0(param_5,param_6);
  FUN_006729e0(&local_c,param_3,param_4);
  FUN_006de960();
  DAT_0292fb54 = 0;
  return (float10)local_8;
}


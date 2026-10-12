/* Ghidra analysis pseudocode, not original source.
 * ev_e2fbe3df4bc4fbdf62093b0f900a9735f5717e0efc1b865b12ee91c40549ae6e
 * Entry: 0x499170; label: FUN_00499170
 */

void FUN_00499170(float param_1,undefined4 param_2,int *param_3)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  iVar2 = (int)param_1;
  *(undefined4 *)((int)param_1 + 0xf20) = 0;
  *(undefined4 *)((int)param_1 + 0xf1c) = 0;
  *(undefined4 *)((int)param_1 + 0xf18) = 0;
  if (param_1 == (float)DAT_0093d7f0) {
    local_c = *(undefined4 *)(DAT_0093d7f4 + 0x5c);
    local_8 = *(undefined4 *)(DAT_0093d7f4 + 0x60);
    local_4 = *(undefined4 *)(DAT_0093d7f4 + 100);
    iVar3 = DAT_0093d7f4;
  }
  else if (param_1 == (float)DAT_0093d7f4) {
    local_c = *(undefined4 *)(DAT_0093d7f0 + 0x5c);
    local_8 = *(undefined4 *)(DAT_0093d7f0 + 0x60);
    local_4 = *(undefined4 *)(DAT_0093d7f0 + 100);
    iVar3 = DAT_0093d7f0;
  }
  else {
    param_1 = 0.0;
    local_c = DAT_0093b0cc;
    local_8 = DAT_0093b0d0;
    local_4 = DAT_0093b0d4;
    if (DAT_0093d7f0 != 0) {
      FUN_005b37d0(&local_c,&local_c,DAT_0093d7f0 + 0x5c);
      param_1 = 1.0;
    }
    if (DAT_0093d7f4 != 0) {
      FUN_005b37d0(&local_c,&local_c,DAT_0093d7f4 + 0x5c);
      param_1 = param_1 + 1.0;
    }
    if (0.0 < param_1) {
      FUN_005b3830(&local_c,&local_c,1.0 / param_1);
    }
    iVar3 = 0;
  }
  FUN_0054fb80(iVar2 + 0x5c,iVar2 + 0x5c,&local_c,0x41200000);
  *(undefined4 *)(iVar2 + 0x68) = *(undefined4 *)(iVar2 + 0xf18);
  *(undefined4 *)(iVar2 + 0x6c) = *(undefined4 *)(iVar2 + 0xf1c);
  *(undefined4 *)(iVar2 + 0x70) = *(undefined4 *)(iVar2 + 0xf20);
  if (iVar3 != 0) {
    uVar1 = *(undefined2 *)(iVar3 + 0x27a);
    *(undefined2 *)(iVar2 + 0x27a) = uVar1;
    *(undefined2 *)(iVar2 + 0x5a) = uVar1;
    *(undefined2 *)(iVar2 + 0x58) = uVar1;
  }
  if (param_3 != (int *)0x0) {
    *param_3 = iVar3;
  }
  *(undefined4 *)(iVar2 + 0xd48) = 0;
  *(undefined4 *)(iVar2 + 0xddc) = 0;
  return;
}


/* Ghidra analysis pseudocode, not original source.
 * ev_71ff980de6cd2ba2d40ffdcea863fac96239c7d224aa9f068f740db15dbd9919
 * Entry: 0x52ff40; label: FUN_0052ff40
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0052ff40(undefined4 param_1,int param_2,int param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  float10 fVar4;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  puVar3 = (undefined4 *)(param_3 + 0x5c);
  fVar4 = (float10)FUN_005bed80(puVar3,param_2 + 0x1b4,&local_3c);
  if ((float)fVar4 == 0.0) {
    local_3c = *(undefined4 *)(param_2 + 0x1c4);
    local_38 = 0;
    local_34 = 0;
  }
  else {
    FUN_005b3830(&local_3c,&local_3c,*(float *)(param_2 + 0x1c4) / (float)fVar4);
  }
  puVar1 = (undefined4 *)(param_2 + 0x104);
  FUN_005b37d0(puVar1,param_2 + 0x1b4,&local_3c);
  *(undefined4 *)(param_2 + 0x110) = 0;
  fVar4 = (float10)FUN_005bed80(puVar1,puVar3,&local_3c);
  if (_DAT_00801c6c < (float)fVar4) {
    FUN_005b3830(&local_3c,&local_3c,_DAT_00801c6c / (float)fVar4);
    FUN_005b37d0(puVar1,puVar3,&local_3c);
  }
  local_14 = *(undefined4 *)(param_2 + 0x15c);
  local_c = *(undefined4 *)(param_2 + 0x164);
  local_10 = *(undefined4 *)(param_2 + 0x160);
  uVar2 = *(undefined4 *)(param_2 + 0x158);
  local_8 = *(undefined4 *)(param_2 + 0x168);
  local_30 = *puVar3;
  local_4 = *(undefined4 *)(param_2 + 0x16c);
  local_2c = *(undefined4 *)(param_3 + 0x60);
  local_24 = *(undefined4 *)(param_2 + 0x170);
  local_28 = *(undefined4 *)(param_3 + 100);
  local_20 = *(undefined4 *)(param_2 + 0x174);
  local_1c = *(undefined4 *)(param_2 + 0x178);
  *puVar3 = *puVar1;
  *(undefined4 *)(param_3 + 0x60) = *(undefined4 *)(param_2 + 0x108);
  *(undefined4 *)(param_3 + 100) = *(undefined4 *)(param_2 + 0x10c);
  FUN_0052f800(param_1,param_3,param_2,0,1);
  *puVar1 = *(undefined4 *)(param_2 + 0x170);
  *(undefined4 *)(param_2 + 0x108) = *(undefined4 *)(param_2 + 0x174);
  *(undefined4 *)(param_2 + 0x158) = uVar2;
  *(undefined4 *)(param_2 + 0x15c) = local_14;
  *(undefined4 *)(param_2 + 0x160) = local_10;
  *(undefined4 *)(param_2 + 0x10c) = *(undefined4 *)(param_2 + 0x178);
  *(undefined4 *)(param_2 + 0x164) = local_c;
  *(undefined4 *)(param_2 + 0x168) = local_8;
  *(undefined4 *)(param_2 + 0x16c) = local_4;
  *puVar3 = local_30;
  *(undefined4 *)(param_3 + 0x60) = local_2c;
  *(undefined4 *)(param_3 + 100) = local_28;
  *(undefined4 *)(param_2 + 0x170) = local_24;
  *(undefined4 *)(param_2 + 0x174) = local_20;
  *(undefined4 *)(param_2 + 0x178) = local_1c;
  return;
}


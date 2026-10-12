/* Ghidra analysis pseudocode, not original source.
 * ev_04eba8a6041128e42a5942cb543eca22153343fab03a80410cc8a046c9872535
 * Entry: 0x51c150; label: FUN_0051c150
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
FUN_0051c150(float param_1,undefined4 param_2,undefined4 param_3,int param_4,float param_5,
            undefined4 param_6)

{
  int iVar1;
  short sVar2;
  int in_EAX;
  undefined4 uVar3;
  int iVar4;
  int in_ECX;
  int unaff_EDI;
  float local_68;
  float fStack_64;
  float local_60;
  undefined4 local_5c;
  undefined4 local_58;
  float fStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  float local_48 [3];
  float afStack_3c [3];
  float fStack_30;
  float fStack_2c;
  undefined4 uStack_28;
  float fStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined1 auStack_18 [12];
  undefined1 auStack_c [12];
  
  iVar4 = (int)param_5;
  iVar1 = (int)param_1;
  param_1 = *(float *)(in_EAX + 0xac) + _DAT_00801c88;
  local_60 = *(float *)(unaff_EDI + 0x10) - param_1;
  if (local_60 < 0.0) {
    local_60 = 0.0;
  }
  param_5 = *(float *)(param_4 + 0x10) - param_1;
  if (param_5 < 0.0) {
    param_5 = 0.0;
  }
  param_1 = *(float *)(iVar4 + 0x10) - param_1;
  if (param_1 < 0.0) {
    param_1 = 0.0;
  }
  local_5c = 0;
  local_58 = 0;
  local_48[1] = 0.0;
  local_48[2] = *(float *)(in_ECX + 0x1c);
  local_68 = (param_5 - local_60) / *(float *)(in_ECX + 0x1c);
  local_48[0] = local_60;
  sVar2 = FUN_00512900(local_68);
  uVar3 = FUN_005be590(param_2,(int)sVar2);
  FUN_005b3620(&local_60,&local_60,uVar3);
  FUN_005b3620(local_48,local_48,uVar3);
  FUN_005b37d0(&local_60,&local_60,unaff_EDI + 4);
  FUN_005b37d0(local_48,local_48,unaff_EDI + 4);
  fStack_54 = -param_1;
  uStack_50 = 0;
  uStack_4c = 0;
  afStack_3c[1] = 0.0;
  afStack_3c[2] = *(float *)(iVar1 + 0x1c);
  afStack_3c[0] = fStack_54;
  sVar2 = FUN_00512900((param_5 - param_1) / *(float *)(iVar1 + 0x1c));
  uVar3 = FUN_005be5b0(param_3,(int)sVar2);
  FUN_005b3620(&fStack_54,&fStack_54,uVar3);
  FUN_005b3620(afStack_3c,afStack_3c,uVar3);
  iVar4 = iVar4 + 4;
  FUN_005b37d0(&fStack_54,&fStack_54,iVar4);
  FUN_005b37d0(afStack_3c,afStack_3c,iVar4);
  fStack_30 = local_60;
  fStack_2c = (float)local_5c;
  uStack_28 = local_58;
  FUN_005b3800(auStack_18,local_48,&fStack_30);
  fStack_24 = fStack_54;
  uStack_20 = uStack_50;
  uStack_1c = uStack_4c;
  FUN_005b3800(auStack_c,afStack_3c,&fStack_24);
  iVar4 = FUN_005bee20(&fStack_30,auStack_18,&fStack_24,auStack_c,&local_68,&fStack_64);
  if ((((iVar4 != 0) && (0.0 <= local_68)) && (0.0 <= fStack_64)) &&
     ((local_68 <= 1.0 && (fStack_64 <= 1.0)))) {
    fStack_2c = *(float *)(param_4 + 8) * local_68 + (1.0 - local_68) * *(float *)(unaff_EDI + 8);
    FUN_005b3830(auStack_18,auStack_18,local_68);
    FUN_005b37d0(param_6,&fStack_30,auStack_18);
    return 1;
  }
  return 0;
}


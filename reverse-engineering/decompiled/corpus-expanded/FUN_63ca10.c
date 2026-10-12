/* Ghidra pseudocode, not original source.
 * ev_0e84ad542db3be7599677a500db2c2fcd5f6f463504cd13a52c31f7d7facbfa7
 * Entry: 0x63ca10; label: FUN_0063ca10
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0063ca10(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  uint local_84;
  byte local_80;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  uint local_40;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  uint local_1c;
  
  param_1 = param_1 * 0x8c;
  local_80 = (byte)(longlong)ROUND(*(float *)(param_1 + 0x30 + DAT_0291389c) * 255.0);
  uVar2 = (uint)local_80;
  local_80 = (byte)(longlong)ROUND(*(float *)(param_1 + 0x2c + DAT_0291389c) * 255.0);
  uVar1 = (uint)local_80;
  local_80 = (byte)(longlong)ROUND(*(float *)(param_1 + 0x28 + DAT_0291389c) * 255.0);
  uVar1 = ((uVar2 | 0xffff8000) << 8 | uVar1) << 8 | (uint)local_80;
  local_84 = uVar1;
  if (param_2 == 1) {
    uVar2 = ~uVar1;
  }
  else {
    uVar2 = uVar1;
    if (param_2 == 2) {
      local_84 = ~uVar1;
    }
  }
  switch(*(undefined1 *)(param_1 + 0x5c + DAT_0291389c)) {
  case 1:
    uVar4 = *(undefined4 *)(param_1 + 0x40 + DAT_0291389c);
    uVar5 = (&DAT_029135ec)[DAT_029139a8 != 0];
    break;
  case 2:
  case 3:
  case 6:
  case 7:
  case 8:
    uVar4 = *(undefined4 *)(param_1 + 0x40 + DAT_0291389c);
    uVar5 = (&DAT_029135ec)[DAT_029139a8 != 0];
    break;
  case 4:
    local_58 = *(undefined4 *)(param_1 + 4 + DAT_0291389c);
    local_54 = *(undefined4 *)(param_1 + 8 + DAT_0291389c);
    local_50 = *(undefined4 *)(param_1 + 0xc + DAT_0291389c);
    local_40 = uVar1;
    local_1c = uVar1;
    FUN_005b3830(&local_34,param_1 + 0x10 + DAT_0291389c,
                 *(undefined4 *)(param_1 + 0x44 + DAT_0291389c));
    FUN_005b3800(&local_34,&local_58,&local_34);
    FUN_005dc050(local_58,local_54,local_50,local_34,local_30,local_2c,local_40);
    FUN_00623e00(param_1 + 4 + DAT_0291389c,*(undefined4 *)(param_1 + 0x40 + DAT_0291389c),uVar2,
                 DAT_0080ff40,(&DAT_029135ec)[DAT_029139a8 != 0]);
    if (*(float *)(param_1 + 0x40 + DAT_0291389c) < *(float *)(param_1 + 0x44 + DAT_0291389c)) {
      uVar4 = *(undefined4 *)(param_1 + 0x44 + DAT_0291389c);
      uVar5 = (&DAT_029135ec)[DAT_029139a8 != 0];
      iVar3 = param_1 + 4 + DAT_0291389c;
      goto LAB_0063ce22;
    }
    goto LAB_0063ce30;
  case 5:
    local_58 = *(undefined4 *)(param_1 + 4 + DAT_0291389c);
    local_54 = *(undefined4 *)(param_1 + 8 + DAT_0291389c);
    local_50 = *(undefined4 *)(param_1 + 0xc + DAT_0291389c);
    local_40 = uVar1;
    local_1c = uVar1;
    FUN_005b3830(&local_34,param_1 + 0x10 + DAT_0291389c,0x40000000);
    FUN_005b3200(&local_34,&local_34,&DAT_009736e8);
    FUN_005b3800(&local_34,&local_58,&local_34);
    FUN_005dc050(local_58,local_54,local_50,local_34,local_30,local_2c,local_40);
    FUN_00623e00(param_1 + 4 + DAT_0291389c,0x40000000,uVar1,DAT_0080ff40,
                 (&DAT_029135ec)[DAT_029139a8 != 0]);
    iVar3 = param_1 + 4 + DAT_0291389c;
    if (iVar3 == DAT_02913824) {
      FUN_00623fc0(iVar3,0x40000000,0xffffffff,(&DAT_029135ec)[DAT_029139a8 != 0]);
      return;
    }
  default:
    goto switchD_0063caea_default;
  }
  FUN_00623e00(param_1 + 4 + DAT_0291389c,uVar4,uVar2,DAT_0080ff40,uVar5);
  if (*(float *)(param_1 + 0x40 + DAT_0291389c) < *(float *)(param_1 + 0x44 + DAT_0291389c)) {
    uVar4 = *(undefined4 *)(param_1 + 0x44 + DAT_0291389c);
    uVar5 = (&DAT_029135ec)[DAT_029139a8 != 0];
    iVar3 = param_1 + 4 + DAT_0291389c;
LAB_0063ce22:
    FUN_00623e00(iVar3,uVar4,local_84,DAT_0080ff40,uVar5);
  }
LAB_0063ce30:
  iVar3 = param_1 + 4 + DAT_0291389c;
  if (iVar3 == DAT_02913824) {
    FUN_00623fc0(iVar3,*(undefined4 *)(param_1 + 0x44 + DAT_0291389c),0xffffffff,
                 (&DAT_029135ec)[DAT_029139a8 != 0]);
  }
switchD_0063caea_default:
  return;
}


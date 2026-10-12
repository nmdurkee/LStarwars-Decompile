/* Ghidra analysis pseudocode, not original source.
 * ev_d6cfc7f984a94bc477afc350e10de4c03e30e64e3e924293972bd20ad72e1aa6
 * Entry: 0x4c5020; label: FUN_004c5020
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004c5020(undefined4 param_1,undefined4 param_2,float param_3)

{
  undefined4 uVar1;
  bool bVar2;
  undefined *in_EAX;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  bool bVar6;
  bool bVar7;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined1 local_40 [52];
  float local_c;
  
  iVar3 = FUN_005cfac0(&DAT_0087c25c);
  if (iVar3 != 0) {
    bVar6 = in_EAX == &DAT_0087c00c;
    if (bVar6) {
      FUN_005b7d30(_DAT_0092505c,(float)DAT_008800d8 * 0.2);
      iVar3 = FUN_006e6b90();
      in_EAX = (undefined *)(DAT_00880478 + iVar3 * -0x74);
    }
    uVar5 = (uint)*(ushort *)(in_EAX + 0x60);
    bVar2 = true;
    if (uVar5 == (int)DAT_007f17d4) {
      bVar7 = DAT_0086e4e5 != '\0';
    }
    else {
      iVar3 = FUN_00594870(uVar5);
      bVar7 = iVar3 != 0;
    }
    if ((bVar7) && (in_EAX[99] == '\x01')) {
      bVar2 = false;
    }
    if (uVar5 == (int)DAT_007f17d4) {
      bVar7 = DAT_0086e4e5 != '\0';
    }
    else {
      iVar3 = FUN_00594870(uVar5);
      bVar7 = iVar3 != 0;
    }
    if (bVar7) {
      uVar1 = 0x3f800000;
    }
    else {
      uVar1 = 0x3f000000;
    }
    local_44 = param_2;
    local_48 = param_2;
    local_4c = param_2;
    FUN_005b45a0(local_40,&local_4c);
    FUN_004c0db0();
    FUN_004c0e90();
    uVar4 = FUN_004c0f70();
    FUN_005b4900(uVar4,param_1);
    local_c = local_c + param_3;
    uVar4 = uVar1;
    if (bVar6) {
      uVar4 = 0x3f800000;
    }
    FUN_005ff7a0(&DAT_0087c25c,local_40,uVar4);
    iVar3 = (int)*(short *)(uVar5 * 0x4c + 0x42 + DAT_0093b274);
    if (iVar3 != -1) {
      if (bVar2) {
        iVar3 = iVar3 + 1;
      }
      iVar3 = iVar3 * 0x10 + *(int *)(PTR_DAT_00802c54 + 0x2ac0);
      if (*(char *)(iVar3 + 0xe) != '\0') {
        FUN_005ff7a0(iVar3,local_40,uVar1);
      }
    }
  }
  return;
}


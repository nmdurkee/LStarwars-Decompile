/* Ghidra pseudocode, not original source.
 * ev_eea3a7cf55e62a15d31ae8423a3c3e3cacac13ee26e2c6e4adfc577ce8b80763
 * Entry: 0x744b70; label: FUN_00744b70
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00744b70(uint *param_1,int *param_2,int param_3)

{
  int iVar1;
  uint *puVar2;
  char cVar3;
  short sVar4;
  uint uVar5;
  undefined4 uVar6;
  int iVar7;
  undefined1 auStack_94 [4];
  undefined4 local_90;
  int local_8c [8];
  undefined1 local_6c;
  undefined1 local_6b;
  undefined1 local_6a;
  undefined1 local_69;
  undefined1 local_68;
  undefined1 local_67;
  undefined1 local_66;
  undefined1 local_65;
  undefined1 local_64;
  undefined1 local_63;
  undefined1 local_62;
  undefined1 local_61;
  undefined4 local_60;
  undefined4 local_5c;
  undefined1 local_58;
  undefined1 local_57;
  undefined1 local_56;
  undefined1 local_55;
  undefined1 local_54;
  undefined1 local_53;
  undefined1 local_52;
  undefined1 local_51;
  undefined1 local_50;
  undefined1 local_4f;
  undefined1 local_4e;
  undefined1 local_4d;
  undefined1 local_4c;
  undefined1 local_4b;
  undefined1 local_4a;
  undefined1 local_49;
  undefined1 local_48;
  undefined1 local_47;
  undefined1 local_46;
  undefined1 local_45;
  byte local_44;
  undefined1 local_43;
  undefined1 local_42;
  byte local_41;
  undefined1 local_40;
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)auStack_94;
  iVar7 = *param_2;
  _memset(&local_6c,0,0x68);
  local_58 = 1;
  if (param_3 == 0) {
    local_60 = DAT_00854260;
    local_5c = DAT_00854264;
  }
  else {
    local_60 = 0;
    local_5c = 0;
  }
  if (param_2[3] == 0) {
    local_90 = *(undefined4 *)(iVar7 + 0x1bc);
    uVar5 = *(uint *)(iVar7 + 0x1b8) & 0xfffffe3f;
  }
  else {
    local_90 = 0;
    uVar5 = 0x1000;
  }
  local_67 = (undefined1)(uVar5 >> 8);
  local_68 = (undefined1)uVar5;
  local_66 = (undefined1)(uVar5 >> 0x10);
  local_65 = (undefined1)(uVar5 >> 0x18);
  local_64 = local_68;
  local_63 = local_67;
  local_62 = local_66;
  local_61 = local_65;
  uVar6 = FUN_00744600();
  local_6c = (undefined1)uVar6;
  local_4b = param_2[4] != 0;
  local_6b = (undefined1)((uint)uVar6 >> 8);
  local_49 = param_2[6] != 0;
  local_69 = (undefined1)((uint)uVar6 >> 0x18);
  local_4a = param_2[5] != 0;
  local_6a = (undefined1)((uint)uVar6 >> 0x10);
  if ((param_2[3] == 0) &&
     (((*(uint *)(*param_2 + 0x1b8) & 1) != 0 || ((*(uint *)(*param_2 + 0x1b8) >> 1 & 1) != 0)))) {
    local_57 = *(undefined1 *)(iVar7 + 0xa9);
  }
  else {
    local_57 = 0;
  }
  if ((param_2[3] == 0) && (param_2[8] < *(int *)(*param_2 + 0x48))) {
    local_56 = *(undefined1 *)(iVar7 + 0xaa);
  }
  else {
    local_56 = 0;
  }
  cVar3 = FUN_007444b0(0);
  local_55 = cVar3 != '\0';
  cVar3 = FUN_007444b0(1);
  if (cVar3 == '\0') {
    local_54 = 0;
  }
  else {
    local_54 = *(undefined1 *)(iVar7 + 0xab);
  }
  cVar3 = FUN_007444b0(2);
  if (cVar3 == '\0') {
    local_53 = 0;
  }
  else {
    local_53 = *(undefined1 *)(iVar7 + 0xac);
  }
  cVar3 = FUN_007444b0(3);
  if (cVar3 == '\0') {
    local_52 = 0;
  }
  else {
    local_52 = *(undefined1 *)(iVar7 + 0xad);
  }
  if ((param_2[3] == 0) &&
     (((*(uint *)(*param_2 + 0x1b8) >> 0xd & 1) != 0 ||
      ((*(uint *)(*param_2 + 0x1b8) >> 0xe & 1) != 0)))) {
    local_51 = *(undefined1 *)(iVar7 + 0xae);
  }
  else {
    local_51 = 0;
  }
  cVar3 = FUN_007445b0(1);
  if (cVar3 == '\0') {
    local_50 = 0;
  }
  else {
    local_50 = *(undefined1 *)(iVar7 + 0x44);
  }
  cVar3 = FUN_007445b0(2);
  if (cVar3 == '\0') {
    local_4f = 0;
  }
  else {
    local_4f = *(undefined1 *)(iVar7 + 0x45);
  }
  cVar3 = FUN_007445b0(3);
  if (cVar3 == '\0') {
    local_4e = 0;
  }
  else {
    local_4e = *(undefined1 *)(iVar7 + 0x46);
  }
  iVar1 = param_2[3];
  local_4c = 1;
  local_4d = 1;
  if (iVar1 == 0) {
    if (((*(uint *)(*param_2 + 0x1b8) & 1) == 0) || (*(int *)(*param_2 + 0x38) <= param_2[8])) {
      if (((*(uint *)(*param_2 + 0x1b8) >> 1 & 1) == 0) || (*(int *)(*param_2 + 0x38) <= param_2[8])
         ) goto LAB_00744e17;
      local_48 = 1;
    }
    else {
      local_48 = 2;
    }
  }
  else {
LAB_00744e17:
    local_48 = 0;
  }
  if (iVar1 == 0) {
    if (((*(uint *)(*param_2 + 0x1b8) >> 0x14 & 1) == 0) ||
       (*(int *)(*param_2 + 0x34) <= param_2[8])) {
      if (((*(uint *)(*param_2 + 0x1b8) >> 0x14 & 1) == 0) ||
         (param_2[8] < *(int *)(*param_2 + 0x34))) goto LAB_00744e6c;
      local_47 = 1;
    }
    else {
      local_47 = 2;
    }
  }
  else {
LAB_00744e6c:
    local_47 = 0;
  }
  puVar2 = (uint *)*param_2;
  local_46 = 0 < (int)puVar2[0x79];
  local_45 = 0 < (int)puVar2[0x7a];
  if ((iVar1 == 0) &&
     ((((int)*puVar2 < 0 && ((*puVar2 & 0x800000) == 0)) ||
      (((int)*puVar2 < 0 && ((*puVar2 & 0x800000) != 0)))))) {
    local_44 = (byte)(*(uint *)(iVar7 + 0x1bc) >> 2) & 3;
  }
  else {
    local_44 = 0;
  }
  local_43 = (*(byte *)(iVar7 + 0x13c) & 0xc) != 0;
  local_42 = *(undefined1 *)(iVar7 + 0xa8);
  if (iVar1 == 0) {
    if (((int)*puVar2 < 0) && ((*puVar2 & 0x800000) == 0)) {
      local_41 = 1;
      goto LAB_00744f27;
    }
    if ((-1 < (int)*puVar2) || ((*puVar2 & 0x800000) == 0)) goto LAB_00744f1a;
    cVar3 = '\x01';
  }
  else {
LAB_00744f1a:
    cVar3 = '\0';
  }
  local_41 = -cVar3 & 2;
LAB_00744f27:
  iVar7 = param_2[1];
  local_40 = 1;
  if ((((iVar7 != 0) && (*(int *)(iVar7 + 0x100) != 0)) &&
      (iVar7 = FUN_005e5310(*(undefined4 *)(iVar7 + 0x100)), iVar7 != 0)) &&
     ((*(int *)(iVar7 + 0x24) != 0 &&
      ((**(code **)(**(int **)(iVar7 + 0x24) + 0x44))(*(int **)(iVar7 + 0x24),0,local_8c),
      local_8c[0] == 0x31545844)))) {
    local_40 = 0;
  }
  sVar4 = FUN_007462f0(&local_6c,0x68);
  *param_1 = (int)sVar4 << 0x10;
  uVar5 = FUN_007462b0(&local_6c,0x68);
  *param_1 = *param_1 | uVar5 & 0xffff;
  __security_check_cookie(local_4 ^ (uint)auStack_94);
  return;
}


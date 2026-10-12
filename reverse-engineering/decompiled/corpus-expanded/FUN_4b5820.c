/* Ghidra pseudocode, not original source.
 * ev_6ff60c7644817ef8ef03e73cfdcec4dc91928e5367edba007261837c31d60754
 * Entry: 0x4b5820; label: FUN_004b5820
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004b5820(int param_1)

{
  short sVar1;
  bool bVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  int local_14;
  int local_10;
  
  uVar10 = *(uint *)(*(int *)(param_1 + 0xca4) + 8);
  uVar6 = *(uint *)(*(int *)(param_1 + 0xca4) + 4);
  uVar7 = uVar6 & DAT_0080227c;
  uVar9 = uVar10 & DAT_0080227c;
  uVar11 = uVar10 & DAT_00802278;
  uVar8 = uVar6 & DAT_00802278;
  uVar3 = uVar10 & DAT_00802284;
  uVar6 = uVar6 & DAT_00802280;
  uVar10 = uVar10 & DAT_00802280;
  if (*(char *)(param_1 + 0xe43) == -1) {
    local_10 = -1;
  }
  else {
    local_10 = (int)*(short *)(&DAT_007fb0ec + *(char *)(param_1 + 0xe43) * 0x10);
  }
  iVar4 = FUN_0041aef0(param_1);
  if ((iVar4 == 0) || ((*(byte *)(*(int *)(param_1 + 0x54) + 4) & 8) != 0)) {
    if (*(char *)(param_1 + 0xe43) == -1) {
      local_14 = -1;
    }
    else {
      local_14 = (int)*(short *)(&DAT_007fb0ea + *(char *)(param_1 + 0xe43) * 0x10);
    }
  }
  else {
    local_14 = 0xdf;
  }
  FUN_00427b40(param_1);
  FUN_004abac0(param_1,0,0,0x41000000,0);
  sVar1 = *(short *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0xec);
  if ((((sVar1 == 0x65) || (sVar1 == 0x67)) || (sVar1 == 0x69)) || (bVar2 = false, sVar1 == 0x6b)) {
    bVar2 = true;
  }
  FUN_004cdab0(PTR_DAT_00802c54,param_1);
  if (*(int *)(param_1 + 0xcbc) != 0) {
    FUN_004c85e0(PTR_DAT_00802c54,param_1);
  }
  FUN_0049c080(param_1);
  FUN_004a7880(param_1);
  FUN_004a7610(param_1);
  FUN_0049be00(param_1);
  FUN_0056c7a0(param_1);
  FUN_004827a0(PTR_DAT_00802c54,param_1);
  if (DAT_00950c48 != 0) {
    FUN_0056b8f0(param_1);
  }
  FUN_0056c0e0(param_1);
  FUN_004d18a0(param_1,uVar11);
  FUN_004a3be0();
  FUN_004a4a20(param_1);
  FUN_0056d8c0(param_1,PTR_DAT_00802c54);
  FUN_004b0c80();
  if ((DAT_007f39e4 == 0) || (DAT_00876580 != 0)) {
    uVar5 = 0;
  }
  else {
    uVar5 = 1;
  }
  FUN_0059bd40(param_1,uVar5);
  FUN_005623f0(param_1);
  FUN_00488770(param_1,uVar3);
  FUN_0049d720(param_1);
  if (bVar2) {
    uVar3 = 0x1b;
  }
  else {
    uVar3 = 8;
    local_10 = -1;
  }
  iVar4 = FUN_0041aef0(param_1);
  if (iVar4 == 0) {
    if (!bVar2) {
      uVar3 = uVar3 | 0x200;
    }
  }
  else {
    uVar3 = uVar3 | 0x101;
  }
  FUN_00562570(param_1,uVar11,uVar8,uVar3,uVar9,uVar7,local_10);
  FUN_0046eda0(PTR_DAT_00802c54,param_1,uVar10);
  FUN_00474070(PTR_DAT_00802c54,param_1,uVar10);
  FUN_004d6060(param_1,uVar10);
  if ((*(uint *)(*(int *)(param_1 + 0x54) + 4) & 0x100000) != 0) {
    FUN_0054ea40(param_1);
  }
  FUN_00592280(param_1);
  if (bVar2) {
LAB_004b5ac9:
    FUN_004b15c0(uVar10,uVar6);
    FUN_004a28e0(uVar6);
    FUN_004a3270(param_1,uVar10,1);
    FUN_004a4420(uVar10);
    FUN_004a2070(uVar10);
    FUN_004a3270(param_1,uVar10,2);
    FUN_004a4ff0(local_14);
  }
  else {
    iVar4 = FUN_0041aef0(param_1);
    if (iVar4 != 0) goto LAB_004b5ac9;
  }
  FUN_004a3be0();
  FUN_00490d10(PTR_DAT_00802c54,param_1);
  if ((*(uint *)(*(int *)(param_1 + 0x54) + 4) & 0x40000) == 0) {
    iVar4 = FUN_0041aef0(param_1);
    if (iVar4 == 0) goto LAB_004b5b4c;
  }
  FUN_004ce830(param_1,uVar10);
LAB_004b5b4c:
  iVar4 = FUN_004d0290(param_1);
  if ((DAT_007f39e4 == 0) && (DAT_00876580 == 0)) {
    if ((*(int *)(param_1 + 0xcbc) != 0) && ((*(byte *)(*(int *)(param_1 + 0xcbc) + 0xc) & 4) != 0))
    {
      FUN_004271b0(param_1);
    }
    if ((*(int *)(param_1 + 0xcbc) != 0) && ((*(byte *)(*(int *)(param_1 + 0xcbc) + 0xc) & 8) != 0))
    {
      FUN_004c88c0(PTR_DAT_00802c54,param_1);
    }
    if ((*(byte *)(*(int *)(param_1 + 0x54) + 4) & 8) == 0) {
      FUN_004d4dc0(PTR_DAT_00802c54,param_1);
    }
  }
  FUN_00598880(PTR_DAT_00802c54,param_1);
  FUN_0056a5b0(PTR_DAT_00802c54,param_1);
  FUN_0049dfd0(param_1,uVar7);
  FUN_0058d6a0(param_1);
  FUN_0058db50(param_1);
  FUN_0058dec0(param_1);
  FUN_0058b210(param_1);
  FUN_0058e420(param_1);
  FUN_004036a0(PTR_DAT_00802c54,param_1);
  FUN_004bdaf0(PTR_DAT_00802c54,param_1);
  if (bVar2) {
    FUN_0049e450(uVar9,uVar7,uVar11,0);
    FUN_004a1c70(uVar9,uVar7);
    FUN_004a10c0(uVar9,uVar7,uVar11,-(uint)(iVar4 != 1) & uVar10);
    FUN_004a0bc0();
  }
  else {
    FUN_0049e450(uVar9,uVar7,0,0);
    FUN_0049ea70(param_1,uVar9,uVar7,1,0,0);
    FUN_004b13e0(uVar11);
    if ((*(byte *)(*(int *)(param_1 + 0x54) + 4) & 0x80) == 0) {
      if (*(int *)(param_1 + 0xcc0) != 0) {
        FUN_004050c0(param_1);
      }
    }
    else {
      FUN_004b3d40(param_1,uVar9,-(uint)(iVar4 != 1) & uVar10,1,1,0);
    }
  }
  if ((*(byte *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x94) & 0x80) != 0) {
    FUN_004b29f0(*(uint *)(*(int *)(param_1 + 0xca4) + 8) & DAT_00802280,0);
  }
  FUN_004a69e0();
  FUN_004a7d00();
  FUN_0058cef0(param_1);
  FUN_0058cf50(param_1);
  FUN_0058d150(param_1);
  return;
}


/* Ghidra pseudocode, not original source.
 * ev_6ff60c7644817ef8ef03e73cfdcec4dc91928e5367edba007261837c31d60754
 * Entry: 0x4b5ef0; label: FUN_004b5ef0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004b5ef0(int param_1)

{
  short sVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  undefined4 uVar8;
  
  iVar2 = param_1;
  uVar6 = *(uint *)(*(int *)(param_1 + 0xca4) + 8);
  uVar7 = *(uint *)(*(int *)(param_1 + 0xca4) + 4) & DAT_00802278;
  uVar5 = uVar6 & DAT_00802278;
  uVar6 = (DAT_00802280 | DAT_0080227c) & uVar6;
  if ((*(byte *)(*(int *)(param_1 + 0x54) + 4) & 0x40) == 0) {
    if ((*(char *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x116) == '\x04') ||
       (*(short *)(param_1 + 0x1064) == DAT_007f18b4)) {
      FUN_0058d8b0(param_1);
    }
  }
  else {
    if (DAT_007f41a0 != '\0') {
      uVar6 = *(uint *)(*(int *)(param_1 + 0xca4) + 8) & DAT_0080227c;
    }
    FUN_0058dd60(param_1);
  }
  FUN_00427b40(param_1);
  if (*(short *)(param_1 + 0x1064) == DAT_007f1888) {
    param_1 = 0;
  }
  else {
    param_1 = 0x41000000;
  }
  FUN_004abac0(iVar2,0,0,param_1,0);
  if (((*(byte *)(*(int *)(iVar2 + 0x54) + 4) & 0x10) != 0) || (DAT_00951288 == 0)) {
    FUN_0049c080(iVar2);
    if ((*(byte *)(*(int *)(iVar2 + 0x54) + 4) & 0x40) != 0) {
      FUN_004a7880(iVar2);
    }
    FUN_004a7610(iVar2);
    FUN_0049be00(iVar2);
    FUN_004a3be0();
    FUN_004a4a20(iVar2);
    FUN_0056d8c0(iVar2,PTR_DAT_00802c54);
  }
  if ((*(byte *)(*(int *)(iVar2 + 0x54) + 4) & 0x40) != 0) {
    FUN_00562570(iVar2,uVar5,uVar7,4,0,0,0xffffffff);
    FUN_0046eda0(PTR_DAT_00802c54,iVar2,
                 (DAT_00802280 | DAT_0080227c) & *(uint *)(*(int *)(iVar2 + 0xca4) + 8));
    goto LAB_004b6118;
  }
  FUN_0049d720(iVar2);
  if (*(short *)(iVar2 + 0x1064) == DAT_007f1904) {
    FUN_0058d6a0(iVar2);
    FUN_0058db50(iVar2);
    FUN_0058dec0(iVar2);
    uVar5 = *(uint *)(*(int *)(iVar2 + 0xca4) + 8);
    FUN_004b3d40(iVar2,uVar5 & DAT_0080227c,uVar5 & DAT_00802280,1,0,0);
LAB_004b6100:
    uVar8 = 0x80;
    uVar7 = 0;
    uVar5 = 0;
  }
  else {
    if (*(short *)(iVar2 + 0x1064) != DAT_007f1a50) {
      if (((*(byte *)(*(int *)(iVar2 + 0x54) + 4) & 0x20) == 0) &&
         ((*(byte *)(*(int *)(*(int *)(iVar2 + 0x54) + 0x24) + 0x94) & 8) == 0)) {
        FUN_004b3d40(iVar2,*(uint *)(*(int *)(iVar2 + 0xca4) + 8) & DAT_0080227c,0,0,0,0);
      }
      goto LAB_004b6100;
    }
    iVar3 = FUN_0056e160(8);
    if (iVar3 == 0) goto LAB_004b6100;
    uVar8 = 0x40;
  }
  FUN_00562570(iVar2,uVar5,uVar7,uVar8,0,0,0xffffffff);
LAB_004b6118:
  if (*(short *)(iVar2 + 0x1064) == DAT_007f1a94) {
    FUN_0049ea70(iVar2,*(uint *)(*(int *)(iVar2 + 0xca4) + 8) & DAT_0080227c,0,0,1,0);
  }
  FUN_004a6160(uVar6,0);
  FUN_004b0c80();
  FUN_004a7d00();
  uVar6 = *(uint *)(*(int *)(iVar2 + 0x54) + 4);
  if ((uVar6 & 0x10) != 0) {
    if ((uVar6 & 0x40) == 0) {
      if (DAT_00951288 == 0) {
        FUN_004a7d00();
      }
      sVar1 = *(short *)(iVar2 + 0x1064);
      if ((((sVar1 == DAT_007f18a0) || (sVar1 == DAT_007f18a4)) || (sVar1 == DAT_007f18ac)) ||
         (sVar1 == DAT_007f18b0)) {
        if (((*(char *)(iVar2 + 0x281) != '\0') && (*(char *)(iVar2 + 0x7b5) == -1)) &&
           (0.0 < *(float *)(*(int *)(iVar2 + 0xca4) + 0x28))) {
          pcVar4 = "drd_mousebot_lp";
          if (sVar1 != DAT_007f18b0) {
            pcVar4 = "R2Move";
          }
          FUN_00681f40(pcVar4,iVar2 + 0x80);
        }
      }
      else if (sVar1 == DAT_007f18b4) {
        FUN_00681f40("Probot_EngLp",iVar2 + 0x80);
        uVar6 = *(uint *)(*(int *)(iVar2 + 0xca4) + 8) & DAT_0080227c;
        FUN_004a6c30(uVar6,uVar6,0x3f000000,1);
      }
    }
    else {
      FUN_004aa800(iVar2);
    }
  }
  if ((*(byte *)(*(int *)(*(int *)(iVar2 + 0x54) + 0x24) + 0x94) & 0x80) != 0) {
    FUN_004b29f0(*(uint *)(*(int *)(iVar2 + 0xca4) + 8) & DAT_00802280,0);
  }
  if (((*(byte *)(*(int *)(iVar2 + 0x54) + 4) & 0x20) != 0) &&
     (FUN_0046eda0(PTR_DAT_00802c54,iVar2,
                   (DAT_00802280 | DAT_0080227c) & *(uint *)(*(int *)(iVar2 + 0xca4) + 8)),
     *(int *)(PTR_DAT_00802c54 + 0x128) == DAT_0087b1f8)) {
    FUN_00563ec0(iVar2);
  }
  FUN_004a8640(*(uint *)(*(int *)(iVar2 + 0xca4) + 8) & DAT_00802280);
  FUN_0056a5b0(PTR_DAT_00802c54,iVar2);
  return;
}


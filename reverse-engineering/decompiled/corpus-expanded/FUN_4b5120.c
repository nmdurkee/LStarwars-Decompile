/* Ghidra pseudocode, not original source.
 * ev_6ff60c7644817ef8ef03e73cfdcec4dc91928e5367edba007261837c31d60754
 * Entry: 0x4b5120; label: FUN_004b5120
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004b5120(int param_1)

{
  float fVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  float10 fVar10;
  undefined4 uVar11;
  float local_c;
  float local_8;
  float local_4;
  
  iVar7 = *(int *)(param_1 + 0xca4);
  if (((DAT_0093b2a4 != 0) && (*(int *)(PTR_DAT_00802c54 + 300) != 0)) &&
     (*(int *)(PTR_DAT_00802c54 + 300) == DAT_0087af5c)) {
    FUN_004b6800(param_1);
    return;
  }
  FUN_0058d8b0(param_1);
  FUN_00427b40(param_1);
  if ((*(byte *)(param_1 + 0xe20) & 0x20) != 0) {
    return;
  }
  iVar6 = *(int *)(*(int *)(param_1 + 0x54) + 0x24);
  if ((*(byte *)(iVar6 + 0x94) & 0x20) == 0) {
    if (*(char *)(iVar6 + 0x116) == '\x15') {
      fVar10 = (float10)FUN_004aa5a0(param_1,0x41000000,0);
      FUN_004abac0(param_1,0,(float)fVar10);
    }
    else {
      if (0.0 < *(float *)(iVar6 + 0x28)) {
        fVar10 = (float10)FUN_00498590(param_1,0);
        if (((float)fVar10 != 0.0) || (DAT_0087b8e0 != 0)) {
          FUN_004abac0(param_1,0,(float)fVar10,0x41200000,0);
          goto LAB_004b5256;
        }
      }
      uVar11 = 0;
      if (*(char *)(param_1 + 0x7b5) != '\x17') {
        uVar11 = *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x28);
      }
      FUN_004abac0(param_1,0,uVar11,0x41000000,0);
    }
  }
LAB_004b5256:
  FUN_004b0c80();
  if (*(short *)(param_1 + 0x1064) == DAT_007f1990) {
    FUN_005a03d0(param_1,(DAT_00802280 | DAT_0080227c) & *(uint *)(iVar7 + 8));
  }
  else if (((*(short *)(param_1 + 0x1064) == DAT_007f1b3c) &&
           (*(int *)(PTR_DAT_00802c54 + 0x128) == DAT_0087b0f4)) &&
          (((int)*(char *)(param_1 + 0x107f) < (int)(uint)*(byte *)(param_1 + 0x107e) &&
           (iVar6 = *(int *)(*(int *)(*(int *)(PTR_DAT_00802c54 + 0x134) + 8) + 0xa78), iVar6 != -1)
           ))) {
    iVar4 = FUN_0062c350(_DAT_007fc150,_DAT_00925018);
    for (iVar4 = iVar4 * ((int)((uint)*(byte *)(param_1 + 0x107e) - (int)*(char *)(param_1 + 0x107f)
                               ) / 2); 0 < iVar4; iVar4 = iVar4 + -1) {
      iVar5 = FUN_0054fa60();
      fVar1 = (float)iVar5 * 1.5259022e-05;
      local_c = *(float *)(param_1 + 0x80) +
                fVar1 * (*(float *)(param_1 + 0x98) - *(float *)(param_1 + 0x80));
      local_8 = (*(float *)(param_1 + 0x9c) - *(float *)(param_1 + 0x84)) * fVar1 +
                *(float *)(param_1 + 0x84);
      local_4 = (*(float *)(param_1 + 0xa0) - *(float *)(param_1 + 0x88)) * fVar1 +
                *(float *)(param_1 + 0x88);
      FUN_00684c90(iVar6,&local_c,1,0,0);
    }
  }
  iVar6 = *(int *)(*(int *)(param_1 + 0x54) + 0x24);
  if ((0.0 < *(float *)(iVar6 + 0x28)) && ((*(uint *)(iVar6 + 0x90) & 0x10000) == 0)) {
    FUN_0049ad90(param_1,*(uint *)(iVar7 + 8) & DAT_00802278,*(uint *)(iVar7 + 4) & DAT_00802278,
                 iVar7,1);
    FUN_0049b330(param_1,0,iVar7);
    FUN_004a8e30(param_1,0,0x43610000);
  }
  if (((*(uint *)(*(int *)(param_1 + 0x54) + 4) & 0x10000000) != 0) &&
     ((*(byte *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x94) & 8) == 0)) {
    if ((*(short *)(param_1 + 0x1064) == DAT_007f19b8) ||
       (*(short *)(param_1 + 0x1064) == DAT_007f19bc)) {
      uVar11 = 1;
      if (*(int *)(*(int *)(*(int *)(param_1 + 0x50) + 0xc) + 0x58) != 0) {
        FUN_004b3d40(param_1,*(uint *)(*(int *)(param_1 + 0xca4) + 8) & DAT_0080227c,0,0,0,1);
        goto LAB_004b5493;
      }
      uVar2 = 0x3e800000;
    }
    else {
      uVar2 = 0x3e19999a;
      uVar11 = 0;
    }
    FUN_004a6c30(*(uint *)(iVar7 + 8) & DAT_0080227c,*(uint *)(iVar7 + 4) & DAT_0080227c,uVar2,
                 uVar11);
  }
LAB_004b5493:
  if (*(int *)(PTR_DAT_00802c54 + 0x128) == DAT_0087b0f8) {
    FUN_004ab1f0(param_1,0x3c23d70a,0x40000000,0);
  }
  if ((*(uint *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x90) & 0x400) != 0) {
    FUN_004a71f0(param_1,*(uint *)(iVar7 + 8) & DAT_00802280,0x3f000000);
  }
  if ((((*(int *)(PTR_DAT_00802c54 + 300) != 0) &&
       ((*(byte *)(*(int *)(PTR_DAT_00802c54 + 300) + 0x7a) & 1) != 0)) &&
      ((*(byte *)(param_1 + 0x1fc) & 0x80) != 0)) &&
     ((DAT_007f4140 != '\0' || (0.0 < *(float *)(param_1 + 0xdec))))) {
    FUN_004a9450(param_1);
  }
  FUN_0049b8b0();
  FUN_0049b9d0();
  FUN_004a7880(param_1);
  FUN_004d3800(param_1,*(uint *)(iVar7 + 4) & DAT_00802280,0x3f000000);
  if (((*(short *)(param_1 + 0x1064) == DAT_007f1b3c) && (*(int *)(PTR_DAT_00802c54 + 300) != 0)) &&
     (*(int *)(PTR_DAT_00802c54 + 300) == DAT_0087af68)) {
    FUN_004aaec0();
  }
  FUN_004a8760();
  FUN_004a82a0(param_1,0);
  FUN_00547dc0(param_1,*(char *)(param_1 + 0x7b5) == '\x17');
  uVar3 = *(uint *)(param_1 + 0x1fc) >> 7 & 1;
  if ((((uVar3 != 0) && (*(char *)(param_1 + 0x107f) == '\x01')) ||
      ((uVar3 == 0 && (*(char *)(param_1 + 0x107f) < '\x02')))) &&
     (((*(char *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x116) == '\n' &&
       ((*(uint *)(*(int *)(param_1 + 0x54) + 4) & 0x4000000) == 0)) &&
      (iVar6 = *(int *)(*(int *)(*(int *)(PTR_DAT_00802c54 + 0x134) + 8) + 0x780), iVar6 != -1)))) {
    for (iVar4 = FUN_0062c350(0x42480000,_DAT_00925018); 0 < iVar4; iVar4 = iVar4 + -1) {
      iVar5 = FUN_0054fa60();
      fVar1 = (float)iVar5 * 1.5259022e-05;
      local_c = *(float *)(param_1 + 0x80) +
                fVar1 * (*(float *)(param_1 + 0x98) - *(float *)(param_1 + 0x80));
      local_8 = (*(float *)(param_1 + 0x9c) - *(float *)(param_1 + 0x84)) * fVar1 +
                *(float *)(param_1 + 0x84);
      local_4 = (*(float *)(param_1 + 0xa0) - *(float *)(param_1 + 0x88)) * fVar1 +
                *(float *)(param_1 + 0x88);
      FUN_00684c90(iVar6,&local_c,1,0,0);
    }
  }
  if ((*(uint *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x90) & 0x100000) != 0) {
    iVar6 = FUN_0056e160(7);
    if ((iVar6 != 0) && ((*(uint *)(iVar7 + 8) & (DAT_00802280 | DAT_0080227c)) != 0)) {
      FUN_00547930(0x4b,param_1 + 0x80,0,0);
    }
    *(undefined4 *)(param_1 + 0xf3c) = 0;
    *(undefined1 *)(param_1 + 0xf6c) = 0;
    *(undefined1 *)(param_1 + 0xf6d) = 1;
    iVar7 = FUN_00550040(*(undefined2 *)(param_1 + 0x1060),*(undefined2 *)(param_1 + 0x27a));
    fVar1 = _DAT_00925018;
    *(undefined1 *)(param_1 + 0x107d) = 2;
    *(float *)(param_1 + 0xf40) = -(((float)iVar7 * 9.58738e-05) / (fVar1 * 6.0));
    *(undefined4 *)(param_1 + 0xf44) = 0;
    puVar8 = (undefined4 *)(param_1 + 0xf3c);
    puVar9 = (undefined4 *)(param_1 + 0xf70);
    for (iVar7 = 0xd; iVar7 != 0; iVar7 = iVar7 + -1) {
      *puVar9 = *puVar8;
      puVar8 = puVar8 + 1;
      puVar9 = puVar9 + 1;
    }
    *(undefined1 *)(param_1 + 4000) = 1;
  }
  if (((*(char *)(param_1 + 0x280) == -1) &&
      (iVar7 = *(int *)(*(int *)(param_1 + 0x54) + 0x24), (*(byte *)(iVar7 + 0x90) & 0x40) != 0)) &&
     ((*(int *)(*(int *)(*(int *)(param_1 + 0x50) + 0xc) + 0xa8) != 0 &&
      ((*(uint *)(iVar7 + 0x94) & 0x8000000) != 0)))) {
    FUN_0054e750(param_1,0);
  }
  if (*(short *)(param_1 + 0x1064) == DAT_007f184c) {
    FUN_004a89f0();
  }
  iVar7 = FUN_0056a5b0(PTR_DAT_00802c54,param_1);
  if ((iVar7 != 0) && (DAT_0087b8d4 != (code *)0x0)) {
    (*DAT_0087b8d4)(param_1);
  }
  return;
}


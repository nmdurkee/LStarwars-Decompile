/* Ghidra analysis pseudocode, not original source.
 * ev_3ab0ab4bdd8dc8a455ed322812c7dbab6fd6000ce0d7a9019575e9409bf5a2c0
 * Entry: 0x4b6800; label: FUN_004b6800
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004b6800(int param_1)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  bool bVar8;
  float10 fVar9;
  undefined4 uVar10;
  float fVar11;
  
  iVar4 = *(int *)(PTR_DAT_00802c54 + 300);
  if ((iVar4 != 0) && ((iVar4 == DAT_0087b014 || (iVar4 == DAT_0087af5c)))) {
    fVar9 = (float10)FUN_004ab790(param_1,0x41000000,0);
    FUN_004abac0(param_1,0,(float)fVar9);
    if ((DAT_0087af5c != 0) &&
       (((*(int *)(PTR_DAT_00802c54 + 300) == DAT_0087af5c &&
         (0.0 < *(float *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x28))) &&
        (fVar9 = (float10)FUN_004dbb60(PTR_DAT_00802c54),
        fVar9 < (float10)0.0 != (fVar9 == (float10)0.0))))) {
      iVar4 = *(int *)(param_1 + 0xca4);
      FUN_0049ad90(param_1,*(uint *)(iVar4 + 8) & DAT_00802278,*(uint *)(iVar4 + 4) & DAT_00802278,
                   iVar4,0);
    }
    FUN_0049c080(param_1);
    if ((*(uint *)(param_1 + 0x1f8) & 0x40000) == 0) {
      FUN_004ab4b0();
      FUN_004ab350();
    }
    else {
      *(undefined4 *)(param_1 + 0x1038) = 0;
    }
    iVar4 = *(int *)(PTR_DAT_00802c54 + 300);
    if ((iVar4 != 0) && ((iVar4 == DAT_0087b014 || ((iVar4 != 0 && (iVar4 == DAT_0087af5c)))))) {
      FUN_004ab1f0(param_1,0x3ccccccd,0x40400000,0);
    }
    if ((*(byte *)(param_1 + 0x1fc) & 0x80) != 0) {
      FUN_004a2070(0);
    }
    FUN_004ab620(param_1);
    iVar4 = *(int *)(*(int *)(param_1 + 0x54) + 0x24);
    iVar5 = (int)*(short *)(iVar4 + 0xe2);
    if (*(char *)(iVar4 + 0x116) == '\x14') {
      if ((*(byte *)(param_1 + 0x1fc) & 0x80) == 0) goto LAB_004b6b57;
      if ((*(int *)(PTR_DAT_00802c54 + 300) == 0) ||
         (*(int *)(PTR_DAT_00802c54 + 300) != DAT_0087b014)) {
        bVar8 = param_1 != DAT_0093d7f0;
        fVar9 = (float10)FUN_0054fad0(*(undefined4 *)(&DAT_007fc190 + (uint)bVar8 * 4),
                                      (*(float *)(param_1 + 0x228) /
                                      *(float *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x1c))
                                      * 0.35 + 0.65,_DAT_00925018);
        *(float *)(&DAT_007fc190 + (uint)bVar8 * 4) = (float)fVar9;
        FUN_00681ee0(iVar5,param_1 + 0x80,(float)fVar9);
        FUN_0056a5b0(PTR_DAT_00802c54,param_1);
        return;
      }
      fVar11 = (-ABS((float)(&DAT_029899a0)[*(ushort *)(*(int *)(param_1 + 0xca4) + 0x26) >> 1]) *
               (*(float *)(*(int *)(param_1 + 0xca4) + 0x28) - 6.0)) / 96.0;
      if (1.1 <= _DAT_0087b888) {
        fVar11 = fVar11 + 2.0;
      }
      else {
        fVar11 = _DAT_0087b888 + 1.0 + fVar11;
      }
      uVar2 = (uint)(param_1 != DAT_0093d7f0);
      fVar11 = (fVar11 * 0.5 - *(float *)(&DAT_007fc190 + uVar2 * 4)) * _DAT_00925018 * 1.5 +
               *(float *)(&DAT_007fc190 + uVar2 * 4);
      *(float *)(&DAT_007fc190 + uVar2 * 4) = fVar11;
    }
    else {
      if (0.0 <= (*(float *)(param_1 + 0x88) - DAT_00973720) * DAT_00973710 +
                 (*(float *)(param_1 + 0x80) - DAT_00973718) * DAT_00973708 +
                 (*(float *)(param_1 + 0x84) - DAT_0097371c) * DAT_0097370c) {
        FUN_00681e90(iVar5,(float *)(param_1 + 0x80));
        FUN_0056a5b0(PTR_DAT_00802c54,param_1);
        return;
      }
      fVar11 = 0.7;
    }
    FUN_00681ee0(iVar5,param_1 + 0x80,fVar11);
LAB_004b6b57:
    FUN_0056a5b0(PTR_DAT_00802c54,param_1);
    return;
  }
  iVar4 = *(int *)(param_1 + 0xca4);
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
  iVar5 = *(int *)(*(int *)(param_1 + 0x54) + 0x24);
  if ((*(byte *)(iVar5 + 0x94) & 0x20) == 0) {
    if (*(char *)(iVar5 + 0x116) == '\x15') {
      fVar9 = (float10)FUN_004aa5a0(param_1,0x41000000,0);
      FUN_004abac0(param_1,0,(float)fVar9);
    }
    else {
      if (0.0 < *(float *)(iVar5 + 0x28)) {
        fVar9 = (float10)FUN_00498590(param_1,0);
        if (((float)fVar9 != 0.0) || (DAT_0087b8e0 != 0)) {
          FUN_004abac0(param_1,0,(float)fVar9,0x41200000,0);
          goto LAB_004b5256;
        }
      }
      uVar10 = 0;
      if (*(char *)(param_1 + 0x7b5) != '\x17') {
        uVar10 = *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x28);
      }
      FUN_004abac0(param_1,0,uVar10,0x41000000,0);
    }
  }
LAB_004b5256:
  FUN_004b0c80();
  if (*(short *)(param_1 + 0x1064) == DAT_007f1990) {
    FUN_005a03d0(param_1,(DAT_00802280 | DAT_0080227c) & *(uint *)(iVar4 + 8));
  }
  else if (((*(short *)(param_1 + 0x1064) == DAT_007f1b3c) &&
           (*(int *)(PTR_DAT_00802c54 + 0x128) == DAT_0087b0f4)) &&
          (((int)*(char *)(param_1 + 0x107f) < (int)(uint)*(byte *)(param_1 + 0x107e) &&
           (iVar5 = *(int *)(*(int *)(*(int *)(PTR_DAT_00802c54 + 0x134) + 8) + 0xa78), iVar5 != -1)
           ))) {
    iVar3 = FUN_0062c350(_DAT_007fc150,_DAT_00925018);
    for (iVar3 = iVar3 * ((int)((uint)*(byte *)(param_1 + 0x107e) - (int)*(char *)(param_1 + 0x107f)
                               ) / 2); 0 < iVar3; iVar3 = iVar3 + -1) {
      FUN_0054fa60();
      FUN_00684c90(iVar5,&stack0xfffffff4,1,0,0);
    }
  }
  iVar5 = *(int *)(*(int *)(param_1 + 0x54) + 0x24);
  if ((0.0 < *(float *)(iVar5 + 0x28)) && ((*(uint *)(iVar5 + 0x90) & 0x10000) == 0)) {
    FUN_0049ad90(param_1,*(uint *)(iVar4 + 8) & DAT_00802278,*(uint *)(iVar4 + 4) & DAT_00802278,
                 iVar4,1);
    FUN_0049b330(param_1,0,iVar4);
    FUN_004a8e30(param_1,0,0x43610000);
  }
  if (((*(uint *)(*(int *)(param_1 + 0x54) + 4) & 0x10000000) != 0) &&
     ((*(byte *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x94) & 8) == 0)) {
    if ((*(short *)(param_1 + 0x1064) == DAT_007f19b8) ||
       (*(short *)(param_1 + 0x1064) == DAT_007f19bc)) {
      uVar10 = 1;
      if (*(int *)(*(int *)(*(int *)(param_1 + 0x50) + 0xc) + 0x58) != 0) {
        FUN_004b3d40(param_1,*(uint *)(*(int *)(param_1 + 0xca4) + 8) & DAT_0080227c,0,0,0,1);
        goto LAB_004b5493;
      }
      uVar1 = 0x3e800000;
    }
    else {
      uVar1 = 0x3e19999a;
      uVar10 = 0;
    }
    FUN_004a6c30(*(uint *)(iVar4 + 8) & DAT_0080227c,*(uint *)(iVar4 + 4) & DAT_0080227c,uVar1,
                 uVar10);
  }
LAB_004b5493:
  if (*(int *)(PTR_DAT_00802c54 + 0x128) == DAT_0087b0f8) {
    FUN_004ab1f0(param_1,0x3c23d70a,0x40000000,0);
  }
  if ((*(uint *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x90) & 0x400) != 0) {
    FUN_004a71f0(param_1,*(uint *)(iVar4 + 8) & DAT_00802280,0x3f000000);
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
  FUN_004d3800(param_1,*(uint *)(iVar4 + 4) & DAT_00802280,0x3f000000);
  if (((*(short *)(param_1 + 0x1064) == DAT_007f1b3c) && (*(int *)(PTR_DAT_00802c54 + 300) != 0)) &&
     (*(int *)(PTR_DAT_00802c54 + 300) == DAT_0087af68)) {
    FUN_004aaec0();
  }
  FUN_004a8760();
  FUN_004a82a0(param_1,0);
  FUN_00547dc0(param_1,*(char *)(param_1 + 0x7b5) == '\x17');
  uVar2 = *(uint *)(param_1 + 0x1fc) >> 7 & 1;
  if ((((uVar2 != 0) && (*(char *)(param_1 + 0x107f) == '\x01')) ||
      ((uVar2 == 0 && (*(char *)(param_1 + 0x107f) < '\x02')))) &&
     (((*(char *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x116) == '\n' &&
       ((*(uint *)(*(int *)(param_1 + 0x54) + 4) & 0x4000000) == 0)) &&
      (iVar5 = *(int *)(*(int *)(*(int *)(PTR_DAT_00802c54 + 0x134) + 8) + 0x780), iVar5 != -1)))) {
    for (iVar3 = FUN_0062c350(0x42480000,_DAT_00925018); 0 < iVar3; iVar3 = iVar3 + -1) {
      FUN_0054fa60();
      FUN_00684c90(iVar5,&stack0xfffffff4,1,0,0);
    }
  }
  if ((*(uint *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x90) & 0x100000) != 0) {
    iVar5 = FUN_0056e160(7);
    if ((iVar5 != 0) && ((*(uint *)(iVar4 + 8) & (DAT_00802280 | DAT_0080227c)) != 0)) {
      FUN_00547930(0x4b,param_1 + 0x80,0,0);
    }
    *(undefined4 *)(param_1 + 0xf3c) = 0;
    *(undefined1 *)(param_1 + 0xf6c) = 0;
    *(undefined1 *)(param_1 + 0xf6d) = 1;
    iVar4 = FUN_00550040(*(undefined2 *)(param_1 + 0x1060),*(undefined2 *)(param_1 + 0x27a));
    fVar11 = _DAT_00925018;
    *(undefined1 *)(param_1 + 0x107d) = 2;
    *(float *)(param_1 + 0xf40) = -(((float)iVar4 * 9.58738e-05) / (fVar11 * 6.0));
    *(undefined4 *)(param_1 + 0xf44) = 0;
    puVar6 = (undefined4 *)(param_1 + 0xf3c);
    puVar7 = (undefined4 *)(param_1 + 0xf70);
    for (iVar4 = 0xd; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar7 = *puVar6;
      puVar6 = puVar6 + 1;
      puVar7 = puVar7 + 1;
    }
    *(undefined1 *)(param_1 + 4000) = 1;
  }
  if (((*(char *)(param_1 + 0x280) == -1) &&
      (iVar4 = *(int *)(*(int *)(param_1 + 0x54) + 0x24), (*(byte *)(iVar4 + 0x90) & 0x40) != 0)) &&
     ((*(int *)(*(int *)(*(int *)(param_1 + 0x50) + 0xc) + 0xa8) != 0 &&
      ((*(uint *)(iVar4 + 0x94) & 0x8000000) != 0)))) {
    FUN_0054e750(param_1,0);
  }
  if (*(short *)(param_1 + 0x1064) == DAT_007f184c) {
    FUN_004a89f0();
  }
  iVar4 = FUN_0056a5b0(PTR_DAT_00802c54,param_1);
  if ((iVar4 != 0) && (DAT_0087b8d4 != (code *)0x0)) {
    (*DAT_0087b8d4)(param_1);
  }
  return;
}


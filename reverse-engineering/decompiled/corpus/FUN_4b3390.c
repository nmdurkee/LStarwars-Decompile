/* Ghidra analysis pseudocode, not original source.
 * ev_3ab0ab4bdd8dc8a455ed322812c7dbab6fd6000ce0d7a9019575e9409bf5a2c0
 * Entry: 0x4b3390; label: FUN_004b3390
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004b3390(int param_1)

{
  float fVar1;
  char cVar2;
  float fVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  float10 fVar14;
  int local_14;
  
  iVar4 = param_1;
  uVar13 = *(uint *)(*(int *)(param_1 + 0xca4) + 8);
  uVar9 = *(uint *)(*(int *)(param_1 + 0xca4) + 4);
  uVar10 = uVar13 & DAT_0080227c;
  uVar11 = uVar9 & DAT_00802278;
  uVar12 = uVar9 & DAT_0080227c;
  uVar5 = uVar13 & DAT_00802280;
  uVar13 = uVar13 & DAT_00802278;
  uVar9 = uVar9 & DAT_00802280;
  if (*(short *)(param_1 + 0x1064) == DAT_007f187c) {
    FUN_0058d8b0(param_1);
  }
  FUN_00427b40(param_1);
  if ((*(byte *)(param_1 + 0xe20) & 0x20) == 0) {
    FUN_004abac0(param_1,0,0,0x41000000,0);
    if (*(short *)(param_1 + 0x1064) == DAT_007f19dc) {
      if ((*(uint *)(param_1 + 0xef0) & 0x200) == 0) {
        local_14 = 3;
        param_1 = 0xe1;
      }
      else {
        local_14 = 2;
        param_1 = 0xdd;
      }
    }
    else {
      iVar8 = FUN_004190e0(param_1);
      if (iVar8 == 0) {
        if (*(char *)(param_1 + 0xe43) == -1) {
          local_14 = -1;
        }
        else {
          local_14 = (int)*(short *)(&DAT_007fb0ec + *(char *)(param_1 + 0xe43) * 0x10);
        }
        iVar8 = FUN_0041aef0(param_1);
        if ((iVar8 == 0) || ((*(byte *)(*(int *)(param_1 + 0x54) + 4) & 8) != 0)) {
          if (*(char *)(param_1 + 0xe43) == -1) {
            param_1 = -1;
          }
          else {
            param_1 = (int)*(short *)(&DAT_007fb0ea + *(char *)(param_1 + 0xe43) * 0x10);
          }
        }
        else {
          param_1 = 0xdf;
        }
      }
      else {
        local_14 = 2;
        param_1 = 0xdd;
      }
    }
    FUN_004cdab0(PTR_DAT_00802c54,iVar4);
    if (*(int *)(iVar4 + 0xcbc) != 0) {
      FUN_004c85e0(PTR_DAT_00802c54,iVar4);
    }
    FUN_0049c080(iVar4);
    FUN_004a7880(iVar4);
    FUN_004a7610(iVar4);
    FUN_0049be00(iVar4);
    FUN_0056c7a0(iVar4);
    FUN_004827a0(PTR_DAT_00802c54,iVar4);
    if (DAT_00950c48 != 0) {
      FUN_0056b8f0(iVar4);
    }
    FUN_0056c0e0(iVar4);
    FUN_004d18a0(iVar4,uVar13);
    FUN_004a3be0();
    FUN_004a4a20(iVar4);
    FUN_0056d8c0(iVar4,PTR_DAT_00802c54);
    FUN_004b0c80();
    if ((DAT_007f39e4 == 0) || (DAT_00876580 != 0)) {
      uVar6 = 0;
    }
    else {
      uVar6 = 1;
    }
    FUN_0059bd40(iVar4,uVar6);
    FUN_005623f0(iVar4);
    if ((*(short *)(iVar4 + 0x1064) != DAT_007f1968) && (*(short *)(iVar4 + 0x1064) != DAT_007f187c)
       ) {
      FUN_00488770(iVar4,*(uint *)(*(int *)(iVar4 + 0xca4) + 8) & DAT_00802284);
    }
    FUN_0049d720(iVar4);
    uVar7 = 0x10;
    if ((*(short *)(iVar4 + 0x1064) != DAT_007f1878) && (*(short *)(iVar4 + 0x1064) != DAT_007f187c)
       ) {
      uVar7 = 0x1b;
    }
    if ((*(uint *)(*(int *)(*(int *)(iVar4 + 0x54) + 0x24) + 0x90) & 0x400000) != 0) {
      uVar7 = uVar7 | 0x100;
    }
    FUN_00562570(iVar4,uVar13,uVar11,uVar7,uVar10,uVar12,local_14);
    FUN_0046eda0(PTR_DAT_00802c54,iVar4,uVar5);
    FUN_00474070(PTR_DAT_00802c54,iVar4,uVar5);
    FUN_004d6060(iVar4,uVar5);
    FUN_00592280(iVar4);
    FUN_00490d10(PTR_DAT_00802c54,iVar4);
    if ((*(uint *)(*(int *)(*(int *)(iVar4 + 0x54) + 0x24) + 0x94) & 0x8000) == 0) {
      FUN_004b15c0(uVar5,uVar9);
      FUN_004a28e0(uVar9);
      FUN_004a3270(iVar4,uVar5,1);
      FUN_004a4420(uVar5);
      FUN_004a2070(uVar5);
      FUN_004a3270(iVar4,uVar5,2);
      FUN_004a4ff0(param_1);
    }
    if ((*(uint *)(*(int *)(iVar4 + 0x54) + 4) & 0x40000) != 0) {
      FUN_004ce830(iVar4,uVar5);
    }
    FUN_004d0290(iVar4);
    if ((*(int *)(iVar4 + 0xcbc) != 0) && ((*(byte *)(*(int *)(iVar4 + 0xcbc) + 0xc) & 4) != 0)) {
      FUN_004271b0(iVar4);
    }
    FUN_0049dfd0(iVar4,uVar12);
    FUN_0058d6a0(iVar4);
    FUN_0058db50(iVar4);
    FUN_0058dec0(iVar4);
    FUN_0058e420(iVar4);
    FUN_0049e450(uVar10,uVar12,uVar13,0);
    FUN_004a1c70(uVar10,uVar12);
    FUN_004a10c0(uVar10,uVar12,uVar13,uVar5);
    FUN_004a0bc0();
    if (((*(uint *)(*(int *)(*(int *)(iVar4 + 0x54) + 0x24) + 0x90) & 0x8000) != 0) &&
       (iVar8 = *(int *)(*(int *)(*(int *)(PTR_DAT_00802c54 + 0x134) + 8) + 0x9b0), iVar8 != -1)) {
      FUN_00684be0(iVar8,iVar4 + 0x80,6,_DAT_00925018,0,0,0);
    }
    FUN_004a7d00();
    FUN_0058cef0(iVar4);
    FUN_0058cf50(iVar4);
    FUN_0058d150(iVar4);
    cVar2 = *(char *)(iVar4 + 0x7b5);
    if ((((cVar2 == '\x1b') && (*(char *)(iVar4 + 0x7b3) == '\x01')) || (cVar2 == '\x1d')) ||
       (cVar2 == '\b')) {
      fVar3 = 1.0;
    }
    else {
      fVar3 = 0.0;
    }
    fVar14 = (float10)FUN_0054fad0(*(undefined4 *)(iVar4 + 0xd94),fVar3,_DAT_00925018);
    fVar1 = (float)fVar14;
    *(float *)(iVar4 + 0xd94) = fVar1;
    if (0.0 < fVar1) {
      FUN_00651470("JForceUse",iVar4 + 0x80,fVar1);
    }
    if ((((*(byte *)(iVar4 + 0x1fc) & 0x80) != 0) && (fVar3 == 1.0)) &&
       (iVar8 = FUN_0056e460((int)*(char *)(iVar4 + 0x280)), iVar8 == 0)) {
      iVar8 = FUN_0054fa60((float)*(byte *)(iVar4 + 0x28d) * 0.3);
      FUN_0054ac00(iVar4,(float)iVar8 * 1.5259022e-05 * 0.5);
    }
  }
  return;
}


/* Ghidra analysis pseudocode, not original source.
 * ev_89b7b842136f36149785ae3176f422ef77993aed8671c7148cbe0781c54fcb17
 * Entry: 0x475890; label: FUN_00475890
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00475890(int param_1)

{
  short sVar1;
  undefined1 uVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  undefined1 uVar6;
  
  iVar3 = FUN_00574e20();
  uVar4 = FUN_006e6b90();
  FUN_0050d910(*(undefined4 *)(DAT_00926c20 + DAT_00880798 * 4),0,_DAT_007f92ec,0x3f800000,
               _DAT_007f92f0,_DAT_007f92f0,_DAT_007f92f0,0,DAT_007f92f4,DAT_007f92f8,DAT_00879b1c,
               0x3fd9999a,1,0,0,uVar4);
  uVar2 = DAT_0087b6c9;
  uVar6 = DAT_0087b6c8;
  if (iVar3 == -1) {
    if ((DAT_0093d7f0 == 0) || ((*(byte *)(DAT_0093d7f0 + 0x1fc) & 0x80) == 0)) {
      uVar6 = 0;
    }
    else {
      uVar6 = 1;
    }
    if ((DAT_0093d7f4 == 0) || ((*(byte *)(DAT_0093d7f4 + 0x1fc) & 0x80) == 0)) {
      uVar2 = 0;
    }
    else {
      uVar2 = 1;
    }
  }
  FUN_004b8cf0(_DAT_007fc310,uVar6,uVar2,param_1,&DAT_0087956c);
  iVar5 = FUN_00574e20();
  if (iVar5 == 0x10) {
    if (DAT_0087950c == 0) {
      return;
    }
    if (DAT_00879584 != 4) {
      return;
    }
    iVar3 = FUN_00475350();
    if (iVar3 != 0) {
      return;
    }
    sVar1 = DAT_008807a4;
    if (param_1 != 1) {
      return;
    }
  }
  else {
    if (iVar3 != -1) {
      return;
    }
    iVar3 = FUN_0055f1a0();
    sVar1 = DAT_008807a0;
    if (iVar3 != 0) {
      return;
    }
  }
  if (sVar1 != -1) {
    FUN_005b7d30(_DAT_00925030,0x3f000000);
    uVar4 = FUN_006e6b90();
    FUN_0050d910(*(undefined4 *)(DAT_00926c20 + sVar1 * 4),0,_DAT_007f92e4,0x3f800000,_DAT_007f92e8,
                 _DAT_007f92e8,_DAT_007f92e8,0,0xff,0,0,0x3fd9999a,1,0,0,uVar4);
  }
  return;
}


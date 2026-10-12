/* Ghidra pseudocode, not original source.
 * ev_c8c236b59c094db138f75ad711126508fb50275f6e5d8f12ab0ad6308e4435ce
 * Entry: 0x496480; label: FUN_00496480
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00496480(undefined4 param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  byte *pbVar4;
  byte *pbVar5;
  
  if (DAT_0087b74c != 0) {
    DAT_0087a9cc = 0x3f19999a;
    _DAT_0087b940 = 0x40000000;
    DAT_0087a928 = 1;
    FUN_005097d0(&DAT_00921440 + DAT_00800944 * 0x38);
    FUN_00509760();
    FUN_0042b080();
    DAT_0087b74c = 0;
    return;
  }
  iVar1 = FUN_004c74e0(param_1);
  if (iVar1 == 0) {
    return;
  }
  FUN_00547930(0x31,0,0,0);
  _DAT_0087bd78 = 0;
  DAT_00880474 = 0;
  DAT_0087b748 = 1;
  if (DAT_00879b2c != 0) goto LAB_004965bd;
  _DAT_0085e838 = _DAT_0086e4e8;
  uVar2 = 0x7e4c;
  pbVar5 = (byte *)&DAT_00856c18;
  pbVar4 = (byte *)&DAT_008668c8;
  do {
    if (*(int *)pbVar5 != *(int *)pbVar4) goto LAB_00496558;
    uVar2 = uVar2 - 4;
    pbVar4 = pbVar4 + 4;
    pbVar5 = pbVar5 + 4;
  } while (3 < uVar2);
  if (uVar2 == 0) {
LAB_004965b5:
    iVar3 = 0;
  }
  else {
LAB_00496558:
    iVar1 = (uint)*pbVar5 - (uint)*pbVar4;
    if (iVar1 == 0) {
      if (uVar2 == 1) goto LAB_004965b5;
      iVar1 = (uint)pbVar5[1] - (uint)pbVar4[1];
      if (iVar1 == 0) {
        if (uVar2 == 2) goto LAB_004965b5;
        iVar1 = (uint)pbVar5[2] - (uint)pbVar4[2];
        if (iVar1 == 0) {
          if ((uVar2 == 3) || (iVar1 = (uint)pbVar5[3] - (uint)pbVar4[3], iVar1 == 0))
          goto LAB_004965b5;
        }
      }
    }
    iVar3 = 1;
    if (iVar1 < 1) {
      iVar3 = -1;
    }
  }
  if (iVar3 == 0) {
    DAT_0087a9cc = 0x3f19999a;
    _DAT_0087b940 = 0x40000000;
    DAT_0087a928 = 1;
    FUN_005097d0(&DAT_00921440 + DAT_00800944 * 0x38);
    FUN_00509760();
    FUN_0042b080();
    return;
  }
LAB_004965bd:
  DAT_00879b2c = 0;
  FUN_00486c00(0);
  FUN_00479da0();
  FUN_004cf4b0();
  iVar1 = FUN_0050c000();
  if (iVar1 == 0) {
    DAT_0087b74c = 1;
    FUN_00509830(1000,0xffffffff,0xffffffff);
    return;
  }
  FUN_00496430();
  return;
}


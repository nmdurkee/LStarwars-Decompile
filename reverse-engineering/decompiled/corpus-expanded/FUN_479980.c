/* Ghidra pseudocode, not original source.
 * ev_d7259de4d528e446adcf31e3fd20dda0be8e8c3eebc020039674bf2429a30a4e
 * Entry: 0x479980; label: FUN_00479980
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00479980(void)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  bool bVar5;
  
  iVar3 = 0;
  iVar4 = 0;
  bVar1 = false;
  if (_DAT_00879b44 <= 0.0) {
    if (DAT_0087b6c8 != '\0') {
      if ((DAT_009253b4 & DAT_00802288) == 0) {
        if ((DAT_0080228c & DAT_009253b4) != 0) goto LAB_004799d2;
      }
      else if ((DAT_0080228c & DAT_009253b4) == 0) {
        iVar4 = 1;
      }
      else {
LAB_004799d2:
        if ((DAT_009253b4 & DAT_00802288) == 0) {
          iVar3 = 1;
        }
      }
      if ((DAT_009253b8 & DAT_008022c8) != 0) {
        bVar1 = true;
      }
    }
    if (DAT_0087b6c9 != '\0') {
      if ((DAT_00925414 & DAT_00802288) == 0) {
        if ((DAT_0080228c & DAT_00925414) != 0) goto LAB_00479a0a;
      }
      else if ((DAT_0080228c & DAT_00925414) == 0) {
        iVar4 = iVar4 + 1;
      }
      else {
LAB_00479a0a:
        if ((DAT_00925414 & DAT_00802288) == 0) {
          iVar3 = iVar3 + 1;
        }
      }
      if ((DAT_00925418 & DAT_008022c8) != 0) {
        bVar1 = true;
      }
    }
  }
  iVar2 = DAT_00879b34;
  if (iVar4 == 0) {
    if (iVar3 == 0) goto LAB_00479ad7;
    _DAT_00879b40 = 0x3f800000;
    iVar4 = 0;
    do {
      iVar2 = iVar2 + 1;
      if (DAT_00951360 <= iVar2) {
        iVar2 = 0;
      }
      iVar4 = iVar4 + 1;
    } while ((iVar4 < DAT_00951360) && ((*(byte *)(iVar2 * 0x9c + 0x7a + DAT_00951354) & 0x10) == 0)
            );
  }
  else {
    if (iVar3 != 0) goto LAB_00479ad7;
    _DAT_00879b40 = 0xbf800000;
    iVar4 = 0;
    do {
      iVar2 = iVar2 + -1;
      if (iVar2 < 0) {
        iVar2 = DAT_00951360;
      }
      iVar4 = iVar4 + 1;
    } while ((iVar4 < DAT_00951360) && ((*(byte *)(iVar2 * 0x9c + 0x7a + DAT_00951354) & 0x10) == 0)
            );
  }
  bVar5 = iVar2 != DAT_00879b34;
  DAT_00879b34 = iVar2;
  if (bVar5) {
    _DAT_00879b44 = 1.0;
    _DAT_00879b38 = 0;
    FUN_00681f40("JForcePush",&DAT_007f9334);
  }
LAB_00479ad7:
  if (bVar1) {
    FUN_00547930(0x31,0,0,0);
    FUN_00509760();
    _DAT_00879518 = 0;
    DAT_0087954c = 0xffffffff;
    _DAT_00879568 = 0;
    DAT_0087a92c = 1;
    _DAT_0087a9dc = 0x3f19999a;
  }
  return;
}


/* Ghidra pseudocode, not original source.
 * ev_001bae53855cec29a6ea9336ea11e15c4e661e4f9ad78accb3ab39ae90f716fb
 * Entry: 0x61f510; label: FUN_0061f510
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0061f510(void)

{
  float *pfVar1;
  int iVar2;
  float *pfVar3;
  
  if (0 < DAT_02910ca4) {
    DAT_02854d1c = DAT_02854d1c + 1;
    pfVar1 = (float *)0x0;
    FUN_00600b20(0);
    FUN_00607d70(0xe,5,DAT_02900c70);
    if (DAT_02912e8c == (float *)0x0) {
      pfVar3 = (float *)&DAT_02912138;
      iVar2 = DAT_02910ca4;
    }
    else {
      iVar2 = 1;
      pfVar3 = DAT_02912e8c;
    }
    if (0 < iVar2) {
      do {
        FUN_005b9e30();
        FUN_00617cb0();
        FUN_006009e0(*pfVar3,pfVar3[1],0);
        FUN_00617cb0();
        FUN_006009e0(*pfVar3 + pfVar3[2],pfVar3[1],0);
        FUN_00617cb0();
        FUN_006009e0(*pfVar3 + pfVar3[2],pfVar3[1],0);
        FUN_00617cb0();
        FUN_006009e0(*pfVar3 + pfVar3[2],pfVar3[3] + pfVar3[1],0);
        FUN_00617cb0();
        FUN_006009e0(*pfVar3 + pfVar3[2],pfVar3[3] + pfVar3[1],0);
        FUN_00617cb0();
        FUN_006009e0(*pfVar3,pfVar3[3] + pfVar3[1],0);
        FUN_00617cb0();
        FUN_006009e0(*pfVar3,pfVar3[3] + pfVar3[1],0);
        FUN_00617cb0();
        FUN_006009e0(*pfVar3,pfVar3[1],0);
        if ((((*pfVar3 < _DAT_0080f550 != (*pfVar3 == _DAT_0080f550)) &&
             (pfVar3[1] < _DAT_0080f554 != (pfVar3[1] == _DAT_0080f554))) &&
            (_DAT_0080f550 < *pfVar3 + pfVar3[2])) && (_DAT_0080f554 < pfVar3[3] + pfVar3[1])) {
          pfVar1 = pfVar3;
        }
        pfVar3 = pfVar3 + 9;
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
    }
    FUN_006009a0();
    if (pfVar1 != (float *)0x0) {
      FUN_00607d70(0x10,5,DAT_02900c7c);
      FUN_005b9e30();
      FUN_00617cb0();
      FUN_006009e0(*pfVar1,pfVar1[1],0);
      FUN_00617cb0();
      FUN_006009e0(pfVar1[2] + *pfVar1,pfVar1[3] + pfVar1[1],0);
      FUN_006009a0();
    }
    iVar2 = DAT_02854d1c * 4;
    DAT_02854d1c = DAT_02854d1c + -1;
    FUN_00600b20(*(undefined4 *)(&DAT_00981c4c + iVar2));
  }
  return;
}


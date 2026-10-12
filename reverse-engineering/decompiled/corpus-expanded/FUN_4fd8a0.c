/* Ghidra pseudocode, not original source.
 * ev_291f832bd6f6d010a6248a6acee690ff87721c4cdff92148d1e7c4ba042507e6
 * Entry: 0x4fd8a0; label: FUN_004fd8a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int * FUN_004fd8a0(undefined4 param_1,int *param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  DAT_0091eeb8 = 0;
  if (0x2000 < param_4) {
    FUN_004ef7b0();
    DAT_0091eeb8 = 5;
    return (int *)0x0;
  }
  if (param_4 < 5) {
    param_4 = 4;
  }
  piVar3 = (int *)(*param_2 + -1 + param_4 & ~(param_4 - 1U));
  *param_2 = (int)piVar3;
  iVar1 = FUN_004fd5d0(param_1,piVar3,param_3 - (int)piVar3);
  *param_2 = *param_2 + iVar1;
  if (iVar1 == 0) {
    DAT_0091eeb8 = 1;
    return (int *)0x0;
  }
  if (iVar1 != piVar3[2]) {
    FUN_004ef7b0();
    DAT_0091eeb8 = 5;
    return (int *)0x0;
  }
  iVar1 = *piVar3;
  if (iVar1 != 0x12345678) {
    if (iVar1 == 0x12345679) {
      iVar1 = piVar3[3];
      piVar3[3] = 0;
      iVar2 = FUN_004f0de0();
      if (iVar1 != iVar2) goto LAB_004fd9cf;
    }
    else {
      if (iVar1 != 0x1234567a) {
        FUN_004ef7b0(iVar1);
        DAT_0091eeb8 = 4;
        return (int *)0x0;
      }
      iVar1 = piVar3[3];
      piVar3[3] = 0;
      iVar2 = FUN_004f0de0();
      if (iVar1 != iVar2) {
LAB_004fd9cf:
        FUN_004ef7b0();
        DAT_0091eeb8 = 3;
        return (int *)0x0;
      }
      if ((*(byte *)(piVar3 + 4) & 1) != 0) {
        if (param_5 != 0) {
          FUN_004f0e10(param_5);
          iVar1 = piVar3[5];
          piVar3[5] = 0;
          iVar2 = FUN_004f0de0();
          if (iVar1 == iVar2) {
            return piVar3;
          }
        }
        FUN_004ef7b0();
        DAT_0091eeb8 = 6;
        return (int *)0x0;
      }
    }
  }
  return piVar3;
}


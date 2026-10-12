/* Ghidra pseudocode, not original source.
 * ev_4aa7baba24777c7cef62b6758f8d176321ddee5c4eaac4ea92e033f295beb802
 * Entry: 0x450030; label: FUN_00450030
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4
FUN_00450030(undefined4 param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
            float param_7)

{
  ushort *puVar1;
  uint *puVar2;
  int iVar3;
  bool bVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  int aiStack_40 [16];
  
  iVar8 = 0;
  iVar7 = 0;
  bVar4 = false;
  if (((param_3 == 0) || (piVar6 = *(int **)(param_3 + 0xd0), piVar6 == (int *)0x0)) ||
     (*piVar6 == 0)) {
    return 1;
  }
  iVar3 = *piVar6;
  if ((param_6 != 0) && (*(undefined4 *)(param_2 + 0x6c) = 0, 0 < param_5)) {
    do {
      iVar5 = FUN_004f8b10(*(undefined4 *)(param_4 + iVar8 * 4),"throwable");
      if (iVar5 == 0) {
        *(undefined1 *)(param_2 + 0x68) = 1;
      }
      else {
        iVar5 = FUN_004f8b10(*(undefined4 *)(param_4 + iVar8 * 4),"inrange");
        if (iVar5 == 0) {
          *(undefined1 *)(param_2 + 0x69) = 1;
        }
        else {
          iVar5 = FUN_004f8b10(*(undefined4 *)(param_4 + iVar8 * 4),"triggered_by_hit");
          if (iVar5 == 0) {
            bVar4 = true;
          }
          else {
            iVar5 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar8 * 4),&DAT_0075782c);
            if (iVar5 == 0) {
              iVar5 = *(int *)(param_4 + iVar8 * 4);
            }
            else {
              iVar5 = iVar5 + 5;
            }
            if (((iVar5 != 0) && (iVar7 < 0x10)) &&
               ((piVar6 = (int *)FUN_0055a020(*(undefined4 *)(PTR_DAT_00802c54 + 0x2ac8),
                                              DAT_007f8cc4,iVar5), piVar6 != (int *)0x0 &&
                (iVar5 = *piVar6, iVar5 != 0)))) {
              aiStack_40[iVar7] = iVar5;
              if (((*(uint *)(iVar5 + 0xa0) & 2) != 0) && ((*(uint *)(iVar5 + 0xa0) & 0x10000) == 0)
                 ) {
                iVar7 = iVar7 + 1;
              }
            }
          }
        }
      }
      iVar8 = iVar8 + 1;
    } while (iVar8 < param_5);
    if (iVar7 != 0) {
      iVar8 = FUN_0054fa60();
      *(int *)(param_2 + 0x6c) = aiStack_40[iVar8 / ((int)(0xffff / (longlong)iVar7) + 1)];
    }
  }
  iVar7 = *(int *)(param_2 + 0x6c);
  if (iVar7 == 0) {
    return 1;
  }
  if ((*(byte *)(iVar7 + 0xa0) & 1) != 0) {
    iVar8 = FUN_0055bc80(iVar3,(*(byte *)(iVar7 + 0x74) & 0x10) != 0);
    if (bVar4) {
      *(uint *)(iVar7 + 0xa0) = *(uint *)(iVar7 + 0xa0) | 0x8000;
      return 0;
    }
    if (iVar8 == 0) {
      if ((DAT_0093b2a4 != 0) &&
         (param_7 = *(float *)(param_2 + 0x9c) - param_7, *(float *)(param_2 + 0x9c) = param_7,
         param_7 < 0.0)) {
        *(undefined4 *)(param_2 + 0x9c) = 0x3f000000;
        puVar2 = (uint *)(*(int *)(iVar3 + 0xca4) + 8);
        *puVar2 = *puVar2 | DAT_0080228c;
      }
    }
    else {
      *(int *)(param_3 + 0x1e4) = iVar7 + 0x1c;
      puVar1 = (ushort *)(*(int *)(iVar3 + 0xca4) + 0x5a);
      *puVar1 = *puVar1 | 4;
      *(int *)(iVar3 + 0x10cc) = iVar7;
      if (*(char *)(param_2 + 0x68) != '\0') {
        if (*(int *)(param_3 + 0xd4) != 0) {
          return 1;
        }
        puVar1 = (ushort *)(*(int *)(iVar3 + 0xca4) + 0x5a);
        *puVar1 = *puVar1 & 0xfffb;
        *(undefined4 *)(iVar3 + 0x10cc) = 0;
        return 1;
      }
      iVar7 = FUN_00467890(iVar7);
      if (iVar7 != 0) {
        return 1;
      }
    }
  }
  return 0;
}


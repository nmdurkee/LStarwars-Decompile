/* Ghidra pseudocode, not original source.
 * ev_89fddb9d43176fe460e635fa694f7b202ecc9b6cc52422bc9fe5e2fbe10c5c63
 * Entry: 0x44d5c0; label: FUN_0044d5c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4
FUN_0044d5c0(undefined4 param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
            float param_7)

{
  uint *puVar1;
  float fVar2;
  int *piVar3;
  int iVar4;
  bool bVar5;
  int iVar6;
  int iVar7;
  float10 fVar8;
  
  iVar7 = 0;
  bVar5 = false;
  if ((((param_3 == 0) || (piVar3 = *(int **)(param_3 + 0xd0), piVar3 == (int *)0x0)) ||
      (*piVar3 == 0)) || ((iVar4 = *piVar3, DAT_0093b2a4 == 0 || (*(char *)(iVar4 + 0x280) == -1))))
  {
    return 1;
  }
  if (param_6 != 0) {
    *(undefined1 *)(param_2 + 0x68) = (undefined1)DAT_0093b26c;
    *(undefined1 *)(param_2 + 0x69) = (undefined1)DAT_0093b26c;
    if (0 < param_5) {
      do {
        iVar6 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar7 * 4),&DAT_00757ca8);
        if (iVar6 == 0) {
          iVar6 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar7 * 4),"Category");
          if (iVar6 == 0) {
            iVar6 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar7 * 4),"min_speed=");
            if (iVar6 == 0) {
              iVar6 = FUN_004f8b10(*(undefined4 *)(param_4 + iVar7 * 4),"SingleSwitch");
              if (iVar6 == 0) {
                bVar5 = true;
              }
            }
            else {
              fVar8 = (float10)FUN_005147c0(param_2,iVar6 + 10);
              *(float *)(param_2 + 0x74) = (float)fVar8;
            }
          }
          else {
            iVar6 = FUN_0055bc20(iVar6 + 9);
            if (iVar6 != -1) {
              if ((int)(uint)*(byte *)(param_2 + 0x68) < DAT_0093b26c) {
                *(char *)(param_2 + 0x69) = (char)iVar6;
              }
              else {
                *(char *)(param_2 + 0x68) = (char)iVar6;
              }
              break;
            }
          }
        }
        else {
          fVar8 = (float10)FUN_005147c0(param_2,iVar6 + 5);
          *(float *)(param_2 + 0x70) = (float)fVar8;
        }
        iVar7 = iVar7 + 1;
      } while (iVar7 < param_5);
    }
  }
  if (*(char *)(iVar4 + 0x7b5) == '\v') {
    return 0;
  }
  if ((int)(uint)*(byte *)(param_2 + 0x68) < DAT_0093b26c) {
    if (((*(float *)(param_2 + 0x74) != 0.0) &&
        (fVar2 = *(float *)(*(int *)(*(int *)(*(int *)(param_3 + 0xd0) + 0x54) + 0x24) + 0x1c),
        *(float *)(param_2 + 0x74) < fVar2 == (*(float *)(param_2 + 0x74) == fVar2))) ||
       ((iVar7 = FUN_0055bc80(iVar4,(uint)*(byte *)(param_2 + 0x68)), iVar7 == 0 &&
        ((DAT_0093b26c <= (int)(uint)*(byte *)(param_2 + 0x69) ||
         (iVar7 = FUN_0055bc80(iVar4,(uint)*(byte *)(param_2 + 0x69)), iVar7 == 0)))))) {
      param_7 = *(float *)(param_2 + 0x9c) + param_7;
      *(float *)(param_2 + 0x9c) = param_7;
      if (param_7 <= *(float *)(param_2 + 0x70)) {
        return 0;
      }
      *(undefined4 *)(param_2 + 0x9c) = 0;
      puVar1 = (uint *)(*(int *)(iVar4 + 0xca4) + 8);
      *puVar1 = *puVar1 | DAT_0080228c;
      return 0;
    }
  }
  else if (*(float *)(param_2 + 0x74) == 0.0) {
    if (bVar5) {
      puVar1 = (uint *)(*(int *)(iVar4 + 0xca4) + 8);
      *puVar1 = *puVar1 | DAT_0080228c;
      return 1;
    }
  }
  else {
    fVar2 = *(float *)(*(int *)(*(int *)(*(int *)(param_3 + 0xd0) + 0x54) + 0x24) + 0x1c);
    if ((*(float *)(param_2 + 0x74) < fVar2 != (*(float *)(param_2 + 0x74) == fVar2)) ||
       (param_7 = *(float *)(param_2 + 0x9c) + param_7, *(float *)(param_2 + 0x9c) = param_7,
       param_7 <= *(float *)(param_2 + 0x70))) {
      return 1;
    }
    *(undefined4 *)(param_2 + 0x9c) = 0;
    puVar1 = (uint *)(*(int *)(iVar4 + 0xca4) + 8);
    *puVar1 = *puVar1 | DAT_0080228c;
  }
  return 1;
}


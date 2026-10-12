/* Ghidra pseudocode, not original source.
 * ev_fe5af94714569ca149d7ee11beb07ec697c406bef5bd6833183fcd21241d309c
 * Entry: 0x51d5e0; label: FUN_0051d5e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0051d5e0(int param_1,float param_2)

{
  byte *pbVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  float10 fVar8;
  float local_10;
  int local_c;
  double local_8;
  
  iVar2 = (int)param_2;
  iVar7 = *(int *)(*(int *)((int)param_2 + 0x158) + 0x7c);
  iVar5 = 0;
  iVar6 = (uint)*(byte *)(*(int *)((int)param_2 + 0x15c) + 0x10) * 0x5c + iVar7;
  local_c = 0;
  iVar7 = (uint)*(byte *)(*(int *)((int)param_2 + 0x15c) + 0x11) * 0x5c + iVar7;
  fVar8 = (float10)FUN_005b3c50(*(int *)((int)param_2 + 0xd0) + 0x5c,iVar6 + 4,0);
  param_2 = (float)(fVar8 - (float10)*(float *)(iVar6 + 0x14));
  local_8 = (double)param_2;
  fVar8 = (float10)FUN_005b3c50(*(int *)(iVar2 + 0xd0) + 0x5c,iVar7 + 4,0);
  if ((float)(fVar8 - (float10)*(float *)(iVar7 + 0x14)) <= (float)local_8) {
    iVar6 = iVar7;
  }
  if (*(byte *)(iVar6 + 0x30) < *(byte *)(*(int *)(iVar2 + 0x158) + 0x7a)) {
    pbVar1 = (byte *)(*(int *)(*(int *)(param_1 + 0x10) + 0xc) +
                     *(short *)(*(int *)(*(int *)(iVar2 + 0x158) + 0x8c) + 2 +
                               (uint)*(byte *)(iVar6 + 0x30) * 4) * 8);
    uVar3 = (uint)*pbVar1;
    iVar7 = 0;
    if (uVar3 != 0) {
      piVar4 = *(int **)(pbVar1 + 4);
      do {
        if (*piVar4 == *(int *)(iVar2 + 0x1cc)) {
          FUN_0051a7c0(iVar2,*(int *)(iVar2 + 0x1cc));
          return 1;
        }
        iVar7 = iVar7 + 1;
        piVar4 = piVar4 + 1;
      } while (iVar7 < (int)uVar3);
    }
    local_10 = 3.4028235e+38;
    if (uVar3 != 0) {
      do {
        FUN_0051d1f0(iVar2 + 0x1b4,&local_8,&param_2);
        if (param_2 < local_10) {
          local_10 = param_2;
          local_c = *(int *)(*(int *)(pbVar1 + 4) + iVar5 * 4);
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 < (int)(uint)*pbVar1);
      if (local_c != 0) {
        FUN_0051a7c0(iVar2,local_c);
        return 1;
      }
    }
  }
  return 0;
}


/* Ghidra pseudocode, not original source.
 * ev_9cfa2c7caaff9bea1a8899eb9da7a192a21c6dc6359864cdd250e80ead8b0fa3
 * Entry: 0x4e3a00; label: FUN_004e3a00
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_004e3a00(int param_1,int param_2,float param_3,int param_4,int param_5,int param_6)

{
  uint *puVar1;
  int iVar2;
  float fVar3;
  bool bVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  float10 fVar9;
  int local_18;
  undefined1 local_c [12];
  
  iVar5 = (int)param_3;
  iVar7 = 0;
  local_18 = 0;
  bVar4 = true;
  if (((param_3 != 0.0) && (piVar8 = *(int **)((int)param_3 + 0xd0), piVar8 != (int *)0x0)) &&
     (*piVar8 != 0)) {
    iVar2 = *piVar8;
    if (param_6 != 0) {
      *(undefined4 *)(param_2 + 0x70) = 0x3f800000;
      *(undefined4 *)(param_2 + 0x74) = 0x3f800000;
      if (0 < param_5) {
        do {
          iVar6 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar7 * 4),"boulder_range=");
          if (iVar6 == 0) {
            iVar6 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar7 * 4),"attack_time=");
            if (iVar6 == 0) {
              fVar9 = (float10)FUN_005147c0(param_2,*(undefined4 *)(param_4 + iVar7 * 4));
              *(float *)((int)param_3 + 0x180) = (float)fVar9;
            }
            else {
              fVar9 = (float10)FUN_005147c0(param_3,iVar6 + 0xc);
              *(float *)(param_2 + 0x74) = (float)fVar9;
            }
          }
          else {
            fVar9 = (float10)FUN_005147c0(param_3,iVar6 + 0xe);
            *(float *)(param_2 + 0x70) = (float)fVar9;
          }
          iVar7 = iVar7 + 1;
        } while (iVar7 < param_5);
      }
    }
    if (((DAT_0093b2a4 != 0) && (iVar7 = FUN_0055bc80(iVar2,0), iVar7 == 0)) &&
       ((iVar7 = FUN_0055bc80(iVar2,1), iVar7 == 0 && (iVar7 = FUN_0055bc80(iVar2,8), iVar7 == 0))))
    {
      fVar3 = *(float *)(param_2 + 0x9c) - _DAT_00925018;
      *(float *)(param_2 + 0x9c) = fVar3;
      bVar4 = false;
      if (fVar3 < 0.0) {
        *(undefined4 *)(param_2 + 0x9c) = 0x3f000000;
        puVar1 = (uint *)(*(int *)(iVar2 + 0xca4) + 8);
        *puVar1 = *puVar1 | DAT_00802288;
      }
    }
    *(uint *)(iVar2 + 0xeec) = *(uint *)(iVar2 + 0xeec) | 0x10;
    param_3 = *(float *)(param_2 + 0x70) * *(float *)(param_2 + 0x70);
    piVar8 = &DAT_008895c0;
    do {
      if (*piVar8 != 0) {
        fVar9 = (float10)FUN_005b3c50(iVar2 + 0x80,*piVar8 + 0x30,local_c);
        if ((float)fVar9 < param_3) {
          local_18 = *piVar8;
          param_3 = (float)fVar9;
        }
      }
      piVar8 = piVar8 + 1;
    } while ((int)piVar8 < 0x8895cc);
    if (local_18 == 0) {
      iVar7 = *(int *)(*(int *)(param_1 + 0x138c) + 4);
      FUN_0052fcb0(iVar5,iVar7 + 0x170,*(undefined4 *)(iVar7 + 0x120),iVar7 + 0x158,1,
                   *(undefined4 *)(iVar5 + 0x180));
    }
    else {
      *(int *)(iVar5 + 0x1e4) = local_18 + 0x30;
      if (bVar4) {
        puVar1 = (uint *)(*(int *)(iVar2 + 0xca4) + 8);
        *puVar1 = *puVar1 | DAT_0080227c;
        return 0;
      }
    }
    return 0;
  }
  return 1;
}


/* Ghidra pseudocode, not original source.
 * ev_ea16e91579c763516a5ec9191881acc35a0dcfc8106f35e62baf3c19fc401ba6
 * Entry: 0x448830; label: FUN_00448830
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
FUN_00448830(undefined4 param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
            float param_7)

{
  uint *puVar1;
  char cVar2;
  byte bVar3;
  int *piVar4;
  int iVar5;
  float fVar6;
  bool bVar7;
  int iVar8;
  undefined4 uVar9;
  int iVar10;
  float10 fVar11;
  undefined8 uVar12;
  float local_24;
  undefined1 local_18 [8];
  float local_10;
  undefined1 local_c [12];
  
  bVar7 = false;
  if (((param_3 != 0) && (piVar4 = *(int **)(param_3 + 0xd0), piVar4 != (int *)0x0)) &&
     (*piVar4 != 0)) {
    iVar5 = *piVar4;
    if (param_6 != 0) {
      *(undefined4 *)(param_2 + 0x74) = _DAT_007f6828;
      fVar11 = (float10)FUN_005b9dd0();
      iVar10 = 0;
      local_24 = (float)fVar11;
      if (0 < param_5) {
        do {
          iVar8 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar10 * 4),"firerange");
          if (iVar8 == 0) {
            iVar8 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar10 * 4),"offscreen");
            if (iVar8 == 0) {
              iVar8 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar10 * 4),"no_fire_in_minicut");
              if (iVar8 == 0) {
                iVar8 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar10 * 4),"fireinterval");
                if (iVar8 == 0) {
                  iVar8 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar10 * 4),"opponent=");
                  if (iVar8 == 0) {
                    iVar8 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar10 * 4),"instant");
                    if (iVar8 == 0) {
                      iVar8 = FUN_004f8b10(*(undefined4 *)(param_4 + iVar10 * 4),"frontArcOnly");
                      if (iVar8 == 0) {
                        *(undefined1 *)(param_2 + 0x69) = 1;
                      }
                    }
                    else {
                      local_24 = 0.0;
                    }
                  }
                  else {
                    uVar9 = FUN_00440120(param_1,iVar8 + 9);
                    *(undefined4 *)(param_2 + 0x6c) = uVar9;
                  }
                }
                else {
                  fVar11 = (float10)FUN_005147c0(param_2,iVar8 + 0xd);
                  *(float *)(param_2 + 0x74) = (float)fVar11;
                }
              }
              else {
                *(byte *)(param_2 + 0x68) = *(byte *)(param_2 + 0x68) | 4;
              }
            }
            else {
              *(byte *)(param_2 + 0x68) = *(byte *)(param_2 + 0x68) | 1;
            }
          }
          else {
            fVar11 = (float10)FUN_005147c0(param_2,iVar8 + 10);
            *(float *)(param_2 + 0x70) = (float)fVar11;
            bVar7 = true;
          }
          iVar10 = iVar10 + 1;
        } while (iVar10 < param_5);
      }
      *(float *)(param_2 + 0x9c) = *(float *)(param_2 + 0x74) * local_24;
      if (!bVar7) {
        if (*(float *)(param_3 + 0x180) == 0.0) {
          fVar6 = 9999.9;
        }
        else {
          fVar6 = *(float *)(param_3 + 0x180) + _DAT_007f682c;
        }
        *(float *)(param_2 + 0x70) = fVar6;
      }
    }
    iVar10 = *(int *)(param_2 + 0x6c);
    if ((((iVar10 != 0) && ((*(uint *)(iVar10 + 0x1fc) & 1) != 0)) &&
        (((*(uint *)(iVar10 + 0x1fc) & 0x1000) != 0 &&
         ((*(char *)(iVar10 + 0x28b) == '\0' || (0.0 < *(float *)(iVar10 + 0x1010))))))) ||
       ((piVar4 = *(int **)(param_3 + 0xe4), piVar4 != (int *)0x0 &&
        ((piVar4[1] != 0 && (iVar10 = *piVar4, iVar10 != 0)))))) {
      iVar8 = iVar10 + 0x5c;
      fVar11 = (float10)FUN_005b3c50(*(int *)(param_3 + 0xd0) + 0x5c,iVar8,local_c);
      *(uint *)(iVar5 + 0xeec) = *(uint *)(iVar5 + 0xeec) | 0x20;
      cVar2 = *(char *)(param_2 + 0x69);
      if (cVar2 != '\0') {
        FUN_005b3800(local_18,iVar8,*(int *)(param_3 + 0xd0) + 0x5c);
        FUN_005b3620(local_18,local_18,-(uint)*(ushort *)(*(int *)(param_3 + 0xd0) + 0x27a));
        if (0.0 < local_10) {
          cVar2 = '\0';
        }
      }
      bVar3 = *(byte *)(iVar5 + 0x28d);
      uVar12 = __allshl();
      if (((((uint)uVar12 & *(uint *)(*(int *)(PTR_DAT_00802c54 + 0x298c) + 8 + (uint)bVar3 * 8)) !=
            0 || ((uint)((ulonglong)uVar12 >> 0x20) &
                 *(uint *)(*(int *)(PTR_DAT_00802c54 + 0x298c) + 0xc + (uint)bVar3 * 8)) != 0) &&
          ((((*(char *)(iVar5 + 0x288) != '\0' || ((*(byte *)(param_2 + 0x68) & 1) != 0)) &&
            ((float)fVar11 < *(float *)(param_2 + 0x70) * *(float *)(param_2 + 0x70))) &&
           ((*(char *)(iVar10 + 0x28b) == '\0' || (0.0 < *(float *)(iVar10 + 0x1010))))))) &&
         (cVar2 == '\0')) {
        *(int *)(param_3 + 0x1e4) = iVar8;
        if ((DAT_00855de0 == 0) || ((*(byte *)(param_2 + 0x68) & 4) == 0)) {
          fVar11 = (float10)*(float *)(param_2 + 0x9c) - (float10)param_7;
        }
        else {
          fVar11 = (float10)FUN_005b9dd0();
          fVar11 = fVar11 * (float10)*(float *)(param_2 + 0x74) + (float10)2.0;
        }
        *(float *)(param_2 + 0x9c) = (float)fVar11;
        if ((*(char *)(iVar10 + 0x28b) == '\0') && (*(float *)(param_2 + 0x9c) <= 0.0)) {
          fVar11 = (float10)FUN_005b9dd0();
          *(float *)(param_2 + 0x9c) =
               (float)((float10)*(float *)(param_2 + 0x74) * (float10)0.5 +
                      fVar11 * (float10)*(float *)(param_2 + 0x74));
          iVar8 = FUN_00440150(iVar5,iVar10);
          if (iVar8 == 0) {
            puVar1 = (uint *)(*(int *)(iVar5 + 0xca4) + 8);
            *puVar1 = *puVar1 | DAT_0080227c;
            *(int *)(iVar5 + 0xea0) = iVar10;
          }
        }
      }
    }
    return 0;
  }
  return 1;
}


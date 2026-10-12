/* Ghidra pseudocode, not original source.
 * ev_ca5ea7f3b5788154105ce78c12a6b4d3dd45520787e3b427f0542ab309566885
 * Entry: 0x62c030; label: FUN_0062c030
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0062c030(int param_1,int *param_2,float *param_3,int param_4,code *param_5)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  int *piVar9;
  float *pfVar10;
  int *piVar11;
  undefined8 uVar12;
  float *local_30;
  float *local_2c;
  float *local_28;
  float local_24;
  int local_18;
  int local_14;
  
  if (param_5 != (code *)0x0) {
    local_28 = param_3 + 3;
    local_14 = 1;
    if (1 < param_1) {
      local_30 = (float *)((int)local_28 + param_4 + (4 - (int)param_3));
      piVar9 = param_2;
      do {
        piVar9 = piVar9 + 1;
        iVar2 = *piVar9;
        if (0 < local_14) {
          pfVar10 = (float *)(param_4 + 4);
          piVar11 = param_2;
          local_2c = param_3;
          local_18 = local_14;
          do {
            iVar3 = *piVar11;
            iVar4 = *piVar9;
            if ((((((*(int *)(iVar3 + 0x298) == iVar4) || (*(int *)(iVar4 + 0x298) == iVar3)) ||
                  (uVar12 = __allshl(),
                  ((uint)uVar12 & *(uint *)(iVar3 + 0x2a0)) != 0 ||
                  ((uint)((ulonglong)uVar12 >> 0x20) & *(uint *)(iVar3 + 0x2a4)) != 0)) ||
                 ((uVar12 = __allshl(),
                  ((uint)uVar12 & *(uint *)(iVar4 + 0x2a0)) != 0 ||
                  ((uint)((ulonglong)uVar12 >> 0x20) & *(uint *)(iVar4 + 0x2a4)) != 0 ||
                  (local_30[-1] < *local_2c)))) ||
                ((pfVar10[-1] < *local_28 ||
                 ((local_30[1] < local_2c[2] || (pfVar10[1] < local_28[2])))))) ||
               ((*local_30 < *(float *)(((int)param_3 - param_4) + (int)pfVar10) ||
                (*pfVar10 < *(float *)((int)local_30 + ((int)param_3 - param_4)))))) {
LAB_0062c26f:
              uVar5 = *(uint *)(iVar4 + 0x1ec);
              *(uint *)(iVar3 + 0x1f0) = *(uint *)(iVar3 + 0x1f0) & ~*(uint *)(iVar4 + 0x1e8);
              *(uint *)(iVar3 + 500) = *(uint *)(iVar3 + 500) & ~uVar5;
              uVar5 = *(uint *)(*piVar11 + 0x1ec);
              iVar3 = *piVar9;
              puVar1 = (uint *)(iVar3 + 0x1f0);
              *puVar1 = *puVar1 & ~*(uint *)(*piVar11 + 0x1e8);
              puVar1 = (uint *)(iVar3 + 500);
              *puVar1 = *puVar1 & ~uVar5;
            }
            else {
              fVar6 = *(float *)(iVar2 + 0x80) - *(float *)(iVar3 + 0x80);
              local_24 = *(float *)(iVar2 + 0x84) - *(float *)(iVar3 + 0x84);
              fVar7 = *(float *)(iVar2 + 0x88) - *(float *)(iVar3 + 0x88);
              if ((*(float *)(iVar3 + 0x1e0) != *(float *)(iVar3 + 0x1dc)) ||
                 (*(float *)(iVar4 + 0x1e0) != *(float *)(iVar4 + 0x1dc))) {
                local_24 = ((*(float *)(iVar4 + 0x1dc) + *(float *)(iVar3 + 0x1dc)) /
                           (*(float *)(iVar4 + 0x1e0) + *(float *)(iVar3 + 0x1e0))) * local_24;
              }
              fVar8 = *(float *)(iVar4 + 0x1dc) + *(float *)(iVar3 + 0x1dc);
              if (fVar8 * fVar8 <= fVar7 * fVar7 + fVar6 * fVar6 + local_24 * local_24)
              goto LAB_0062c26f;
              (*param_5)(iVar3,iVar4);
            }
            local_2c = local_2c + 3;
            piVar11 = piVar11 + 1;
            pfVar10 = pfVar10 + 3;
            local_18 = local_18 + -1;
          } while (local_18 != 0);
        }
        local_28 = local_28 + 3;
        local_30 = local_30 + 3;
        local_14 = local_14 + 1;
      } while (local_14 < param_1);
    }
  }
  return;
}


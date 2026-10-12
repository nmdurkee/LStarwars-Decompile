/* Ghidra analysis pseudocode, not original source.
 * ev_988aedce7a102035a37775149c4794654cf73d0aa98e786da352e425eaa98523
 * Entry: 0x43af40; label: FUN_0043af40
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0043af40(undefined4 param_1,int param_2,int param_3,int *param_4,float param_5)

{
  uint *puVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  int *piVar6;
  int *piVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  float10 fVar12;
  int local_30;
  int local_24;
  int local_20;
  int local_18;
  
  iVar10 = 0;
  if (3 < param_2) {
    iVar8 = (param_2 - 4U >> 2) + 1;
    piVar6 = (int *)(param_3 + 8);
    iVar10 = iVar8 * 4;
    do {
      iVar11 = piVar6[-2];
      iVar9 = *(int *)(iVar11 + 4);
      *(float *)(iVar9 + 0x18c) = *(float *)(iVar9 + 0x18c) - param_5;
      iVar11 = *(int *)(iVar11 + 4);
      if (*(float *)(iVar11 + 0x18c) < 0.0) {
        *(undefined4 *)(iVar11 + 0x18c) = 0;
      }
      iVar11 = piVar6[-1];
      iVar9 = *(int *)(iVar11 + 4);
      *(float *)(iVar9 + 0x18c) = *(float *)(iVar9 + 0x18c) - param_5;
      iVar11 = *(int *)(iVar11 + 4);
      if (*(float *)(iVar11 + 0x18c) < 0.0) {
        *(undefined4 *)(iVar11 + 0x18c) = 0;
      }
      iVar11 = *piVar6;
      iVar9 = *(int *)(iVar11 + 4);
      *(float *)(iVar9 + 0x18c) = *(float *)(iVar9 + 0x18c) - param_5;
      iVar11 = *(int *)(iVar11 + 4);
      if (*(float *)(iVar11 + 0x18c) < 0.0) {
        *(undefined4 *)(iVar11 + 0x18c) = 0;
      }
      iVar11 = piVar6[1];
      iVar9 = *(int *)(iVar11 + 4);
      *(float *)(iVar9 + 0x18c) = *(float *)(iVar9 + 0x18c) - param_5;
      iVar11 = *(int *)(iVar11 + 4);
      if (*(float *)(iVar11 + 0x18c) < 0.0) {
        *(undefined4 *)(iVar11 + 0x18c) = 0;
      }
      piVar6 = piVar6 + 4;
      iVar8 = iVar8 + -1;
    } while (iVar8 != 0);
  }
  for (; iVar10 < param_2; iVar10 = iVar10 + 1) {
    iVar8 = *(int *)(param_3 + iVar10 * 4);
    *(float *)(*(int *)(iVar8 + 4) + 0x18c) = *(float *)(*(int *)(iVar8 + 4) + 0x18c) - param_5;
    if (*(float *)(*(int *)(iVar8 + 4) + 0x18c) < 0.0) {
      *(undefined4 *)(*(int *)(iVar8 + 4) + 0x18c) = 0;
    }
  }
  local_18 = param_2 + -1;
  if (0 < local_18) {
    local_30 = 0;
    local_20 = 1;
    piVar6 = param_4;
    do {
      piVar6 = piVar6 + 1;
      iVar10 = *(int *)(local_30 + param_3);
      if (local_20 < param_2) {
        local_24 = param_2 - local_20;
        piVar7 = piVar6;
        do {
          iVar8 = *(int *)((param_3 - (int)param_4) + (int)piVar7);
          fVar2 = *(float *)(*(int *)(iVar10 + 4) + 0x120) + *(float *)(*(int *)(iVar8 + 4) + 0x120)
          ;
          fVar3 = *(float *)(*(int *)(iVar10 + 4) + 0x114) - *(float *)(*(int *)(iVar8 + 4) + 0x114)
          ;
          if (((((fVar3 <= fVar2) && (-fVar2 <= fVar3)) &&
               (fVar4 = *(float *)(*(int *)(iVar10 + 4) + 0x11c) -
                        *(float *)(*(int *)(iVar8 + 4) + 0x11c), fVar4 <= fVar2)) &&
              ((-fVar2 <= fVar4 && (*(float *)(iVar10 + 0x17c) <= *(float *)(iVar8 + 0x188))))) &&
             ((*(float *)(iVar8 + 0x17c) <= *(float *)(iVar10 + 0x188) &&
              ((*(int *)(iVar10 + 0x298) != iVar8 && (*(int *)(iVar8 + 0x298) != iVar10)))))) {
            if (param_4 == (int *)0x0) {
              iVar11 = 0;
              iVar9 = 0;
            }
            else {
              iVar11 = *(int *)(local_30 + (int)param_4);
              iVar9 = *piVar7;
            }
            if ((*(byte *)(iVar10 + 0x1fc) & 0x80) != 0) {
              iVar11 = 1;
            }
            if ((*(byte *)(iVar8 + 0x1fc) & 0x80) != 0) {
              iVar9 = 1;
            }
            if (*(ushort *)(iVar8 + 0x292) < *(ushort *)(iVar10 + 0x292)) {
              iVar11 = 1;
              iVar5 = iVar9;
            }
            else {
              if (*(ushort *)(iVar8 + 0x292) <= *(ushort *)(iVar10 + 0x292)) goto LAB_0043b276;
              iVar9 = 1;
              iVar5 = iVar11;
            }
            if ((iVar5 == 0) &&
               (fVar12 = (float10)FUN_005c0240(fVar4 * fVar4 + fVar3 * fVar3),
               fVar12 < (float10)fVar2)) {
              if (iVar11 == 0) {
                if (iVar9 == 0) {
                  *(undefined2 *)(iVar10 + 0x294) = *(undefined2 *)(iVar8 + 0x292);
                  goto LAB_0043b237;
                }
                if (*(ushort *)(iVar10 + 0x294) < *(ushort *)(iVar8 + 0x292)) {
                  *(ushort *)(iVar10 + 0x294) = *(ushort *)(iVar8 + 0x292);
                  FUN_0043ae00(iVar8,fVar2);
                }
              }
              else if (*(ushort *)(iVar8 + 0x294) < *(ushort *)(iVar10 + 0x292)) {
                *(ushort *)(iVar8 + 0x294) = *(ushort *)(iVar10 + 0x292);
LAB_0043b237:
                FUN_0043ae00(iVar10,fVar2);
              }
              iVar11 = *(int *)(iVar10 + 4);
              if ((*(float *)(iVar11 + 0x18c) <= _DAT_00801c74) ||
                 (iVar9 = *(int *)(iVar8 + 4), *(float *)(iVar9 + 0x18c) <= _DAT_00801c74)) {
                iVar9 = *(int *)(iVar8 + 4);
                if (_DAT_00801c74 < *(float *)(iVar9 + 0x18c)) goto LAB_0043b362;
                if (0.0 < *(float *)(iVar11 + 0x18c)) goto LAB_0043b397;
              }
              else {
                if (*(float *)(iVar9 + 0x18c) < *(float *)(iVar11 + 0x18c)) {
LAB_0043b397:
                  *(undefined4 *)(iVar9 + 0x18c) = *(undefined4 *)(iVar11 + 0x18c);
                  iVar9 = *(int *)(iVar10 + 4);
                  iVar11 = *(int *)(iVar8 + 4);
                }
                else {
LAB_0043b362:
                  *(undefined4 *)(iVar11 + 0x18c) = *(undefined4 *)(iVar9 + 0x18c);
                  iVar11 = *(int *)(iVar10 + 4);
                  iVar9 = *(int *)(iVar8 + 4);
                }
                *(uint *)(iVar11 + 0x1e8) =
                     *(uint *)(iVar11 + 0x1e8) ^
                     (*(uint *)(iVar9 + 0x1e8) ^ *(uint *)(iVar11 + 0x1e8)) & 0x8000;
              }
              if (((*(uint *)(iVar8 + 0x1f8) ^ *(uint *)(iVar10 + 0x1f8)) & 1) != 0) {
                puVar1 = (uint *)(*(int *)(iVar10 + 4) + 0x1e8);
                *puVar1 = *puVar1 | 0x4000;
                puVar1 = (uint *)(*(int *)(iVar8 + 4) + 0x1e8);
                *puVar1 = *puVar1 | 0x4000;
              }
            }
          }
LAB_0043b276:
          piVar7 = piVar7 + 1;
          local_24 = local_24 + -1;
        } while (local_24 != 0);
      }
      local_30 = local_30 + 4;
      local_20 = local_20 + 1;
      local_18 = local_18 + -1;
    } while (local_18 != 0);
  }
  FUN_005196f0(param_1,param_2,param_3,param_4);
  return;
}


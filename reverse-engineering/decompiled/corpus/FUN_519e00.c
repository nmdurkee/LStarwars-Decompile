/* Ghidra analysis pseudocode, not original source.
 * ev_e9352ae8b4f9815c7bd33078f32d38974dd715693a5fa54abaaf9429a7276350
 * Entry: 0x519e00; label: FUN_00519e00
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00519e00(undefined4 param_1,int param_2,int param_3,int *param_4,float param_5)

{
  uint *puVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  float10 fVar11;
  int local_30;
  int local_24;
  int local_20;
  int local_18;
  float local_c [3];
  
  iVar10 = 0;
  if (3 < param_2) {
    piVar5 = (int *)(param_3 + 8);
    iVar9 = (param_2 - 4U >> 2) + 1;
    iVar10 = iVar9 * 4;
    do {
      iVar6 = piVar5[-2];
      iVar8 = *(int *)(iVar6 + 4);
      *(float *)(iVar8 + 0x18c) = *(float *)(iVar8 + 0x18c) - param_5;
      iVar6 = *(int *)(iVar6 + 4);
      if (*(float *)(iVar6 + 0x18c) < 0.0) {
        *(undefined4 *)(iVar6 + 0x18c) = 0;
      }
      iVar6 = piVar5[-1];
      iVar8 = *(int *)(iVar6 + 4);
      *(float *)(iVar8 + 0x18c) = *(float *)(iVar8 + 0x18c) - param_5;
      iVar6 = *(int *)(iVar6 + 4);
      if (*(float *)(iVar6 + 0x18c) < 0.0) {
        *(undefined4 *)(iVar6 + 0x18c) = 0;
      }
      iVar6 = *piVar5;
      iVar8 = *(int *)(iVar6 + 4);
      *(float *)(iVar8 + 0x18c) = *(float *)(iVar8 + 0x18c) - param_5;
      iVar6 = *(int *)(iVar6 + 4);
      if (*(float *)(iVar6 + 0x18c) < 0.0) {
        *(undefined4 *)(iVar6 + 0x18c) = 0;
      }
      iVar6 = piVar5[1];
      iVar8 = *(int *)(iVar6 + 4);
      *(float *)(iVar8 + 0x18c) = *(float *)(iVar8 + 0x18c) - param_5;
      iVar6 = *(int *)(iVar6 + 4);
      if (*(float *)(iVar6 + 0x18c) < 0.0) {
        *(undefined4 *)(iVar6 + 0x18c) = 0;
      }
      piVar5 = piVar5 + 4;
      iVar9 = iVar9 + -1;
    } while (iVar9 != 0);
  }
  for (; iVar10 < param_2; iVar10 = iVar10 + 1) {
    iVar9 = *(int *)(param_3 + iVar10 * 4);
    *(float *)(*(int *)(iVar9 + 4) + 0x18c) = *(float *)(*(int *)(iVar9 + 4) + 0x18c) - param_5;
    if (*(float *)(*(int *)(iVar9 + 4) + 0x18c) < 0.0) {
      *(undefined4 *)(*(int *)(iVar9 + 4) + 0x18c) = 0;
    }
  }
  local_18 = param_2 + -1;
  if (0 < local_18) {
    local_30 = 0;
    local_20 = 1;
    piVar5 = param_4;
    do {
      piVar5 = piVar5 + 1;
      iVar10 = *(int *)(local_30 + param_3);
      if (local_20 < param_2) {
        local_24 = param_2 - local_20;
        piVar7 = piVar5;
        do {
          iVar9 = *(int *)((param_3 - (int)param_4) + (int)piVar7);
          fVar3 = *(float *)(*(int *)(iVar10 + 4) + 0x120) + *(float *)(*(int *)(iVar9 + 4) + 0x120)
          ;
          local_c[0] = *(float *)(*(int *)(iVar10 + 4) + 0x114) -
                       *(float *)(*(int *)(iVar9 + 4) + 0x114);
          if (((((local_c[0] <= fVar3) && (-fVar3 <= local_c[0])) &&
               (local_c[2] = *(float *)(*(int *)(iVar10 + 4) + 0x11c) -
                             *(float *)(*(int *)(iVar9 + 4) + 0x11c), local_c[2] <= fVar3)) &&
              ((-fVar3 <= local_c[2] && (*(float *)(iVar10 + 0x17c) <= *(float *)(iVar9 + 0x188)))))
             && ((*(float *)(iVar9 + 0x17c) <= *(float *)(iVar10 + 0x188) &&
                 ((*(int *)(iVar10 + 0x298) != iVar9 && (*(int *)(iVar9 + 0x298) != iVar10)))))) {
            if (param_4 == (int *)0x0) {
              iVar6 = 0;
              iVar8 = 0;
            }
            else {
              iVar6 = *(int *)(local_30 + (int)param_4);
              iVar8 = *piVar7;
            }
            if (*(int *)(*(int *)(iVar10 + 4) + 0xf4) == iVar9) {
              iVar6 = 1;
            }
            if (*(int *)(*(int *)(iVar9 + 4) + 0xf4) == iVar10) {
              iVar8 = 1;
            }
            if ((*(byte *)(iVar10 + 0x1fc) & 0x80) != 0) {
              iVar6 = 1;
            }
            if ((*(byte *)(iVar9 + 0x1fc) & 0x80) != 0) {
              iVar8 = 1;
            }
            if (*(ushort *)(iVar9 + 0x292) < *(ushort *)(iVar10 + 0x292)) {
              iVar6 = 1;
              iVar4 = iVar8;
            }
            else {
              if (*(ushort *)(iVar9 + 0x292) <= *(ushort *)(iVar10 + 0x292)) goto LAB_0051a193;
              iVar8 = 1;
              iVar4 = iVar6;
            }
            if (iVar4 == 0) {
              fVar11 = (float10)FUN_005c0240(local_c[2] * local_c[2] + local_c[0] * local_c[0]);
              fVar2 = (float)fVar11;
              if (fVar2 < fVar3) {
                local_c[1] = 0.0;
                fVar3 = fVar3 - fVar2;
                if (iVar6 == 0) {
                  if (iVar8 == 0) {
                    fVar11 = (float10)FUN_00512850();
                    fVar11 = (float10)FUN_005128a0(fVar3,(float)fVar11);
                    FUN_005b3830(local_c,local_c,(float)fVar11);
                    iVar6 = *(int *)(iVar9 + 4) + 0x114;
                    FUN_005b3800(iVar6,iVar6,local_c);
                  }
                  else if (*(ushort *)(iVar10 + 0x294) < *(ushort *)(iVar9 + 0x292)) {
                    fVar11 = (float10)FUN_005128a0(fVar3,fVar2);
                    FUN_005b3830(local_c,local_c,(float)fVar11);
                    iVar6 = *(int *)(iVar10 + 4) + 0x114;
                    FUN_005b37d0(iVar6,iVar6,local_c);
                    *(undefined2 *)(iVar10 + 0x294) = *(undefined2 *)(iVar9 + 0x292);
                  }
                }
                else if (*(ushort *)(iVar9 + 0x294) < *(ushort *)(iVar10 + 0x292)) {
                  fVar11 = (float10)FUN_005128a0(fVar3,fVar2);
                  FUN_005b3830(local_c,local_c,(float)fVar11);
                  iVar6 = *(int *)(iVar9 + 4) + 0x114;
                  FUN_005b3800(iVar6,iVar6,local_c);
                  *(undefined2 *)(iVar9 + 0x294) = *(undefined2 *)(iVar10 + 0x292);
                }
                iVar6 = *(int *)(iVar10 + 4);
                if ((*(float *)(iVar6 + 0x18c) <= _DAT_00801c74) ||
                   (iVar8 = *(int *)(iVar9 + 4), *(float *)(iVar8 + 0x18c) <= _DAT_00801c74)) {
                  iVar8 = *(int *)(iVar9 + 4);
                  if (_DAT_00801c74 < *(float *)(iVar8 + 0x18c)) goto LAB_0051a2e1;
                  if (0.0 < *(float *)(iVar6 + 0x18c)) goto LAB_0051a316;
                }
                else {
                  if (*(float *)(iVar8 + 0x18c) < *(float *)(iVar6 + 0x18c)) {
LAB_0051a316:
                    *(undefined4 *)(iVar8 + 0x18c) = *(undefined4 *)(iVar6 + 0x18c);
                    iVar8 = *(int *)(iVar10 + 4);
                    iVar6 = *(int *)(iVar9 + 4);
                  }
                  else {
LAB_0051a2e1:
                    *(undefined4 *)(iVar6 + 0x18c) = *(undefined4 *)(iVar8 + 0x18c);
                    iVar6 = *(int *)(iVar10 + 4);
                    iVar8 = *(int *)(iVar9 + 4);
                  }
                  *(uint *)(iVar6 + 0x1e8) =
                       *(uint *)(iVar6 + 0x1e8) ^
                       (*(uint *)(iVar8 + 0x1e8) ^ *(uint *)(iVar6 + 0x1e8)) & 0x8000;
                }
                if (((*(uint *)(iVar9 + 0x1f8) ^ *(uint *)(iVar10 + 0x1f8)) & 1) != 0) {
                  puVar1 = (uint *)(*(int *)(iVar10 + 4) + 0x1e8);
                  *puVar1 = *puVar1 | 0x4000;
                  puVar1 = (uint *)(*(int *)(iVar9 + 4) + 0x1e8);
                  *puVar1 = *puVar1 | 0x4000;
                }
              }
            }
          }
LAB_0051a193:
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


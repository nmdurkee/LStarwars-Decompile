/* Ghidra pseudocode, not original source.
 * ev_565248e81838fc57af25e3b2c05c11c2e8daf24aacbb3d036db872a2a4b2fd33
 * Entry: 0x571330; label: FUN_00571330
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00571330(undefined4 param_1,int param_2)

{
  byte bVar1;
  int *piVar2;
  bool bVar3;
  float fVar4;
  byte bVar5;
  undefined *puVar6;
  int in_EAX;
  int iVar7;
  int iVar8;
  int iVar9;
  int in_ECX;
  uint uVar10;
  bool bVar11;
  float10 fVar12;
  float local_20;
  int local_1c;
  int local_18;
  undefined2 local_14;
  int local_10;
  undefined4 local_c;
  float local_8;
  undefined4 local_4;
  
  if ((in_ECX != 0) && (iVar7 = FUN_0058aab0(DAT_009553d4), iVar7 == 0)) {
    local_20 = 100000.0;
    local_18 = 0;
    bVar5 = 0;
    bVar11 = false;
    if ((param_2 != 0) &&
       ((_DAT_00950780 == 0.0 &&
        (fVar12 = (float10)FUN_005b7d30(_DAT_00925064,0x3e4ccccd),
        fVar12 < (float10)0.10000000149011612)))) {
      iVar7 = FUN_0056e0f0(0x200);
      bVar11 = iVar7 != 0;
      iVar7 = FUN_0056e0f0(0x40000);
      bVar5 = bVar11;
      if (iVar7 != 0) {
        bVar5 = 2;
      }
    }
    FUN_00573b80(param_1);
    local_1c = in_EAX;
    if (0 < in_EAX) {
      do {
        puVar6 = PTR_PTR_008033b0;
        bVar1 = *(byte *)(in_ECX + 0x17);
        if ((bVar1 & 1) != 0) {
          local_14 = (undefined2)
                     (int)ROUND((float)*(ushort *)(in_ECX + 0x26) + _DAT_00925018 * 16384.0);
          *(undefined2 *)(in_ECX + 0x26) = local_14;
          *(byte *)(in_ECX + 0x17) = bVar1 | 0x20;
          if (((bVar1 & 0x40) == 0) || (puVar6[0xc] == -1)) {
            iVar7 = *(int *)puVar6 + (uint)*(byte *)(in_ECX + 0x25) * 0x38;
          }
          else {
            iVar7 = *(int *)puVar6 + (char)puVar6[0xc] * 0x38;
          }
          if ((((bVar1 & 8) == 0) && (*(char *)(iVar7 + 0xf) == '\0')) &&
             (bVar1 = *(byte *)(iVar7 + 0xe), (bVar1 & 0x2c) != 0)) {
            bVar3 = true;
            iVar8 = FUN_005739f0(in_ECX,param_1,&local_10);
            if (iVar8 != 0) {
              if ((((*(byte *)(in_ECX + 0x17) & 2) == 0) || ((*(byte *)(in_ECX + 0x17) & 4) == 0))
                 && (((*(byte *)(iVar8 + 0x1e7) & 1) == 0 && (*(int *)(local_10 + 4) != 0)))) {
                piVar2 = *(int **)(local_10 + 4);
                uVar10 = (uint)*(byte *)((int)piVar2 + 6);
                if (uVar10 == DAT_00805e24) {
                  if ((*(byte *)(*piVar2 + 0x13a) & 0x20) != 0) goto LAB_00571555;
                  goto LAB_00571535;
                }
                if (uVar10 == DAT_00802f54) {
                  if ((*(byte *)(*piVar2 + 0x94) & 1) == 0) goto LAB_00571535;
                }
                else if ((uVar10 != DAT_00804e44) || (*(char *)(*piVar2 + 0x6d) != '\x02'))
                goto LAB_00571535;
LAB_00571555:
                bVar3 = false;
              }
              else {
LAB_00571535:
                iVar9 = FUN_00573aa0(iVar8,param_1);
                if ((iVar9 != 0) ||
                   (((*(byte *)(iVar8 + 0x1e7) & 1) != 0 && ((*(byte *)(iVar8 + 0x1e7) & 2) != 0))))
                goto LAB_00571555;
              }
              *(byte *)(iVar8 + 0x1e7) = *(byte *)(iVar8 + 0x1e7) | 2;
              if (!bVar3) goto LAB_005715e9;
            }
            if (((bVar11) && ((bVar1 & 4) != 0)) || (((bVar5 & 2) != 0 && ((bVar1 & 8) != 0)))) {
              local_c = *(undefined4 *)(in_ECX + 8);
              local_8 = *(float *)(in_ECX + 0xc) + 0.2;
              local_4 = *(undefined4 *)(in_ECX + 0x10);
              FUN_00570a00(&local_c);
            }
            if (param_2 != 0) {
              fVar12 = (float10)FUN_005b3c50(in_ECX + 8,PTR_DAT_008021b4 + 0x11c,0);
              if ((float)fVar12 < local_20) {
                local_20 = (float)fVar12;
                local_18 = in_ECX + 8;
              }
            }
          }
LAB_005715e9:
          if (0.0 < *(float *)(in_ECX + 0x28)) {
            if (*(float *)(in_ECX + 0x28) <= 2.0) {
              if (0.0 < *(float *)(in_ECX + 0x28)) {
                if (2 < DAT_00925068 % 6) {
                  *(byte *)(in_ECX + 0x17) = *(byte *)(in_ECX + 0x17) & 0xdf;
                }
              }
              else {
                *(byte *)(in_ECX + 0x17) = *(byte *)(in_ECX + 0x17) & 0xfd;
              }
            }
            if ((DAT_00855de0 != 2) &&
               (fVar4 = *(float *)(in_ECX + 0x28) - _DAT_00925018, *(float *)(in_ECX + 0x28) = fVar4
               , fVar4 < 0.0)) {
              *(byte *)(in_ECX + 0x17) = *(byte *)(in_ECX + 0x17) & 0xfe;
            }
          }
          if ((((*(char *)(iVar7 + 0xf) == '\0') &&
               (bVar1 = *(byte *)(in_ECX + 0x17), (bVar1 & 8) == 0)) && ((bVar1 & 2) != 0)) &&
             (((bVar1 & 4) != 0 && (*(code **)(iVar7 + 0x24) != (code *)0x0)))) {
            (**(code **)(iVar7 + 0x24))(param_1,in_ECX);
          }
        }
        in_ECX = in_ECX + 0x2c;
        local_1c = local_1c + -1;
      } while (local_1c != 0);
      if (local_18 != 0) {
        FUN_00547930(0x25,local_18,0,0);
      }
    }
  }
  return;
}


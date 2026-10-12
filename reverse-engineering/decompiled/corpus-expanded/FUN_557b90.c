/* Ghidra pseudocode, not original source.
 * ev_f8ed381e2b466dd5bc773ab3f84ab60966b69e10a49b3e28fcf3f54e00ea1563
 * Entry: 0x557b90; label: FUN_00557b90
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00557b90(int param_1)

{
  undefined *puVar1;
  float fVar2;
  char cVar3;
  byte bVar4;
  uint uVar5;
  uint uVar6;
  undefined4 *puVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  float10 fVar11;
  uint local_10;
  float local_c;
  undefined *local_8;
  int local_4;
  
  local_10 = 0;
  *(undefined4 *)(param_1 + 0x98) = 0;
  if ((*(byte *)(param_1 + 0x9c) & 8) == 0) {
    cVar3 = *(char *)(param_1 + 0x91);
    local_c = *(float *)(param_1 + 0x44) * *(float *)(param_1 + 0x44);
    local_8 = (undefined *)0x0;
    local_4 = 0;
    if (cVar3 == '\x01') {
LAB_00557be9:
      if ((PTR_DAT_008021b4[0x22c] != -1) &&
         ((*(char *)(param_1 + 0x92) == -1 && ((*(uint *)(param_1 + 0x68) & 0x4435) == 0)))) {
        fVar11 = (float10)FUN_005b3c50(PTR_DAT_008021b4 + 0x11c,param_1 + 0x1c,0);
        if (((float)fVar11 < local_c) && (iVar8 = FUN_00557a50(), iVar8 != 0)) {
          local_8 = PTR_DAT_008021b4 + 0x11c;
          local_c = (float)fVar11;
        }
      }
LAB_00557c5e:
      if (((*(byte *)(param_1 + 0x68) & 1) == 0) && (iVar8 = 0, 0 < DAT_0093b1e0)) {
        do {
          fVar11 = (float10)FUN_005b3c50(param_1 + 0x1c,(&DAT_0093b1a0)[iVar8],0);
          if (((float)fVar11 < local_c) && (iVar9 = FUN_00557a50(), iVar9 != 0)) {
            local_8 = (undefined *)(&DAT_0093b1a0)[iVar8];
            local_c = (float)fVar11;
          }
          iVar8 = iVar8 + 1;
        } while (iVar8 < DAT_0093b1e0);
      }
    }
    else if (((cVar3 == '\x02') || (cVar3 == '\x05')) || (cVar3 == '\x06')) {
      if ((cVar3 == '\x01') || (cVar3 == '\x05')) goto LAB_00557be9;
      goto LAB_00557c5e;
    }
    if (0 < DAT_0093d500) {
      iVar9 = 0;
      iVar8 = DAT_0093d504;
      do {
        uVar5 = *(uint *)(iVar8 + 0x1fc);
        if (((((((uVar5 & 1) != 0) && ((uVar5 & 0x1000) != 0)) && (*(char *)(iVar8 + 0x28b) == '\0')
              ) && ((DAT_00802828 == -1 || (*(char *)(iVar8 + 0x7b5) != DAT_00802828)))) &&
            ((*(byte *)(iVar8 + 0x1044) & 1) != 0)) && ((*(byte *)(iVar8 + 0xe20) & 0x20) == 0)) {
          bVar4 = *(byte *)(iVar8 + 0x280);
          if (bVar4 != 0xff) {
            local_10 = local_10 | 1 << (bVar4 & 0x1f);
          }
          uVar6 = *(uint *)(param_1 + 0x68);
          if (((((((uVar6 & 4) == 0) || (bVar4 != 0xff)) &&
                (((uVar6 & 0x20) == 0 || ((char)uVar5 < '\0')))) &&
               (((*(uint *)(PTR_PTR_007fb0e4 + *(char *)(iVar8 + 0x7b5) * 0x10 + 8) & 0x8000) == 0
                && (((uVar6 & 0x400) == 0 || (*(int *)(iVar8 + 0xcd0) != 0)))))) &&
              ((((uVar6 & 0x4000) == 0 || ((*(byte *)(*(int *)(iVar8 + 0x54) + 4) & 4) != 0)) &&
               (((uVar6 & 8) == 0 || ((*(uint *)(*(int *)(iVar8 + 0x54) + 4) & 0x2000) != 0)))))) &&
             ((DAT_0093b1e4 == (code *)0x0 || (iVar10 = (*DAT_0093b1e4)(param_1,iVar8), iVar10 == 0)
              ))) {
            if ((((*(char *)(param_1 + 0x91) == '\x02') || (*(char *)(param_1 + 0x91) == '\x06')) &&
                (*(char *)(iVar8 + 0x281) == '\0')) &&
               (((*(uint *)(iVar8 + 0xef4) & 0x20000000) == 0 &&
                (*(char *)(iVar8 + 0xe32) != '\x01')))) {
              if (*(int *)(param_1 + 0x34) != 0) {
                for (puVar7 = *(undefined4 **)(*(int *)(param_1 + 0x34) + 0x18);
                    puVar7 != (undefined4 *)0x0; puVar7 = (undefined4 *)*puVar7) {
                  if ((*(short *)(puVar7[9] + 2) != -1) &&
                     (*(short *)(iVar8 + 0x27e) == *(short *)(puVar7[9] + 2))) goto LAB_00557e51;
                }
              }
            }
            else {
LAB_00557e51:
              puVar1 = (undefined *)(iVar8 + 0x19c);
              fVar11 = (float10)FUN_005b3c50(param_1 + 0x1c,puVar1,0);
              fVar2 = (float)fVar11;
              if (local_c <= fVar2) {
                if (((((*(uint *)(param_1 + 0x68) & 0x2000) != 0) &&
                     (*(char *)(iVar8 + 0x280) != -1)) &&
                    (fVar2 < *(float *)(param_1 + 0x44) * *(float *)(param_1 + 0x44))) &&
                   ((iVar10 = FUN_00557a50(), iVar10 != 0 && (iVar10 = FUN_00557b00(), iVar10 != 0))
                   )) {
                  local_10 = local_10 & ~(1 << (*(byte *)(iVar8 + 0x280) & 0x1f));
                }
              }
              else {
                iVar10 = FUN_00557a50();
                if (((iVar10 != 0) && (iVar10 = FUN_00557b00(), iVar10 != 0)) &&
                   (local_c = fVar2, local_8 = puVar1, local_4 = iVar8,
                   *(byte *)(iVar8 + 0x280) != 0xff)) {
                  local_10 = local_10 & ~(1 << (*(byte *)(iVar8 + 0x280) & 0x1f));
                }
              }
            }
          }
        }
        iVar9 = iVar9 + 1;
        iVar8 = iVar8 + 0x10d8;
      } while (iVar9 < DAT_0093d500);
    }
    if ((*(uint *)(param_1 + 0x68) & 1) == 0) {
      if ((local_8 != (undefined *)0x0) &&
         (((*(uint *)(param_1 + 0x68) & 0x2000) == 0 || (local_10 == 0)))) {
        *(int *)(param_1 + 0x38) = local_4;
        goto LAB_00557f65;
      }
    }
    else if (local_8 == (undefined *)0x0) {
      *(int *)(param_1 + 0x38) = local_4;
LAB_00557f65:
      *(undefined4 *)(param_1 + 0x98) = 1;
    }
  }
  iVar8 = *(int *)(*(int *)(param_1 + 0x34) + 0xc);
  if (iVar8 == 0) {
LAB_00557fa3:
    if (iVar8 != 2) goto LAB_00557fb1;
  }
  else if (iVar8 != 2) {
    if (*(int *)(PTR_DAT_00802c54 + 0x128) != DAT_0087b178) {
      return;
    }
    if (param_1 != DAT_0087a908) {
      return;
    }
    if (iVar8 != 4) {
      return;
    }
    goto LAB_00557fa3;
  }
  if (*(char *)(param_1 + 0x90) == '\0') {
    return;
  }
LAB_00557fb1:
  if (iVar8 == 0) {
    if ((*(int *)(param_1 + 0x98) != 0) || ((*(byte *)(param_1 + 0x9c) & 0x44) != 0)) {
      FUN_00557960(param_1);
      *(undefined4 *)(param_1 + 0x40) = *(undefined4 *)(param_1 + 0x3c);
      return;
    }
  }
  else if ((*(int *)(param_1 + 0x98) == 0) && ((*(byte *)(param_1 + 0x9c) & 0x44) == 0)) {
    if (*(float *)(param_1 + 0x40) <= 0.0) {
      FUN_005579d0(param_1);
    }
    else if (iVar8 == 2) {
      *(float *)(param_1 + 0x40) = *(float *)(param_1 + 0x40) - _DAT_00925018;
      return;
    }
  }
  return;
}


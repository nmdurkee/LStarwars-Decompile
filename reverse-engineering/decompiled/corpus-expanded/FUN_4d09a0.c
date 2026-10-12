/* Ghidra pseudocode, not original source.
 * ev_1794ca22652287671530b7d2e638694f2898180de05a8f26cc5ace6b6aa326ae
 * Entry: 0x4d09a0; label: FUN_004d09a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_004d09a0(int param_1,int param_2,float *param_3)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  iVar4 = *(int *)(param_2 + 0x5058);
  local_c = *(float *)(param_1 + 0x80);
  fVar1 = *(float *)(param_1 + 0x1dc) * 3.0;
  local_8 = *(float *)(param_1 + 0x84);
  local_4 = *(float *)(param_1 + 0x88);
  iVar3 = 0;
  if (0 < *(int *)(param_2 + 0x505c)) {
    do {
      if ((*(char *)(iVar4 + 0x46) != '\0') && (*(char *)(iVar4 + 0x47) != '\0')) {
        local_18 = local_c - *(float *)(iVar4 + 0x10);
        local_10 = local_4 - *(float *)(iVar4 + 0x18);
        FUN_005b3620(&local_18,&local_18,-(uint)*(ushort *)(iVar4 + 0x44));
        if ((0.0 <= local_10) &&
           (((local_10 <= *(float *)(iVar4 + 0x40) &&
             (fVar2 = -fVar1, fVar2 < local_18 != (fVar2 == local_18))) && (local_18 <= fVar1)))) {
          local_18 = 0.0;
          local_14 = (local_10 / *(float *)(iVar4 + 0x40)) *
                     (*(float *)(iVar4 + 0x20) - *(float *)(iVar4 + 0x14)) +
                     *(float *)(iVar4 + 0x14);
          if (ABS(local_14 - local_8) < *(float *)(param_1 + 0x1e0)) {
            if (param_3 == (float *)0x0) {
              return iVar4;
            }
            if ((*(uint *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x90) & 0x10000000) == 0) {
              fVar1 = *(float *)(param_1 + 0x1dc);
            }
            else {
              fVar1 = *(float *)(param_1 + 0x1e0);
            }
            fVar2 = *(float *)(iVar4 + 0x40) - fVar1;
            if ((local_10 <= fVar2) && (fVar2 = local_10, local_10 < fVar1)) {
              fVar2 = fVar1;
            }
            local_10 = fVar2;
            FUN_005b3620(param_3,&local_18,*(undefined2 *)(iVar4 + 0x44));
            *param_3 = *(float *)(iVar4 + 0x10) + *param_3;
            param_3[2] = *(float *)(iVar4 + 0x18) + param_3[2];
            return iVar4;
          }
        }
      }
      iVar3 = iVar3 + 1;
      iVar4 = iVar4 + 0x48;
    } while (iVar3 < *(int *)(param_2 + 0x505c));
  }
  return 0;
}


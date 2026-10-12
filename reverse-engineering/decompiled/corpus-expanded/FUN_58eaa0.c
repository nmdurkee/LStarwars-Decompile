/* Ghidra pseudocode, not original source.
 * ev_d7fef5854a4ea50d405948ed3aa82c9004ffbc8626dda7a7f3cbba7e59036064
 * Entry: 0x58eaa0; label: FUN_0058eaa0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_0058eaa0(int param_1,int param_2,int param_3,int param_4)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int *piVar4;
  int iVar5;
  float fVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  float10 fVar11;
  float local_24;
  int local_20;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  piVar4 = *(int **)(param_1 + 0x46a8);
  iVar10 = 0;
  if ((piVar4 == (int *)0x0) || (param_2 == 0)) {
    return 0;
  }
  local_c = *(undefined4 *)(param_2 + 0x80);
  fVar1 = *(float *)(param_2 + 0x1a0);
  local_8 = *(undefined4 *)(param_2 + 0x84);
  fVar2 = *(float *)(param_2 + 0x194);
  local_4 = *(undefined4 *)(param_2 + 0x88);
  local_24 = 1e+06;
  iVar9 = *piVar4;
  local_20 = 0;
  iVar8 = _DAT_00802860;
  if ((short)piVar4[1] != 0) {
    do {
      if (param_3 == 2) {
LAB_0058eb95:
        fVar3 = ((float)*(byte *)(iVar9 + 0x71) / 100.0) * *(float *)(iVar9 + 0x40);
        if ((*(float *)(iVar9 + 0x2c) - fVar3 <= fVar2) &&
           (fVar1 <= *(float *)(iVar9 + 0x2c) + fVar3)) {
          fVar6 = *(float *)(iVar9 + 0x40) + 0.3;
          fVar11 = (float10)FUN_005b3cf0(iVar9 + 0x28,&local_c,0);
          fVar3 = (float)fVar11;
          iVar8 = _DAT_00802860;
          if ((fVar3 < fVar6 * fVar6) && (fVar3 < local_24)) {
            local_24 = fVar3;
            local_20 = iVar9;
          }
        }
      }
      else if ((((*(ushort *)(iVar9 + 0x7a) & 2) != 0) && ((*(ushort *)(iVar9 + 0x7a) & 1) != 0)) &&
              (((*(byte *)(iVar9 + 0x72) & 0x80) == 0 || (param_4 != 0)))) {
        if (param_3 == 1) {
          if ((*(char *)(iVar9 + 0x6d) != '\0') || (iVar8 == -1)) goto LAB_0058ec42;
          iVar7 = 0;
          do {
            iVar5 = (&DAT_0093d7f0)[iVar7];
            if (((iVar5 != 0) && (*(char *)(iVar5 + 0x7b5) == iVar8)) &&
               (*(int *)(iVar5 + 0x798) == iVar9)) {
              if (iVar7 < 8) goto LAB_0058ec42;
              break;
            }
            iVar7 = iVar7 + 1;
          } while (iVar7 < 8);
        }
        goto LAB_0058eb95;
      }
LAB_0058ec42:
      iVar10 = iVar10 + 1;
      iVar9 = iVar9 + 0x7c;
    } while (iVar10 < (int)(uint)*(ushort *)(*(int *)(param_1 + 0x46a8) + 4));
  }
  return local_20;
}


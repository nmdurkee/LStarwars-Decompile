/* Ghidra pseudocode, not original source.
 * ev_d287e844ea66f87c3c60c812c2454ec5cd238ea97f1ed9ffb4b19045dfabbd11
 * Entry: 0x47fc30; label: FUN_0047fc30
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0047fc30(undefined4 param_1,int param_2,int *param_3)

{
  int iVar1;
  float fVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  float local_8;
  int local_4;
  
  iVar3 = *param_3;
  iVar5 = *(int *)(iVar3 + 0x10b4);
  if ((iVar5 != 0) && (*(int *)(iVar5 + 0x14) == *(int *)(param_2 + 0x15c))) {
    if (*(char *)(iVar3 + 0x7b5) == 'C') {
      iVar5 = FUN_0056cf30(iVar3 + 400,PTR_DAT_00802c54,&local_4,&local_8);
      if (((iVar5 == 0) || (0.2 <= local_8)) ||
         ((*(char *)(iVar3 + 0x1073) == -1 && (*(int *)(iVar3 + 0x1074) == iVar5)))) {
        *(float *)(param_2 + 0x104) =
             (*(float **)(iVar3 + 0x10b4))[3] + **(float **)(iVar3 + 0x10b4);
        *(undefined4 *)(param_2 + 0x108) = *(undefined4 *)(iVar3 + 0x60);
        *(float *)(param_2 + 0x10c) =
             *(float *)(*(int *)(iVar3 + 0x10b4) + 0x10) + *(float *)(*(int *)(iVar3 + 0x10b4) + 8);
        *(undefined4 *)(param_2 + 0x110) = 0;
      }
      else {
        if (iVar5 != *(int *)(iVar3 + 0x1074)) {
          *(undefined1 *)(iVar3 + 0x1073) = 1;
          *(int *)(iVar3 + 0x1074) = iVar5;
        }
        iVar1 = iVar5 + *(char *)(iVar3 + 0x1073) * 0xc;
        fVar2 = *(float *)(iVar3 + 0x60) - *(float *)(iVar1 + 0xc);
        if (1.0 < fVar2) {
          fVar2 = 1.0;
        }
        if (fVar2 < 0.0) {
          fVar2 = 0.0;
        }
        *(float *)(param_2 + 0x104) = **(float **)(iVar3 + 0x10b4) * fVar2 + *(float *)(iVar1 + 8);
        *(undefined4 *)(param_2 + 0x108) =
             *(undefined4 *)(iVar5 + (*(char *)(iVar3 + 0x1073) + 1) * 0xc);
        *(float *)(param_2 + 0x10c) =
             *(float *)(iVar5 + 0x10 + *(char *)(iVar3 + 0x1073) * 0xc) +
             *(float *)(*(int *)(iVar3 + 0x10b4) + 8) * fVar2;
        *(undefined4 *)(iVar3 + 0x3d8) = 0;
        if (local_8 < 0.05) {
          if (*(char *)(iVar3 + 0x1073) == '\x01') {
            *(undefined1 *)(iVar3 + 0x1073) = 0;
            return 1;
          }
          if (*(char *)(iVar3 + 0x1073) == local_4) {
            *(undefined1 *)(iVar3 + 0x1073) = 0xff;
            return 1;
          }
        }
      }
      return 1;
    }
    if (*(char *)(iVar3 + 0x281) != '\0') {
      if (*(float *)(iVar3 + 0x60) < *(float *)(*(int *)(iVar3 + 0x1094) + 0x18)) goto LAB_0047fe80;
      if (*(char *)(iVar3 + 0x281) != '\0') {
        iVar5 = *(int *)(iVar3 + 0x44c);
        *(undefined4 *)(iVar3 + 0x3cc) = *(undefined4 *)(iVar5 + 4);
        *(undefined4 *)(iVar3 + 0x3d0) = *(undefined4 *)(iVar5 + 8);
        uVar4 = *(undefined4 *)(iVar5 + 0xc);
        *(undefined4 *)(iVar3 + 0x3d8) = 0;
        *(undefined4 *)(iVar3 + 0x3d4) = uVar4;
        return 1;
      }
    }
    *(undefined4 *)(iVar3 + 0x3cc) = *(undefined4 *)(iVar5 + 0xc);
    *(undefined4 *)(iVar3 + 0x3d0) = *(undefined4 *)(*(int *)(iVar3 + 0x44c) + 8);
    *(undefined4 *)(iVar3 + 0x3d4) = *(undefined4 *)(iVar5 + 0x10);
    *(undefined4 *)(iVar3 + 0x3d8) = 0;
    return 1;
  }
LAB_0047fe80:
  FUN_0043cbf0(iVar3);
  return 0;
}


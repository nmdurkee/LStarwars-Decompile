/* Ghidra pseudocode, not original source.
 * ev_d287e844ea66f87c3c60c812c2454ec5cd238ea97f1ed9ffb4b19045dfabbd11
 * Entry: 0x47f9e0; label: FUN_0047f9e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0047f9e0(undefined4 param_1,int param_2,int *param_3)

{
  uint *puVar1;
  int iVar2;
  float fVar3;
  int iVar4;
  int iVar5;
  float local_8;
  int local_4;
  
  iVar4 = *param_3;
  iVar5 = *(int *)(iVar4 + 0x10b4);
  if ((iVar5 == 0) || (*(int *)(iVar5 + 0x14) != *(int *)(param_2 + 0x15c))) {
    FUN_0043cbf0(iVar4);
    return 0;
  }
  if (*(float *)(*(int *)(iVar4 + 0x44c) + 0x20) < *(float *)(iVar4 + 0x194)) {
    puVar1 = (uint *)(*(int *)(iVar4 + 0xca4) + 8);
    *puVar1 = *puVar1 | DAT_00802278;
    FUN_0043cbb0(iVar4,*(undefined4 *)(iVar4 + 0x44c),0,0);
    return 1;
  }
  if (*(char *)(iVar4 + 0x7b5) == 'C') {
    iVar5 = FUN_0056cf30(iVar4 + 400,PTR_DAT_00802c54,&local_4,&local_8);
    if (((iVar5 == 0) || (0.2 <= local_8)) ||
       ((*(char *)(iVar4 + 0x1073) == -1 && (*(int *)(iVar4 + 0x1074) == iVar5)))) {
      *(float *)(param_2 + 0x104) = (*(float **)(iVar4 + 0x10b4))[3] - **(float **)(iVar4 + 0x10b4);
      *(undefined4 *)(param_2 + 0x108) = *(undefined4 *)(iVar4 + 0x60);
      *(float *)(param_2 + 0x10c) =
           *(float *)(*(int *)(iVar4 + 0x10b4) + 0x10) - *(float *)(*(int *)(iVar4 + 0x10b4) + 8);
      *(undefined4 *)(iVar4 + 0x3d8) = 0;
      return 1;
    }
    if (iVar5 != *(int *)(iVar4 + 0x1074)) {
      *(undefined1 *)(iVar4 + 0x1073) = 0;
      *(int *)(iVar4 + 0x1074) = iVar5;
    }
    iVar2 = iVar5 + *(char *)(iVar4 + 0x1073) * 0xc;
    fVar3 = *(float *)(iVar2 + 0xc) - *(float *)(iVar4 + 0x60);
    if (1.0 < fVar3) {
      fVar3 = 1.0;
    }
    if (fVar3 < 0.0) {
      fVar3 = 0.0;
    }
    *(float *)(param_2 + 0x104) = *(float *)(iVar2 + 8) - **(float **)(iVar4 + 0x10b4) * fVar3;
    *(undefined4 *)(param_2 + 0x108) =
         *(undefined4 *)(iVar5 + (*(char *)(iVar4 + 0x1073) + 1) * 0xc);
    *(float *)(param_2 + 0x10c) =
         *(float *)(iVar5 + 0x10 + *(char *)(iVar4 + 0x1073) * 0xc) -
         *(float *)(*(int *)(iVar4 + 0x10b4) + 8) * fVar3;
    *(undefined4 *)(iVar4 + 0x3d8) = 0;
    if (local_8 < 0.05) {
      if (*(char *)(iVar4 + 0x1073) == '\0') {
        *(undefined1 *)(iVar4 + 0x1073) = 1;
        return 1;
      }
      if (*(char *)(iVar4 + 0x1073) == local_4) {
        *(undefined1 *)(iVar4 + 0x1073) = 0xff;
        return 1;
      }
    }
  }
  else {
    *(undefined4 *)(iVar4 + 0x3cc) = *(undefined4 *)(iVar5 + 0xc);
    *(undefined4 *)(iVar4 + 0x3d0) = *(undefined4 *)(*(int *)(iVar4 + 0x44c) + 8);
    *(undefined4 *)(iVar4 + 0x3d4) = *(undefined4 *)(iVar5 + 0x10);
    *(undefined4 *)(iVar4 + 0x3d8) = 0;
  }
  return 1;
}


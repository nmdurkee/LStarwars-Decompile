/* Ghidra analysis pseudocode, not original source.
 * ev_280130a43e77cd6b8822caba528fd01ad8a7c5be61051c42bd6bb5c51ef00c77
 * Entry: 0x661f60; label: FUN_00661f60
 */

void FUN_00661f60(float param_1)

{
  float fVar1;
  int *piVar2;
  int iVar3;
  float local_c;
  float local_8;
  float local_4;
  
  if ((((DAT_029231a8 != -1) && ((&DAT_02924b60)[DAT_029231a8 * 0x16] != -1)) &&
      ((&DAT_02924b60)[DAT_029231a8 * 0x16] != 99999)) &&
     (FUN_005b3800(&local_c,&DAT_02920abc,&DAT_02924b50 + DAT_029231a8 * 0x16),
     local_4 * local_4 + local_c * local_c + local_8 * local_8 == 0.0)) {
    return;
  }
  DAT_029231a8 = -1;
  iVar3 = 0;
  piVar2 = &DAT_02924b60;
  do {
    if ((*piVar2 != -1) && (*piVar2 != 99999)) {
      FUN_005b3800(&local_c,&DAT_02920abc,piVar2 + -4);
      fVar1 = local_4 * local_4 + local_c * local_c + local_8 * local_8;
      if ((param_1 < 0.0) || (fVar1 < param_1)) {
        DAT_029231a8 = iVar3;
        param_1 = fVar1;
      }
    }
    piVar2 = piVar2 + 0x16;
    iVar3 = iVar3 + 1;
  } while ((int)piVar2 < 0x292fb60);
  return;
}


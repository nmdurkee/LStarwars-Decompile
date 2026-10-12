/* Ghidra analysis pseudocode, not original source.
 * ev_4ddc17d0b5ae2dc444590ce1384da883f11f3d0f2dd8037fed9dcc825d4bbeec
 * Entry: 0x636240; label: FUN_00636240
 */

float10 FUN_00636240(int param_1,float param_2,float param_3)

{
  int iVar1;
  int *piVar2;
  float *pfVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar1 = (int)param_2;
  param_2 = 0.0;
  iVar5 = *(int *)(iVar1 + 0x48);
  iVar6 = 0;
  if (3 < iVar5) {
    iVar4 = (iVar5 - 4U >> 2) + 1;
    piVar2 = (int *)(iVar1 + 0x34);
    iVar6 = iVar4 * 4;
    do {
      if (((*(ushort *)(piVar2[-1] + 0x5e) == 0) ||
          ((*(ushort *)(param_1 + 0x5e) & *(ushort *)(piVar2[-1] + 0x5e)) != 0)) &&
         (param_2 <= (float)piVar2[2])) {
        param_2 = (float)piVar2[2];
      }
      if (((*(ushort *)(*piVar2 + 0x5e) == 0) ||
          ((*(ushort *)(param_1 + 0x5e) & *(ushort *)(*piVar2 + 0x5e)) != 0)) &&
         (param_2 <= (float)piVar2[3])) {
        param_2 = (float)piVar2[3];
      }
      if (((*(ushort *)(piVar2[1] + 0x5e) == 0) ||
          ((*(ushort *)(param_1 + 0x5e) & *(ushort *)(piVar2[1] + 0x5e)) != 0)) &&
         (param_2 <= (float)piVar2[4])) {
        param_2 = (float)piVar2[4];
      }
      if (((*(ushort *)(piVar2[2] + 0x5e) == 0) ||
          ((*(ushort *)(param_1 + 0x5e) & *(ushort *)(piVar2[2] + 0x5e)) != 0)) &&
         (param_2 <= (float)piVar2[5])) {
        param_2 = (float)piVar2[5];
      }
      piVar2 = piVar2 + 4;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
  }
  if (iVar6 < iVar5) {
    iVar5 = iVar5 - iVar6;
    pfVar3 = (float *)(iVar1 + 0x3c + iVar6 * 4);
    do {
      if (((*(ushort *)((int)pfVar3[-3] + 0x5e) == 0) ||
          ((*(ushort *)(param_1 + 0x5e) & *(ushort *)((int)pfVar3[-3] + 0x5e)) != 0)) &&
         (param_2 <= *pfVar3)) {
        param_2 = *pfVar3;
      }
      pfVar3 = pfVar3 + 1;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
  }
  return (float10)((1.0 - param_2) * param_3);
}


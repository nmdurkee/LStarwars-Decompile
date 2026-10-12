/* Ghidra analysis pseudocode, not original source.
 * ev_d93daca17d105ef5f57eb8b76e4a8c3d960b6599f63d34fdaa382c813fb01a39
 * Entry: 0x578e10; label: FUN_00578e10
 */

void FUN_00578e10(int *param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  if (param_1 != (int *)0x0) {
    iVar5 = *param_1;
    while (iVar5 != 0) {
      if (param_1[1] != 0) {
        iVar4 = 0;
        if (0 < DAT_00951b84) {
          iVar3 = 0;
          do {
            iVar2 = FUN_004f8b10(iVar3 + 0x40 + DAT_00951b78,iVar5);
            if (iVar2 == 0) {
              iVar5 = iVar4 * 0x130 + DAT_00951b78;
              goto LAB_00578e70;
            }
            iVar4 = iVar4 + 1;
            iVar3 = iVar3 + 0x130;
          } while (iVar4 < DAT_00951b84);
        }
        iVar5 = 0;
LAB_00578e70:
        *(int *)param_1[1] = iVar5;
        if (iVar5 != 0) {
          if (param_1[2] != 0) {
            *(int *)(iVar5 + 0x68) = param_1[2];
          }
          if (param_1[3] != 0) {
            *(int *)(iVar5 + 0x6c) = param_1[3];
          }
          if (param_1[4] != 0) {
            *(int *)(iVar5 + 0x70) = param_1[4];
          }
          if (param_1[5] != 0) {
            *(int *)(iVar5 + 0x74) = param_1[5];
          }
          if (param_1[6] != 0) {
            *(int *)(iVar5 + 0x78) = param_1[6];
          }
          if (param_1[7] != 0) {
            *(int *)(iVar5 + 0x7c) = param_1[7];
          }
          if (param_1[8] != 0) {
            *(int *)(iVar5 + 0x80) = param_1[8];
          }
        }
      }
      piVar1 = param_1 + 9;
      param_1 = param_1 + 9;
      iVar5 = *piVar1;
    }
  }
  return;
}


/* Ghidra analysis pseudocode, not original source.
 * ev_101b67aa7badcd34fc3aca69d932f1af6fd7c0870f1a0aed34e591760076c155
 * Entry: 0x5036a0; label: FUN_005036a0
 */

void FUN_005036a0(int param_1)

{
  int *piVar1;
  int in_EAX;
  int iVar2;
  int *piVar3;
  int iVar4;
  short *psVar5;
  int iVar6;
  int local_c;
  int local_4;
  
  piVar1 = *(int **)(in_EAX + 0x24);
  local_4 = 0;
  if (0 < *piVar1) {
    local_c = 0;
    piVar3 = piVar1;
    do {
      psVar5 = (short *)(piVar3[1] + local_c);
      iVar6 = 0;
      if (0 < *(int *)(param_1 + 8)) {
        iVar4 = 0;
        do {
          *psVar5 = -1;
          iVar2 = FUN_004f8b10(*(undefined4 *)(psVar5 + 2),
                               *(undefined4 *)(*(int *)(param_1 + 0xc) + iVar4));
          if (iVar2 == 0) {
            *psVar5 = (short)iVar6;
            piVar3 = piVar1;
            break;
          }
          iVar6 = iVar6 + 1;
          iVar4 = iVar4 + 0x34;
          piVar3 = piVar1;
        } while (iVar6 < *(int *)(param_1 + 8));
      }
      if (*psVar5 == -1) {
        piVar3 = (int *)FUN_004fff00(*(undefined4 *)(psVar5 + 2));
      }
      local_c = local_c + 0xc;
      local_4 = local_4 + 1;
    } while (local_4 < *piVar3);
  }
  return;
}


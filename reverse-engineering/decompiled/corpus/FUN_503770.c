/* Ghidra analysis pseudocode, not original source.
 * ev_101b67aa7badcd34fc3aca69d932f1af6fd7c0870f1a0aed34e591760076c155
 * Entry: 0x503770; label: FUN_00503770
 */

void FUN_00503770(undefined4 param_1)

{
  byte *pbVar1;
  int *piVar2;
  int *piVar3;
  int in_EAX;
  int iVar4;
  short *psVar5;
  int iVar6;
  char local_5;
  int local_4;
  
  piVar2 = *(int **)(in_EAX + 0xac);
  piVar3 = *(int **)(*(int *)(in_EAX + 0x58) + 0x24);
  if (0 < *piVar3) {
    local_4 = 0;
    iVar6 = 0;
    do {
      psVar5 = (short *)(piVar3[1] + local_4);
      iVar4 = *(int *)(psVar5 + 4);
      if ((iVar4 != 0) &&
         (iVar4 = FUN_005da520(iVar4,piVar2[1] + iVar6 * 4,&local_5,param_1), iVar4 != 0)) {
        pbVar1 = (byte *)(*(int *)(*piVar2 + 0xc) + 2 + *psVar5 * 4);
        if (local_5 == '\0') {
          *pbVar1 = *pbVar1 & 0xfe;
        }
        else {
          *pbVar1 = *pbVar1 | 1;
        }
      }
      local_4 = local_4 + 0xc;
      iVar6 = iVar6 + 1;
    } while (iVar6 < *piVar3);
  }
  return;
}


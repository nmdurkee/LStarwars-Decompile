/* Ghidra analysis pseudocode, not original source.
 * ev_ca54e982c9f1bc50e375bb5e2806226defe8bc9769d9e20e94a8e2507c387560
 * Entry: 0x464760; label: FUN_00464760
 */

void FUN_00464760(int param_1,undefined4 param_2,int param_3,int param_4)

{
  ushort *puVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  byte bVar5;
  int iVar6;
  int local_4;
  
  iVar6 = 0;
  local_4 = 0;
  bVar5 = 1;
  bVar2 = 1;
  if (0 < param_4) {
    do {
      bVar5 = bVar2;
      iVar3 = FUN_004f8a70(*(undefined4 *)(param_3 + iVar6 * 4),"name=");
      if (iVar3 == 0) {
        iVar3 = FUN_004f8b10(*(undefined4 *)(param_3 + iVar6 * 4),"FALSE");
        if (iVar3 == 0) {
          bVar5 = 0;
        }
      }
      else {
        local_4 = iVar3 + 5;
      }
      iVar6 = iVar6 + 1;
      bVar2 = bVar5;
    } while (iVar6 < param_4);
  }
  if (((param_1 != 0) && (local_4 != 0)) && (iVar6 = 0, 0 < *(int *)(param_1 + 4))) {
    iVar3 = 0;
    do {
      iVar4 = *(int *)(iVar3 + 0x1c + *(int *)(param_1 + 8));
      if ((iVar4 != 0) && (iVar4 = FUN_004f8b10(iVar4,local_4), iVar4 == 0)) {
        puVar1 = (ushort *)(iVar3 + 10 + *(int *)(param_1 + 8));
        *puVar1 = *puVar1 ^ (*(byte *)(iVar3 + 10 + *(int *)(param_1 + 8)) ^ bVar5) & 1;
      }
      iVar6 = iVar6 + 1;
      iVar3 = iVar3 + 0x20;
    } while (iVar6 < *(int *)(param_1 + 4));
  }
  return;
}


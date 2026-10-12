/* Ghidra analysis pseudocode, not original source.
 * ev_ad9cc5423de1ab1dd38d346f275414df9adbe91527778a2cec40e67e5c2b6778
 * Entry: 0x473fc0; label: FUN_00473fc0
 */

void FUN_00473fc0(int param_1,undefined4 param_2,int param_3)

{
  uint *puVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  
  if (param_3 != 0) {
    *(undefined4 *)(param_3 + 4) = 0xffffffff;
    *(undefined4 *)(param_3 + 8) = 0xffffffff;
    if ((((param_1 != 0) && (piVar3 = *(int **)(param_1 + 0x5074), piVar3 != (int *)0x0)) &&
        (piVar3[3] != 0)) && (iVar7 = 0, 0 < *piVar3)) {
      iVar6 = 0;
      do {
        if (0x13ff < iVar6) {
          return;
        }
        iVar2 = piVar3[3];
        iVar4 = (int)(iVar7 + (iVar7 >> 0x1f & 0x1fU)) >> 5;
        uVar5 = 1 << ((byte)iVar7 & 0x1f);
        if ((*(byte *)(iVar2 + iVar6 + 99) & 4) == 0) {
          puVar1 = (uint *)(param_3 + 8 + iVar4 * 4);
          *puVar1 = *puVar1 & ~uVar5;
        }
        if ((*(byte *)(iVar2 + iVar6 + 99) & 8) == 0) {
          puVar1 = (uint *)(param_3 + 4 + iVar4 * 4);
          *puVar1 = *puVar1 & ~uVar5;
        }
        piVar3 = *(int **)(param_1 + 0x5074);
        iVar7 = iVar7 + 1;
        iVar6 = iVar6 + 0xa0;
      } while (iVar7 < *piVar3);
    }
  }
  return;
}


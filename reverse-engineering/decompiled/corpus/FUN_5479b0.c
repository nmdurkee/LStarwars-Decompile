/* Ghidra analysis pseudocode, not original source.
 * ev_c1ca6a36f678473ebb33648a43a5c1c2c83c1c89260a3af1d5a93a85b2681cef
 * Entry: 0x5479b0; label: FUN_005479b0
 */

void FUN_005479b0(uint param_1,int param_2,int *param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if ((((param_2 != 0) && (param_3 != (int *)0x0)) && (iVar1 = *param_3, iVar1 < param_4)) &&
     ((param_1 < 0x54 &&
      (iVar3 = (int)*(short *)(PTR_DAT_008020bc + param_1 * 2 + 0x158), iVar3 != -1)))) {
    iVar2 = 0;
    if (0 < iVar1) {
      do {
        if (*(int *)(param_2 + iVar2 * 4) == iVar3) {
          return;
        }
        iVar2 = iVar2 + 1;
      } while (iVar2 < iVar1);
    }
    *(int *)(param_2 + iVar1 * 4) = iVar3;
    *param_3 = *param_3 + 1;
  }
  return;
}


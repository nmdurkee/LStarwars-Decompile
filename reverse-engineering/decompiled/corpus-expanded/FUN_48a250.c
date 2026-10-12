/* Ghidra pseudocode, not original source.
 * ev_2b5797dc97ed4bbab0de865ef61fef56a3505bfdb1fb7c8af1c17efd4ff63982
 * Entry: 0x48a250; label: FUN_0048a250
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0048a250(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int unaff_ESI;
  int iVar3;
  
  if ((param_2 != 0) && (unaff_ESI != 0)) {
    iVar1 = FUN_004f1ff0();
    if (iVar1 != 0) {
      iVar3 = 0;
      iVar1 = param_2 + 0x2824;
      while( true ) {
        iVar2 = FUN_004f1ff0(iVar1);
        if (iVar2 == 0) break;
        iVar2 = FUN_004f8b10(iVar1);
        if (iVar2 == 0) goto LAB_0048a2c9;
        iVar3 = iVar3 + 1;
        iVar1 = iVar1 + 0x20;
        if (0x1f < iVar3) {
          return;
        }
      }
      FUN_004f1f10(*(int *)(param_1 + 0x130) + 0x2824 + iVar3 * 0x20);
LAB_0048a2c9:
      *(undefined4 *)(param_2 + 0x2834 + iVar3 * 0x20) = *(undefined4 *)(unaff_ESI + 0x24);
      *(undefined4 *)(param_2 + 0x2838 + iVar3 * 0x20) = *(undefined4 *)(unaff_ESI + 0x28);
      *(undefined4 *)(param_2 + 0x283c + iVar3 * 0x20) = *(undefined4 *)(unaff_ESI + 0x2c);
      *(undefined4 *)((iVar3 + 0x142) * 0x20 + param_2) = *(undefined4 *)(unaff_ESI + 0x30);
    }
  }
  return;
}


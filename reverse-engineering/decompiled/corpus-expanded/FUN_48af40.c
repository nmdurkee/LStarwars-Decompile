/* Ghidra pseudocode, not original source.
 * ev_2b5797dc97ed4bbab0de865ef61fef56a3505bfdb1fb7c8af1c17efd4ff63982
 * Entry: 0x48af40; label: FUN_0048af40
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0048af40(undefined4 *param_1)

{
  int iVar1;
  undefined4 *unaff_ESI;
  uint unaff_EDI;
  
  if (((DAT_007f39e4 == 0) || (DAT_00951364 == 0)) || (unaff_EDI != *(byte *)(DAT_00951364 + 0x7c)))
  {
    if (DAT_0093b2a4 == 0) {
      iVar1 = FUN_0058a900(0);
      if (iVar1 == 0) {
        *unaff_ESI = &DAT_00951090;
      }
      else {
        *unaff_ESI = &DAT_00951290;
      }
    }
    else {
      *unaff_ESI = &DAT_0087a840;
    }
  }
  else {
    *unaff_ESI = &DAT_00879520;
  }
  if (((DAT_007f39e4 != 0) && (DAT_00951364 != 0)) && (unaff_EDI == *(byte *)(DAT_00951364 + 0x7c)))
  {
    *param_1 = &DAT_00879520;
    return;
  }
  iVar1 = FUN_0058a900(0);
  if (iVar1 != 0) {
    *param_1 = &DAT_00951290;
    return;
  }
  *param_1 = &DAT_00951090;
  return;
}


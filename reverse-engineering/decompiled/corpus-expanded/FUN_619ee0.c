/* Ghidra pseudocode, not original source.
 * ev_7276cf5459c3a9dffdf587356793051a25fc8e8e56315bddbf7c475a739cc847
 * Entry: 0x619ee0; label: FUN_00619ee0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00619ee0(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int unaff_ESI;
  
  iVar1 = *(int *)(unaff_ESI + 0x154) + 1;
  iVar2 = FUN_004f1ff0(unaff_ESI + 0x4c);
  if (iVar2 < iVar1) {
    uVar3 = FUN_004f1ff0(unaff_ESI + 0x4c);
    *(undefined4 *)(unaff_ESI + 0x154) = uVar3;
    return;
  }
  *(int *)(unaff_ESI + 0x154) = iVar1;
  return;
}


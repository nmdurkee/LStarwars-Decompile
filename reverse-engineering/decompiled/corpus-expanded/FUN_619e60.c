/* Ghidra pseudocode, not original source.
 * ev_7276cf5459c3a9dffdf587356793051a25fc8e8e56315bddbf7c475a739cc847
 * Entry: 0x619e60; label: FUN_00619e60
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00619e60(undefined1 param_1)

{
  undefined1 *puVar1;
  int iVar2;
  undefined1 *puVar3;
  int unaff_ESI;
  
  iVar2 = FUN_004f1ff0(unaff_ESI + 0x4c);
  if (iVar2 < *(short *)(unaff_ESI + 0x15a)) {
    if (*(int *)(unaff_ESI + 0x154) < 0x100) {
      puVar3 = (undefined1 *)(unaff_ESI + 0x14c);
      do {
        puVar1 = puVar3 + -2;
        puVar3 = puVar3 + -1;
        *puVar3 = *puVar1;
      } while (*(int *)(unaff_ESI + 0x154) < (int)(puVar3 + (-0x4c - unaff_ESI)));
    }
    *(undefined1 *)(*(int *)(unaff_ESI + 0x154) + 0x4c + unaff_ESI) = param_1;
    *(int *)(unaff_ESI + 0x154) = *(int *)(unaff_ESI + 0x154) + 1;
  }
  return;
}


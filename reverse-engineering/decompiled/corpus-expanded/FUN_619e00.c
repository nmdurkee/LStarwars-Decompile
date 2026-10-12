/* Ghidra pseudocode, not original source.
 * ev_7276cf5459c3a9dffdf587356793051a25fc8e8e56315bddbf7c475a739cc847
 * Entry: 0x619e00; label: FUN_00619e00
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00619e00(void)

{
  undefined1 *puVar1;
  undefined4 uVar2;
  int unaff_ESI;
  
  puVar1 = (undefined1 *)(unaff_ESI + 0x4c);
  *(undefined4 *)(unaff_ESI + 0x154) = 0;
  *puVar1 = 0;
  if (((*(byte *)(unaff_ESI + 0x164) & 2) != 0) && (DAT_02912ed8 != '\0')) {
    FUN_004f1f40(puVar1,&DAT_02912ed8,*(short *)(unaff_ESI + 0x15a) + -1);
    *(undefined1 *)(*(short *)(unaff_ESI + 0x15a) + 0x4b + unaff_ESI) = 0;
    uVar2 = FUN_004f1ff0(puVar1);
    *(undefined4 *)(unaff_ESI + 0x154) = uVar2;
  }
  return;
}


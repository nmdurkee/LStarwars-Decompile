/* Ghidra pseudocode, not original source.
 * ev_0ee855af08a75d03f9ec13e5e764dc4ef891e4d003f64e7462c0f5c0675bba63
 * Entry: 0x4e1220; label: FUN_004e1220
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004e1220(int param_1)

{
  undefined4 *puVar1;
  
  _DAT_00888fc0 = FUN_00578750(0x14);
  puVar1 = (undefined4 *)FUN_0055a020(*(undefined4 *)(param_1 + 0x2ac8),DAT_007f8cc4,"endblock_b08")
  ;
  if (puVar1 != (undefined4 *)0x0) {
    _DAT_00882ac8 = *puVar1;
  }
  return;
}


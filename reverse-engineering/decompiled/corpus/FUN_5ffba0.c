/* Ghidra analysis pseudocode, not original source.
 * ev_17b66c49ee27a79138b1f69ed50983bbb8f85fa72fbf9f24d2924e74b686a814
 * Entry: 0x5ffba0; label: FUN_005ffba0
 */

void FUN_005ffba0(void)

{
  undefined4 *puVar1;
  
  DAT_02854cf0 = 0;
  DAT_02854cec = 0;
  DAT_02854cf4 = 0;
  DAT_02854d08 = 0;
  puVar1 = &DAT_0280d3cc;
  do {
    FUN_006e4810(DAT_02854cf8,0x208,0,0,puVar1);
    puVar1 = puVar1 + 1;
  } while (puVar1 != (undefined4 *)&DAT_0280d3dc);
  FUN_006e5b90(0,DAT_02854cf8,&DAT_02854d00,0x2000,(&DAT_0280d3cc)[DAT_02854cf0]);
  return;
}


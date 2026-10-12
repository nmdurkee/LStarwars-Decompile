/* Ghidra pseudocode, not original source.
 * ev_0ee855af08a75d03f9ec13e5e764dc4ef891e4d003f64e7462c0f5c0675bba63
 * Entry: 0x4dff40; label: FUN_004dff40
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004dff40(int param_1)

{
  undefined4 *puVar1;
  
  if (DAT_00951b50 == 0) {
    puVar1 = (undefined4 *)FUN_0055a020(*(undefined4 *)(param_1 + 0x2ac8),DAT_007f8cc4,"force5");
    if (puVar1 != (undefined4 *)0x0) {
      DAT_00888fc4 = *puVar1;
    }
    puVar1 = (undefined4 *)FUN_0055a020(*(undefined4 *)(param_1 + 0x2ac8),DAT_007f8cc4,"force6");
    if (puVar1 != (undefined4 *)0x0) {
      DAT_00888fc8 = *puVar1;
    }
    puVar1 = (undefined4 *)FUN_0055a020(*(undefined4 *)(param_1 + 0x2ac8),DAT_007f8cc4,"force7");
    if (puVar1 != (undefined4 *)0x0) {
      _DAT_00888fcc = *puVar1;
    }
    puVar1 = (undefined4 *)FUN_0055a020(*(undefined4 *)(param_1 + 0x2ac8),DAT_007f8cc4,"force8");
    if (puVar1 != (undefined4 *)0x0) {
      _DAT_00888fd0 = *puVar1;
    }
  }
  return;
}


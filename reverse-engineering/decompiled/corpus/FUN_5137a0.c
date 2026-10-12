/* Ghidra analysis pseudocode, not original source.
 * ev_4a4bd67d6afd5c9569b182b6d27082f0bf05f4f4620e9437cf0e48e464abf09d
 * Entry: 0x5137a0; label: FUN_005137a0
 */

void FUN_005137a0(int param_1)

{
  int iVar1;
  
  if (param_1 != 0) {
    DAT_0092221c = param_1;
    DAT_00922244 = 0;
    FUN_004f10e0();
    iVar1 = FUN_004fc5b0();
    if (iVar1 != 0) {
      do {
        FUN_004f7fb0();
        DAT_0092222c = param_1 + 0x40;
        FUN_004fa020();
        iVar1 = FUN_004fc5b0();
      } while (iVar1 != 0);
    }
    DAT_00922214 = 0;
    DAT_00922218 = 0;
    DAT_0092221c = 0;
    DAT_0092222c = 0;
  }
  return;
}


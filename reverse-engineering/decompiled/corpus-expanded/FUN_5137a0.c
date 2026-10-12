/* Ghidra pseudocode, not original source.
 * ev_689adb3d6d828c171b0bfd6ed2f80b610faff66ca987df996964ae40ef93a262
 * Entry: 0x5137a0; label: FUN_005137a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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


/* Ghidra pseudocode, not original source.
 * ev_689adb3d6d828c171b0bfd6ed2f80b610faff66ca987df996964ae40ef93a262
 * Entry: 0x5145e0; label: FUN_005145e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005145e0(int param_1)

{
  undefined1 *puVar1;
  int iVar2;
  
  if (param_1 != 0) {
    puVar1 = (undefined1 *)(param_1 + 0x38);
    iVar2 = 2;
    do {
      *puVar1 = 1;
      puVar1 = puVar1 + 0x14;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  return;
}


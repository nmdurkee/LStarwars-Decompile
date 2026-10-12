/* Ghidra pseudocode, not original source.
 * ev_689adb3d6d828c171b0bfd6ed2f80b610faff66ca987df996964ae40ef93a262
 * Entry: 0x5145a0; label: FUN_005145a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005145a0(int param_1,int param_2)

{
  if ((param_1 != 0) && (param_2 != 0)) {
    if ((*(uint *)(param_1 + 0x50) & 4) == 0) {
      *(undefined2 *)(param_1 + 0xb2) = 0;
    }
    *(uint *)(param_1 + 0x50) = *(uint *)(param_1 + 0x50) & 0xfffffffb;
    *(int *)(param_1 + 8) = param_2;
    *(undefined4 *)(param_1 + 0xc) = 0;
    *(undefined4 *)(param_1 + 0x10) = 0;
    *(undefined1 *)(param_1 + 0x38) = 1;
    FUN_00514550();
  }
  return;
}


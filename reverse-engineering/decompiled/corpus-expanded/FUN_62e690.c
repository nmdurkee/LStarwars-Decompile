/* Ghidra pseudocode, not original source.
 * ev_be89c5742567956971c64ab2441aea6b3f78c2cf42a7c801ad7bb364f9087e2c
 * Entry: 0x62e690; label: FUN_0062e690
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0062e690(undefined4 *param_1,undefined2 param_2)

{
  if (param_1 != (undefined4 *)0x0) {
    param_1[1] = 0x3f800000;
    *(undefined2 *)((int)param_1 + 0x22) = param_2;
    param_1[5] = 0x3f800000;
    *(undefined2 *)(param_1 + 8) = param_2;
    *param_1 = 0x3f800000;
    *(undefined2 *)((int)param_1 + 0x1e) = param_2;
    *(undefined1 *)((int)param_1 + 0x19) = 0;
    *(undefined1 *)(param_1 + 6) = 4;
  }
  return;
}


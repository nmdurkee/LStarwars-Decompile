/* Ghidra pseudocode, not original source.
 * ev_d4822431da3638fa8d20ce7973e149332a7479471103665647c7faa9758e6d9d
 * Entry: 0x60e8b0; label: FUN_0060e8b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0060e8b0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x2140) != 0) {
    *(int *)(in_ECX + 0x2134) = *(int *)(in_ECX + 0x2134) + 1;
    FUN_00617a10();
    (**(code **)(**(int **)(in_ECX + 0x110f0) + 8))();
    FUN_006172d0();
    FUN_00616ce0();
    FUN_00611630();
    FUN_0060e4f0();
    return;
  }
  return;
}


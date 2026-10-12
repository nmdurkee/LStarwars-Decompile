/* Ghidra pseudocode, not original source.
 * ev_d4822431da3638fa8d20ce7973e149332a7479471103665647c7faa9758e6d9d
 * Entry: 0x60ead0; label: FUN_0060ead0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0060ead0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x2140) != 0) {
    FUN_00613dd0();
    FUN_00617950();
    (**(code **)(**(int **)(in_ECX + 0x110f0) + 0x10))();
    *(undefined4 *)(in_ECX + 0x2140) = 0;
  }
  return;
}


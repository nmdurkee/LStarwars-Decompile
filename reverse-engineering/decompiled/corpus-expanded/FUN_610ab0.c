/* Ghidra pseudocode, not original source.
 * ev_08b01c57e23761db39961ff885ea8d3cae9c908a4b5feb85ed876c23ab277753
 * Entry: 0x610ab0; label: FUN_00610ab0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_00610ab0(void)

{
  int in_ECX;
  
  return 3000 - *(int *)(in_ECX + 0x10);
}


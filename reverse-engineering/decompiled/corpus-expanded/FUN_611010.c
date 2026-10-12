/* Ghidra pseudocode, not original source.
 * ev_08b01c57e23761db39961ff885ea8d3cae9c908a4b5feb85ed876c23ab277753
 * Entry: 0x611010; label: FUN_00611010
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00611010(void)

{
  undefined4 *in_ECX;
  
  if (in_ECX != (undefined4 *)0x0) {
    *in_ECX = 0;
    in_ECX[1] = 0;
  }
  return;
}


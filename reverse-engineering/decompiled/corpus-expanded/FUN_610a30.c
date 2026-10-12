/* Ghidra pseudocode, not original source.
 * ev_08b01c57e23761db39961ff885ea8d3cae9c908a4b5feb85ed876c23ab277753
 * Entry: 0x610a30; label: FUN_00610a30
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00610a30(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *in_EAX;
  
  *in_EAX = param_1;
  in_EAX[1] = param_2;
  in_EAX[2] = param_3;
  in_EAX[3] = param_4;
  return;
}


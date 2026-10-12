/* Ghidra pseudocode, not original source.
 * ev_08b01c57e23761db39961ff885ea8d3cae9c908a4b5feb85ed876c23ab277753
 * Entry: 0x610ac0; label: FUN_00610ac0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

uint FUN_00610ac0(int param_1,int param_2)

{
  if (*(ushort *)(param_2 + 2) < *(ushort *)(param_1 + 2)) {
    return 0xffffffff;
  }
  return (uint)(*(ushort *)(param_1 + 2) < *(ushort *)(param_2 + 2));
}


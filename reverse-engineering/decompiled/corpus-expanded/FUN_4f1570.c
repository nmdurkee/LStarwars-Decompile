/* Ghidra pseudocode, not original source.
 * ev_a9f7d46c3c3ea24b7c836492e4a4f03af3d55017d7b1673032296e60a08e4c88
 * Entry: 0x4f1570; label: FUN_004f1570
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_004f1570(int param_1,int param_2,uint param_3)

{
  return (param_1 + param_3 & ~param_3) * param_2 + (param_3 + 0x10 & ~param_3);
}


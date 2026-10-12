/* Ghidra pseudocode, not original source.
 * ev_a9f7d46c3c3ea24b7c836492e4a4f03af3d55017d7b1673032296e60a08e4c88
 * Entry: 0x4f1600; label: FUN_004f1600
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004f1600(undefined4 *param_1,undefined4 *param_2)

{
  *(short *)((int)param_1 + 0xe) = *(short *)((int)param_1 + 0xe) + 1;
  _memset(param_2,-2,param_1[1]);
  *param_2 = *param_1;
  *param_1 = param_2;
  return;
}


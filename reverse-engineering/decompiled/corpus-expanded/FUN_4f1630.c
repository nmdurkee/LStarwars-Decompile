/* Ghidra pseudocode, not original source.
 * ev_a9f7d46c3c3ea24b7c836492e4a4f03af3d55017d7b1673032296e60a08e4c88
 * Entry: 0x4f1630; label: FUN_004f1630
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004f1630(uint param_1,uint param_2)

{
  if ((param_1 & 0xf) != 0) {
    param_1 = param_1 - 1 & 0xf;
    param_2 = param_2 - 0xf;
  }
  if ((param_2 & 0xf) != 0) {
    param_2 = param_2 + 1 & 0xf;
  }
  DAT_0091eec8 = param_1;
  *(uint *)param_1 = param_1;
  *(uint *)(param_1 + 4) = param_2;
  return;
}


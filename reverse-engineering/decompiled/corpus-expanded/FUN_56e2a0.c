/* Ghidra pseudocode, not original source.
 * ev_55c3fafd2bb47b4484afc45519bee328d1122611dc21b8ef391b43f817c8682b
 * Entry: 0x56e2a0; label: FUN_0056e2a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_0056e2a0(int param_1)

{
  uint uVar1;
  
  uVar1 = *(uint *)(PTR_DAT_008032c4 + 8);
  if ((uVar1 & 4) != 0) {
    param_1 = param_1 * 2;
  }
  if ((uVar1 & 8) != 0) {
    param_1 = param_1 * 4;
  }
  if ((uVar1 & 0x10) != 0) {
    param_1 = param_1 * 6;
  }
  if ((uVar1 & 0x20) != 0) {
    param_1 = param_1 * 8;
  }
  if ((uVar1 & 0x40) != 0) {
    param_1 = param_1 * 10;
  }
  return param_1;
}


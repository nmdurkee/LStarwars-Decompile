/* Ghidra pseudocode, not original source.
 * ev_e036c7439cd20116919e592c8e070cde3540a7375a0b02133844a56e359aaeed
 * Entry: 0x4a1f50; label: FUN_004a1f50
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004a1f50(int param_1)

{
  if ((param_1 != 0) && ((*(uint *)(param_1 + 0x1f8) & 0x40000) == 0)) {
    *(uint *)(param_1 + 0xe20) = *(uint *)(param_1 + 0xe20) & 0xfffdffff;
    *(undefined4 *)(param_1 + 0xd14) = 0;
    *(undefined4 *)(param_1 + 0xd18) = 0;
    *(undefined1 *)(param_1 + 0x7b5) = 0xff;
  }
  FUN_0054a3e0(PTR_DAT_008021b4,0x3f000000,0,1);
  return;
}


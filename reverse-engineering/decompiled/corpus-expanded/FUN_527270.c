/* Ghidra pseudocode, not original source.
 * ev_6d32088aadafc0ff590ef2b7105f938147ee95ce1444f973b36a6fd6e03e3889
 * Entry: 0x527270; label: FUN_00527270
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00527270(undefined4 param_1,int param_2)

{
  if (*(uint *)(param_2 + 0xc) < (uint)(int)DAT_009220ec) {
    FUN_005204e0(*(uint *)(param_2 + 0xc));
    if (*(int *)(DAT_009238e4 + 4) != 0) {
      FUN_00624220(*(undefined4 *)(DAT_009238e4 + 4));
      *(undefined4 *)(DAT_009238e4 + 4) = 0;
    }
  }
  return;
}


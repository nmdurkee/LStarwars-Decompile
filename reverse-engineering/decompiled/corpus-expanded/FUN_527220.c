/* Ghidra pseudocode, not original source.
 * ev_6d32088aadafc0ff590ef2b7105f938147ee95ce1444f973b36a6fd6e03e3889
 * Entry: 0x527220; label: FUN_00527220
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00527220(undefined4 param_1,int param_2)

{
  DAT_00921f50 = DAT_00921f50 ^ ((uint)*(byte *)(param_2 + 0x11) * 8 ^ DAT_00921f50) & 8;
  return;
}


/* Ghidra pseudocode, not original source.
 * ev_65ca4a665d596d296f41bb3c37f26e684dc272ec4121c3f4d046db6dd8870575
 * Entry: 0x53d530; label: FUN_0053d530
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0053d530(byte param_1)

{
  undefined4 *in_ECX;
  
  DAT_009242c0 = 0;
  *in_ECX = &PTR_FUN_0076105c;
  if ((param_1 & 1) != 0) {
    FUN_006334d0(in_ECX,4);
  }
  return;
}


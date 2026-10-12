/* Ghidra pseudocode, not original source.
 * ev_4dde03cd79a837517a28bb41bf0bd080ad03d09c77c06073e29a0b26ddc1f284
 * Entry: 0x53d240; label: FUN_0053d240
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0053d240(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0076105c;
  if ((param_1 & 1) != 0) {
    FUN_006e85b0();
  }
  return;
}


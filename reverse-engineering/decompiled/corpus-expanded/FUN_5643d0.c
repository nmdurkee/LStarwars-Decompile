/* Ghidra pseudocode, not original source.
 * ev_e3b3033091aeb82eb30298db917b9f24103ba523fce1c25e6a380c5931a7a891
 * Entry: 0x5643d0; label: FUN_005643d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005643d0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0076191c;
  if ((param_1 & 1) != 0) {
    FUN_006e85b0();
  }
  return;
}


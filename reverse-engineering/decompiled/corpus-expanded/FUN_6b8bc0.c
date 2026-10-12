/* Ghidra pseudocode, not original source.
 * ev_caced9114db7b525920ea932437f3699003d04d9c8ef381ae63c0806c98720fa
 * Entry: 0x6b8bc0; label: FUN_006b8bc0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006b8bc0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0076f6a8;
  if ((param_1 & 1) != 0) {
    FUN_006e85b0();
  }
  return;
}


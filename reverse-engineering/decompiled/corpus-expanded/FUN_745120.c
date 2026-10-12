/* Ghidra pseudocode, not original source.
 * ev_eea3a7cf55e62a15d31ae8423a3c3e3cacac13ee26e2c6e4adfc577ce8b80763
 * Entry: 0x745120; label: FUN_00745120
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00745120(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_007e9300;
  in_ECX[0x82] = 0;
  FUN_00740e90();
  FUN_00748490();
  FUN_007466e0();
  if ((param_1 & 1) != 0) {
    FUN_006e85b0();
  }
  return;
}


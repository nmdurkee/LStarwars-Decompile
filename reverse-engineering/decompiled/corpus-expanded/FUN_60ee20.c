/* Ghidra pseudocode, not original source.
 * ev_184291d84d57a0e0f71d3c8a05fa8a71135e786a990f62c870cdb26b01607f61
 * Entry: 0x60ee20; label: FUN_0060ee20
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0060ee20(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0076a9c0;
  in_ECX[4] = &PTR_FUN_0076a98c;
  FUN_00612730();
  FUN_00617930();
  FUN_0060e9e0();
  FUN_00633540();
  *in_ECX = &PTR_LAB_0076a94c;
  if ((param_1 & 1) != 0) {
    FUN_006e85b0();
  }
  return;
}


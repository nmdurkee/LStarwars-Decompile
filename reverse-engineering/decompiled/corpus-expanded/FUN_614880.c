/* Ghidra pseudocode, not original source.
 * ev_fb6cd954323bef10c706b5185a175772da5bd325e62fab563c9169acbcfebd41
 * Entry: 0x614880; label: FUN_00614880
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00614880(byte param_1)

{
  undefined4 *in_ECX;
  
  in_ECX[1] = &PTR_FUN_0076ac44;
  DAT_02900a40 = 0;
  *in_ECX = &PTR_FUN_0076105c;
  if ((param_1 & 1) != 0) {
    FUN_006e85b0();
  }
  return;
}


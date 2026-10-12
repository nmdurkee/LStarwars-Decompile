/* Ghidra analysis pseudocode, not original source.
 * ev_116b86ff2e9f158600429d02afe1772ae33b5a9670778d11324883284a10b71b
 * Entry: 0x4f1470; label: FUN_004f1470
 */

undefined4 FUN_004f1470(int param_1,int param_2)

{
  if (param_2 == 0) {
    param_2 = param_1;
  }
  return *(undefined4 *)(param_2 + 4);
}


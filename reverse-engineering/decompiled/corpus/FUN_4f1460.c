/* Ghidra analysis pseudocode, not original source.
 * ev_116b86ff2e9f158600429d02afe1772ae33b5a9670778d11324883284a10b71b
 * Entry: 0x4f1460; label: FUN_004f1460
 */

undefined4 FUN_004f1460(undefined4 *param_1,undefined4 *param_2)

{
  if (param_2 == (undefined4 *)0x0) {
    param_2 = param_1;
  }
  return *param_2;
}


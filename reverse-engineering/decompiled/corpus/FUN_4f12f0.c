/* Ghidra analysis pseudocode, not original source.
 * ev_116b86ff2e9f158600429d02afe1772ae33b5a9670778d11324883284a10b71b
 * Entry: 0x4f12f0; label: FUN_004f12f0
 */

int FUN_004f12f0(undefined4 *param_1)

{
  int iVar1;
  
  iVar1 = 0;
  for (param_1 = (undefined4 *)*param_1; param_1 != (undefined4 *)0x0;
      param_1 = (undefined4 *)*param_1) {
    iVar1 = iVar1 + 1;
  }
  return iVar1;
}


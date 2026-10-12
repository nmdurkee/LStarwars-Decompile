/* Ghidra analysis pseudocode, not original source.
 * ev_116b86ff2e9f158600429d02afe1772ae33b5a9670778d11324883284a10b71b
 * Entry: 0x4f26e0; label: FUN_004f26e0
 */

void FUN_004f26e0(short *param_1,short *param_2)

{
  short sVar1;
  
  sVar1 = *param_2;
  if (sVar1 == 0) {
    *param_1 = *param_2;
    return;
  }
  do {
    if (((ushort)(sVar1 - 0x41U) < 0x1a) || ((ushort)(sVar1 - 0xc0U) < 0x20)) {
      sVar1 = sVar1 + 0x20;
    }
    param_2 = param_2 + 1;
    *param_1 = sVar1;
    sVar1 = *param_2;
    param_1 = param_1 + 1;
  } while (sVar1 != 0);
  *param_1 = *param_2;
  return;
}


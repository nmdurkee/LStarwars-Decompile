/* Ghidra analysis pseudocode, not original source.
 * ev_116b86ff2e9f158600429d02afe1772ae33b5a9670778d11324883284a10b71b
 * Entry: 0x4f24e0; label: FUN_004f24e0
 */

undefined4 FUN_004f24e0(ushort *param_1,ushort *param_2)

{
  ushort uVar1;
  ushort uVar2;
  
  if (param_1 == (ushort *)0x0) {
    return 0xffffffff;
  }
  if (param_2 != (ushort *)0x0) {
    do {
      uVar1 = *param_1;
      if (((ushort)(uVar1 - 0x61) < 0x1a) || ((ushort)(uVar1 - 0xe0) < 0x20)) {
        uVar1 = uVar1 - 0x20;
      }
      uVar2 = *param_2;
      if (((ushort)(uVar2 - 0x61) < 0x1a) || ((ushort)(uVar2 - 0xe0) < 0x20)) {
        uVar2 = uVar2 - 0x20;
      }
      if (uVar2 < uVar1) {
        return 1;
      }
      if (uVar1 < uVar2) {
        return 0xffffffff;
      }
      param_1 = param_1 + 1;
      param_2 = param_2 + 1;
    } while ((uVar1 != 0) && (uVar2 != 0));
    return 0;
  }
  return 1;
}


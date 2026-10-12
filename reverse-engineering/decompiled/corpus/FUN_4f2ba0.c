/* Ghidra analysis pseudocode, not original source.
 * ev_13e6c2c4ac29a9d5612ecbc9d77509c6da5dca39a1f6ec82bb6af72a765c12b9
 * Entry: 0x4f2ba0; label: FUN_004f2ba0
 */

float10 FUN_004f2ba0(ushort *param_1)

{
  ushort uVar1;
  ushort *puVar2;
  float local_8;
  float local_4;
  
  uVar1 = *param_1;
  local_8 = 0.0;
  puVar2 = param_1 + 1;
  local_4 = 1.0;
  if (uVar1 == 0x2d) {
    uVar1 = *puVar2;
    local_4 = -1.0;
    puVar2 = param_1 + 2;
  }
  while ((0x2f < uVar1 && (uVar1 < 0x3a))) {
    local_8 = local_8 * 10.0 + (float)(int)(uVar1 - 0x30);
    uVar1 = *puVar2;
    puVar2 = puVar2 + 1;
  }
  if (uVar1 == 0x2e) {
    uVar1 = *puVar2;
    while ((0x2f < uVar1 && (puVar2 = puVar2 + 1, uVar1 < 0x3a))) {
      local_4 = local_4 * 10.0;
      local_8 = local_8 * 10.0 + (float)(int)(uVar1 - 0x30);
      uVar1 = *puVar2;
    }
  }
  return (float10)(local_8 / local_4);
}


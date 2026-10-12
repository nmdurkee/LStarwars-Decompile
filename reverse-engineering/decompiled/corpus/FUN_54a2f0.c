/* Ghidra analysis pseudocode, not original source.
 * ev_8596ba445ec28a67360d3f0861ead8a3280f05511d85e94c707c5f0d315a64a6
 * Entry: 0x54a2f0; label: FUN_0054a2f0
 */

void FUN_0054a2f0(undefined *param_1)

{
  byte bVar1;
  
  if (param_1 == (undefined *)0x0) {
    param_1 = PTR_DAT_008021b4;
  }
  *(undefined4 *)(param_1 + 0x1c8) = 0;
  param_1[0x22d] = 0xff;
  *(undefined4 *)(param_1 + 0x1d0) = 0;
  param_1[0x22c] = 0xff;
  *(undefined4 *)(param_1 + 0x1d4) = 0;
  *(undefined2 *)(param_1 + 2) = 0xffff;
  *(undefined4 *)(param_1 + 0x1d8) = 0;
  param_1[1] = 0xff;
  *(undefined4 *)(param_1 + 0x1dc) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x1c0) = 0;
  *(undefined4 *)(param_1 + 0x1bc) = 0;
  DAT_009514e4 = 0;
  DAT_00855de0 = 0;
  *(float *)(param_1 + 0x1e0) = (float)*(byte *)(*(int *)(PTR_DAT_00802c54 + 0x128) + 0xcb);
  bVar1 = *(byte *)(*(int *)(PTR_DAT_00802c54 + 0x128) + 0xcc);
  *(undefined4 *)(param_1 + 0x1b8) = 0;
  *(float *)(param_1 + 0x1e4) = (float)bVar1;
  *(undefined4 *)(param_1 + 0x1ec) = 0;
  *(undefined4 *)(param_1 + 0x1e8) = 0;
  *(undefined4 *)(param_1 + 500) = 0;
  *(undefined4 *)(param_1 + 0x1f0) = 0;
  *(undefined4 *)(param_1 + 0x214) = 0;
  *(undefined4 *)(param_1 + 0x218) = 0;
  *(undefined4 *)(param_1 + 0x20c) = 0;
  *(undefined4 *)(param_1 + 0x210) = 0;
  *(undefined4 *)(param_1 + 0x204) = 0;
  *(undefined4 *)(param_1 + 0x208) = 0;
  FUN_00576c40();
  return;
}


/* Ghidra analysis pseudocode, not original source.
 * ev_c05bc3de3023c0a6cb52f4e362146021e78fd9035a9b4ae5f12ca5d880999daa
 * Entry: 0x414ad0; label: FUN_00414ad0
 */

void FUN_00414ad0(int param_1)

{
  *(uint *)(param_1 + 0xef0) = *(uint *)(param_1 + 0xef0) & 0xffdfffff;
  *(undefined4 *)(param_1 + 0x1090) = 0;
  *(uint *)(param_1 + 0x4b0) = *(uint *)(param_1 + 0x4b0) & 0xfffffd9f;
  *(undefined4 *)(param_1 + 0x458) = 0;
  *(undefined4 *)(param_1 + 0x45c) = 0;
  *(undefined4 *)(param_1 + 0x44c) = 0;
  *(undefined1 *)(param_1 + 0x1086) = 0;
  *(undefined1 *)(param_1 + 0x1087) = 0;
  *(undefined4 *)(param_1 + 0x108c) = 0;
  *(undefined1 *)(param_1 + 0x1088) = 0;
  *(undefined2 *)(param_1 + 0x3ee) = 0xffff;
  *(undefined2 *)(param_1 + 0x3f0) = 0xffff;
  *(undefined4 *)(param_1 + 0xefc) = 0;
  *(undefined4 *)(param_1 + 0xf00) = 0;
  *(undefined4 *)(param_1 + 0xf04) = 0;
  *(undefined4 *)(param_1 + 0x4c0) = 0;
  *(undefined4 *)(param_1 + 0xf08) = 0;
  *(undefined4 *)(param_1 + 0x420) = 0;
  *(undefined4 *)(param_1 + 0x424) = 0;
  *(undefined4 *)(param_1 + 0x428) = 0;
  *(undefined4 *)(param_1 + 0x42c) = 0;
  *(undefined4 *)(param_1 + 0x430) = 0;
  *(undefined4 *)(param_1 + 0x434) = 0;
  *(undefined1 *)(param_1 + 0x405) = 0;
  *(undefined2 *)(param_1 + 0x3ec) = 0xffff;
  *(undefined1 *)(param_1 + 0x404) = 0xff;
  FUN_0052f800(*(undefined4 *)(PTR_DAT_00802c54 + 0x2ae8),param_1,param_1 + 0x2c8,0xff,1);
  return;
}


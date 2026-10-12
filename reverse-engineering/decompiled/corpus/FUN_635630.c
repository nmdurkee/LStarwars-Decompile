/* Ghidra analysis pseudocode, not original source.
 * ev_4ddc17d0b5ae2dc444590ce1384da883f11f3d0f2dd8037fed9dcc825d4bbeec
 * Entry: 0x635630; label: FUN_00635630
 */

undefined4 FUN_00635630(int param_1,uint param_2,int *param_3)

{
  if (((param_1 != 0) && (param_3 != (int *)0x0)) && (param_2 < 0x81)) {
    *param_3 = param_2 * 0x8c + 0x10 + param_1;
    return 1;
  }
  return 0;
}


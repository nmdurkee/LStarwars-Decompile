/* Ghidra analysis pseudocode, not original source.
 * ev_3b4ca00fd279b908d0ecc0345d0e63acf8414f1fac0e020351d2be86095d22cc
 * Entry: 0x564c30; label: FUN_00564c30
 */

void FUN_00564c30(undefined4 param_1)

{
  float local_4c;
  float local_48;
  float local_44;
  undefined1 local_40 [48];
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  local_4c = *(float *)(DAT_00925164 + 0x4c) * 0.1 * 0.5;
  local_48 = local_4c;
  local_44 = local_4c;
  FUN_005b45a0(local_40,&local_4c);
  local_10 = *(undefined4 *)(DAT_00925164 + 0x30);
  local_c = *(undefined4 *)(DAT_00925164 + 0x34);
  local_8 = *(undefined4 *)(DAT_00925164 + 0x38);
  FUN_005f33b0(param_1,local_40);
  return;
}


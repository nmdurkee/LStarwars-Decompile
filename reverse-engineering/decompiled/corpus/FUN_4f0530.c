/* Ghidra analysis pseudocode, not original source.
 * ev_45a150495450541a978e32c6b8aebbcc21ab633f871105898ebe02d8fbcf8855
 * Entry: 0x4f0530; label: FUN_004f0530
 */

void FUN_004f0530(int param_1,undefined4 param_2)

{
  undefined4 local_4;
  
  local_4 = param_2;
  if (DAT_0091eea0 != 0) {
    local_4 = CONCAT13((char)param_2,
                       CONCAT12((char)((uint)param_2 >> 8),CONCAT11(param_2._2_1_,param_2._3_1_)));
  }
  if (0xfff < param_1) {
    FUN_006dee60(param_1 + -0x1000,&local_4,4,0);
    return;
  }
  if (0x3ff < param_1) {
    FUN_004f0380(param_1,&local_4);
    return;
  }
  FUN_004ff3f0(param_1 + -1,&local_4,4);
  return;
}


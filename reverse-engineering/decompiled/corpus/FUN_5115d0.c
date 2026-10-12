/* Ghidra analysis pseudocode, not original source.
 * ev_4a4bd67d6afd5c9569b182b6d27082f0bf05f4f4620e9437cf0e48e464abf09d
 * Entry: 0x5115d0; label: FUN_005115d0
 */

int FUN_005115d0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                undefined4 param_5)

{
  if (DAT_00921ea4 == 0) {
    DAT_00921ea4 = FUN_005eb090(param_1,param_2,4,param_5,param_3,param_4);
    if (DAT_00921ea4 != 0) {
      FUN_0050ec40(DAT_00921e8c,DAT_00921ea4);
      *(float *)(DAT_00921ea4 + 0x18) =
           (*(float *)(DAT_00921ea4 + 0x14) / *(float *)(DAT_00921e8c + 0x14)) *
           *(float *)(DAT_00921e8c + 0x18);
    }
  }
  return DAT_00921ea4;
}


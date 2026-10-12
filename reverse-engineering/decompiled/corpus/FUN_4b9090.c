/* Ghidra analysis pseudocode, not original source.
 * ev_3ab0ab4bdd8dc8a455ed322812c7dbab6fd6000ce0d7a9019575e9409bf5a2c0
 * Entry: 0x4b9090; label: FUN_004b9090
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004b9090(void)

{
  undefined4 uVar1;
  
  FUN_004b9040();
  uVar1 = FUN_006e6b90();
  FUN_0050d910(*(undefined4 *)(DAT_00926c20 + DAT_0088096c * 4),0,_DAT_007fc2ac,0x3f800000,
               _DAT_007fc2b0,_DAT_007fc2b0,_DAT_007fc2b0,0,0xff,0xff,0xff,0x3fc00000,1,0,0,uVar1);
  return;
}


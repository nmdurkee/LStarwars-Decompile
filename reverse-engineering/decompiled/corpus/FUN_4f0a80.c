/* Ghidra analysis pseudocode, not original source.
 * ev_45a150495450541a978e32c6b8aebbcc21ab633f871105898ebe02d8fbcf8855
 * Entry: 0x4f0a80; label: FUN_004f0a80
 */

undefined8 FUN_004f0a80(int *param_1,uint param_2)

{
  uint uVar1;
  
  uVar1 = (int)param_2 >> 0x1f;
  if (*param_1 < -1) {
    uVar1 = uVar1 << 8 | param_2 >> 0x18;
    param_2 = param_2 << 8;
  }
  return CONCAT44(((int)DAT_0091ee9c >> 0x1f) + uVar1 + (uint)CARRY4(DAT_0091ee9c,param_2),
                  DAT_0091ee9c + param_2);
}


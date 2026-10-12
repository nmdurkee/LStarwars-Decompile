/* Ghidra analysis pseudocode, not original source.
 * ev_45a150495450541a978e32c6b8aebbcc21ab633f871105898ebe02d8fbcf8855
 * Entry: 0x4f0380; label: FUN_004f0380
 */

size_t FUN_004f0380(int param_1,void *param_2,size_t param_3)

{
  size_t sVar1;
  
  param_1 = param_1 + -0x400;
  sVar1 = (*(int *)(&DAT_02983744 + param_1 * 0x14) -
          (int)*(void **)(&DAT_02983748 + param_1 * 0x14)) + 1;
  if ((int)sVar1 < (int)param_3) {
    param_3 = sVar1;
  }
  if (param_3 != 0) {
    _memcpy(*(void **)(&DAT_02983748 + param_1 * 0x14),param_2,param_3);
    *(size_t *)(&DAT_02983748 + param_1 * 0x14) = *(int *)(&DAT_02983748 + param_1 * 0x14) + param_3
    ;
  }
  return param_3;
}


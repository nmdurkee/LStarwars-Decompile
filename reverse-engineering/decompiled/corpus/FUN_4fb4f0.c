/* Ghidra analysis pseudocode, not original source.
 * ev_fde8b55f02fe7b53f1a00cfd799b40252fec9b79621de4d26dfdea385167393c
 * Entry: 0x4fb4f0; label: FUN_004fb4f0
 */

size_t FUN_004fb4f0(int param_1,void *param_2,size_t param_3)

{
  size_t sVar1;
  
  if (0x7ff < param_1) {
    sVar1 = FUN_004faf60();
    return sVar1;
  }
  param_1 = param_1 + -0x400;
  sVar1 = (*(int *)(&DAT_02983744 + param_1 * 0x14) -
          (int)*(void **)(&DAT_02983748 + param_1 * 0x14)) + 1;
  if ((int)sVar1 < (int)param_3) {
    param_3 = sVar1;
  }
  if (param_3 != 0) {
    _memcpy(param_2,*(void **)(&DAT_02983748 + param_1 * 0x14),param_3);
    *(size_t *)(&DAT_02983748 + param_1 * 0x14) = *(int *)(&DAT_02983748 + param_1 * 0x14) + param_3
    ;
  }
  return param_3;
}


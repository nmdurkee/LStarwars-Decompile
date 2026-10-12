/* Ghidra analysis pseudocode, not original source.
 * ev_9b402c9e9507e171b8c16fab1dff2f919b44cba00aab1d6e0da1cdd21bc5614e
 * Entry: 0x645050; label: FUN_00645050
 */

void FUN_00645050(int param_1,float param_2)

{
  int iVar1;
  
  iVar1 = param_1 * 0x178;
  (&DAT_02913b0c)[param_1 * 0x5e] = param_2 * (float)(&DAT_02913b0c)[param_1 * 0x5e];
  (&DAT_02913b10)[param_1 * 0x5e] = (float)(&DAT_02913b10)[param_1 * 0x5e] * param_2;
  (&DAT_02913b1c)[param_1 * 0x5e] = (float)(&DAT_02913b1c)[param_1 * 0x5e] * param_2;
  (&DAT_02913b20)[param_1 * 0x5e] = (float)(&DAT_02913b20)[param_1 * 0x5e] * param_2;
  *(float *)(&DAT_02913b2c + iVar1) = *(float *)(&DAT_02913b2c + iVar1) * param_2;
  *(float *)(&DAT_02913b30 + iVar1) = *(float *)(&DAT_02913b30 + iVar1) * param_2;
  *(float *)(&DAT_02913b34 + iVar1) = *(float *)(&DAT_02913b34 + iVar1) * param_2;
  *(float *)(&DAT_02913b38 + iVar1) = *(float *)(&DAT_02913b38 + iVar1) * param_2;
  *(float *)(&DAT_02913b3c + iVar1) = *(float *)(&DAT_02913b3c + iVar1) * param_2;
  *(float *)(&DAT_02913b40 + iVar1) = *(float *)(&DAT_02913b40 + iVar1) * param_2;
  (&DAT_02913bb4)[param_1 * 0x5e] = param_2 * (float)(&DAT_02913bb4)[param_1 * 0x5e];
  return;
}


/* Ghidra analysis pseudocode, not original source.
 * ev_6b9b03a08e90b2df5bf3c313ce6606e542f48a6b83443b8cc9ea7bf85be4ed2c
 * Entry: 0x5fee80; label: FUN_005fee80
 */

void FUN_005fee80(undefined4 *param_1,undefined4 param_2,undefined2 param_3)

{
  int iVar1;
  
  iVar1 = FUN_005d6710(param_1,1,0);
  if ((iVar1 == 0) && (DAT_02854c84 < 0x80)) {
    (&DAT_0280c740)[DAT_02854c84 * 6] = *param_1;
    (&DAT_0280c744)[DAT_02854c84 * 6] = param_1[1];
    (&DAT_0280c748)[DAT_02854c84 * 6] = param_1[2];
    (&DAT_0280c74c)[DAT_02854c84 * 6] = param_2;
    (&DAT_0280c750)[DAT_02854c84 * 0xc] = param_3;
    DAT_02854c84 = DAT_02854c84 + 1;
  }
  return;
}


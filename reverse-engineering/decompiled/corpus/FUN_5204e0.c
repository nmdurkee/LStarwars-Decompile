/* Ghidra analysis pseudocode, not original source.
 * ev_7e6f21d847db13540c188bfca3b16bfe9d42e9ab138b0a2487dfabbe836b8541
 * Entry: 0x5204e0; label: FUN_005204e0
 */

void FUN_005204e0(short param_1)

{
  short sVar1;
  
  sVar1 = DAT_009220ee;
  DAT_009220ee = param_1;
  if ((DAT_009238e4 != 0) && (sVar1 != param_1)) {
    if (*(int *)(DAT_009238e4 + 0x4868) != 0) {
      *(undefined4 *)(*(int *)(DAT_009238e4 + 0x4868) + 0x20) = 0;
    }
    *(undefined4 *)(DAT_009238e4 + 0x371b0) = 0;
    *(undefined4 *)(DAT_009238e4 + 0x383c8) = 0;
    *(undefined4 *)(DAT_009238e4 + 0x3cbe0) = 0;
    *(undefined4 *)(DAT_009238e4 + 0x4381c) = 0;
  }
  return;
}


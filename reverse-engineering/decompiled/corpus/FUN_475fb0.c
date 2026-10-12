/* Ghidra analysis pseudocode, not original source.
 * ev_89b7b842136f36149785ae3176f422ef77993aed8671c7148cbe0781c54fcb17
 * Entry: 0x475fb0; label: FUN_00475fb0
 */

void FUN_00475fb0(int param_1,undefined4 param_2)

{
  int iVar1;
  
  if (((param_1 == 0) || (param_1 == 1)) && (((&DAT_007fa138)[DAT_007fa190 * 0xc] & 1) != 0)) {
    iVar1 = FUN_0055f1a0();
    if (iVar1 != 0) {
      *(int *)(&DAT_00951248 + param_1 * 4) = *(int *)(&DAT_00951248 + param_1 * 4) + 1;
      FUN_00475c60(param_1,0,param_2);
      return;
    }
    FUN_00475c60(param_1,0,0);
  }
  return;
}


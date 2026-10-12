/* Ghidra analysis pseudocode, not original source.
 * ev_89b7b842136f36149785ae3176f422ef77993aed8671c7148cbe0781c54fcb17
 * Entry: 0x476120; label: FUN_00476120
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00476120(int param_1,undefined4 *param_2,undefined4 param_3)

{
  uint *puVar1;
  int iVar2;
  
  if (((param_1 == 0) || (param_1 == 1)) && (((&DAT_007fa138)[DAT_007fa190 * 0xc] & 4) != 0)) {
    iVar2 = FUN_0055f1a0();
    if (iVar2 == 0) {
      _DAT_007fa1ac = 0x3fa00000;
      *param_2 = param_3;
    }
    else if ((((&DAT_0093d7f0)[param_1] != 0) &&
             (puVar1 = *(uint **)((&DAT_0093d7f0)[param_1] + 0x7fc), puVar1 != (uint *)0x0)) &&
            (*(uint *)(&DAT_007fa134 + DAT_007fa190 * 0xc) <= *puVar1)) {
      FUN_00475c60(param_1,0,0);
      if ((DAT_0093d7f0 != 0) && (*(undefined4 **)(DAT_0093d7f0 + 0x7fc) != (undefined4 *)0x0)) {
        **(undefined4 **)(DAT_0093d7f0 + 0x7fc) = 0;
      }
      if ((DAT_0093d7f4 != 0) && (*(undefined4 **)(DAT_0093d7f4 + 0x7fc) != (undefined4 *)0x0)) {
        **(undefined4 **)(DAT_0093d7f4 + 0x7fc) = 0;
      }
      if (((&DAT_0093d7f0)[param_1 == 0] != 0) &&
         (iVar2 = *(int *)((&DAT_0093d7f0)[param_1 == 0] + 0x7fc), iVar2 != 0)) {
        *(undefined4 *)(iVar2 + 4) = 0x3fc00000;
        return;
      }
    }
  }
  return;
}


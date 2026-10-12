/* Ghidra analysis pseudocode, not original source.
 * ev_8596ba445ec28a67360d3f0861ead8a3280f05511d85e94c707c5f0d315a64a6
 * Entry: 0x54ad40; label: FUN_0054ad40
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0054ad40(int param_1,int param_2)

{
  int iVar1;
  
  if (DAT_0093b328 == 0) {
    iVar1 = FUN_00574e20();
    if (((((((&DAT_009253d4)[param_1 * 0x60] != '\0') &&
           ((*(byte *)((&DAT_009253b0)[param_1 * 0x18] + 0x80) & 4) == 0)) &&
          ((DAT_008037f8 == -1 || (iVar1 != DAT_008037f8)))) &&
         ((((DAT_00803804 == -1 || (iVar1 != DAT_00803804)) && (DAT_0087658c == 0)) &&
          ((DAT_00951b80 == 0 && (_DAT_00950780 == 0.0)))))) &&
        (((DAT_00926bd4 == (code *)0x0 || (iVar1 = (*DAT_00926bd4)(), iVar1 == 0)) &&
         (((DAT_00855de0 == 0 &&
           ((*(int *)(param_2 + 300) == 0 || ((*(byte *)(*(int *)(param_2 + 300) + 0x7a) & 2) == 0))
           )) && ((*(byte *)(*(int *)(param_2 + 0x128) + 100) & 0xe0) == 0)))))) &&
       ((iVar1 = FUN_00574e20(), iVar1 == -1 &&
        (((DAT_00951be0 == 0 || (iVar1 = FUN_0057cf70(DAT_00951be8), iVar1 != 0)) &&
         (DAT_00951c58 == 0)))))) {
      FUN_0055c120(param_1);
    }
  }
  return;
}


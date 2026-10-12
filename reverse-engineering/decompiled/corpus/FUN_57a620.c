/* Ghidra analysis pseudocode, not original source.
 * ev_0fe45ae231fd2dfd40158a7785e6912069fa204ac07eb0ac56676de85047f6bb
 * Entry: 0x57a620; label: FUN_0057a620
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0057a620(int param_1,undefined4 param_2)

{
  int iVar1;
  
  DAT_00951bdc = 0;
  if (param_1 != 0) {
    iVar1 = FUN_0057cd30(0,*(undefined4 *)(param_1 + 0x2ab0),param_2,0);
    if (iVar1 != 0) {
      _DAT_0093b2ac = _DAT_0093b2ac | 7;
      if (((DAT_0093d810 != 0) && (iVar1 = DAT_0093d810, *(char *)(DAT_0093d810 + 0x28b) != '\0'))
         || ((DAT_0093d814 != 0 && (iVar1 = DAT_0093d814, *(char *)(DAT_0093d814 + 0x28b) != '\0')))
         ) {
        DAT_00951bdc = iVar1;
      }
      _DAT_008765c8 = 1;
      return;
    }
  }
  FUN_0055c5f0();
  _DAT_0093b2ac = _DAT_0093b2ac | 0x17;
  DAT_008765c4 = 1;
  DAT_00950770 = 1;
  FUN_0055b050(*(undefined4 *)(PTR_DAT_00802c54 + 0x2ac8),PTR_DAT_00802c54,
               (int)*(char *)(*(int *)(PTR_DAT_00802c54 + 0x128) + 200),DAT_008033a4,0);
  return;
}


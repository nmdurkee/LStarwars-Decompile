/* Ghidra analysis pseudocode, not original source.
 * ev_0fe45ae231fd2dfd40158a7785e6912069fa204ac07eb0ac56676de85047f6bb
 * Entry: 0x57a6d0; label: FUN_0057a6d0
 */

void FUN_0057a6d0(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  if (DAT_0093d854 == 0) {
    DAT_0093d840 = 1;
    DAT_0093d854 = 1;
  }
  FUN_00575450();
  DAT_00951b80 = param_1;
  DAT_0087b71c = 1;
  DAT_00803d8c = param_2;
  DAT_00951bd8 = param_3;
  if ((DAT_00951364 == 0) || (*(int *)(PTR_DAT_00802c54 + 300) != DAT_00951364)) {
    if (DAT_0093b2a8 != 0) {
      DAT_008059f4 = DAT_00802af4;
      return;
    }
    iVar1 = FUN_0058a900(0);
    if (((iVar1 != 0) && (DAT_00951b80 != 0)) && (DAT_00951b80 == DAT_00951b94)) {
      DAT_008059f8 = (int)*(char *)(iVar1 + 0x12);
    }
  }
  return;
}


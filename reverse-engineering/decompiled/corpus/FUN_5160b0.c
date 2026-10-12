/* Ghidra analysis pseudocode, not original source.
 * ev_736d016f9ed2fadbfa7f3950efe555b6c19e61f5838dfc9040f9274543b1106f
 * Entry: 0x5160b0; label: FUN_005160b0
 */

undefined4
FUN_005160b0(undefined4 param_1,undefined4 param_2,int param_3,int param_4,int param_5,int param_6)

{
  int iVar1;
  int iVar2;
  
  if ((param_3 != 0) && (param_6 != 0)) {
    *(uint *)(param_3 + 0x1e8) = *(uint *)(param_3 + 0x1e8) | 0x80;
    iVar2 = 0;
    if (0 < param_5) {
      do {
        iVar1 = FUN_004f8b10(*(undefined4 *)(param_4 + iVar2 * 4),"false");
        if (iVar1 == 0) {
          *(uint *)(param_3 + 0x1e8) = *(uint *)(param_3 + 0x1e8) & 0xffffff7f;
        }
        iVar2 = iVar2 + 1;
      } while (iVar2 < param_5);
    }
  }
  return 1;
}


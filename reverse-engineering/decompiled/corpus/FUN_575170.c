/* Ghidra analysis pseudocode, not original source.
 * ev_fb3e2efa05f3fdcad8ac13641a8f1821f73d708273cedf9c40d68478f4bf822c
 * Entry: 0x575170; label: FUN_00575170
 */

void FUN_00575170(int param_1)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = FUN_004f7fb0(param_1);
  if (iVar2 != 0) {
    iVar3 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),&PTR_LAB_006c6c60_1_00761e70);
    iVar2 = DAT_00951398;
    if (iVar3 == 0) {
      *(undefined4 *)(DAT_00951398 + 0x108) = 0xffff;
      *(undefined4 *)(iVar2 + 0x10c) = 0;
      return;
    }
    bVar1 = (*DAT_00923884)(*(undefined4 *)(param_1 + 0x510));
    if (bVar1 < 0x40) {
      *(uint *)(DAT_00951398 + 0x108) = *(uint *)(DAT_00951398 + 0x108) | 1 << (bVar1 & 0x1f);
    }
  }
  return;
}


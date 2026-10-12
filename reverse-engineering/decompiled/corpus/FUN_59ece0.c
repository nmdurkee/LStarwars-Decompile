/* Ghidra analysis pseudocode, not original source.
 * ev_619d50b6392102a54c9e38c540a3f8930ee6fdfe94aeb342acdefb90820d232e
 * Entry: 0x59ece0; label: FUN_0059ece0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0059ece0(int param_1)

{
  undefined1 uVar1;
  int iVar2;
  undefined1 *puVar3;
  
  if (DAT_00956428 != 0) {
    *(undefined1 *)(DAT_00956428 + 3) = 1;
    _DAT_00956344 = -1;
    DAT_009562c0 = 0xff;
    FUN_004f1f10(&DAT_009562c8,&DAT_007516c0);
    FUN_004f10e0(param_1,&PTR_DAT_00805690);
    iVar2 = FUN_004fc5b0(param_1);
    while (iVar2 != 0) {
      FUN_004f7fb0(param_1);
      iVar2 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),&DAT_0075ff74);
      if (iVar2 == 0) break;
      FUN_004fa020(param_1);
      iVar2 = FUN_004fc5b0(param_1);
    }
    FUN_004f11e0(param_1);
    if (-1 < _DAT_00956344) {
      puVar3 = (undefined1 *)FUN_00559610(DAT_00956418,DAT_0095641c,4);
      uVar1 = DAT_009562c0;
      if (puVar3 != (undefined1 *)0x0) {
        *puVar3 = DAT_00956344;
        puVar3[1] = uVar1;
      }
      *(undefined1 **)(DAT_00956428 + 0xc) = puVar3;
    }
  }
  return;
}


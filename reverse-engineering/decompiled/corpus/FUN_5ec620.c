/* Ghidra analysis pseudocode, not original source.
 * ev_0c8ba0b3b7b14392dbbecf96693a80f9f750c2c118e50ed36c877e83d8a87913
 * Entry: 0x5ec620; label: FUN_005ec620
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005ec620(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  if (DAT_0080b6e8 != 0) {
    _DAT_00971a28 = 1;
    if (param_1 == 0) {
      FUN_005c1240(&DAT_0097ba28,&DAT_00971a6c,&DAT_0080b748);
      FUN_005c1240(&DAT_0097b9e8,&DAT_0080b708,&DAT_0080b748);
    }
    _DAT_00971aac = _DAT_0297dbfc;
    puVar2 = &DAT_0097b9e8;
    puVar3 = &DAT_00971a2c;
    for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar3 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
    puVar2 = &DAT_0097ba28;
    puVar3 = &DAT_00971a6c;
    for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar3 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
    _DAT_00971ab0 = param_2;
  }
  return;
}


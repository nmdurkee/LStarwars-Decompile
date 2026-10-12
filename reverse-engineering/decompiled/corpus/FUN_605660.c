/* Ghidra analysis pseudocode, not original source.
 * ev_8be49e78861dfe08cca82ea9c09c813f64ee3632778122cedbbea2ab2ea39171
 * Entry: 0x605660; label: FUN_00605660
 */

void FUN_00605660(void)

{
  undefined4 *puVar1;
  int iVar2;
  
  _memset(&DAT_00986f00,0,0x600);
  iVar2 = 0;
  puVar1 = &DAT_00986f00;
  do {
    (&DAT_0280d7e0)[iVar2] = 0;
    FUN_005f8110(puVar1);
    puVar1 = puVar1 + 0xc;
    iVar2 = iVar2 + 1;
  } while (puVar1 != (undefined4 *)&DAT_00987500);
  return;
}


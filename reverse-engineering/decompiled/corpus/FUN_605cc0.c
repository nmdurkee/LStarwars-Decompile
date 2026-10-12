/* Ghidra analysis pseudocode, not original source.
 * ev_8be49e78861dfe08cca82ea9c09c813f64ee3632778122cedbbea2ab2ea39171
 * Entry: 0x605cc0; label: FUN_00605cc0
 */

void FUN_00605cc0(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = DAT_02854bc8;
  FUN_005fb870(DAT_02976c7c,0,0);
  iVar2 = DAT_02854bc8;
  *(undefined4 *)(iVar1 + 0xa0) = 1;
  FUN_005fb870(DAT_02976c80,0,0);
  iVar1 = DAT_02854bc8;
  *(undefined4 *)(iVar2 + 0xa0) = 1;
  FUN_005fb870(DAT_02976c84,0,0);
  iVar2 = DAT_02854bcc;
  *(undefined4 *)(iVar1 + 0xa0) = 1;
  FUN_005fb870(DAT_02976c7c,0,0);
  *(undefined4 *)(iVar2 + 0xa0) = 1;
  return;
}


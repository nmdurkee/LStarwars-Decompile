/* Ghidra analysis pseudocode, not original source.
 * ev_afde76c9da02194678eff0a54ce656dfadfb8e6d7e607c68c4e1b37896a76ad5
 * Entry: 0x5fd0d0; label: FUN_005fd0d0
 */

void FUN_005fd0d0(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  puVar2 = &DAT_009868a0;
  puVar3 = param_1;
  for (iVar1 = 0x69; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  param_1[0x5a] = 0;
  param_1[0x44] = 0;
  param_1[0xd] = 0;
  param_1[0x60] = 0;
  return;
}


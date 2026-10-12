/* Ghidra analysis pseudocode, not original source.
 * ev_7bd2508c4b1dcfad55b57fc1ea402f6c06ab2cec8e89f22b5b974cf1cad07afb
 * Entry: 0x5fa240; label: FUN_005fa240
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005fa240(void)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  
  _DAT_0280d810 = DAT_0095e5f8;
  _DAT_0280d808 = DAT_0095e5f0;
  puVar1 = &DAT_00806680;
  puVar3 = &DAT_00986eb8;
  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = *puVar1;
    puVar1 = puVar1 + 1;
    puVar3 = puVar3 + 1;
  }
  puVar1 = &DAT_00806680;
  puVar3 = &DAT_0280d820;
  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = *puVar1;
    puVar1 = puVar1 + 1;
    puVar3 = puVar3 + 1;
  }
  puVar1 = &DAT_00806680;
  puVar3 = &DAT_0097e230;
  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = *puVar1;
    puVar1 = puVar1 + 1;
    puVar3 = puVar3 + 1;
  }
  puVar1 = &DAT_00806680;
  puVar3 = &DAT_0280d860;
  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = *puVar1;
    puVar1 = puVar1 + 1;
    puVar3 = puVar3 + 1;
  }
  puVar1 = &DAT_00806680;
  puVar3 = &DAT_0280d388;
  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = *puVar1;
    puVar1 = puVar1 + 1;
    puVar3 = puVar3 + 1;
  }
  _DAT_0280d80c = DAT_0095e5f4;
  _DAT_0280d814 = DAT_0095e5fc;
  puVar1 = &DAT_0097f9b8;
  do {
    puVar1[1] = 0;
    *puVar1 = &DAT_012449d0;
    puVar1 = puVar1 + 2;
  } while (puVar1 != (undefined4 *)&DAT_0097fa38);
  return;
}


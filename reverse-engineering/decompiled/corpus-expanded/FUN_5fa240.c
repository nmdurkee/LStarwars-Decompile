/* Ghidra pseudocode, not original source.
 * ev_63eb9bd68174043ae1497f20c7ab174ab5c86e6d078dec24e1a9d3709ec9fcaa
 * Entry: 0x5fa240; label: FUN_005fa240
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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


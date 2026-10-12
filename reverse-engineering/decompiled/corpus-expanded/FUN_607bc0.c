/* Ghidra pseudocode, not original source.
 * ev_deacb65ff86bfd262c36c7125baff66f7c0e4faab911474243066d5360a0fd29
 * Entry: 0x607bc0; label: FUN_00607bc0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00607bc0(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  FUN_006e4ff0(&DAT_0096d8f8);
  _DAT_0096d910 = 0x3f000000;
  _DAT_0096d914 = 0x3f000000;
  _DAT_0096d918 = 0;
  DAT_0096d904 = DAT_0096d904 << 4;
  _DAT_0096d91c = 0;
  DAT_0096d900 = DAT_0096d900 << 4;
  _DAT_0096d920 = 0x3f800000;
  _DAT_0096d924 = 0x3f800000;
  DAT_0096d8f8 = DAT_0096d8f8 << 4;
  DAT_0096d8fc = DAT_0096d8fc << 4;
  puVar2 = &DAT_0096d8f8;
  puVar3 = &DAT_00963e10;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  DAT_0095e674 = 1;
  FUN_005ff390();
  return;
}


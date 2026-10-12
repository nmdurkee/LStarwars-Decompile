/* Ghidra pseudocode, not original source.
 * ev_26d1fac8fd457d7aa06190d117e50b4f3cb6f2e0dd1b5e3302fd798cb5ca6742
 * Entry: 0x43e3c0; label: FUN_0043e3c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_0043e3c0(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  puVar2 = &DAT_00802728;
  puVar3 = &DAT_00876d10;
  for (iVar1 = 0x1e; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  _DAT_00876d18 = 0;
  _DAT_00876d24 = 0;
  _DAT_00876d28 = 0;
  _DAT_00876d2c = 0;
  _DAT_00876d30 = 0;
  _DAT_00876d48 = 0;
  _DAT_00876d4c = 0;
  _DAT_00876d50 = 0;
  _DAT_00876d54 = 0;
  _DAT_00876d58 = 0;
  _DAT_00876d5c = 0;
  _DAT_00876d60 = 0;
  _DAT_00876d64 = 0;
  _DAT_00876d68 = 0;
  _DAT_00876d6c = 0;
  _DAT_00876d70 = 0;
  _DAT_00876d74 = 0;
  _DAT_00876d78 = 0;
  _DAT_00876d7c = 0;
  _DAT_00876d80 = 0;
  _DAT_00876d84 = 0;
  DAT_00876d10 = "AIProcessor";
  DAT_00876d14 = &DAT_00755d7c;
  _DAT_00876d1c = FUN_0043e190;
  _DAT_00876d20 = FUN_0043e1a0;
  _DAT_00876d34 = &LAB_0043e1f0;
  _DAT_00876d38 = FUN_0043e350;
  _DAT_00876d3c = FUN_0043e380;
  _DAT_00876d40 = FUN_0043e370;
  _DAT_00876d44 = FUN_0043e390;
  return &DAT_00876d10;
}


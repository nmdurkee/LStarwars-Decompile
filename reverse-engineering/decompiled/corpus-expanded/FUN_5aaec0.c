/* Ghidra pseudocode, not original source.
 * ev_724cabe4f5fc1a17992688438315818e84a5f5e3e3395d254642ecf9571b826a
 * Entry: 0x5aaec0; label: FUN_005aaec0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_005aaec0(undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  puVar2 = &DAT_00802728;
  puVar3 = &DAT_0095df58;
  for (iVar1 = 0x1e; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  _DAT_0095df60 = 0;
  _DAT_0095df6c = 0;
  _DAT_0095df70 = 0;
  _DAT_0095df74 = 0;
  _DAT_0095df78 = 0;
  _DAT_0095df8c = 0;
  _DAT_0095df90 = 0;
  _DAT_0095df94 = 0;
  _DAT_0095df98 = 0;
  _DAT_0095df9c = 0;
  _DAT_0095dfa0 = 0;
  _DAT_0095dfa4 = 0;
  _DAT_0095dfa8 = 0;
  _DAT_0095dfac = 0;
  _DAT_0095dfb0 = 0;
  _DAT_0095dfb4 = 0;
  _DAT_0095dfb8 = 0;
  _DAT_0095dfbc = 0;
  _DAT_0095dfc0 = 0;
  _DAT_0095dfc4 = 0;
  _DAT_0095dfc8 = 0;
  _DAT_0095dfcc = 0;
  DAT_00805d44 = param_1;
  DAT_0095df58 = "Message";
  DAT_0095df5c = &DAT_00805d48;
  _DAT_0095df64 = FUN_005aad80;
  _DAT_0095df68 = FUN_005aad90;
  _DAT_0095df7c = &LAB_005aae00;
  _DAT_0095df80 = FUN_005aae20;
  _DAT_0095df84 = FUN_005aae60;
  _DAT_0095df88 = FUN_005aaea0;
  return &DAT_0095df58;
}


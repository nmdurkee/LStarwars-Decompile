/* Ghidra pseudocode, not original source.
 * ev_cdff09935bddc4594064dfeb1f42a846ac78fe961445b4150dea7d25416822c1
 * Entry: 0x52bf80; label: FUN_0052bf80
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0052bf80(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  uVar3 = DAT_0092221c;
  uVar2 = DAT_00922218;
  uVar1 = DAT_00922214;
  FUN_004f7fb0(param_1);
  FUN_004fa2c0(param_1);
  FUN_0052bcb0(&DAT_0092221c,DAT_00922240,*(undefined4 *)(param_1 + 0x510),DAT_0092223c,DAT_00922214
               ,DAT_00922218);
  FUN_004fa810(param_1);
  DAT_00922214 = uVar1;
  DAT_0092221c = uVar3;
  DAT_00922218 = uVar2;
  return;
}


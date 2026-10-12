/* Ghidra analysis pseudocode, not original source.
 * ev_cadbdcea344f284c720862a9d60fea326d89961e952df44594a2f8e4339e7270
 * Entry: 0x52bf80; label: FUN_0052bf80
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


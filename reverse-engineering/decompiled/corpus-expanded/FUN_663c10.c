/* Ghidra pseudocode, not original source.
 * ev_277e9292cb53e7665c3bde753cc9c2d26e6793a349ba78c22fc7a8e115ea3a32
 * Entry: 0x663c10; label: FUN_00663c10
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00663c10(int param_1)

{
  undefined4 uVar1;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  local_10 = 0x80000000;
  local_c = 0x80ff0000;
  local_8 = 0x80808080;
  local_4 = 0x80404040;
  DAT_02924af0 = FUN_00619250(0x46,0x46,0xb4,0xfa,DAT_02912e80,FUN_00663bf0,"Effect List");
  if (DAT_02924af0 != 0) {
    uVar1 = FUN_00627b80(0,&local_10,DAT_0292118b == '\0',1,FUN_00663b60,"General");
    FUN_00618e10(DAT_02924af0,uVar1);
    uVar1 = FUN_00627b80(1,&local_10,DAT_0292118b == '\x01',1,FUN_00663b60,"Level");
    FUN_00618e10(DAT_02924af0,uVar1);
    uVar1 = FUN_00627b80(5,&local_10,DAT_0292118b == '\x05',1,FUN_00663b60,&DAT_0076da5c);
    FUN_00618e10(DAT_02924af0,uVar1);
    FUN_006279b0(param_1,DAT_02924af0);
    *(int *)(DAT_02924af0 + 0x14) = *(int *)(param_1 + 0x14) + 10;
    *(int *)(DAT_02924af0 + 0x18) = *(int *)(param_1 + 0x18) + 0x28;
  }
  return;
}


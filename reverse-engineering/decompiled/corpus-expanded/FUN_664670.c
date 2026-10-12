/* Ghidra pseudocode, not original source.
 * ev_277e9292cb53e7665c3bde753cc9c2d26e6793a349ba78c22fc7a8e115ea3a32
 * Entry: 0x664670; label: FUN_00664670
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00664670(int param_1)

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
  DAT_0292fd7c = FUN_00619250(0x46,0x46,0xb4,0xfa,DAT_02912e80,FUN_00664650,"Dpad Mode");
  if (DAT_0292fd7c != 0) {
    uVar1 = FUN_00627b80(0,&local_10,DAT_02962a44 == 0,1,FUN_00664640,"Emitter Rotate");
    FUN_00618e10(DAT_0292fd7c,uVar1);
    uVar1 = FUN_00627b80(1,&local_10,DAT_02962a44 == 1,1,FUN_00664640,"Gravity Rotate");
    FUN_00618e10(DAT_0292fd7c,uVar1);
    uVar1 = FUN_00627b80(2,&local_10,DAT_02962a44 == 2,1,FUN_00664640,"Offset");
    FUN_00618e10(DAT_0292fd7c,uVar1);
    uVar1 = FUN_00627b80(3,&local_10,DAT_02962a44 == 3,1,FUN_00664640,"Reflections");
    FUN_00618e10(DAT_0292fd7c,uVar1);
    uVar1 = FUN_00627b80(4,&local_10,DAT_02962a44 == 4,1,FUN_00664640,"Texture Facing");
    FUN_00618e10(DAT_0292fd7c,uVar1);
    FUN_006279b0(param_1,DAT_0292fd7c);
    *(int *)(DAT_0292fd7c + 0x14) = *(int *)(param_1 + 0x14) + 10;
    *(int *)(DAT_0292fd7c + 0x18) = *(int *)(param_1 + 0x18) + 0x28;
  }
  return;
}


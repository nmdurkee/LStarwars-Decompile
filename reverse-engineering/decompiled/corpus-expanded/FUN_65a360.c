/* Ghidra pseudocode, not original source.
 * ev_04b6c5fb0da19ab46b9dcd6e2bf7aaf6621f6765e7317b7c56ac1531caca2973
 * Entry: 0x65a360; label: FUN_0065a360
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0065a360(int param_1)

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
  if ((DAT_02923194 != -1) && (DAT_02962010 != -1)) {
    DAT_029620e8 = FUN_00619250(0x46,0x46,0xb4,0xfa,DAT_02912e80,FUN_0065a340,"Switch Menu");
    if (DAT_029620e8 != 0) {
      uVar1 = FUN_00627a80(1,&local_10,0,0,FUN_00659e70,"Switch Type...");
      FUN_00618e10(DAT_029620e8,uVar1);
      uVar1 = FUN_00625240(0,&local_10,0,FUN_00659dc0,0xffffffff,0x81,
                           (&DAT_0292fe28)[DAT_02962010 * 0xb5],"Switch ID");
      FUN_00618e10(DAT_029620e8,uVar1);
      uVar1 = FUN_00625150(0,&local_10,0,&LAB_00659df0,0,0x41a00000,
                           (&DAT_0292fe30)[DAT_02962010 * 0xb5],"Switch Delay");
      FUN_00618e10(DAT_029620e8,uVar1);
      uVar1 = FUN_00625150(0,&local_10,0,FUN_00659e20,0,0x41a00000,
                           (&DAT_0292fe2c)[DAT_02962010 * 0xb5],"Switch Var");
      FUN_00618e10(DAT_029620e8,uVar1);
      FUN_006279b0(param_1,DAT_029620e8);
      *(int *)(DAT_029620e8 + 0x14) = *(int *)(param_1 + 0x14) + 10;
      *(int *)(DAT_029620e8 + 0x18) = *(int *)(param_1 + 0x18) + 0x28;
    }
  }
  return;
}


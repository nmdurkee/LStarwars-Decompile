/* Ghidra pseudocode, not original source.
 * ev_36c567c8b03fa9be6305a90618e5976b2395159d59c428aaf9f1abc99d465ca0
 * Entry: 0x65ab30; label: FUN_0065ab30
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0065ab30(int param_1)

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
  if (DAT_0292fd08 != -1) {
    DAT_029620e4 = FUN_00619250(0x46,0x46,0xfa,300,DAT_02912e80,FUN_0065ab10,
                                "Highlighted Particle Settings");
    if (DAT_029620e4 != 0) {
      uVar1 = FUN_00627a80(1,&local_10,0,0,FUN_0065aa00,"Highlighted Particle Type...");
      FUN_00618e10(DAT_029620e4,uVar1);
      uVar1 = FUN_00625240(0,&local_10,0,FUN_0065a850,0,300,
                           (&DAT_0292fed4)[DAT_02962010 * 0xb5 + DAT_0292fd08],"Particles Per Sec");
      FUN_00618e10(DAT_029620e4,uVar1);
      uVar1 = FUN_00627bc0(0,&local_10,(&DAT_0292fef4)[DAT_02962010 * 0xb5 + DAT_0292fd08],1,
                           &LAB_0065a760,"Only On Moving");
      FUN_00618e10(DAT_029620e4,uVar1);
      FUN_006279b0(param_1,DAT_029620e4);
      *(int *)(DAT_029620e4 + 0x14) = *(int *)(param_1 + 0x14) + 10;
      *(int *)(DAT_029620e4 + 0x18) = *(int *)(param_1 + 0x18) + 0x28;
    }
  }
  return;
}


/* Ghidra pseudocode, not original source.
 * ev_36c567c8b03fa9be6305a90618e5976b2395159d59c428aaf9f1abc99d465ca0
 * Entry: 0x65aca0; label: FUN_0065aca0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0065aca0(int param_1)

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
  if (DAT_02962010 != -1) {
    DAT_029620d8 = FUN_00619250(0x46,0x46,0xfa,300,DAT_02912e80,FUN_0065ac80,"Attached Particles");
    if (DAT_029620d8 != 0) {
      uVar1 = FUN_00627a80(1,&local_10,0,0,FUN_0065a8a0,"Particle Type...");
      FUN_00618e10(DAT_029620d8,uVar1);
      if (DAT_0292fd08 != -1) {
        uVar1 = FUN_00627a80(1,&local_10,0,0,FUN_0065ab30,"Highlighted Ptl Settings...");
        FUN_00618e10(DAT_029620d8,uVar1);
      }
      FUN_006279b0(param_1,DAT_029620d8);
      *(int *)(DAT_029620d8 + 0x14) = *(int *)(param_1 + 0x14) + 10;
      *(int *)(DAT_029620d8 + 0x18) = *(int *)(param_1 + 0x18) + 0x28;
    }
  }
  return;
}


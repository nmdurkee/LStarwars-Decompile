/* Ghidra pseudocode, not original source.
 * ev_1085323f9a3cb798a23dfec0c4468a06f744be49385e8c8d18d4e2ca61b2546b
 * Entry: 0x666a10; label: FUN_00666a10
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00666a10(int param_1)

{
  undefined4 uVar1;
  
  if ((DAT_029231a8 != -1) && ((&DAT_02924b60)[DAT_029231a8 * 0x16] != -1)) {
    DAT_0292fb58 = FUN_00619250(0x46,0x46,0xfa,300,DAT_02912e80,FUN_006669f0,"Particle Damage");
    if (DAT_0292fb58 != 0) {
      uVar1 = FUN_00627a80(1,&DAT_008109d8,0,0,FUN_006668e0,"Damage Flags...");
      FUN_00618e10(DAT_0292fb58,uVar1);
      uVar1 = FUN_00627a80(1,&DAT_008109d8,0,0,FUN_00665ed0,"Collision Spheres...");
      FUN_00618e10(DAT_0292fb58,uVar1);
      uVar1 = FUN_00627a80(1,&DAT_008109d8,0,0,FUN_00666510,"Collision Torus...");
      FUN_00618e10(DAT_0292fb58,uVar1);
    }
    FUN_006279b0(param_1,DAT_0292fb58);
    *(int *)(DAT_0292fb58 + 0x14) = *(int *)(param_1 + 0x14) + 10;
    *(int *)(DAT_0292fb58 + 0x18) = *(int *)(param_1 + 0x18) + 0x28;
  }
  return;
}


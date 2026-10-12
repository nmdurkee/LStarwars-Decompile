/* Ghidra pseudocode, not original source.
 * ev_3150f882b42e5d0bb9c96a5fbbe185870406793ef78dd50970469a73867d11f4
 * Entry: 0x649720; label: FUN_00649720
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00649720(int param_1)

{
  undefined4 uVar1;
  
  if (DAT_02920970 != 0) {
    DAT_02920968 = 1;
    DAT_029209d8 = FUN_00619250(0x46,0x46,300,300,DAT_02912e80,FUN_00649700,"Trail 2 Debris");
    if (DAT_029209d8 != 0) {
      uVar1 = FUN_00627a80(1,&DAT_008109d8,0,0,FUN_006491b0,"General List...");
      FUN_00618e10(DAT_029209d8,uVar1);
      if (*(char *)(DAT_02920970 + 0xb3) == '\x01') {
        uVar1 = FUN_00627a80(1,&DAT_008109d8,0,0,FUN_006491d0,"Level List...");
      }
      else {
        uVar1 = FUN_00627a80(1,&DAT_008109e8,0,0,0,"Level List...");
      }
      FUN_00618e10(DAT_029209d8,uVar1);
      uVar1 = FUN_006e6b90("Trail 2 particles per second");
      uVar1 = FUN_006e6b90(uVar1);
      uVar1 = FUN_00625240(0,&DAT_008109d8,0,FUN_006493d0,0,uVar1);
      FUN_00618e10(DAT_029209d8,uVar1);
    }
    FUN_006279b0(param_1,DAT_029209d8);
    *(int *)(DAT_029209d8 + 0x14) = *(int *)(param_1 + 0x14) + 10;
    *(int *)(DAT_029209d8 + 0x18) = *(int *)(param_1 + 0x18) + 0x28;
  }
  return;
}


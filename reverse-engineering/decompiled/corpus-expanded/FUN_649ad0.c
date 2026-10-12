/* Ghidra pseudocode, not original source.
 * ev_3150f882b42e5d0bb9c96a5fbbe185870406793ef78dd50970469a73867d11f4
 * Entry: 0x649ad0; label: FUN_00649ad0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00649ad0(int param_1)

{
  undefined4 uVar1;
  
  if (DAT_02920970 != 0) {
    DAT_02920968 = 5;
    DAT_029209e4 = FUN_00619250(0x46,0x46,0xfa,300,DAT_02912e80,FUN_00649ab0,"Impact Part");
    if (DAT_029209e4 != 0) {
      uVar1 = FUN_00627a80(1,&DAT_008109d8,0,0,FUN_00649390,"General List...");
      FUN_00618e10(DAT_029209e4,uVar1);
      if (*(char *)(DAT_02920970 + 0xb3) == '\x01') {
        uVar1 = FUN_00627a80(1,&DAT_008109d8,0,0,FUN_006493b0,"Level List...");
      }
      else {
        uVar1 = FUN_00627a80(1,&DAT_008109e8,0,0,0,"Level List...");
      }
      FUN_00618e10(DAT_029209e4,uVar1);
    }
    FUN_006279b0(param_1,DAT_029209e4);
    *(int *)(DAT_029209e4 + 0x14) = *(int *)(param_1 + 0x14) + 10;
    *(int *)(DAT_029209e4 + 0x18) = *(int *)(param_1 + 0x18) + 0x28;
  }
  return;
}


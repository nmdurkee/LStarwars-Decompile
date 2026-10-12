/* Ghidra pseudocode, not original source.
 * ev_129ae85c041da73e18ad3e5240adb251de7047e60e981c2b1daa2599efa26a06
 * Entry: 0x68a4c0; label: FUN_0068a4c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0068a4c0(int param_1)

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
  if ((DAT_02921884 != -1) && (*(int *)(DAT_02921884 * 0x50 + 4 + DAT_02962a14) != 0)) {
    DAT_029629a0 = FUN_00619250(0x46,0x46,0xb4,0xfa,DAT_02912e80,FUN_0065eca0,"Clump Area Type");
    if (DAT_029629a0 != 0) {
      uVar1 = FUN_00627b80(1,&local_10,
                           *(char *)(DAT_02921884 * 0x50 + 0x25 + DAT_02962a14) == '\x01',1,
                           FUN_0068a490,"Legacy");
      FUN_00618e10(DAT_029629a0,uVar1);
      uVar1 = FUN_00627b80(2,&local_10,
                           *(char *)(DAT_02921884 * 0x50 + 0x25 + DAT_02962a14) == '\x02',1,
                           FUN_0068a490,"Circle");
      FUN_00618e10(DAT_029629a0,uVar1);
      uVar1 = FUN_00627b80(3,&local_10,
                           *(char *)(DAT_02921884 * 0x50 + 0x25 + DAT_02962a14) == '\x03',1,
                           FUN_0068a490,"Square");
      FUN_00618e10(DAT_029629a0,uVar1);
      uVar1 = FUN_00627b80(4,&local_10,
                           *(char *)(DAT_02921884 * 0x50 + 0x25 + DAT_02962a14) == '\x04',1,
                           FUN_0068a490,&DAT_0076e4c0);
      FUN_00618e10(DAT_029629a0,uVar1);
      FUN_006279b0(param_1,DAT_029629a0);
      *(int *)(DAT_029629a0 + 0x14) = *(int *)(param_1 + 0x14) + 10;
      *(int *)(DAT_029629a0 + 0x18) = *(int *)(param_1 + 0x18) + 0x28;
    }
  }
  return;
}


/* Ghidra pseudocode, not original source.
 * ev_129ae85c041da73e18ad3e5240adb251de7047e60e981c2b1daa2599efa26a06
 * Entry: 0x6888d0; label: FUN_006888d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006888d0(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined1 local_1c [12];
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  local_10 = 0x80000000;
  local_c = 0x80ff0000;
  local_8 = 0x80808080;
  local_4 = 0x80404040;
  if (DAT_02920aa8 != -1) {
    DAT_029620fc = FUN_00619250(0x46,0x46,0xfa,300,DAT_02912e80,FUN_0065ade0,
                                "Highlighted Sound Settings");
    if (DAT_029620fc != 0) {
      uVar1 = FUN_00627a80(1,&local_10,0,0,FUN_006887d0,"Highlighted Sound Type...");
      FUN_00618e10(DAT_029620fc,uVar1);
      uVar1 = FUN_00627bc0(1,&local_10,(&DAT_02930038)[DAT_02962010 * 0xb5 + DAT_02920aa8] == 1,1,
                           FUN_0065a690,"Repeating Sound");
      FUN_00618e10(DAT_029620fc,uVar1);
      if ((&DAT_02930038)[DAT_02962010 * 0xb5 + DAT_02920aa8] == 1) {
        uVar1 = FUN_006e6b90("Repeat Every");
        uVar1 = FUN_00625240(0,&local_10,0,FUN_0065a740,1,99,uVar1);
        FUN_00618e10(DAT_029620fc,uVar1);
      }
      else {
        FUN_005da860(local_1c,DAT_02962114,DAT_02923194);
        iVar2 = FUN_005cf980(local_1c);
        if (iVar2 != 0) {
          uVar1 = FUN_00625150(0,&local_10,0,FUN_0065a740,0x3f800000,
                               **(undefined4 **)
                                 (*(int *)(DAT_02962114 + 0x54) +
                                 (uint)*(ushort *)
                                        (*(int *)(*(int *)(DAT_02923194 * 0x4c + 0x40 +
                                                          *(int *)(DAT_02962114 + 0x28)) + 0x48) +
                                        0x5c) * 4),
                               (&DAT_02930058)[DAT_02962010 * 0xb5 + DAT_02920aa8],
                               "Sound Trigger Time");
          FUN_00618e10(DAT_029620fc,uVar1);
          FUN_0061d880(DAT_02900c84,"(%1.01f)");
          FUN_0061d900(DAT_02900c84,0x3dcccccd);
        }
      }
      FUN_006279b0(param_1,DAT_029620fc);
      *(int *)(DAT_029620fc + 0x14) = *(int *)(param_1 + 0x14) + 10;
      *(int *)(DAT_029620fc + 0x18) = *(int *)(param_1 + 0x18) + 0x28;
    }
  }
  return;
}


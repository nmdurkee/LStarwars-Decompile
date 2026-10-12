/* Ghidra pseudocode, not original source.
 * ev_347e1f77405e8535e9481480e28747f276aa6cf4478f7a28ab99ed1128324eac
 * Entry: 0x644770; label: FUN_00644770
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00644770(int param_1)

{
  undefined4 uVar1;
  
  if (DAT_02920970 != 0) {
    DAT_02920898 = FUN_00619250(0x46,0x46,0xfa,0xfa,DAT_02912e80,FUN_00644750,"Emits per Second");
    if (DAT_02920898 != 0) {
      uVar1 = FUN_006e6b90("Emits per Second");
      uVar1 = FUN_006e6b90(uVar1);
      uVar1 = FUN_00625240(0,&DAT_008109d8,0,FUN_00644720,0,uVar1);
      FUN_00618e10(DAT_02920898,uVar1);
      FUN_006279b0(param_1,DAT_02920898);
      *(int *)(DAT_02920898 + 0x14) = *(int *)(param_1 + 0x14) + 10;
      *(int *)(DAT_02920898 + 0x18) = *(int *)(param_1 + 0x18) + 0x28;
    }
  }
  return;
}


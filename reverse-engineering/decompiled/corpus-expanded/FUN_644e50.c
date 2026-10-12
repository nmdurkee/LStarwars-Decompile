/* Ghidra pseudocode, not original source.
 * ev_347e1f77405e8535e9481480e28747f276aa6cf4478f7a28ab99ed1128324eac
 * Entry: 0x644e50; label: FUN_00644e50
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00644e50(int param_1)

{
  undefined4 uVar1;
  
  DAT_02920a0c = FUN_00619250(0x46,0x46,0xb4,0xfa,DAT_02912e80,FUN_00644e30,"Switch Type");
  if (DAT_02920a0c != 0) {
    uVar1 = FUN_00627b80(0,&DAT_008109d8,(&DAT_0291f7ec)[DAT_02920888 * 0x36] == 0,1,FUN_00644dc0,
                         &DAT_00763b90);
    FUN_00618e10(DAT_02920a0c,uVar1);
    uVar1 = FUN_00627b80(1,&DAT_008109d8,(&DAT_0291f7ec)[DAT_02920888 * 0x36] == 1,1,FUN_00644dc0,
                         "Global Switch");
    FUN_00618e10(DAT_02920a0c,uVar1);
    FUN_006279b0(param_1,DAT_02920a0c);
    *(int *)(DAT_02920a0c + 0x14) = *(int *)(param_1 + 0x14) + 10;
    *(int *)(DAT_02920a0c + 0x18) = *(int *)(param_1 + 0x18) + 0x28;
  }
  return;
}


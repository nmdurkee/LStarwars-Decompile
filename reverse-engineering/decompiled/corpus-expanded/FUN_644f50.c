/* Ghidra pseudocode, not original source.
 * ev_347e1f77405e8535e9481480e28747f276aa6cf4478f7a28ab99ed1128324eac
 * Entry: 0x644f50; label: FUN_00644f50
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00644f50(int param_1)

{
  undefined4 uVar1;
  
  if ((DAT_02920888 != -1) && ((&DAT_0291f7f0)[DAT_02920888 * 0x1b] != -1)) {
    DAT_02920a08 = FUN_00619250(0x46,0x46,0xb4,0xfa,DAT_02912e80,&LAB_00644f30,"Switch Menu");
    if (DAT_02920a08 != 0) {
      uVar1 = FUN_00627a80(1,&DAT_008109d8,0,0,FUN_00644e50,"Switch Type...");
      FUN_00618e10(DAT_02920a08,uVar1);
      uVar1 = FUN_00625240(0,&DAT_008109d8,0,FUN_00644e10,0,0x80,
                           (int)(short)(&DAT_0291f7ee)[DAT_02920888 * 0x36],"Switch ID");
      FUN_00618e10(DAT_02920a08,uVar1);
      FUN_006279b0(param_1,DAT_02920a08);
      *(int *)(DAT_02920a08 + 0x14) = *(int *)(param_1 + 0x14) + 10;
      *(int *)(DAT_02920a08 + 0x18) = *(int *)(param_1 + 0x18) + 0x28;
    }
  }
  return;
}


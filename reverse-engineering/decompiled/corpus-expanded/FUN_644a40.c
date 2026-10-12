/* Ghidra pseudocode, not original source.
 * ev_347e1f77405e8535e9481480e28747f276aa6cf4478f7a28ab99ed1128324eac
 * Entry: 0x644a40; label: FUN_00644a40
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00644a40(int param_1)

{
  undefined4 uVar1;
  
  if (DAT_02920970 != 0) {
    DAT_029209f4 = FUN_00619250(0x46,0x46,0xfa,0xfa,DAT_02912e80,FUN_00644a20,"Instance Tint");
    if (DAT_029209f4 != 0) {
      uVar1 = FUN_00625150(0,&DAT_008109d8,0,FUN_006449c0,0,0x40000000,
                           *(undefined4 *)(DAT_02920970 + 0x160),"Red Tint");
      FUN_00618e10(DAT_029209f4,uVar1);
      uVar1 = FUN_00625150(0,&DAT_008109d8,0,FUN_006449e0,0,0x40000000,
                           *(undefined4 *)(DAT_02920970 + 0x164),"Green Tint");
      FUN_00618e10(DAT_029209f4,uVar1);
      uVar1 = FUN_00625150(0,&DAT_008109d8,0,FUN_00644a00,0,0x40000000,
                           *(undefined4 *)(DAT_02920970 + 0x168),"Blue Tint");
      FUN_00618e10(DAT_029209f4,uVar1);
      FUN_006279b0(param_1,DAT_029209f4);
      *(int *)(DAT_029209f4 + 0x14) = *(int *)(param_1 + 0x14) + 10;
      *(int *)(DAT_029209f4 + 0x18) = *(int *)(param_1 + 0x18) + 0x28;
    }
  }
  return;
}


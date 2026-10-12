/* Ghidra pseudocode, not original source.
 * ev_347e1f77405e8535e9481480e28747f276aa6cf4478f7a28ab99ed1128324eac
 * Entry: 0x644bd0; label: FUN_00644bd0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00644bd0(int param_1)

{
  undefined4 uVar1;
  
  DAT_029209fc = FUN_00619250(0x46,0x46,0xb4,300,DAT_02912e80,FUN_00644bb0,"Instance Scale");
  if ((DAT_029209fc != 0) && (DAT_02920970 != 0)) {
    uVar1 = FUN_00625150(0,&DAT_008109d8,0,FUN_00644b90,0,(float)DAT_008101bc * 10.0,
                         *(undefined4 *)(DAT_02920970 + 0xb4),"Instance Scale");
    FUN_00618e10(DAT_029209fc,uVar1);
    FUN_006279b0(param_1,DAT_029209fc);
    *(int *)(DAT_029209fc + 0x14) = *(int *)(param_1 + 0x14) + 10;
    *(int *)(DAT_029209fc + 0x18) = *(int *)(param_1 + 0x18) + 0x28;
  }
  return;
}


/* Ghidra pseudocode, not original source.
 * ev_2e86f2171d5c14e65a9d827277689f6eb238c30686d251b2df2a036861678988
 * Entry: 0x4a8980; label: FUN_004a8980
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004a8980(void)

{
  int in_EAX;
  undefined4 uVar1;
  char *pcVar2;
  
  if ((*(short *)(in_EAX + 0x1064) != DAT_007f1878) && (0.0 < *(float *)(in_EAX + 0xd3c))) {
    if (*(short *)(in_EAX + 0x1064) == DAT_007f187c) {
      pcVar2 = "Grv_GuardWeaponLp";
    }
    else if ((*(byte *)(*(int *)(in_EAX + 0x54) + 4) & 4) == 0) {
      pcVar2 = "SaberLoopJ";
    }
    else {
      pcVar2 = "SaberLoopB";
    }
    uVar1 = FUN_00650dc0(pcVar2);
    FUN_00681eb0(uVar1,in_EAX + 0x80,*(undefined4 *)(in_EAX + 0xd3c));
  }
  return;
}


/* Ghidra pseudocode, not original source.
 * ev_8a909e0f7cdee8f131d9fa101a03e4afa99ad6c03186a84914f93ab3f48399ec
 * Entry: 0x61fa00; label: FUN_0061fa00
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0061fa00(undefined4 param_1,undefined4 param_2,int param_3)

{
  int in_EAX;
  int iVar1;
  float10 extraout_ST0;
  
  iVar1 = FUN_006e6b90();
  *(undefined4 *)(in_EAX + 0x60) = 0x3c;
  *(float *)(in_EAX + 0x54) = (float)(extraout_ST0 * (float10)iVar1);
  *(float *)(in_EAX + 0x50) =
       ((float)(extraout_ST0 * (float10)iVar1) - *(float *)(in_EAX + 0x58)) /
       *(float *)(in_EAX + 0x5c);
  if (*(code **)(in_EAX + 0x4c) != (code *)0x0) {
    (**(code **)(in_EAX + 0x4c))(param_1,param_2,*(undefined4 *)(param_3 + 0x70));
  }
  return;
}


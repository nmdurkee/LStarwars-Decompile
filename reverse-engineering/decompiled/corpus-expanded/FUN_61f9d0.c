/* Ghidra pseudocode, not original source.
 * ev_8a909e0f7cdee8f131d9fa101a03e4afa99ad6c03186a84914f93ab3f48399ec
 * Entry: 0x61f9d0; label: FUN_0061f9d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0061f9d0(undefined4 param_1,undefined4 param_2,float param_3)

{
  int in_EAX;
  
  *(undefined4 *)(in_EAX + 0x60) = 0x3c;
  *(float *)(in_EAX + 0x54) = param_3;
  *(float *)(in_EAX + 0x50) = (param_3 - *(float *)(in_EAX + 0x58)) / *(float *)(in_EAX + 0x5c);
  if (*(code **)(in_EAX + 0x4c) != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0061f9f5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(in_EAX + 0x4c))();
    return;
  }
  return;
}


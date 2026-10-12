/* Ghidra pseudocode, not original source.
 * ev_4df9c92bab8da1c62fff3d01a59be6c54dba6221cb99b73c04065ca1a333c731
 * Entry: 0x4aad20; label: FUN_004aad20
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004aad20(void)

{
  int in_EAX;
  float10 fVar1;
  
  *(undefined1 *)(in_EAX + 0x7b5) = 0x32;
  *(undefined2 *)(in_EAX + 0x7aa) = 0x23;
  fVar1 = (float10)FUN_0062e040((int)*(short *)(in_EAX + 0x1064),0x23,0,0,1);
  *(float *)(in_EAX + 0x77c) = (float)fVar1;
  FUN_00681f40("DDekaFold",in_EAX + 0x80);
  return;
}


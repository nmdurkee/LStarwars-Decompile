/* Ghidra analysis pseudocode, not original source.
 * ev_d01615a5a43d674e3d5304a49d42c1316108bf7c3b83d91b26d188fd5d83afac
 * Entry: 0x4aad20; label: FUN_004aad20
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


/* Ghidra pseudocode, not original source.
 * ev_7e454dac1a79555432f813726d68bcfcf5762a505a2d8dbf5e6e5fb42bc98c3e
 * Entry: 0x54d000; label: FUN_0054d000
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0054d000(void)

{
  float fVar1;
  int in_EAX;
  
  fVar1 = *(float *)(in_EAX + 0x50) / 6.0;
  *(undefined4 *)(in_EAX + 0xa4) = *(undefined4 *)(in_EAX + 0x30);
  *(float *)(in_EAX + 0xa8) = *(float *)(in_EAX + 0x34) - (fVar1 * 0.0 + fVar1);
  *(undefined4 *)(in_EAX + 0xac) = *(undefined4 *)(in_EAX + 0x38);
  *(undefined4 *)(in_EAX + 0xb0) = *(undefined4 *)(in_EAX + 0x30);
  *(float *)(in_EAX + 0xb4) = *(float *)(in_EAX + 0x34) - (fVar1 + fVar1);
  *(undefined4 *)(in_EAX + 0xb8) = *(undefined4 *)(in_EAX + 0x38);
  *(undefined4 *)(in_EAX + 0xbc) = *(undefined4 *)(in_EAX + 0x30);
  *(float *)(in_EAX + 0xc0) = *(float *)(in_EAX + 0x34) - (fVar1 + fVar1 + fVar1);
  *(undefined4 *)(in_EAX + 0xc4) = *(undefined4 *)(in_EAX + 0x38);
  *(undefined4 *)(in_EAX + 200) = *(undefined4 *)(in_EAX + 0x30);
  *(float *)(in_EAX + 0xcc) = *(float *)(in_EAX + 0x34) - (fVar1 * 3.0 + fVar1);
  *(undefined4 *)(in_EAX + 0xd0) = *(undefined4 *)(in_EAX + 0x38);
  *(undefined4 *)(in_EAX + 0xd4) = *(undefined4 *)(in_EAX + 0x30);
  *(float *)(in_EAX + 0xd8) = *(float *)(in_EAX + 0x34) - (fVar1 * 4.0 + fVar1);
  *(undefined4 *)(in_EAX + 0xdc) = *(undefined4 *)(in_EAX + 0x38);
  *(undefined4 *)(in_EAX + 0xe0) = *(undefined4 *)(in_EAX + 0x30);
  *(float *)(in_EAX + 0xe4) = *(float *)(in_EAX + 0x34) - (fVar1 * 5.0 + fVar1);
  *(undefined4 *)(in_EAX + 0xe8) = *(undefined4 *)(in_EAX + 0x38);
  return;
}


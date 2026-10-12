/* Ghidra analysis pseudocode, not original source.
 * ev_22c3a398bc6b82f0935d4925f42062b7808fee9576bfee9324dc2ce76fb66214
 * Entry: 0x742120; label: FUN_00742120
 */

void FUN_00742120(void)

{
  float *in_EAX;
  uint in_ECX;
  
  *in_EAX = (float)(in_ECX & 0xff) / 255.0;
  in_EAX[1] = (float)((int)in_ECX >> 8 & 0xff) / 255.0;
  in_EAX[2] = (float)((int)in_ECX >> 0x10 & 0xff) / 255.0;
  in_EAX[3] = (float)((int)in_ECX >> 0x18 & 0xff) / 255.0;
  return;
}


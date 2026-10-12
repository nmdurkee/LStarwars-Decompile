/* Ghidra analysis pseudocode, not original source.
 * ev_22c3a398bc6b82f0935d4925f42062b7808fee9576bfee9324dc2ce76fb66214
 * Entry: 0x742380; label: FUN_00742380
 */

void FUN_00742380(undefined4 param_1)

{
  short *in_ECX;
  
  if ((*(uint *)(in_ECX + 2) & 0xf0000000) == 0x10000000) {
    FUN_006e5750();
    return;
  }
  FUN_006e52e0((int)*in_ECX,param_1,1);
  return;
}


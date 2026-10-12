/* Ghidra analysis pseudocode, not original source.
 * ev_988aedce7a102035a37775149c4794654cf73d0aa98e786da352e425eaa98523
 * Entry: 0x43bb20; label: FUN_0043bb20
 */

undefined4 FUN_0043bb20(int param_1,int param_2,float param_3)

{
  float local_c;
  float local_8;
  float local_4;
  
  if ((param_1 != 0) && (param_2 != 0)) {
    FUN_005b3800(&local_c,param_2,param_1 + 0x10);
    FUN_005b3620(&local_c,&local_c,-(int)*(short *)(param_1 + 0x28));
    if ((-*(float *)(param_1 + 0x1c) < param_3 + local_c !=
         (-*(float *)(param_1 + 0x1c) == param_3 + local_c)) &&
       ((-0.1 <= local_8 + param_3 &&
        (-*(float *)(param_1 + 0x24) < local_4 + param_3 !=
         (-*(float *)(param_1 + 0x24) == local_4 + param_3))))) {
      if (*(float *)(param_1 + 0x1c) < local_c - param_3) {
        return 0;
      }
      if ((local_8 - param_3 <= *(float *)(param_1 + 0x20)) &&
         (local_4 - param_3 <= *(float *)(param_1 + 0x24))) {
        return 1;
      }
    }
  }
  return 0;
}


/* Ghidra analysis pseudocode, not original source.
 * ev_1b769233bdb8589f5b6c19d1b053d2efd2e6005a2a8cafb96b11ff416f994ddb
 * Entry: 0x4e54d0; label: FUN_004e54d0
 */

void FUN_004e54d0(int param_1)

{
  FUN_005cf5b0(*(undefined4 *)(param_1 + 0x13c),&DAT_0087aaf0,"door_push",1);
  DAT_0087a9e0 = FUN_0051adf0(*(int *)(param_1 + 0x2ae8),
                              *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x2ae8) + 0x10) + 8),
                              "droid_rescue_a","droid_rescue_b",&DAT_0087a950);
  return;
}


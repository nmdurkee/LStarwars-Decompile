/* Ghidra analysis pseudocode, not original source.
 * ev_1c7a82f294435201fd9406ba2f36685e25c9dd11fb4cb3b46f5b103b3befd94c
 * Entry: 0x6039d0; label: FUN_006039d0
 */

void FUN_006039d0(int param_1,int param_2,int *param_3)

{
  undefined4 *puVar1;
  
  *(undefined4 *)(param_2 + 0x7c) = 0;
  if (*(int *)(param_1 + 0x7c) != 0) {
    puVar1 = (undefined4 *)(*param_3 + 3U & 0xfffffffc);
    *param_3 = (*param_3 + 3U & 0xfffffffc) + 4;
    *puVar1 = **(undefined4 **)(param_1 + 0x7c);
    *(undefined4 **)(param_2 + 0x7c) = puVar1;
  }
  return;
}


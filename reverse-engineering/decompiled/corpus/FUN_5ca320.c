/* Ghidra analysis pseudocode, not original source.
 * ev_58a5325186d3cd5df394779674731c2ac26ad2d4ec877fc6396ce44c5c65b6b5
 * Entry: 0x5ca320; label: FUN_005ca320
 */

void FUN_005ca320(int *param_1,int param_2)

{
  ushort uVar1;
  
  if (*param_1 == 0x414e4934) {
    while( true ) {
      if (param_1[10] != 0) {
        param_1[10] = param_1[10] + param_2;
      }
      if (param_1[9] != 0) {
        param_1[9] = param_1[9] + param_2;
      }
      if (param_1[0xc] != 0) {
        param_1[0xc] = param_1[0xc] + param_2;
      }
      if (param_1[0xb] != 0) {
        param_1[0xb] = param_1[0xb] + param_2;
      }
      if (param_1[0xd] != 0) {
        param_1[0xd] = param_1[0xd] + param_2;
      }
      if (param_1[0xe] != 0) {
        param_1[0xe] = param_1[0xe] + param_2;
      }
      uVar1 = *(ushort *)(param_1 + 5);
      if (uVar1 == 0) break;
      param_2 = param_2 + (uint)uVar1;
      param_1 = (int *)((int)param_1 + (uint)uVar1);
    }
  }
  return;
}


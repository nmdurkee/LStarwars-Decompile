/* Ghidra pseudocode, not original source.
 * ev_506f2ef4e11b68e7edff25e0427d0f13a0f8158f7d3b962ea2de52b74731d8d7
 * Entry: 0x5ca320; label: FUN_005ca320
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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


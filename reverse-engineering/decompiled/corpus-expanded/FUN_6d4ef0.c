/* Ghidra pseudocode, not original source.
 * ev_334294c16a8347b4bc11d90e134269a6e2c30475b5c30bcaa57a53f4585ea308
 * Entry: 0x6d4ef0; label: FUN_006d4ef0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_006d4ef0(uint param_1,int *param_2,int *param_3,int *param_4,uint *param_5)

{
  int in_ECX;
  
  if (param_1 < 0x20) {
    if (param_2 != (int *)0x0) {
      *param_2 = (int)*(char *)(in_ECX + 0x67f0 + param_1 * 6);
    }
    if (param_3 != (int *)0x0) {
      *param_3 = (int)*(char *)(in_ECX + 0x67f1 + param_1 * 6);
    }
    if (param_4 != (int *)0x0) {
      *param_4 = (int)*(char *)(in_ECX + (param_1 * 3 + 0x33f9) * 2);
    }
    if (param_5 != (uint *)0x0) {
      *param_5 = (uint)*(ushort *)(in_ECX + 0x67f4 + param_1 * 6);
    }
    return 1;
  }
  return 0;
}


/* Ghidra pseudocode, not original source.
 * ev_a45c3c1faa99142355c13bd889df9cc9cfbd82e1fed23ccee59d68361bef177f
 * Entry: 0x5f8a80; label: FUN_005f8a80
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_005f8a80(int param_1,int param_2,uint *param_3,undefined4 *param_4)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + param_2 * 0x1c);
  param_1 = param_1 + param_2 * 0x1c;
  if (iVar1 == 0) {
    if (param_3 != (uint *)0x0) {
      *param_3 = 0;
    }
    if (param_4 != (undefined4 *)0x0) {
      *param_4 = 0;
    }
    return 0;
  }
  if (param_3 != (uint *)0x0) {
    *param_3 = (uint)*(ushort *)(param_1 + 0xc);
  }
  if (param_4 != (undefined4 *)0x0) {
    *param_3 = *(uint *)(param_1 + 0x10);
  }
  return iVar1;
}


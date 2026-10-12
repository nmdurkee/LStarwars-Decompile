/* Ghidra pseudocode, not original source.
 * ev_fbd0714d29abf1967b7a59c1140afabe8eda1c53d580ba604e59c833adf58051
 * Entry: 0x6194c0; label: FUN_006194c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_006194c0(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x14);
  if (*(int *)(param_1 + 0x18) != 0) {
    if (((byte)DAT_02912ec8 & 0x40) != 0) {
      (**(code **)(iVar1 + 0x4c))(*(undefined4 *)(param_1 + 0x10),iVar1,DAT_02912ec4);
      return 0;
    }
    if (((*(int *)(param_1 + 0x18) != 0) && ((DAT_02912ec4 & 0x40) != 0)) &&
       (*(code **)(iVar1 + 0x50) != (code *)0x0)) {
      (**(code **)(iVar1 + 0x50))(*(undefined4 *)(param_1 + 0x10),iVar1,DAT_02912ec4);
    }
  }
  return 0;
}


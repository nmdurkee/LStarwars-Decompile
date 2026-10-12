/* Ghidra pseudocode, not original source.
 * ev_b0f5904faee5764ce17927395194cf9c706559b4251213f14920f3fe78cd8be0
 * Entry: 0x43c0c0; label: FUN_0043c0c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0043c0c0(undefined4 param_1,undefined1 *param_2)

{
  int iVar1;
  
  iVar1 = FUN_004f8b10(param_1,&DAT_00755d44);
  if (iVar1 == 0) {
    *param_2 = 0;
    return 1;
  }
  iVar1 = FUN_004f8b10(param_1,&DAT_00755d3c);
  if (iVar1 == 0) {
    *param_2 = 1;
    return 1;
  }
  iVar1 = FUN_004f8b10(param_1,"TIPTOE");
  if (iVar1 == 0) {
    *param_2 = 2;
    return 1;
  }
  return 0;
}


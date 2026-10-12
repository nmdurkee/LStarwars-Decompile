/* Ghidra pseudocode, not original source.
 * ev_f37daf0a5dc4028c7f86144cc3857775ddac8ffa4172b341c81015a8a14d5d27
 * Entry: 0x5c20b0; label: FUN_005c20b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005c20b0(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *in_ECX;
  
  iVar1 = FUN_004f1ff0(param_1);
  FUN_004ef660(in_ECX + 1,param_1,iVar1 + 1);
  in_ECX[9] = in_ECX[9] + 1;
  *in_ECX = param_2;
  return;
}


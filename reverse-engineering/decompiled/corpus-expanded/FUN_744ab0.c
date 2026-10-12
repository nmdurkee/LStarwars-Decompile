/* Ghidra pseudocode, not original source.
 * ev_0a8198a66e8ec6a1eea085c3401beb2c994e6aa9b143cc409d97940c91a3eeae
 * Entry: 0x744ab0; label: FUN_00744ab0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00744ab0(undefined1 *param_1)

{
  int iVar1;
  
  if (param_1 == (undefined1 *)0x0) {
    param_1 = &DAT_0297d688;
  }
  iVar1 = 0;
  do {
    *(undefined1 *)((int)&DAT_00854260 + iVar1) = param_1[iVar1];
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0x10);
  return;
}

